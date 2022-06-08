/*
背景の処理
作成日 : 2020/07/22
最終調整:2020/10/01
作成者 : 米澤駿介
*/

#pragma once

struct UserInterface
{
	SpriteData mSprite;


	int mPlayerStock;

	// hp表示

	// ケージの横幅---------------------------------
	int HpSide;

	// 体力の最大値
	int HpMax;
	
	// 体力バー
	int HpGauge;

	// 体力カラー
	float HpColor;

	// 色
	unsigned int Red;

	unsigned int Green;

	unsigned int Blue;

	// 初期化
	void Initialize(void);

	// 更新
	void Update(void);

	//描画
	void Draw(void);

};