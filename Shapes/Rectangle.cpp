#include "Rectangle.h"
#include <iostream>

using namespace std;


/// --------------------------------------------------------
///						　コンストラクタ
/// --------------------------------------------------------
Rectangle::Rectangle(float width, float height) : width_(width), height_(height) {}


/// --------------------------------------------------------
///							　面積
/// --------------------------------------------------------
void Rectangle::Size() const
{
	float area = width_ * height_;

	cout << "Rectangle Area : " << area << endl;
}


/// --------------------------------------------------------
///							　表示
/// --------------------------------------------------------
void Rectangle::Draw() const
{
	Size(); // 面積を求めて表示する
}
