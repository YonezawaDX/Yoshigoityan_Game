/*
ゲーム内の詳細データ
作成日 : 2020/06/28
最終調整:2020/10/01
作成者 : 米澤駿介
*/
#pragma once

#include "../Utility.h"
#include "../GameData.h"




// 敵の種類
enum ENEMY_TYPE
{
	// 通常←
	ENEMY_TYPE_RIGHT_60,
	ENEMY_TYPE_RIGHT_120,
	ENEMY_TYPE_RIGHT_180,
	ENEMY_TYPE_RIGHT_240,
	ENEMY_TYPE_RIGHT_300,
	ENEMY_TYPE_RIGHT_360,
	ENEMY_TYPE_RIGHT_420,
	
	// 通常→
	ENEMY_TYPE_LEFT_60,
	ENEMY_TYPE_LEFT_120,
	ENEMY_TYPE_LEFT_180,
	ENEMY_TYPE_LEFT_240,
	ENEMY_TYPE_LEFT_300,
	ENEMY_TYPE_LEFT_360,
	ENEMY_TYPE_LEFT_420,
	
	// 通常↓
	ENEMY_TYPE_TOP_80,
	ENEMY_TYPE_TOP_160,
	ENEMY_TYPE_TOP_240,
	ENEMY_TYPE_TOP_320,
	ENEMY_TYPE_TOP_400,
	ENEMY_TYPE_TOP_480,
	ENEMY_TYPE_TOP_560,

	// 通常↑
	ENEMY_TYPE_BOTTOM_80,
	ENEMY_TYPE_BOTTOM_160,
	ENEMY_TYPE_BOTTOM_240,
	ENEMY_TYPE_BOTTOM_320,
	ENEMY_TYPE_BOTTOM_400,
	ENEMY_TYPE_BOTTOM_480,
	ENEMY_TYPE_BOTTOM_560,

	// 通常回転
	ENEMY_TYPE_CIRCLE,		

	// 種類の数
	ENEMY_TYPE_NUM
};

// 敵の情報
struct EnemyData
{
	// HP
	int mHp;

	// 移動速度
	float mVel;

	// 当たり半径の半径
	float mRadius;

	// 画像の切り取り情報
	int mRectX1;
	int mRectY1;
	int mRectX2;
	int mRectY2;

	// スコア
	int mScore;

};

// 敵の最大出現数
#define ENEMY_ARRIVAL_NUM		128

// 敵の出現情報
struct EnemyArrivalData
{
	// 出現時間
	int mArrivalTime;

	// 出現する敵の種類
	int mEnemyType;

};

// データをまとめた構造体
struct Database
{

	// 敵の種類
	static const EnemyData msEnemyData[ENEMY_ARRIVAL_NUM];

	// 敵の出現パターン
	static const EnemyArrivalData mEnemyArrivalData[ENEMY_ARRIVAL_NUM];
};