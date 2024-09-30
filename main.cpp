#include <stdio.h>

// 再帰的な賃金を計算する関数
int RecursiveWages(int hour)
{
	if (hour == 1)
	{
		return 100; // 最初の一時間の時給
	}
	else
	{
		return RecursiveWages(hour - 1) * 2 - 50; // 再帰的に自給を計算
	}
}

// 一般的な賃金体系を再帰的な賃金体系を比較する関数
void CompareWages(int hours)
{
	int standardWage = 1072; // 一般的な賃金体系の時給
	int totalStandard = 0;	 // 一般的な賃金の合計
	int toralRecursive = 0;  // 再帰的な賃金の合計

	for (int i = 1; i <= hours; i++)
	{
		// 一般的な賃金体系の合計
		totalStandard += standardWage;

		// 再帰的な賃金体系の合計
		toralRecursive += RecursiveWages(i);

		// 結果を出力
		printf("時間 %d | 一般的な賃金の合計 : %d | 再帰的な賃金の合計 : %d\n", i, totalStandard, toralRecursive);
	}
}

int main()
{
	// 働く時間
	int hours = 8;

	// 比較結果を表示
	CompareWages(hours);
	
	return 0;
}
