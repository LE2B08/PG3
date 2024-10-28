#pragma once
#include "Animal.h"

/// --------------------------------------------------------
///		　			  派生クラス：人間の赤ちゃん
/// --------------------------------------------------------
class HumanBaby : public Animal
{
public: /// ---------- メンバ関数 ---------- ///
	
	// 鳴き声
	void MakeSound() const override;
};

