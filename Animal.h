#pragma once
#include <iostream>

/// --------------------------------------------------------
///		　			  基底クラス：Animal
/// --------------------------------------------------------
class Animal
{
public: /// ---------- メンバ関数 ---------- ///
	virtual void MakeSound() const = 0; // 純粋仮想関数
	virtual ~Animal() = default; // 仮想デストラクタ
};

