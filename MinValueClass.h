#pragma once
#include <type_traits>

/// ---------- クラステンプレート MinValueClassを定義 ---------- ///
template <typename T1, typename T2>
class MinValueClass
{
public: /// ---------- メンバ関数 ---------- ///
	
	// コンストラクタ
	MinValueClass(T1 value1, T2 value2) : val1(value1), val2(value2) {}

	// Minメンバ関数
	typename std::common_type<T1, T2>::type Min() {
		return val1 < val2 ? val1 : val2;
	}

private: /// ---------- メンバ変数 ---------- ///
	T1 val1;
	T2 val2;
};