/*
背景の処理
作成日 : 2020/07/22
最終調整:2020/10/01
作成者 : 米澤駿介
*/

#include "UserInterface.h"
#include "../GameData.h"


// 定数
#define PLAYER_RECT_X1			0
#define PLAYER_RECT_Y1			0
#define PLAYER_RECT_X2			32
#define PLAYER_RECT_Y2			32

#define PLAYER_RECT_X3			64
#define PLAYER_RECT_Y3			64


#define SCREEN_WIDTH    (640)                  // 画面の幅[pixel]
#define SCREEN_HEIGHT   (480)                  // 画面の高さ[pixel]

#define SCREEN_TOP      (0)                    // 画面の上端
#define SCREEN_BOTTOM   (SCREEN_HEIGHT)        // 画面の下端
#define SCREEN_LEFT     (0)                    // 画面の左端
#define SCREEN_RIGHT    (SCREEN_WIDTH)         // 画面の右端

#define SCREEN_CENTER_X (SCREEN_WIDTH  / 2)    // 画面の中央(X座標)
#define SCREEN_CENTER_Y (SCREEN_HEIGHT / 2)    // 画面の中央(Y座標)


// インターフェースの定数---------------------
// スコア
#define UI_SCORE_X				30
#define UI_SCORE_Y				10

// 残機
#define UI_RE_X					300
#define UI_RE_Y					10

// フォントのサイズ
#define FONT_SIZE_B				32
#define FONT_SIZE_S				16


void UserInterface::Initialize(void)
{
	mPlayerStock = LoadGraph("Resources/Textures/ハート.png");
	// 画像の設定
	mSprite.SetTexture(mPlayerStock);
	mSprite.src.x = PLAYER_RECT_X1;
	mSprite.src.y = PLAYER_RECT_Y1;
	mSprite.size.x = PLAYER_RECT_X2;
	mSprite.size.y = PLAYER_RECT_Y2;

	mSprite.scale.x = 0.5f;
	mSprite.scale.y = 0.5f;

	mSprite.pos.x = 15;
	mSprite.pos.y = 18;

	mSprite.alpha = 1.0f;


	// ケージの横幅
	HpSide = 100;

	// 体力の最大値
	HpMax = 5;

	HpGauge = 0;

}

void UserInterface::Update(void)
{
	// 体力ゲージの色の更新
	HpColor = g_gameData.mStock * (512.0f / HpMax) - 100;
	
	// 赤の量
	Red = (int)min(max((384 - HpColor), 0), 0xff);
	// 緑の量
	Green = (int)min(max((HpColor + 64), 0), 0xff);
	// 青の量
	Blue = (int)max((HpColor - 384), 0);

	// ゲージの長さ
	HpGauge = HpSide * g_gameData.mStock / HpMax;
}


void UserInterface::Draw(void)
{
	// ハートの描画
	mSprite.Draw();

	// 体力ゲージの描画
	DrawBox(30, 10, 30 + HpGauge, 30, GetColor(Red, Green, Blue), true);

	SetFontSize(FONT_SIZE_S);

	// スコア文字の表示
	DrawFormatString(
		UI_RE_X,
		SCREEN_CENTER_Y - 230,
		GetColor(255, 255, 255),
		"SCORE"
	);

	// スコアの表示
	DrawFormatString(
		UI_RE_X,
		SCREEN_CENTER_Y - 215,
		GetColor(255, 255, 255),
		"%d",
		g_gameData.mBreakScore
	);

	// タイムの文字
	DrawFormatString(
		SCREEN_RIGHT - 60,
		SCREEN_CENTER_Y - 230,
		GetColor(255, 255, 255),
		"TIME"
	);

	SetFontSize(FONT_SIZE_S);
}
