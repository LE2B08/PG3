#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::vector<std::vector<int>> map_data; // マップデータ
std::mutex mtx;
std::condition_variable cv;
bool data_ready = false;

// CSVを読み込む関数（バックグラウンドで実行）
void loadCSV(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    std::vector<std::vector<int>> temp_data;
    std::string line;

    while (std::getline(file, line)) {
        std::vector<int> row;
        std::stringstream ss(line);
        std::string cell;

        while (std::getline(ss, cell, ',')) {
            row.push_back(std::stoi(cell)); // 数値に変換
        }
        temp_data.push_back(row);
    }

    // 読み込み完了後にデータを共有
    {
        std::lock_guard<std::mutex> lock(mtx);
        map_data = temp_data;
        data_ready = true;
    }
    cv.notify_one(); // メインスレッドに通知
}

// マップチップを表示する関数
void displayMap() {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, []() { return data_ready; }); // CSV読み込みが完了するまで待機

    // マップデータを表示
    for (const auto& row : map_data) {
        for (const auto& cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    // CSVファイル名
    std::string filename = "map.csv";

    // バックグラウンドでCSVを読み込むスレッドを開始
    std::thread loader(loadCSV, filename);

    // メインスレッドでマップを表示
    displayMap();

    // スレッドを結合
    loader.join();

    return 0;
}