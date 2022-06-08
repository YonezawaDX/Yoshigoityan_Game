/*
背景の処理
作成日 : 2020/07/18
最終調整:2020/10/01
作成者 : 米澤駿介
*/

#include "../Utility.h"

#pragma once

#define SCREEN_WIDTH    (640)                  // 画面の幅[pixel]
#define SCREEN_HEIGHT   (480)                  // 画面の高さ[pixel]

#define SCREEN_TOP      (0)                    // 画面の上端
#define SCREEN_BOTTOM   (SCREEN_HEIGHT)        // 画面の下端
#define SCREEN_LEFT     (0)                    // 画面の左端
#define SCREEN_RIGHT    (SCREEN_WIDTH)         // 画面の右端


#define SCREEN_CENTER_X (SCREEN_WIDTH  / 2)    // 画面の中央(X座標)
#define SCREEN_CENTER_Y (SCREEN_HEIGHT / 2)    // 画面の中央(Y座標)


struct BackGround
{
	// 変数 ==================================================
	
	// 後ろ画像の変数
	int mBackGroundHandle1;
	
	// 前画像の変数
	int mBackGroundHandle2;

	// 画像を動かす変数
	int mX;
	int mX2;

	// 関数 ================================================

	// 初期化
	void Initialize(void);

	// 更新
	void Draw(void);

	// 動き
	void Move(void);

	// 終了処理
	void Finalize(void);
};