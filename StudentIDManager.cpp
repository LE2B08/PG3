#include "StudentIDManager.h"


/// ------------------------------------------------
///			入力ファイルから学籍番号を読み込む
/// ------------------------------------------------
bool StudentIDManager::loadStudentIDs()
{
    // 入力ファイルを開く
    std::ifstream input_file(input_filename);
    if (!input_file.is_open()) // ファイルが開けなかった場合
    {
        std::cerr << "Error: Could not open file '" << input_filename << "'" << std::endl;
        return false; // エラーを返す
    }

    std::string line;
    // ファイルの内容を1行ずつ読み取る
    while (std::getline(input_file, line))
    {
        if (!line.empty()) { // 空行でない場合
            // 行が正しいフォーマットか確認
            if (std::regex_match(line, id_format))
            {
                student_ids.push_back(line); // フォーマットが正しければベクタに追加
            }
            else
            {
                // フォーマットが不正な場合は警告メッセージを出力
                std::cerr << "Warning: Invalid ID format skipped: " << line << std::endl;
            }
        }
    }
    input_file.close(); // ファイルを閉じる

    if (student_ids.empty()) // 有効な学籍番号が1つも見つからなかった場合
    {
        std::cerr << "No valid student IDs found." << std::endl;
        return false; // エラーを返す
    }

    return true; // 正常に読み込めた場合は成功を返す
}


/// ------------------------------------------------
///			　　学籍番号をソートする
/// ------------------------------------------------
void StudentIDManager::sortStudentIDs()
{
    // 学籍番号部分(k0XXgYYYY)を基準にソート
    std::sort(student_ids.begin(), student_ids.end(), [](const std::string& a, const std::string& b)
        {
            return a.substr(0, 9) < b.substr(0, 9); // 9文字目までを比較
        });
}


/// ------------------------------------------------
///	　ソート済みの学籍番号を出力ファイルに保存する
/// ------------------------------------------------
bool StudentIDManager::saveSortedIDs() const
{
    // 出力ファイルを開く
    std::ofstream output_file(output_filename);
    if (!output_file.is_open()) // ファイルが開けなかった場合
    {
        std::cerr << "Error: Could not open file '" << output_filename << "'" << std::endl;
        return false; // エラーを返す
    }

    // ソート済みの学籍番号をファイルに書き込む
    for (const auto& id : student_ids)
    {
        output_file << id << std::endl; // 1行ずつ書き込み
    }

    output_file.close(); // ファイルを閉じる
    return true; // 正常に保存できた場合は成功を返す
}


/// ------------------------------------------------
///	　ソート済みの学籍番号をコンソールに表示する
/// ------------------------------------------------
void StudentIDManager::displaySortedIDs() const
{
    std::cout << "Sorted student IDs:" << std::endl; // 見出しを表示
    for (const auto& id : student_ids) // 学籍番号を1つずつ処理
    {
        std::cout << id << std::endl; // コンソールに出力
    }
}
