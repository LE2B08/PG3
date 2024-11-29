#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <regex>

// StudentIDManager クラスを定義
class StudentIDManager
{
private: /// ---------- メンバ変数 ---------- ///
    std::vector<std::string> student_ids; // 学籍番号を格納するベクタ
    const std::string input_filename;
    const std::string output_filename;

    // 学籍番号のフォーマットを確認するための正規表現
    const std::regex id_format{ "^k0[0-9]{2}g[0-9]{4}@g\\.neec\\.ac\\.jp$" };

public: /// ---------- メンバ関数 ---------- ///
    // コンストラクタ
    StudentIDManager(const std::string& input, const std::string& output)
        : input_filename(input), output_filename(output) {
    }

    // ファイルから学籍番号を読み込む
    bool loadStudentIDs() {
        std::ifstream input_file(input_filename);
        if (!input_file.is_open()) {
            std::cerr << "Error: Could not open file '" << input_filename << "'" << std::endl;
            return false;
        }

        std::string line;
        while (std::getline(input_file, line)) {
            if (!line.empty()) {
                if (std::regex_match(line, id_format)) {
                    student_ids.push_back(line);
                }
                else {
                    std::cerr << "Warning: Invalid ID format skipped: " << line << std::endl;
                }
            }
        }
        input_file.close();

        if (student_ids.empty()) {
            std::cerr << "No valid student IDs found." << std::endl;
            return false;
        }
        return true;
    }

    // 学籍番号をソート
    void sortStudentIDs() {
        std::sort(student_ids.begin(), student_ids.end(), [](const std::string& a, const std::string& b) {
            return a.substr(0, 9) < b.substr(0, 9); // 学籍番号部分のみで比較
            });
    }

    // ソート済み学籍番号をファイルに保存
    bool saveSortedIDs() const {
        std::ofstream output_file(output_filename);
        if (!output_file.is_open()) {
            std::cerr << "Error: Could not open file '" << output_filename << "'" << std::endl;
            return false;
        }

        for (const auto& id : student_ids) {
            output_file << id << std::endl;
        }
        output_file.close();
        return true;
    }

    // ソート結果をコンソールに表示
    void displaySortedIDs() const {
        std::cout << "Sorted student IDs:" << std::endl;
        for (const auto& id : student_ids) {
            std::cout << id << std::endl;
        }
    }
};
