/*
プレイヤー
作成日 : 2020/08/10
最終調整:2020/10/01
作成者 : 米澤駿介
*/
#include <math.h>

#include "Player.h"
#include "Enemy.h"

#include "../GameMain.h"


// プレイヤーの状態
enum PLAYER_STATE
{
	PLAYER_STATE_ACTIVE,		// 操作できる状態
	PLAYER_STATE_BOMB,			// やられ状態
};

// 飛行機の画像の切り取り情報
#define PLAYER_RECT_X1			0
#define PLAYER_RECT_Y1			0
#define PLAYER_RECT_X2			32
#define PLAYER_RECT_Y2			32

// 飛行機ミニ画像
#define PLAYER_MINI_X1			192
#define PLAYER_MINI_Y1			0
#define PLAYER_MINI_X2			60
#define PLAYER_MINI_Y2			32

// 移動スピード
#define PLAYER_VEL				10.0f

// 弾の発射間隔
#define PLAYER_BULLET_INTERVAL		5

// 初期の残機
#define PLAYER_STOCK_DEFAULT		2

// プレイヤーの当たり判定
#define PLAYER_RADIUS				5.0f

// 円周率
#define PI						3.141592f

#define LIMITH					50.0f


/*----------------------------------------------------
初期化
----------------------------------------------------*/
void Player::Initialize(int textureHandle)
{
	// 状態の初期化
	mState = PLAYER_STATE_ACTIVE;

	// 画像の設定
	mSprite.SetTexture(textureHandle);
	mSprite.src.x = PLAYER_RECT_X1;
	mSprite.src.y = PLAYER_RECT_Y1;
	mSprite.size.x = PLAYER_RECT_X2;
	mSprite.size.y = PLAYER_RECT_Y2;

	mSprite.scale.x = 1.0f;
	mSprite.scale.y = 1.0f;

	mSprite.alpha = 1.0f;

	// 画像の設定2
	mSprite2.SetTexture(textureHandle);
	mSprite2.src.x = 128;
	mSprite2.src.y = PLAYER_RECT_Y1;
	mSprite2.size.x = PLAYER_RECT_X2 + 2;
	mSprite2.size.y = PLAYER_RECT_Y2;

	mSprite2.scale.x = 1.1f;
	mSprite2.scale.y = 1.1f;

	mSprite2.alpha = 1.0f;

	// 初期座標の設定
	mPos.x = SCREEN_CENTER_X;
	mPos.y = SCREEN_CENTER_Y;

	// 画像に座標を反映
	mSprite.pos.x = hx;
	mSprite.pos.y = hy;

	// 画像に座標を反映
	mSprite2.pos.x = cx;
	mSprite2.pos.y = cy;


	// 弾の発射間隔管理用タイマーの初期化
	mShootIntervalTimer = 0;



	//-----------------------------------------------------
	// 移動速度
	v = PLAYER_VEL;

	// 中心
	rx = SCREEN_CENTER_X;
	ry = SCREEN_CENTER_Y;

	cx = rx;
	cy = ry;

	// 先端
	hx = rx;
	hy = ry;

	// 長さの限界
	limith = LIMITH;



	for (int i = 0; i < EMAX; i++)
	{
		x[i] = rx;
		y[i] = ry;
	}

	// 効果音
	mAttackSe = LoadSoundMem("Resources/Audio/Slash.mp3");
	// 音量変更
	ChangeVolumeSoundMem(50, mAttackSe);
}

