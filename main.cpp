#include <stdio.h>

// テンプレートの宣言
template <typename T>

// テンプレートの定義
T add(T a, T b) { return static_cast<T>(a + b); }

// 複数の関数のテンプレートの定義
template <typename T1, typename T2>
T1 add(T1 a, T2 b) { return a + b; }

// テンプレートの特殊化（オーバーライド）
template <> // テンプレートの解除
float add<float>(float a, float b) { return a - b; }

// オーバーロード
float add(float a, float b) { return a * b; }

// テンプレートの宣言
template <typename T>
// 比較関数（小さい方）
T Min(T a, T b)
{
	return (a > b) ? a : b;
}

// char型のテンプレートの特殊化
template <> // テンプレートの解除
char Min(char a, char b)
{
	return (a > b) ? a : b;
}

int main()
{

	return 0;
}
