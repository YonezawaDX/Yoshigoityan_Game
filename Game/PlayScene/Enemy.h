/*
プレイヤー
作成日 : 2020/06/04
最終調整:2020/10/01
作成者 : 米澤駿介
*/
#pragma once

#include "../Utility.h"

#include "Collision.h"

struct Enemy
{
	// 変数 ============================

	// 敵の種類
	int mType;

	// 状態
	int mState;

	// HP
	int mHp;

	// 画像情報
	SpriteData mSprite;

	// 座標
	Float2 mPos;

	// 速度
	Float2 mVel;

	// 使用されているかのフラグ
	BOOL mIsActive;

	// 当たり判定情報
	CircleCollider mCollision;

	// 爆破処理用のタイマー
	int mBombTimer;

	// 敵のやられ音
	int mBombSe;

	// カウンター
	int counter;

	// 回転する敵用の関数
	float angle = -90.0f;	// アングル
	float clox = 200.0f;	// 回転ｘ
	float cloy = 200.0f;	// 回転y

	// 関数 ==================================

	// 初期化
	void Initialize(int textureHandle, int enemyType);

	// 更新
	void Update(void);

	// 描画
	void Draw(void);

	// ダメージ処理
	void Damage(int damage);

	// ダメージ判定
	BOOL IsDamage(void);
};