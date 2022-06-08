#include "PlayScene.h"

#include "../GameMain.h"
#include "../GameData.h"

// シーンの状態
enum PLAY_STATE
{
	PLAY_STATE_INITIALIZE,		// 初期化

	PLAY_STATE_FADEIN,			// フェードイン待ちの状態
	PLAY_STATE_MAIN,			// メイン処理
	PLAY_STATE_FADEOUT,			// フェードアウト状態

	PLAY_STATE_FINALIZE,		// 終了処理

};

/*------------------------------------------------------------------
初期化
--------------------------------------------------------------------*/
void PlayScene::Initialize(void)
{
	// プレイヤーの画像
	mShootingHandle = LoadGraph("Resources/Textures/allgame2.png");

	// 敵の画像
	mEnemyHandle = LoadGraph("Resources/Textures/allgame3.png");
	
	// BGMのロード
	PlayBGM = LoadSoundMem("Resources/Audio/playscene.mp3");
	// 音量変更
	ChangeVolumeSoundMem(80, PlayBGM);
	// 変数などのリセット
	Reset();
}

/*----------------------------------------------------------
情報のリセット
------------------------------------------------------------*/
void PlayScene::Reset(void)
{
	// 状態の初期化
	mState = PLAY_STATE_INITIALIZE;


	// プレイヤーの初期化
	mPlayer.Initialize(mShootingHandle);

	// 雛
	mYoung.Initialize(mShootingHandle);

	// 敵の管理者の初期化
	mEnemyManager.Initialize(mEnemyHandle);

	// 背景の初期化
	mBackGround.Initialize();

	// ユーザーインターフェイスの初期化
	mUserInterface.Initialize();

	// カウントダウンの初期化
	mCountdown.Initialize();

	// 障害物
	mObs = LoadGraph("Resources/Textures/jama.png");

	// 障害物の初期位置
	mX = -640;
}

/*-----------------------------------------------------------
更新
-------------------------------------------------------------*/
int PlayScene::Update(void)
{
	int nextScene = GAME_SCENE_NONE;

	switch (mState)
	{
		// 初期化      =================================
		case PLAY_STATE_INITIALIZE:
		{
			
			// 変数などのリセット
			Reset();

			// ゲームデータの初期化
			g_gameData.Initialize();

			// フェードイン状態へ
			mState = PLAY_STATE_FADEIN;

			PlaySoundMem(PlayBGM, DX_PLAYTYPE_LOOP);
			break;
		}
			// フェードイン　　　========================
		case PLAY_STATE_FADEIN:
		{
			// フェードの更新
			int res = FadeInUpdate(FADE_TIME);

			// フェードが終了したら次の状態へ
			if (res == FALSE)
			{
				mState = PLAY_STATE_MAIN;
			}

			break;
		}
		// メイン処理	    ========================
		case PLAY_STATE_MAIN:
		{
			// プレイヤーの更新
			mPlayer.Update();

			// 雛の動き
			mYoung.Update();

			//背景の動き
			mBackGround.Move();

			// 敵の管理者の更新
			mEnemyManager.Update();

			// カウントダウンの更新
			mCountdown.Update();

			// ユーザインタフェースの描画
			mUserInterface.Update();

			// 障害物を動かす
			mX -= 1;

			// 障害物
			if (mX <= -330 * 2)
			{
				mX = 640;
			}

			// 敵と弾との当たり判定
			for (int i = 0; i < ENEMY_NUM; i++)
			{
				// 未使用状態なら処理しない
				if (mEnemyManager.mEnemies[i].mIsActive == FALSE)
				{
					continue;
				}
			}

			for (int i = 0; i < 50; i++)
			{	
				// 敵とプレイヤーとの当たり判定
				mPlayer.CheckHitEnemy(&mEnemyManager.mEnemies[i]);
				
			}

			for (int i = 0; i < 50; i++)
			{

				mEnemyManager.CheckHitYoung(&mYoung);
			}

			// 敵がいなくなったらゲーム終了
			if (mEnemyManager.IsEnd() == TRUE)
			{
				mState = PLAY_STATE_FADEOUT;
			}

			// ストックが無くなったら終了
			if (g_gameData.mStock == 0)
			{
				mState = PLAY_STATE_FADEOUT;
			}

			// タイマーが０になったら終了
			if (mCountdown.mTimer <= 0)
			{
				mState = PLAY_STATE_FADEOUT;
			}
			break;
		}
		// フェードアウト　　====================
		case PLAY_STATE_FADEOUT:
		{
			// フェードの更新
			int res = FadeOutUpdate(FADE_TIME);

			// フェードが終了したら次の状態へ
			if (res == FALSE)
			{
				mState = PLAY_STATE_FINALIZE;
			}

			StopSoundMem(PlayBGM);
			break;
		}
		// 終了処理　　=========================
		case PLAY_STATE_FINALIZE:
		{
			// 次のシーンへ
			nextScene = GAME_SCENE_RESULT;

			// 変数などのリセット
			Reset();

			break;
		}
	}

	return nextScene;
}

/*-------------------------------------------------
描画
-------------------------------------------------*/
void PlayScene::Draw(void)
{
	// 背景の描画
	mBackGround.Draw();
	
	// プレイヤーの描画
	mPlayer.Draw();

	// ヒナの描画
	mYoung.Draw();

	// 敵の管理者の描画
	mEnemyManager.Draw();

	// 障害物の描画
	DrawGraph(mX, SCREEN_TOP, mObs, TRUE);

	//ユーザーインターフェースの描画
	mUserInterface.Draw();

	// カウントダウンの描画
	mCountdown.Draw();
}

/*---------------------------------------------------
終了処理
------------------------------------------------------*/
void PlayScene::Finalize(void)
{
	DeleteGraph(mShootingHandle);
	DeleteGraph(mEnemyHandle);
	DeleteSoundMem(PlayBGM);
	DeleteGraph(mObs);

	mBackGround.Finalize();
}



