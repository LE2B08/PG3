#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <regex>

/// ------------------------------------------------
///			StudentIDManager クラスを定義
/// ------------------------------------------------
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
	bool loadStudentIDs();

	// 学籍番号をソート
	void sortStudentIDs();

	// ソート済み学籍番号をファイルに保存
	bool saveSortedIDs() const;

	// ソート結果をコンソールに表示
	void displaySortedIDs() const;
};
