#include <stdio.h>
#include <Windows.h>

// 関数ポインタ
int addition(int a, int b)
{
	return a + b;
}
int subtraction(int a, int b)
{
	return a - b;
}
int multiplication(int a, int b)
{
	return a * b;
}
int division(int a, int b)
{
	return a / b;
}

// typedefで回避する
typedef int (*newType)(int a);

int twice(int a)
{
	return a * 2;
}

int triple(int a)
{
	return a * 3;
}

// C++のコールバック関数
typedef void (*PFunc)(int*);

// コールバック関数
void DispResult(int* s)
{
	printf("%d秒待って実行されたよ\n", *s);
}

void setTimeout(PFunc p, int second)
{
	// コールバック関数を呼び出す
	Sleep(second * 1000);
	p(&second);
}

int main()
{
	/*int l = 33;
	int h = 4;

	int (*funcArr[4])(int, int) =
	{
		addition,
		subtraction,
		multiplication,
		division
	};

	for (int i = 0; i < 4; i++)
	{
		printf("%d\n", funcArr[i](l, h));
	}*/

	/*newType calc;

	int h = 4;

	calc = &twice;
	printf("%d\n", calc(h));

	calc = &triple;
	printf("%d\n", calc(h));*/

	printf("start\n");

	PFunc p;
	p = DispResult;
	setTimeout(p, 5);

	return 0;
}
