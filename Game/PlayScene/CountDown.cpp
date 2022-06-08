/*
�J�E���g�_�E���̍\����
�쐬�� : 2020/09/25
�ŏI����:2020/10/01
�쐬�� : ���V�x��
*/
#include "Countdown.h"
#include "../GameMain.h"

// �J�E���g�_�E���̕b��
#define COUNTDOWN_TIME		(50 * 60)

// �J�E���g�_�E���̕����T�C�Y
#define COUNTDOWN_SIZE		16

// �J�E���g�_�E���̕����̕\���ʒu
#define COUNTDOWN_POS_X		(SCREEN_RIGHT - 60)
#define COUNTDOWN_POS_Y		(SCREEN_CENTER_Y - 215)

/*---------------------------------
�J�E���g�_�E���̏�����
-----------------------------------*/
void Countdown::Initialize(void)
{
	mTimer = COUNTDOWN_TIME;
}

/*-----------------------------------
�J�E���g�_�E���̍X�V
-------------------------------------*/
void Countdown::Update(void)
{
	// �J�E���g�_�E��
	mTimer--;
}

/*------------------------------------
�J�E���g�_�E���̕`��
-------------------------------------*/
void Countdown::Draw(void)
{
	// ���̕����T�C�Y���擾
	int defaultSize = GetFontSize();

	// �����T�C�Y�̐ݒ�
	SetFontSize(COUNTDOWN_SIZE);

	// �J�E���g�_�E���̐�����\��
	DrawFormatString(
		COUNTDOWN_POS_X,
		COUNTDOWN_POS_Y,
		GetColor(255, 255, 255),
		"%d",
		(mTimer / 60)
	);

	// �ŏ��̕����̃T�C�Y�ɖ߂�
	SetFontSize(defaultSize);
}
