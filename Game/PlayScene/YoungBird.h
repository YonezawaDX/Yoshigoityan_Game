/*
ひなの当たり判定
作成日 : 2020/9/26
最終調整:2020/10/01
作成者 : 米澤駿介
*/
#pragma once

#include "../Utility.h"

#include "Collision.h"

// 前方宣言
struct Enemy;

struct Young
{
	// 変数 ====================================

	// 状態
	int mState;

	// 画像描画構造体
	SpriteData mSprite;

	// 座標(先端)
	Float2 mPos;

	// 効果音
	int mBombSe;

	//=============================================

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

	// ダメージ処理
	void Damage(void);

	// 被弾中か確認
	BOOL IsDamage(void);
};
