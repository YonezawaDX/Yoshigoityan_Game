/*
弾の処理
作成日 : 2020/07/14
作成者 : 米澤駿介
*/
#include "Bullet.h"
#include <math.h>
#include "../GameMain.h"

// 弾が生存している画面外プラスαの範囲
#define BULLET_ALIVE_AREA		50

#define PI 3.14f
#define PLAYER_VEL 10.0f
#define LIMITH 20.0f
/*---------------------------------------------
初期化
引数: int textureHandle(弾の画像ハンドル), int bulletType(弾の種類),Float2 pos
----------------------------------------------*/
void Bullet::Initialize(int textureHandle, int bulletType, int shooterType, Float2 pos)
{
	// 弾の種類を保存
	mBulletType = bulletType;

	// 発射対象の保存
	mShooterType = shooterType;

	// 弾の情報を取得
	const BulletData data = Database::msBulletDate[bulletType];

	//画像の設定
	mSprite.SetTexture(textureHandle);
	mSprite.src.x = data.mRectX1;
	mSprite.src.y = data.mRectY1;
	mSprite.size.x = data.mRectX2;
	mSprite.size.y = data.mRectY2;

	// 初期座標の設定
	mPos.x = pos.x;
	mPos.y = pos.y;

	// 画像に座標を反映
	mSprite.pos.x = mPos.x;
	mSprite.pos.y = mPos.y;

	// 使用状態とする
	mIsActive = TRUE;

	// 威力の設定
	mPower = data.mPower;

	// 当たり判定情報の初期化
	mCollision.mRadius = data.mRadius;
	mCollision.mPos.x = hx;
	mCollision.mPos.y = hy;

	// 移動速度
	v = PLAYER_VEL;

	// 中心
	rx = SCREEN_CENTER_X;
	ry = SCREEN_CENTER_Y;

	// 先端
	hx = rx;
	hy = ry;

	// 長さの限界
	limith = LIMITH;

}

/*----------------------------------------------
更新
-----------------------------------------------*/
void Bullet::Update(void)
{

	// 使用中でなければ処理しない
	if (mIsActive == FALSE)
	{
		return;
	}

	// 弾の情報を取得
	const BulletData data = Database::msBulletDate[mBulletType];

	// 弾の種類に応じた移動処理
	switch (mBulletType)
	{
		case BULLET_TYPE_PLAYER_NORMAL:		// プレイヤー通常弾
		case BULLET_TYPE_PLAYER_POWER:		// プレイヤー強化弾
		{
			// 先端の移動処理

			// 移動
			int inputUD = 0;
			int inputLR = 0;

			// アナログパッドから角度を算出
			GetJoypadAnalogInput(&inputUD, &inputLR, DX_INPUT_PAD1);

			angle = atan2((float)inputUD, (float)inputLR) - PI / 2;
			//if (angle < 0)angle += PI;


			// 入力がされていないならこれ以上処理しない
			if (inputUD == 0 && inputLR == 0)
			{
				// 早期リターン
				return;
			}

			// 先端のx,y方向移動量;
			etxv = cosf(angle) * v;
			etyv = -1 * sinf(angle) * v;


			if (IsButtonDown(PAD_INPUT_1) == TRUE)
			{

				// 先端のx,y方向移動量
				v = 40.0f;
				limith = 220.0f;
			}
			else
			{
				v = PLAYER_VEL;
				limith = LIMITH;
			}



			//先端のx,y座標指定
			hx = etxv + hx;
			hy = etyv + hy;


			// 先端の移動限界の計算
			dx = hx - rx;
			dy = hy - ry;

			d = sqrtf((dx * dx) + (dy * dy));
			if (d > limith)
			{
				hx = dx * limith / d + rx;
				hy = dy * limith / d + ry;
			}

			break;
		}

		case BULLET_TYPE_ENEMY_NORMAL:		// 敵の通常弾
		{
			//mPos.x -= data.mVel;
			break;
		}

	}

	// 画面外に出たら弾を未使用状態にする
	if (
		mPos.x < SCREEN_LEFT - BULLET_ALIVE_AREA ||
		mPos.x > SCREEN_RIGHT + BULLET_ALIVE_AREA ||
		mPos.y < SCREEN_TOP - BULLET_ALIVE_AREA ||
		mPos.y > SCREEN_BOTTOM + BULLET_ALIVE_AREA
		)
	{
		mIsActive = FALSE;
	}

	// 画像に座標を反映
	mSprite.pos.x = mPos.x;
	mSprite.pos.y = mPos.y;

	// 当たり判定に座標を反映
	mCollision.mPos.x = hx;
	mCollision.mPos.y = hy;
}

/*----------------------------------------------------
描画
----------------------------------------------------*/
void Bullet::Draw(void)
{
	// 使用中でなければ処理しない
	if (mIsActive == FALSE)
	{
		return;
	}

	// 自機の表示
	//mSprite.Draw();
}