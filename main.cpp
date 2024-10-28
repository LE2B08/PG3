#include <iostream>
#include "MinValueClass.h"

using namespace std;

int main()
{
	/// ---------- 各型の組み合わせでインスタンスを生成し、Min()を呼び出す ---------- ///
	
	// int型の比較
	MinValueClass<int, int> intInt(3, 7);
	cout << "Min(int, int) : " << intInt.Min() << endl;

	// int型、float型の比較
	MinValueClass<int, float> intFloat(4, 3.8518f);
	cout << "Min(int, float) : " << intFloat.Min() << endl;

	// int型、double型の比較
	MinValueClass<int, double> intDouble(8, 7.795);
	cout << "Min(double, double) : " << intDouble.Min() << endl;

	// float型の比較
	MinValueClass<float, float> floatFloat(5.695f, 5.8518f);
	cout << "Min(float, float) : " << floatFloat.Min() << endl;

	// float型、double型の比較
	MinValueClass<float, double> floatDouble(9.865f, 9.851);
	cout << "Min(double, double) : " << floatDouble.Min() << endl;

	// double型の比較
	MinValueClass<double, double> doubleDouble(7.556, 8.851);
	cout << "Min(double, double) : " << doubleDouble.Min() << endl;

	return 0;
}
