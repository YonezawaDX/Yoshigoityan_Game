#include "ResultScene.h"

#include "../GameMain.h"
#include "../GameData.h"

//  シーンの状態
enum RESULT_STATE
{
	RESULT_STATE_INITIALIZE,		// 初期化

	RESULT_STATE_FADEIN,			// フェードイン待ちの状態
	RESULT_STATE_MAIN,				// メイン処理
	RESULT_STATE_FADEOUT,			// フェードアウト状態

	RESULT_STATE_FINALIZE,			// 終了処理

};

// リザルト文字の座標
#define RESULT_LOGO_POS_X			(SCREEN_CENTER_X - 100)
#define RESULT_LOGO_POS_Y			(SCREEN_CENTER_Y - 100)

// リザルト文字のサイズ
#define RESULT_LOGO_SIZE			50
#define RESULT_LOGO_SIZE_SMOLL			15

// 結果文字の座標
#define RESULT_POS_X				(SCREEN_CENTER_X - 100)
#define RESULT_POS_Y				(SCREEN_CENTER_Y + 100)

// 結果文字のサイズ
#define RESULT_SIZE					30

// 残機の文字の座標
#define RE_POS_Y					(RESULT_LOGO_POS_Y + 70)

/*------------------------------------------------
初期化
-------------------------------------------------*/
void ResultScene::Initialize(void)
{
	// 効果音の初期化
	mKeySe = LoadSoundMem("Resources/Audio/SE00.ogg");
	// 音量変更
	ChangeVolumeSoundMem(80, mKeySe);
	
	// BGMの初期化
	mGameClear = LoadSoundMem("Resources/Audio/GameClear.mp3");
	// 音量変更
	ChangeVolumeSoundMem(80, mGameClear);
	
	mGameOver = LoadSoundMem("Resources/Audio/gameover.mp3");
	// 音量変更
	ChangeVolumeSoundMem(80, mGameOver);

	// 画像の初期化
	mTop = LoadGraph("Resources/Textures/YoshigoiTop.gif");
	mCen = LoadGraph("Resources/Textures/YoshigoiCen.gif");
	mBott = LoadGraph("Resources/Textures/YoshigoiBott.gif");
	mOver = LoadGraph("Resources/Textures/ヨシゴイ112.png");

	// 変数などのリセット
	Reset();
}

/*------------------------------------------------
情報のリセット
----------------------------------------------------*/
void ResultScene::Reset(void)
{
	// 状態の初期化
	mState = RESULT_STATE_INITIALIZE;
}

/*-----------------------------------------------------
更新
------------------------------------------------------*/
int ResultScene::Update(void)
{
	int nextScene = GAME_SCENE_NONE;

	switch (mState)
	{
		// 初期化       ==================================
		case RESULT_STATE_INITIALIZE:
		{
			// 変数などのリセット
			Reset();

			// フェードイン状態へ
			mState = RESULT_STATE_FADEIN;

			// フェードアウト済みの状態にする
			SetFadeOut();
			if (g_gameData.mStock <= 0)
			{
				PlaySoundMem(mGameOver, DX_PLAYTYPE_LOOP);
			}
			else
			{
				PlaySoundMem(mGameClear, DX_PLAYTYPE_LOOP);
			}
			break;
		}
		// フェードイン		===============================
		case  RESULT_STATE_FADEIN:
		{
			// フェードの更新
			int res = FadeInUpdate(FADE_TIME);

			// フェードが終了したら次の状態へ
			if (res == FALSE)
			{
				mState = RESULT_STATE_MAIN;
			}

			break;
		}
		// メイン処理		================================
		case RESULT_STATE_MAIN:
		{

			// ボタンが押さえたら次へ
			if (IsButtonPressed(PAD_INPUT_1) == TRUE)
			{
				// 決定音
				PlaySoundMem(mKeySe, DX_PLAYTYPE_BACK);

				mState = RESULT_STATE_FADEOUT;
			}

			break;
		}
		// フェードアウト		===================================
		case RESULT_STATE_FADEOUT:
		{
			// フェードの更新
			int res = FadeOutUpdate(FADE_TIME);

			// フェードが終了したら次の状態へ
			if (res == FALSE)
			{
				mState = RESULT_STATE_FINALIZE;
			}
			StopSoundMem(mGameClear);
			StopSoundMem(mGameOver);
			break;
		}
		// 終了処理			===========================
		case RESULT_STATE_FINALIZE:
		{
			// 次のシーンへ
			nextScene = GAME_SCENE_TITLE;

			// 変数などのリセット
			Reset();

			break;
		}
	}

	return nextScene;
}

/*-------------------------------------------------
描画
--------------------------------------------------*/
void ResultScene::Draw(void)
{
	int defaultSize = GetFontSize();

	// リザルト文字の表示

	SetFontSize(RESULT_LOGO_SIZE);

	// ゲームオーバーの描画
	if (g_gameData.mStock <= 0)
	{
		DrawGraph(0, 0, mOver, TRUE);

		DrawFormatString(
			RESULT_LOGO_POS_X-10,
			RESULT_LOGO_POS_Y,
			GetColor(255, 0, 0),
			"GAME OVER"
		);
	}

	// ゲームクリアの描画
	else
	{
		// スコアによって出す画像を変える----------------------------
		if (g_gameData.mBreakScore >=  5200)
		{
			PlayMovieToGraph(mTop);
			DrawExtendGraph(200, 0, 840, 480, mTop, TRUE);

			SetFontSize(RESULT_LOGO_SIZE_SMOLL);
			DrawFormatString(
				RESULT_LOGO_POS_X + 150,
				RESULT_LOGO_POS_Y + 300,
				GetColor(255, 255, 255),
				"究極のヘドバン"
			);
		}

		else if (g_gameData.mBreakScore >= 3500)
		{
			PlayMovieToGraph(mCen);
			DrawExtendGraph(200, 0, 840, 480, mCen, TRUE);
			
			SetFontSize(RESULT_LOGO_SIZE_SMOLL);
			DrawFormatString(
				RESULT_LOGO_POS_X + 150,
				RESULT_LOGO_POS_Y + 300,
				GetColor(255, 255, 255),
				"スコア5200以上だと...？"
			);
		}

		else
		{
			PlayMovieToGraph(mBott);
			DrawExtendGraph(200, 0, 840, 480, mBott, TRUE);

			SetFontSize(RESULT_LOGO_SIZE_SMOLL);
			DrawFormatString(
				RESULT_LOGO_POS_X + 150,
				RESULT_LOGO_POS_Y + 300,
				GetColor(255, 255, 255),
				"スコア3500以上だと...？"
			);
		}

		SetFontSize(RESULT_LOGO_SIZE);
		DrawFormatString(
			RESULT_LOGO_POS_X-10,
			RESULT_LOGO_POS_Y,
			GetColor(255, 180, 0),
			"GAME CLEAR"
		);
	}


	// スコアの表示
	SetFontSize(RESULT_SIZE);

	DrawFormatString(
		RESULT_POS_X,
		RESULT_POS_Y,
		GetColor(255, 180, 0),
		"スコア : %d",
		g_gameData.mBreakScore
	);

	SetFontSize(defaultSize);
}

/*-------------------------------------------------------------
終了処理
--------------------------------------------------*/
void ResultScene::Finalize(void)
{
	DeleteSoundMem(mGameClear);
	DeleteSoundMem(mGameOver);
	DeleteGraph(mTop);
	DeleteGraph(mCen);
	DeleteGraph(mBott);
	DeleteGraph(mOver);
}
