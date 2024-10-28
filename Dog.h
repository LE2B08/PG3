#pragma once
#include "Animal.h"

/// --------------------------------------------------------
///		　			  派生クラス：Dog
/// --------------------------------------------------------
class Dog : public Animal
{
public: /// ---------- メンバ関数 ---------- ///

	// 鳴き声
	void MakeSound() const override;

};

