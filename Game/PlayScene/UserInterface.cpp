/*
�w�i�̏���
�쐬�� : 2020/07/22
�ŏI����:2020/10/01
�쐬�� : ���V�x��
*/

#include "UserInterface.h"
#include "../GameData.h"


// �萔
#define PLAYER_RECT_X1			0
#define PLAYER_RECT_Y1			0
#define PLAYER_RECT_X2			32
#define PLAYER_RECT_Y2			32

#define PLAYER_RECT_X3			64
#define PLAYER_RECT_Y3			64


#define SCREEN_WIDTH    (640)                  // ��ʂ̕�[pixel]
#define SCREEN_HEIGHT   (480)                  // ��ʂ̍���[pixel]

#define SCREEN_TOP      (0)                    // ��ʂ̏�[
#define SCREEN_BOTTOM   (SCREEN_HEIGHT)        // ��ʂ̉��[
#define SCREEN_LEFT     (0)                    // ��ʂ̍��[
#define SCREEN_RIGHT    (SCREEN_WIDTH)         // ��ʂ̉E�[

#define SCREEN_CENTER_X (SCREEN_WIDTH  / 2)    // ��ʂ̒���(X���W)
#define SCREEN_CENTER_Y (SCREEN_HEIGHT / 2)    // ��ʂ̒���(Y���W)


// �C���^�[�t�F�[�X�̒萔---------------------
// �X�R�A
#define UI_SCORE_X				30
#define UI_SCORE_Y				10

// �c�@
#define UI_RE_X					300
#define UI_RE_Y					10

// �t�H���g�̃T�C�Y
#define FONT_SIZE_B				32
#define FONT_SIZE_S				16


void UserInterface::Initialize(void)
{
	mPlayerStock = LoadGraph("Resources/Textures/�n�[�g.png");
	// �摜�̐ݒ�
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


	// �P�[�W�̉���
	HpSide = 100;

	// �̗͂̍ő�l
	HpMax = 5;

	HpGauge = 0;

}

void UserInterface::Update(void)
{
	// �̗̓Q�[�W�̐F�̍X�V
	HpColor = g_gameData.mStock * (512.0f / HpMax) - 100;
	
	// �Ԃ̗�
	Red = (int)min(max((384 - HpColor), 0), 0xff);
	// �΂̗�
	Green = (int)min(max((HpColor + 64), 0), 0xff);
	// �̗�
	Blue = (int)max((HpColor - 384), 0);

	// �Q�[�W�̒���
	HpGauge = HpSide * g_gameData.mStock / HpMax;
}


void UserInterface::Draw(void)
{
	// �n�[�g�̕`��
	mSprite.Draw();

	// �̗̓Q�[�W�̕`��
	DrawBox(30, 10, 30 + HpGauge, 30, GetColor(Red, Green, Blue), true);

	SetFontSize(FONT_SIZE_S);

	// �X�R�A�����̕\��
	DrawFormatString(
		UI_RE_X,
		SCREEN_CENTER_Y - 230,
		GetColor(255, 255, 255),
		"SCORE"
	);

	// �X�R�A�̕\��
	DrawFormatString(
		UI_RE_X,
		SCREEN_CENTER_Y - 215,
		GetColor(255, 255, 255),
		"%d",
		g_gameData.mBreakScore
	);

	// �^�C���̕���
	DrawFormatString(
		SCREEN_RIGHT - 60,
		SCREEN_CENTER_Y - 230,
		GetColor(255, 255, 255),
		"TIME"
	);

	SetFontSize(FONT_SIZE_S);
}
