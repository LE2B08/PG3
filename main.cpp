#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
#include <algorithm>
#include <cstring>


// カスタム文字列型（std::stringの代替として使用）
class CustomString
{
private: /// ---------- メンバ変数 ---------- ///
	char data[64];

public: /// ---------- メンバ関数 ---------- ///

	CustomString(const char* str)
	{
		std::fill(data, data + sizeof(data), '\0'); // すべてを初期化
		std::copy(str, str + std::min(strlen(str), sizeof(data) - 1), data);
	}

	bool operator==(const CustomString& other) const { return std::strcmp(data, other.data) == 0; }

	friend std::ostream& operator<<(std::ostream& os, const CustomString& str)
	{
		os << str.data;
		return os;
	}
};


// 駅名リストの内容を表示する関数
void printStations(const std::list<CustomString>& stations)
{
	for (const auto& station : stations)
	{
		std::cout << station << " -> ";
	}
	std::cout << "END\n";
}

// 指定した名前の駅の次に新しい駅を挿入する関数
void insertAfter(std::list<CustomString>& stations, const CustomString& target, const CustomString& newStation)
{
	auto it = std::find(stations.begin(), stations.end(), target);
	if (it != stations.end())
	{
		stations.insert(std::next(it), newStation);
	}
}


int main()
{
	// 1970年の山手線リストを初期化
	std::list<CustomString> stations1970 =
	{
		"Shinjuku", "Yoyogi", "Harajuku", "Shibuya", "Ebisu", "Meguro",
		"Gotanda", "Osaki", "Shinagawa", "Tamachi", "Hamamatucho",
		"Okachimachi", "Ueno", "Uguisudani", "Nippori", "Tabata",
		"Komagome", "Sugamo", "Otsuka", "Ikebukuro",
	};

	// 西日暮里駅を追加（1971年開業）
	insertAfter(stations1970, "Nippori", "Nishi-Nippori");

	// 2019年の駅リスト（1970年のリストをコピー）
	std::list<CustomString> stations2019 = stations1970;

	// 高輪ゲートウェイ駅を追加（2020年開業）
	insertAfter(stations2019, "Shinagawa", "Takanawa Gateway");

	// 2022年の駅リスト（2019年のリストをコピー）
	std::list<CustomString> stations2022 = stations2019;

	// 各年の駅リストを表示
	std::cout << "Stations in 1970 : \n";
	printStations(stations1970);

	std::cout << "\nStations in 2019 : \n";
	printStations(stations2019);

	std::cout << "\nStations in 2022 : \n";
	printStations(stations2022);

	return 0;
}
