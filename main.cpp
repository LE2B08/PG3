#include "StudentIDManager.h"

int main()
{
    // 入力ファイルと出力ファイルの指定
    const std::string input_filename = "student_ids.txt";
    const std::string output_filename = "sorted_student_ids.txt";

    // StudentIDManager のインスタンスを作成
    StudentIDManager manager(input_filename, output_filename);

    // 学籍番号の処理
    if (manager.loadStudentIDs())
    {
        manager.sortStudentIDs();
        if (manager.saveSortedIDs())
        {
            manager.displaySortedIDs();
        }
    }

    return 0;
}
