/*
弾の処理
作成日 : 2020/07/02
作成者 : 米澤駿介
*/
#pragma once

#include "../Utility.h"
#include "Database.h"
#include "Collision.h"

// 弾を発射した対象
enum SHOOTER_TYPE
{
	SHOOTER_TYPE_PLAYER,		// プレイヤー
	SHOOTER_TYPE_ENEMY,			// 敵

	SHOOTER_TYPE_NUM,			// 発射対象の総数
};

struct Bullet
{
	// 変数 ======================================

	// 弾の種類
	int mBulletType;

	// 発射対象
	int mShooterType;

	// 画像描画構造体
	SpriteData mSprite;

	// 座標
	Float2 mPos;

	// 速度
	Float2 mVel;

	// 使用されているかのフラグ
	BOOL mIsActive;

	// 威力
	int mPower;

	// 円の当たり判定
	CircleCollider mCollision;


	// 触手の移動速度
	float v;

	//触手の中心x,y
	float rx;
	float ry;

	// 触手の先端x,y
	float hx;
	float hy;

	// 触手の腕の長さの限界
	float limith;

	// 移動量の変数
	float etxv;
	float etyv;

	// 先端の計算
	float dx;
	float dy;

	float d;

	int i;

	float angle;
	// 関数 ==========================================

	// 初期化
	void Initialize(int textureHandle, int bulletType, int shooterType, Float2 pos);

	// 更新
	void Update(void);

	// 描画
	void Draw(void);
};