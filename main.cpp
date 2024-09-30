#include <stdio.h>
#include <limits>
#include <ctype.h> // isdigitを使う

// テンプレートの宣言
template <typename T>
// 比較関数（小さい方）
T Min(T a, T b) { return (a < b) ? a : b; }

// char型のテンプレートの特殊化
template <> // テンプレートの解除
char Min<char>(char a, char b)
{
	// 文字が数字じゃないとき
	if (!isdigit(a) || !isdigit(b))
	{
		printf("数字以外は代入できません\n");
		return std::numeric_limits<char>::min(); // エラーの場合のデフォルト値
	}
	return (a < b) ? a : b;
}

int main()
{
	int a = 32, b = 64;
	float c = 3.14f, d = 2.78f;
	double e = 6.39, f = 4.22;
	char g = '7', h = '4';

	// Min関数呼び出し
	printf("int : %d\n", Min(a, b));	 // intの比較
	printf("float : %f\n", Min(c, d));	 // float型の比較
	printf("double : %lf\n", Min(e, f)); // double型の比較

	// char型の文字か数字かわかりやすく
	char result = Min(g, h);
	if (result == std::numeric_limits<char>::min())
	{
		printf("chat : ???\n"); // エラー時は'???'を表示
	}
	else
	{
		printf("char : %c\n", result);	 // 正常時はchar型の比較結果を表示
	}

	return 0;
}
