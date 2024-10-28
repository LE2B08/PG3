#pragma once
#include "Animal.h"

/// --------------------------------------------------------
///		　			  派生クラス：Cat
/// --------------------------------------------------------
class Cat : public Animal
{
public: /// ---------- メンバ関数 ---------- ///

	// 鳴き声
	void MakeSound() const override;
};

