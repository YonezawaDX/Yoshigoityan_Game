/*
プレイヤー
作成日 : 2020/9/26
作成者 : 米澤駿介
*/
#include <math.h>

#include "YoungBird.h"

#include "../GameMain.h"
#include "../GameData.h"

// プレイヤーの状態
enum YOUNG_STATE
{
	YOUNG_STATE_ACTIVE,		// 操作できる状態
	YOUNG_STATE_BOMB,			// やられ状態
};


// 飛行機ミニ画像
#define PLAYER_MINI_X1			192
#define PLAYER_MINI_Y1			0
#define PLAYER_MINI_X2			60
#define PLAYER_MINI_Y2			32


// 初期の残機
#define PLAYER_STOCK_DEFAULT		2

// プレイヤーの当たり判定
#define PLAYER_RADIUS				4.0f

// 円周率
#define PI						3.141592f

#define LIMITH					50.0f


/*----------------------------------------------------
初期化
----------------------------------------------------*/
void Young::Initialize(int textureHandle)
{
	// 状態の初期化
	mState = YOUNG_STATE_ACTIVE;

	// 画像の設定
	mSprite.SetTexture(textureHandle);
	mSprite.src.x = PLAYER_MINI_X1;
	mSprite.src.y = PLAYER_MINI_Y1;
	mSprite.size.x = PLAYER_MINI_X2;
	mSprite.size.y = PLAYER_MINI_Y2;

	mSprite.scale.x = 1.0f;
	mSprite.scale.y = 1.0f;

	mSprite.alpha = 1.0f;

	// 初期座標の設定
	mPos.x = SCREEN_CENTER_X;
	mPos.y = SCREEN_CENTER_Y;

	// 画像に座標を反映
	mSprite.pos.x = SCREEN_CENTER_X;
	mSprite.pos.y = SCREEN_CENTER_Y;

	mCollision.mRadius = PLAYER_RADIUS;
	mCollision.mPos.x = mPos.x;
	mCollision.mPos.y = mPos.y;

	// 敵のやられ音
	mBombSe = LoadSoundMem("Resources/Audio/swing34.wav");
	// 音量変更
	ChangeVolumeSoundMem(80, mBombSe);

}

/*----------------------------------------------------
更新
-----------------------------------------------------*/
void Young::Update(void)
{
	switch (mState)
	{
		// 待機状態		=========================
		case YOUNG_STATE_ACTIVE:
		{
			break;
		}
		// やられ状態        =======================================
		case YOUNG_STATE_BOMB:
		{
			// タイマーを進める
			mBombTimer++;

			if (mBombTimer == 5)
			{
				PlaySoundMem(mBombSe, DX_PLAYTYPE_BACK, TRUE);
				mSprite.src.x = 48;
			}
			else if (mBombTimer == 10)
			{
				mSprite.src.x = 64;
			}
			else if (mBombTimer == 15)
			{
				mSprite.src.x = 80;
			}
			else if (mBombTimer == 20)
			{
				mSprite.alpha = 0.0f;
			}
			else if (mBombTimer >= 60)
			{
				// 爆破が終了したら復帰させる
				mSprite.src.x = PLAYER_MINI_X1;
				mSprite.src.y = PLAYER_MINI_Y1;
				mSprite.size.x = PLAYER_MINI_X2;
				mSprite.size.y = PLAYER_MINI_Y2;


				mSprite.scale.x = 0.8f;
				mSprite.scale.y = 0.8f;

				mSprite.alpha = 1.0f;

				// 爆発タイマーの初期化
				mBombTimer = 0;

				// 復活状態へ
				mState = YOUNG_STATE_ACTIVE;
			}

			break;
		}
	}

	// 画像に座標を反映
	mSprite.pos.x = SCREEN_CENTER_X;
	mSprite.pos.y = SCREEN_CENTER_Y;

	mCollision.mRadius = PLAYER_RADIUS;
	mCollision.mPos.x = mPos.x;
	mCollision.mPos.y = mPos.y;


}

/*-------------------------------------------------
描画
-------------------------------------------------*/
void Young::Draw(void)
{
	//自機の表示
	mSprite.Draw();
}


/*----------------------------------------------------
ダメージ処理
------------------------------------------------------*/
void Young::Damage(void)
{
	g_gameData.mStock--;

	// やられ状態にする
	mState = YOUNG_STATE_BOMB;

	// 見た目を爆破状態へ
	mSprite.src.x = 32;
	mSprite.src.y = 80;
	mSprite.size.x = 16;
	mSprite.size.y = 16;

	mSprite.scale.x = 3.0f;
	mSprite.scale.y = 3.0f;
}


/*-------------------------------------------------------
更新
----------------------------------------------------*/
BOOL Young::IsDamage(void)
{
	BOOL res = mState == YOUNG_STATE_BOMB;

	return res;
}
