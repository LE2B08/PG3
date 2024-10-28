#include "Circle.h"
#include <iostream>

#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;


/// --------------------------------------------------------
///						　コンストラクタ
/// --------------------------------------------------------
Circle::Circle(float radius) : radius_(radius) {}



/// --------------------------------------------------------
///							　面積
/// --------------------------------------------------------
void Circle::Size() const
{
	float area = (float)M_PI * powf(radius_, 2);

	cout << "Circle Area : " << area << endl;
}



/// --------------------------------------------------------
///							　表示
/// --------------------------------------------------------
void Circle::Draw() const
{
	Size();
}
