/*
”wŒi‚Ìˆ—
ì¬“ú : 2020/09/25
ÅI’²®:2020/10/01
ì¬ŽÒ : •ÄàVx‰î
*/

#include "BackGround.h"

void BackGround::Initialize(void)
{
	// ”wŒi‚Ìƒ[ƒh
	mBackGroundHandle1 = LoadGraph("Resources/Textures/wetwet2.png");
	mBackGroundHandle2 = LoadGraph("Resources/Textures/wetwet3.png");
}


void BackGround::Draw(void)
{
	// ”wŒi‚Ì•`‰æ
	DrawGraph(mX, SCREEN_TOP, mBackGroundHandle1,TRUE);
	DrawGraph(mX -SCREEN_RIGHT, SCREEN_TOP, mBackGroundHandle1, TRUE);
	DrawGraph(mX - (SCREEN_RIGHT*2), SCREEN_TOP, mBackGroundHandle1, TRUE);

	// ”wŒi‚Ì•`‰æ
	DrawGraph(mX2, SCREEN_TOP, mBackGroundHandle2, TRUE);
	DrawGraph(mX2 -SCREEN_RIGHT, SCREEN_TOP, mBackGroundHandle2, TRUE);
	DrawGraph(mX2 - (SCREEN_RIGHT*2), SCREEN_TOP, mBackGroundHandle2, TRUE);
}

void BackGround::Move(void)
{
	// ”wŒi‚ð“®‚©‚·•Ï”
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

