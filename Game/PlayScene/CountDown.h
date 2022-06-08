/*
カウントダウン構造体
作成日 : 2020.9.25
最終調整:2020/10/01
作成者 : 米澤駿介
*/
#pragma once

struct Countdown
{
	// 変数=====================================

	// カウントダウン用タイマー
	int mTimer;

	// 関数=====================================

	// 初期化
	void Initialize(void);

	// 更新
	void Update(void);

	// 描画
	void Draw(void);
};