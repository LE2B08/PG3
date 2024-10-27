#include <stdio.h>

// 自作クラス
class MyClass
{
public:
	// 自作メンバ関数
	void Func1();
	void Func2();

	

private:
	// メンバ関数ポインタのテーブル
	static void (MyClass::* spFuncTable[])();


};

// staticで宣言したメンバ関数ポインタテーブルの実態
void(MyClass::* MyClass::spFuncTable[])() = {
	&MyClass::Func1, // 要素番号0
	&MyClass::Func2  // 要素番号1
};

int main()
{
	/*// メンバ関数ポインタに関数のアドレスを代入する
	pFunc = &MyClass::TestFunc;

	// メンバ関数ポインタに入ってる関数を呼び出す
	(this->*pFunc);*/

	// メンバ関数ポインタにハイ会っている関数を呼び出す
	(this->*spFuncTable[])();


	return 0;
}
