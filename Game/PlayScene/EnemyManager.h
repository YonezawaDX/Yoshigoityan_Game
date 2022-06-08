/*
敵の管理
作成日 : 2020/06/30
最終調整:2020/10/01
作成者 : 米澤駿介
*/
#pragma once

#include "Enemy.h"

// 前方宣言
struct Young;

// 敵の数
#define ENEMY_NUM		32

struct EnemyManager
{
	// 変数 ====================================

	// 敵の画像ハンドル
	int mTextureHandle;

	// 敵
	Enemy mEnemies[ENEMY_NUM];

	// 敵生成用のタイマー
	int mTimer;

	// 敵の生成配列を参照番号
	int mArrivalIdx;

	// 関数 ===========================

	// 初期化
	void Initialize(int txtureHandle);

	// 更新
	void Update();

	// 描画
	void Draw();

	// 終了処理
	BOOL IsEnd(void);

	// プレイヤーの当たり判定
	void CheckHitYoung(Young* pYoung);
};