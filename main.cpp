#include <iostream>
#include <string>
#include <chrono>

// 時間計測用関数
template <typename Func>
long long measureTime(Func func) {
    auto start = std::chrono::high_resolution_clock::now();
    func();
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

// コピーのテスト
void testCopy(const std::string& src) {
    std::string dest = src; // コピー
}

// 移動のテスト
void testMove(std::string&& src) {
    std::string dest = std::move(src); // 移動
}

int main() {
    // 10万文字の 'a' で初期化された文字列
    std::string a(100000, 'a');

    // コピー時間計測
    auto copyTime = measureTime([&]() {
        testCopy(a);
        });

    // 移動時間計測
    auto moveTime = measureTime([&]() {
        testMove(std::move(a));
        });

    // 結果表示
    std::cout << "Copy Time: " << copyTime << " microseconds\n";
    std::cout << "Move Time: " << moveTime << " microseconds\n";

    return 0;
}