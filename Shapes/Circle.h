#pragma once
#include "IShape.h"


/// --------------------------------------------------------
///		　			  派生クラス：Circle
/// --------------------------------------------------------
class Circle : public IShape
{
public: /// ---------- メンバ関数 ---------- ///

	// コンストラクタ
	Circle(float radius);

	// 面積
	void Size() const override;

	// 値を表示
	void Draw() const override;

private: /// ---------- メンバ変数 ---------- ///
	
	// 半径
	float radius_;
};

