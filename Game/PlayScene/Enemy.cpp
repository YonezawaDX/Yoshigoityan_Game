#include "Enemy.h"

#include "../GameMain.h"
#include "Database.h"
#include "../GameData.h"
#include <math.h>

// 敵の情報
enum ENEMY_STATE
{
	ENEMY_STATE_ACTIVE,		// 通常状態
	ENEMY_STATE_BOMB,		// やられ状態
};

// 敵の生存範囲
#define ENEMY_ALIVE_AREA		100


// 開始座標
#define ENEMY_START				110
#define ENEMY_START_POS_X		(SCREEN_RIGHT - ENEMY_ALIVE_AREA + ENEMY_START)
#define ENEMY_START_POS_X_LEFT	(SCREEN_LEFT + ENEMY_ALIVE_AREA - ENEMY_START)
#define ENEMY_START_POS_Y_TOP	(SCREEN_TOP + ENEMY_ALIVE_AREA - ENEMY_START)
#define ENEMY_START_POS_Y_BOTTOM (SCREEN_BOTTOM - ENEMY_ALIVE_AREA + ENEMY_START)

#define ENEMY_START_POS_Y		(SCREEN_BOTTOM - 50)

// 通常敵の弾発射間隔
#define ENEMY_NORMAL_SHOT_INTERVAL		60

// 円周率
#define PI						3.141593f
#define COUNT_1					40.0f
#define COUNT_2					4.0f

/*---------------------------------------------------------
初期化
引数	:int textureHandle(画像ハンドル), int enemyType(種類)
---------------------------------------------------------*/
void Enemy::Initialize(int textureHandle, int enemyType)
{
	// 弾の種類を保存
	mType = enemyType;

	// 弾の情報を取得
	const EnemyData data = Database::msEnemyData[enemyType];

	// 画像の設定
	mSprite.SetTexture(textureHandle);
	mSprite.src.x = data.mRectX1;
	mSprite.src.y = data.mRectY1;
	mSprite.size.x = data.mRectX2;
	mSprite.size.y = data.mRectY2;

	mSprite.scale.x = 1.0f;
	mSprite.scale.y = 1.0f;

	// HPの初期化
	mHp = data.mHp;


	switch (mType)
	{

		// 右から　Y座標が変わる---------------------------------
		case ENEMY_TYPE_RIGHT_60:
		{
			mPos.x = ENEMY_START_POS_X;
			mPos.y = 60;
			break;
		}
		case ENEMY_TYPE_RIGHT_120:
		{
			mPos.x = ENEMY_START_POS_X;
			mPos.y = 120;
			break;
		}
		case ENEMY_TYPE_RIGHT_180:
		{
			mPos.x = ENEMY_START_POS_X;
			mPos.y = 180;
			break;
		}
		case ENEMY_TYPE_RIGHT_240:
		{
			mPos.x = ENEMY_START_POS_X;
			mPos.y = 240;
			break;
		}
		case ENEMY_TYPE_RIGHT_300:
		{	
			mPos.x = ENEMY_START_POS_X;
			mPos.y = 300;
			break;
		}
		case ENEMY_TYPE_RIGHT_360:
		{
			mPos.x = ENEMY_START_POS_X;
			mPos.y = 360;
			break;
		}
		case ENEMY_TYPE_RIGHT_420:
		{
			mPos.x = ENEMY_START_POS_X;
			mPos.y = 420;
			break;
		}


		// 左から Y座標が変わる------------------------------------------
		case ENEMY_TYPE_LEFT_60:
		{	
			mPos.x = ENEMY_START_POS_X_LEFT;
			mPos.y = 60;
			break;
		}
		case ENEMY_TYPE_LEFT_120:
		{
			mPos.x = ENEMY_START_POS_X_LEFT;
			mPos.y = 120;
			break;
		}
		case ENEMY_TYPE_LEFT_180:
		{
			mPos.x = ENEMY_START_POS_X_LEFT;
			mPos.y = 180;
			break;
		}
		case ENEMY_TYPE_LEFT_240:
		{
			mPos.x = ENEMY_START_POS_X_LEFT;
			mPos.y = 240;
			break;
		}
		case ENEMY_TYPE_LEFT_300:
		{
			mPos.x = ENEMY_START_POS_X_LEFT;
			mPos.y = 300;
			break;
		}
		case ENEMY_TYPE_LEFT_360:
		{
			mPos.x = ENEMY_START_POS_X_LEFT;
			mPos.y = 360;
			break;
		}
		case ENEMY_TYPE_LEFT_420:
		{
			mPos.x = ENEMY_START_POS_X_LEFT;
			mPos.y = 420;
			break;
		}

		// 上から X座標が変わる-------------------------------------------
		case ENEMY_TYPE_TOP_80:
		{
			mPos.x = 80;
			mPos.y = ENEMY_START_POS_Y_TOP;
			break;
		}
		case ENEMY_TYPE_TOP_160:
		{
			mPos.x = 160;
			mPos.y = ENEMY_START_POS_Y_TOP;
			break;
		}
		case ENEMY_TYPE_TOP_240:
		{
			mPos.x = 240;
			mPos.y = ENEMY_START_POS_Y_TOP;
			break;
		}
		case ENEMY_TYPE_TOP_320:
		{
			mPos.x = 320;
			mPos.y = ENEMY_START_POS_Y_TOP;
			break;
		}
		case ENEMY_TYPE_TOP_400:
		{
			mPos.x = 400;
			mPos.y = ENEMY_START_POS_Y_TOP;
			break;
		}
		case ENEMY_TYPE_TOP_480:
		{
			mPos.x = 480;
			mPos.y = ENEMY_START_POS_Y_TOP;
			break;
		case ENEMY_TYPE_TOP_560:
		{
			mPos.x = 560;
			mPos.y = ENEMY_START_POS_Y_TOP;
			break;
		}
		}
		// 下から X座標が変わる-------------------------------------------
		case ENEMY_TYPE_BOTTOM_80:
		{
			mPos.x = 80;
			mPos.y = ENEMY_START_POS_Y_BOTTOM;
			break;
		}
		case ENEMY_TYPE_BOTTOM_160:
		{
			mPos.x = 160;
			mPos.y = ENEMY_START_POS_Y_BOTTOM;
			break;
		}
		case ENEMY_TYPE_BOTTOM_240:
		{
			mPos.x = 240;
			mPos.y = ENEMY_START_POS_Y_BOTTOM;
			break;
		}
		case ENEMY_TYPE_BOTTOM_320:
		{
			mPos.x = 320;
			mPos.y = ENEMY_START_POS_Y_BOTTOM;
			break;
		}
		case ENEMY_TYPE_BOTTOM_400:
		{
			mPos.x = 400;
			mPos.y = ENEMY_START_POS_Y_BOTTOM;
			break;
		}
		case ENEMY_TYPE_BOTTOM_480:
		{
			mPos.x = 480;
			mPos.y = ENEMY_START_POS_Y_BOTTOM;
			break;
		}
		case ENEMY_TYPE_BOTTOM_560:
		{
			mPos.x = 560;
			mPos.y = ENEMY_START_POS_Y_BOTTOM;
			break;
		}

		// 回転---------------------------------------------
		case ENEMY_TYPE_CIRCLE:
		{
			mPos.x = SCREEN_CENTER_X;
			mPos.y = ENEMY_START_POS_Y_TOP;
			break;
		}

	}


	// 画像に座標を反映
	mSprite.pos.x = mPos.x;
	mSprite.pos.y = mPos.y;

	// 状態の初期化
	mState = ENEMY_STATE_ACTIVE;

	// 使用状態とする
	mIsActive = TRUE;

	// 当たり判定の初期化
	mCollision.mRadius = data.mRadius;
	mCollision.mPos.x = mPos.x;
	mCollision.mPos.y = mPos.y;

	// タイマーの初期化
	mBombTimer = 0;

	// 敵のやられ音
	mBombSe = LoadSoundMem("Resources/Audio/swing34.wav");
	// 音量変更
	ChangeVolumeSoundMem(80, mBombSe);
}

