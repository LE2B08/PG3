#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

// コールバック関数
typedef void (*PFunc)(int*);

// サイコロの出目を表示するコールバック関数
void DispDiceResult(int* result)
{
	printf("結果は %d でした！\n", *result);
}

// 3秒待ってからコールバック関数を呼び出す
void setTimeout(PFunc p, int second, int result)
{
	Sleep(second * 1000);
	p(&result);
}

// サイコロの丁半
void playGame()
{
	// サイコロの目をランダムに決定
	srand((unsigned int)time(NULL));
	int dice = rand() % 6 + 1; // 1から6の乱数を生成

	// ユーザーに奇数か偶数かを入力させる
	int guess;
	printf("奇数か偶数か当ててください (1 : 奇数, 2 : 偶数): ");
	scanf_s("%d", &guess);

	// 丁半を判定する
	int isEven = (dice % 2 == 0); // 偶数なら1、奇数なら0

	// 3秒後に結果を表示する
	printf("結果を判定中...\n");
	setTimeout(DispDiceResult, 3, dice);

	// 判定結果
	if ((guess == 1 && !isEven) || (guess == 2 && isEven))
	{
		printf("正解です！\n");
	}
	else
	{
		printf("不正解です...\n");
	}

}

int main()
{
	printf("サイコロ丁半ゲームを始めます\n");
	playGame();

	return 0;
}
