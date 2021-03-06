/*
wiĖ
ėŽú : 2020/09/25
ÅIēŪ:2020/10/01
ėŽŌ : ÄāVxî
*/

#include "BackGround.h"

void BackGround::Initialize(void)
{
	// wiĖ[h
	mBackGroundHandle1 = LoadGraph("Resources/Textures/wetwet2.png");
	mBackGroundHandle2 = LoadGraph("Resources/Textures/wetwet3.png");
}


void BackGround::Draw(void)
{
	// wiĖ`æ
	DrawGraph(mX, SCREEN_TOP, mBackGroundHandle1,TRUE);
	DrawGraph(mX -SCREEN_RIGHT, SCREEN_TOP, mBackGroundHandle1, TRUE);
	DrawGraph(mX - (SCREEN_RIGHT*2), SCREEN_TOP, mBackGroundHandle1, TRUE);

	// wiĖ`æ
	DrawGraph(mX2, SCREEN_TOP, mBackGroundHandle2, TRUE);
	DrawGraph(mX2 -SCREEN_RIGHT, SCREEN_TOP, mBackGroundHandle2, TRUE);
	DrawGraph(mX2 - (SCREEN_RIGHT*2), SCREEN_TOP, mBackGroundHandle2, TRUE);
}

void BackGround::Move(void)
{
	// wiðŪĐ·Ï
	mX += 2;

	mX2 += 1;

	if (mX >= 640*2)
	{
		mX = 640;
	}

	
	if (mX2 >= 640*2)
	{
		mX2 = 640;
	}
}

void BackGround::Finalize(void)
{
	DeleteGraph(mBackGroundHandle1);
	DeleteGraph(mBackGroundHandle2);
}

