/*
タイトルシーン
作成日 : 2020/08/10
最終調整:2020/10/01
作成者 : 米澤駿介
*/
#pragma once

#include "../Utility.h"

#include "Collision.h"


#define  EMAX	20	//触手の数 

struct Enemy;

struct Player
{
	// 変数 ====================================

	// 状態
	int mState;

	// 画像描画構造体
	SpriteData mSprite;

	SpriteData mSprite2;
	// 座標(先端)
	Float2 mPos;

	// 効果音
	int mAttackSe;
	//=============================================
	// 触手の移動速度
	float v;

	//触手の腕の中間のx,y座標
	float x[EMAX];
	float y[EMAX];

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

	// 画像のアングル
	float angle;
	float angle_1;
	float angle2;
	float angle2_1;
	
	float cx;
	float cy;

	//===========================================


	// 弾の発射間隔管理用のタイマー
	int mShootIntervalTimer;

	// 当たり判定
	CircleCollider mCollision;

	// 爆発用タイマー
	int mBombTimer;

	// 無敵タイマー
	int mInvTimer;

	// 弾の発射音
	int mBulletSe;

	// 関数 =====================================

	// 初期化
	void Initialize(int textureHandle);

	// 更新
	void Update(void);

	// 描画
	void Draw(void);

	// 移動
	void Move(void);

	// ダメージ処理
	void Damage(void);

	// 被弾中か確認
	BOOL IsDamage(void);

	// 当たり
	void CheckHitEnemy(Enemy* pEnemy);

};
