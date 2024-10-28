#include <iostream>
#include "MinValueClass.h"

using namespace std;

int main()
{
	/// ---------- 各型の組み合わせでインスタンスを生成し、Min()を呼び出す ---------- ///
	
	// int型の比較
	MinValueClass<int, int> intInt(3, 7);
	cout << "Min(int, int) : " << intInt.Min() << endl;

	// float型の比較
	MinValueClass<float, float> floatFloat(3.695f, 3.8518f);
	cout << "Min(float, float) : " << floatFloat.Min() << endl;

	// double型の比較
	MinValueClass<double, double> doubleDouble(3.865, 2.851);
	cout << "Min(double, double) : " << doubleDouble.Min() << endl;

	return 0;
}
