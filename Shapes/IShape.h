#pragma once

/// --------------------------------------------------------
///		　			  基底クラス：IShape
/// --------------------------------------------------------
class IShape
{
public: /// ---------- メンバ関数 ---------- ///

	// 純粋仮想関数
	virtual ~IShape() = default;
	virtual void Size() const = 0; // 面積の純粋仮想関数
	virtual void Draw() const = 0; // 面積の値を表示する純粋仮想関数
};

