#include "ResultScene.h"

#include "../GameMain.h"
#include "../GameData.h"

//  �V�[���̏��
enum RESULT_STATE
{
	RESULT_STATE_INITIALIZE,		// ������

	RESULT_STATE_FADEIN,			// �t�F�[�h�C���҂��̏��
	RESULT_STATE_MAIN,				// ���C������
	RESULT_STATE_FADEOUT,			// �t�F�[�h�A�E�g���

	RESULT_STATE_FINALIZE,			// �I������

};

// ���U���g�����̍��W
#define RESULT_LOGO_POS_X			(SCREEN_CENTER_X - 100)
#define RESULT_LOGO_POS_Y			(SCREEN_CENTER_Y - 100)

// ���U���g�����̃T�C�Y
#define RESULT_LOGO_SIZE			50
#define RESULT_LOGO_SIZE_SMOLL			15

// ���ʕ����̍��W
#define RESULT_POS_X				(SCREEN_CENTER_X - 100)
#define RESULT_POS_Y				(SCREEN_CENTER_Y + 100)

// ���ʕ����̃T�C�Y
#define RESULT_SIZE					30

// �c�@�̕����̍��W
#define RE_POS_Y					(RESULT_LOGO_POS_Y + 70)

/*------------------------------------------------
������
-------------------------------------------------*/
void ResultScene::Initialize(void)
{
	// ���ʉ��̏�����
	mKeySe = LoadSoundMem("Resources/Audio/SE00.ogg");
	// ���ʕύX
	ChangeVolumeSoundMem(80, mKeySe);
	
	// BGM�̏�����
	mGameClear = LoadSoundMem("Resources/Audio/GameClear.mp3");
	// ���ʕύX
	ChangeVolumeSoundMem(80, mGameClear);
	
	mGameOver = LoadSoundMem("Resources/Audio/gameover.mp3");
	// ���ʕύX
	ChangeVolumeSoundMem(80, mGameOver);

	// �摜�̏�����
	mTop = LoadGraph("Resources/Textures/YoshigoiTop.gif");
	mCen = LoadGraph("Resources/Textures/YoshigoiCen.gif");
	mBott = LoadGraph("Resources/Textures/YoshigoiBott.gif");
	mOver = LoadGraph("Resources/Textures/���V�S�C112.png");

	// �ϐ��Ȃǂ̃��Z�b�g
	Reset();
}

/*------------------------------------------------
���̃��Z�b�g
----------------------------------------------------*/
void ResultScene::Reset(void)
{
	// ��Ԃ̏�����
	mState = RESULT_STATE_INITIALIZE;
}

/*-----------------------------------------------------
�X�V
------------------------------------------------------*/
int ResultScene::Update(void)
{
	int nextScene = GAME_SCENE_NONE;

	switch (mState)
	{
		// ������       ==================================
		case RESULT_STATE_INITIALIZE:
		{
			// �ϐ��Ȃǂ̃��Z�b�g
			Reset();

			// �t�F�[�h�C����Ԃ�
			mState = RESULT_STATE_FADEIN;

			// �t�F�[�h�A�E�g�ς݂̏�Ԃɂ���
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
		// �t�F�[�h�C��		===============================
		case  RESULT_STATE_FADEIN:
		{
			// �t�F�[�h�̍X�V
			int res = FadeInUpdate(FADE_TIME);

			// �t�F�[�h���I�������玟�̏�Ԃ�
			if (res == FALSE)
			{
				mState = RESULT_STATE_MAIN;
			}

			break;
		}
		// ���C������		================================
		case RESULT_STATE_MAIN:
		{

			// �{�^�������������玟��
			if (IsButtonPressed(PAD_INPUT_1) == TRUE)
			{
				// ���艹
				PlaySoundMem(mKeySe, DX_PLAYTYPE_BACK);

				mState = RESULT_STATE_FADEOUT;
			}

			break;
		}
		// �t�F�[�h�A�E�g		===================================
		case RESULT_STATE_FADEOUT:
		{
			// �t�F�[�h�̍X�V
			int res = FadeOutUpdate(FADE_TIME);

			// �t�F�[�h���I�������玟�̏�Ԃ�
			if (res == FALSE)
			{
				mState = RESULT_STATE_FINALIZE;
			}
			StopSoundMem(mGameClear);
			StopSoundMem(mGameOver);
			break;
		}
		// �I������			===========================
		case RESULT_STATE_FINALIZE:
		{
			// ���̃V�[����
			nextScene = GAME_SCENE_TITLE;

			// �ϐ��Ȃǂ̃��Z�b�g
			Reset();

			break;
		}
	}

	return nextScene;
}

/*-------------------------------------------------
�`��
--------------------------------------------------*/
void ResultScene::Draw(void)
{
	int defaultSize = GetFontSize();

	// ���U���g�����̕\��

	SetFontSize(RESULT_LOGO_SIZE);

	// �Q�[���I�[�o�[�̕`��
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

	// �Q�[���N���A�̕`��
	else
	{
		// �X�R�A�ɂ���ďo���摜��ς���----------------------------
		if (g_gameData.mBreakScore >=  5200)
		{
			PlayMovieToGraph(mTop);
			DrawExtendGraph(200, 0, 840, 480, mTop, TRUE);

			SetFontSize(RESULT_LOGO_SIZE_SMOLL);
			DrawFormatString(
				RESULT_LOGO_POS_X + 150,
				RESULT_LOGO_POS_Y + 300,
				GetColor(255, 255, 255),
				"���ɂ̃w�h�o��"
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
				"�X�R�A5200�ȏゾ��...�H"
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
				"�X�R�A3500�ȏゾ��...�H"
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


	// �X�R�A�̕\��
	SetFontSize(RESULT_SIZE);

	DrawFormatString(
		RESULT_POS_X,
		RESULT_POS_Y,
		GetColor(255, 180, 0),
		"�X�R�A : %d",
		g_gameData.mBreakScore
	);

	SetFontSize(defaultSize);
}

/*-------------------------------------------------------------
�I������
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
