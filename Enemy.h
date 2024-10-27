#pragma once
#include <iostream>


/// --------------------------------------------------------
///						敵クラス
/// --------------------------------------------------------
class Enemy
{
public: /// ---------- メンバ関数 ---------- ///
	
	// コンストラクタ
	Enemy();

	// 状態遷移を行う関数
	void UpdateState();

private: /// ---------- メンバ関数 ---------- ///

	// 接近状態処理
	void Approach();

	// 射撃状態処理
	void Shoot();

	// 離脱状態処理
	void Retreat();

private: /// ---------- メンバ変数
	
	// メンバ関数ポインタテーブル
	using StateFunc = void (Enemy::*)();
	static StateFunc stateFuncTable[];

	// 現在の状態
	int currentState;
};