/*-------------------------------------------------------
更新
-----------------------------------------------------*/
void Enemy::Update(void)
{

	// アクティブ状態でなければ処理しない
	if (mIsActive == FALSE)
	{
		return;
	}

	// 敵情報の取得
	const EnemyData data = Database::msEnemyData[mType];

	// 敵の種類に応じた動き
	if (mState == ENEMY_STATE_ACTIVE)
	{
		switch (mType)
		{

			// 右から------------------------------------------------
			case ENEMY_TYPE_RIGHT_60:
			{
				//counter++;
				//sinカーブ
				//mPos.y -= sinf(PI*counter/COUNT_1) * COUNT_2;
				mPos.x -= data.mVel;

				break;
			}
			case ENEMY_TYPE_RIGHT_120:
			{
				mPos.x -= data.mVel;
				break;
			}
			case ENEMY_TYPE_RIGHT_180:
			{
				mPos.x -= data.mVel;
				break;
			}
			case ENEMY_TYPE_RIGHT_240:
			{
				mPos.x -= data.mVel;
				break;
			}
			case ENEMY_TYPE_RIGHT_300:
			{
				mPos.x -= data.mVel;
				break;
			}
			case ENEMY_TYPE_RIGHT_360:
			{
				mPos.x -= data.mVel;
				break;
			}
			case ENEMY_TYPE_RIGHT_420:
			{
				mPos.x -= data.mVel;
				break;
			}

			// 左から----------------------------------------------------------
			case ENEMY_TYPE_LEFT_60:
			{
				mPos.x += data.mVel;
				break;
			}
			case ENEMY_TYPE_LEFT_120:
			{
				mPos.x += data.mVel;
				break;
			}
			case ENEMY_TYPE_LEFT_180:
			{
				mPos.x += data.mVel;
				break;
			}
			case ENEMY_TYPE_LEFT_240:
			{
				mPos.x += data.mVel;
				break;
			}
			case ENEMY_TYPE_LEFT_300:
			{
				mPos.x += data.mVel;
				break;
			}
			case ENEMY_TYPE_LEFT_360:
			{
				mPos.x += data.mVel;
				break;
			}
			case ENEMY_TYPE_LEFT_420:
			{
				mPos.x += data.mVel;
				break;
			}

			// 上からくる敵----------------------------------------------------
			case ENEMY_TYPE_TOP_80:
			{
				mPos.y += data.mVel;
				break;
			}
			case ENEMY_TYPE_TOP_160:
			{
				mPos.y += data.mVel;
				break;
			}
			case ENEMY_TYPE_TOP_240:
			{
				mPos.y += data.mVel;
				break;
			}
			case ENEMY_TYPE_TOP_320:
			{
				mPos.y += data.mVel;
				break;
			}
			case ENEMY_TYPE_TOP_400:
			{
				mPos.y += data.mVel;
				break;
			}
			case ENEMY_TYPE_TOP_480:
			{
				mPos.y += data.mVel;
				break;
			}
			case ENEMY_TYPE_TOP_560:
			{
				mPos.y += data.mVel;
				break;
			}

			// 下からくる敵-----------------------------------------------------
			case ENEMY_TYPE_BOTTOM_80:
			{
				mPos.y -= data.mVel;
				break;
			}
			case ENEMY_TYPE_BOTTOM_160:
			{
				mPos.y -= data.mVel;
				break;
			}
			case ENEMY_TYPE_BOTTOM_240:
			{
				mPos.y -= data.mVel;
				break;
			}
			case ENEMY_TYPE_BOTTOM_320:
			{
				mPos.y -= data.mVel;
				break;
			}
			case ENEMY_TYPE_BOTTOM_400:
			{
				mPos.y -= data.mVel;
				break;
			}
			case ENEMY_TYPE_BOTTOM_480:
			{
				mPos.y -= data.mVel;
				break;
			}
			case ENEMY_TYPE_BOTTOM_560:
			{
				mPos.y -= data.mVel;
				break;
			}

			// 回転する敵
			case ENEMY_TYPE_CIRCLE:
			{
				mPos.x += clox * (cosf((angle + 2.0f) * (PI / 180.0f)) - cosf(angle * (PI / 180.0f)));
				mPos.y += cloy * (sinf((angle + 2.0f) * (PI / 180.0f)) - sinf(angle * (PI / 180.0f)));

				angle += 2.0f;
				clox -= 0.3f;
				cloy -= 0.3f;
			}
		}
	}



	// やられ状態
	else if (mState == ENEMY_STATE_BOMB)
	{
		// タイマーをすすめる
		mBombTimer++;

		// スコア
		g_gameData.mBreakScore += data.mScore;


		if (mBombTimer == 5)
		{
			// 爆発音
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
		else if (mBombTimer >= 20)
		{
			// 爆破が終了したら未使用状態にする
			mIsActive = FALSE;

			// 撃破数を1機増やす
			g_gameData.mBreakNum++;
		}


	}

	// 生存範囲外に出たら未使用状態にする
	if (
		mPos.x < SCREEN_LEFT - ENEMY_ALIVE_AREA ||
		mPos.x > SCREEN_RIGHT + ENEMY_ALIVE_AREA ||
		mPos.y < SCREEN_TOP - ENEMY_ALIVE_AREA ||
		mPos.y > SCREEN_BOTTOM + ENEMY_ALIVE_AREA
		)
	{
		mIsActive = FALSE;
	}

	// 画像に座標を反映
	mSprite.pos.x = mPos.x;
	mSprite.pos.y = mPos.y;

	// 当たり判定に座標を更新
	mCollision.mPos.x = mPos.x;
	mCollision.mPos.y = mPos.y;
}

/*--------------------------------------------------
描画
---------------------------------------------------*/
void Enemy::Draw(void)
{
	// アクティブ状態でなければ処理しない
	if (mIsActive == FALSE)
	{
		return;
	}
	// 画像を切り取り描画
	mSprite.Draw();
}

/*-------------------------------------------------
ダメージ処理
--------------------------------------------------*/
void Enemy::Damage(int damage)
{
	// 体力を削る
	mHp -= damage;

	// 体力がなくなっていたら爆破状態へ
	if (mHp <= 0)
	{
		mState = ENEMY_STATE_BOMB;

		// 見た目を爆破状態へ
		mSprite.src.x = 32;
		mSprite.src.y = 80;
		mSprite.size.x = 16;
		mSprite.size.y = 16;

		mSprite.scale.x = 3.0f;
		mSprite.scale.y = 3.0f;
	}
}


/*-------------------------------------------------------
更新
----------------------------------------------------*/
BOOL Enemy::IsDamage(void)
{
	BOOL res = mState == ENEMY_STATE_BOMB;

	return res;
}