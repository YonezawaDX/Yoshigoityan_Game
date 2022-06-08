/*
カウントダウンの構造体
作成日 : 2020/09/25
最終調整:2020/10/01
作成者 : 米澤駿介
*/
#include "Countdown.h"
#include "../GameMain.h"

// カウントダウンの秒数
#define COUNTDOWN_TIME		(50 * 60)

// カウントダウンの文字サイズ
#define COUNTDOWN_SIZE		16

// カウントダウンの文字の表示位置
#define COUNTDOWN_POS_X		(SCREEN_RIGHT - 60)
#define COUNTDOWN_POS_Y		(SCREEN_CENTER_Y - 215)

/*---------------------------------
カウントダウンの初期化
-----------------------------------*/
void Countdown::Initialize(void)
{
	mTimer = COUNTDOWN_TIME;
}

/*-----------------------------------
カウントダウンの更新
-------------------------------------*/
void Countdown::Update(void)
{
	// カウントダウン
	mTimer--;
}

/*------------------------------------
カウントダウンの描画
-------------------------------------*/
void Countdown::Draw(void)
{
	// 元の文字サイズを取得
	int defaultSize = GetFontSize();

	// 文字サイズの設定
	SetFontSize(COUNTDOWN_SIZE);

	// カウントダウンの数字を表示
	DrawFormatString(
		COUNTDOWN_POS_X,
		COUNTDOWN_POS_Y,
		GetColor(255, 255, 255),
		"%d",
		(mTimer / 60)
	);

	// 最初の文字のサイズに戻す
	SetFontSize(defaultSize);
}