/*----------------------------------------------------
更新
-----------------------------------------------------*/
void Player::Update(void)
{
	switch (mState)
	{
		// 操作できる状態		=========================
		case PLAYER_STATE_ACTIVE:
		{
			// タイマー処理
			++mShootIntervalTimer %= PLAYER_BULLET_INTERVAL;

			// 移動処理
			Move();

			break;
		}
		// やられ状態        =======================================
		case PLAYER_STATE_BOMB:
		{
			// タイマーを進める
			mBombTimer++;

			if (mBombTimer == 5)
			{
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
			else if(mBombTimer == 20)
			{
				mSprite.alpha = 0.0f;
			}
			else if (mBombTimer >= 60)
			{
				// 爆破が終了したら復帰させる
				mSprite.src.x = PLAYER_RECT_X1;
				mSprite.src.y = PLAYER_RECT_Y1;
				mSprite.size.x = PLAYER_RECT_X2;
				mSprite.size.y = PLAYER_RECT_Y2;


				mSprite.scale.x = 0.8f;
				mSprite.scale.y = 0.8f;

				mSprite.alpha = 1.0f;

				// 爆発タイマーの初期化
				mBombTimer = 0;

				// 操作可能状態へ
				mState = PLAYER_STATE_ACTIVE;
			}

			break;
		}
	}

	// 画像に座標を反映
	mSprite.pos.x = hx;
	mSprite.pos.y = hy;

	mSprite2.pos.x = rx;
	mSprite2.pos.y = ry;





}

/*-------------------------------------------------
描画
-------------------------------------------------*/
void Player::Draw(void)
{

	// 体の表示
	for (int i = 0; i < EMAX - 2; i++)
	{

		x[i] = (x[i - 1] + x[i + 1]) / 2;
		y[i] = (y[i - 1] + y[i + 1]) / 2;
		
		if (i <= 1)
		{
			x[0] = hx;
			y[0] = hy;


		}

		else if (i == EMAX - 3)
		{
			x[EMAX - 3] = rx;
			y[EMAX - 3] = ry;
		}

		else if (i >= 1 && i != EMAX - 3)
		{
			DrawCircle((int)x[i], (int)y[i], 10, GetColor(192, 136, 105), true, true);
			DrawCircle((int)x[i], (int)y[i], 10, GetColor(0, 0, 0), false, true);

		}

	}

	//自機の表示
	mSprite.Draw();	
	mSprite2.Draw();
}

/*-----------------------------------------------------------------
プレイヤーの移動処理
-------------------------------------------------------*/
void Player::Move(void)
{
	angle = angle;
	angle2 = angle2;
	////////////////////////////////////////////////////////////////////////////////////////
	// 先端の移動処理

	// 頭の移動
	int inputUD = 0;
	int inputLR = 0;

	// 体の移動
	int bodyUD = 0;
	int bodyLR = 0;


	// アナログパッドから角度を算出
	GetJoypadAnalogInput(&inputUD, &inputLR, DX_INPUT_PAD1);

	GetJoypadAnalogInputRight(&bodyLR, &bodyUD, DX_INPUT_PAD1);

	angle = atan2f((float)inputUD, (float)inputLR) - PI / 2;
	//if (angle < 0)angle += PI;
	angle_1 = atan2f((float)-bodyLR, (float)bodyUD) - PI / 2;

	angle2 = atan2f((float)-bodyLR, (float)bodyUD) - PI / 2;
	//if (angle < 0)angle += PI;


	// 入力がされていないならこれ以上処理しない
	if ((inputUD == 0 && inputLR == 0) && (bodyUD == 0 && bodyLR == 0))
	{
		// 早期リターン
		hx = hx;
		hy = hy;

		rx = rx;
		ry = ry;
		return;
	}

	if ((bodyUD < 0 || bodyUD > 0 || bodyLR < 0 || bodyLR > 0) && (inputUD == 0 && inputLR == 0))
	{
		// 中心の移動
		if (bodyLR == 1000)
		{
			rx += 4.0f;
		}
		if (bodyLR == -1000)
		{
			rx -= 4.0f;
		}
		if (bodyUD == 1000)
		{
			ry += 4.0f;
		}
		if (bodyUD == -1000)
		{
			ry -= 4.0f;
		}

		// 先端のx,y方向移動量
		etxv = cosf(angle) * v;
		etyv = -1 * sinf(angle) * v;

		limith = LIMITH;

		//先端のx,y座標指定
		hx = etxv + hx;
		hy = etyv + hy;



		// 先端の移動限界の計算
		dx = hx - rx;
		dy = hy - ry;

		// 先端の平方根を求める
		d = sqrtf((dx * dx) + (dy * dy));
		if (d > limith)
		{
			// 先端の座標が限界ならそれ以上伸ばさない
			hx = dx * limith / d + x[5];
			hy = dy * limith / d + y[5];
		}
		
		// 画像の角度の更新
		mSprite.rot = angle_1;
		mSprite2.rot = angle2;
	}
	else
	{
		// 先端のx,y方向移動量
		etxv = cosf(angle) * v;
		etyv = -1 * sinf(angle) * v;

		// 攻撃時音を出す
		if (IsButtonPressed(PAD_INPUT_1))
		{
			PlaySoundMem(mAttackSe,DX_PLAYTYPE_BACK);
		}

		if (IsButtonDown(PAD_INPUT_1) == TRUE)
		{
			// 先端のx,y方向移動量
			for (int i = 10; i < 40; i+=5)
			{
				v = (float)i;
			}
			limith = 250.0f;
		}
		else if (bodyUD == 0 && bodyLR == 0)
		{
			v = PLAYER_VEL;
			limith = LIMITH;
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

		//画像の角度の更新
		mSprite.rot =  -angle;
		mSprite2.rot = -angle;
	}


	//////////////////////////////////////////////////////////////////////////////

	// 当たり判定
	mCollision.mRadius = PLAYER_RADIUS;
	mCollision.mPos.x = hx;
	mCollision.mPos.y = hy;

	rx = ClampF(rx, SCREEN_LEFT, SCREEN_RIGHT);
	ry = ClampF(ry, SCREEN_TOP, SCREEN_BOTTOM);
}

/*----------------------------------------------------
ダメージ処理
------------------------------------------------------*/
void Player::Damage(void)
{

	// やられ状態にする
	mState = PLAYER_STATE_BOMB;

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
BOOL Player::IsDamage(void)
{
	BOOL res = mState == PLAYER_STATE_BOMB;

	return res;
}


/*-----------------------------------------------------------
当たり判定
--------------------------------------------------------*/
void Player::CheckHitEnemy(Enemy* pEnemy)
{
	if (IsButtonDown(PAD_INPUT_1) == TRUE)
	{

		// すべての弾と渡された対象の判定をとる
		for (int i = 0; i < 50; i++)
		{
			// 特定の条件ならば処理しない
			if (
				pEnemy->IsDamage() == TRUE					// プレイヤーが被弾中
				)
			{
				continue;
			}

			// 当たっていなければ次へ
			if (mCollision.CheckHit(pEnemy->mCollision) == FALSE)
			{
				continue;
			}

			// ダメージ処理
			pEnemy->Damage(20);

			break;
		}
	}
}