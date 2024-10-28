#pragma once
#include "IShape.h"


/// --------------------------------------------------------
///						派生クラス：Rectangle
/// --------------------------------------------------------
class Rectangle : public IShape
{
public: /// ---------- メンバ関数 ---------- ///

	// コンストラクタ
	Rectangle(float width, float height);

	// 面積
	void Size() const override;

	// 値を表示
	void Draw() const override;

private: /// ---------- メンバ変数 ---------- ///
	float width_;
	float height_;
};

