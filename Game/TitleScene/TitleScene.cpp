#include "TitleScene.h"

#include "../GameMain.h"


// �V�[���̏��
enum  TITLE_STATE
{
	TITLE_STATE_INITIALIZE,		// ������

	TITLE_STATE_FADEIN,			// �t�F�[�h�C���҂��̏��
	TITLE_STATE_MAIN,			// ���C������
	TITLE_STATE_FADEOUT,		// �t�F�[�h�A�E�g���

	TITLE_STATE_FINALIZE,		//�I������
};

// �^�C�g�����W
#define TITLE_POS_X			(SCREEN_CENTER_X - 220)
#define TITLE_POS_Y			(SCREEN_CENTER_Y - 80)

// �^�C�g�����S�T�C�Y
#define TITLE_LOGO_SIZE			60

// �L�[���͂̕����ʒu
#define PUSHKEY_POS_X		(SCREEN_CENTER_X - 40)
#define PUSHKEY_POS_Y		(SCREEN_CENTER_Y + 40)

// �L�[���͂̕����_�ŊԊu
#define PUSHKEY_INTERVAL	30

/*---------------------------------------------------
������
---------------------------------------------------*/
void TitleScene::Initialize(void)
{
	// ���艹
	mKeySe = LoadSoundMem("Resources/Audio/SE00.ogg");
	// ���ʕύX
	ChangeVolumeSoundMem(80, mKeySe);

	// �^�C�g���̔w�i
	mBackgroundTexture = LoadGraph("Resources/Textures/re.jpg");
	
	// ���S�̕\��
	mMovieTitle = PlayMovie("Resources/Textures/Movie.avi",1,DX_MOVIEPLAYTYPE_BCANCEL);

	// �^�C�g��BGM
	TitleBGM = LoadSoundMem("Resources/Audio/bgm_maoudamashii_8bit21.mp3");
	// ���ʕύX
	ChangeVolumeSoundMem(80, TitleBGM);

	// �ϐ��Ȃǂ̃��Z�b�g
	Reset();
}

/*--------------------------------------------------
���̃��Z�b�g
---------------------------------------------------*/
void TitleScene::Reset(void)
{
	// ��Ԃ̏�����
	mState = TITLE_STATE_INITIALIZE;

	// �^�C�}�[�̏�����
	mTimer = 0;

	// �t���O�̏�����
	mIsDrawString = FALSE;

	// �摜���̐ݒ�
	mSprite.SetTexture(mBackgroundTexture);
	mSprite.pos.x = 320;
	mSprite.pos.y = 240;
	mSprite.scale.x = 2.0f;
	mSprite.scale.y = 2.0f;
}

/*----------------------------------------------------
�X�V
----------------------------------------------------*/
int TitleScene::Update(void)
{
	int nextScene = GAME_SCENE_NONE;
			
	switch (mState)
	{
		// ������			===============================
		case TITLE_STATE_INITIALIZE:
		{
			// �ϐ��Ȃǂ̃��Z�b�g
			Reset();

			// �t�F�[�h�C����Ԃ�
			mState = TITLE_STATE_FADEIN;

			// �t�F�[�h�A�E�g�ς݂̏�Ԃɂ���
			SetFadeOut();
			
			// BGM
			PlaySoundMem(TitleBGM, DX_PLAYTYPE_LOOP);
			break;
		}
		// �t�F�[�h�C��		===============================
		case TITLE_STATE_FADEIN:
		{
			// �t�F�[�h�C���̍X�V
			int res = FadeInUpdate(FADE_TIME);

			// �t�F�[�h���I�������玟�̏�Ԃ�
			if (res == FALSE)
			{
				mState = TITLE_STATE_MAIN;
			}


			break;
		}
		// ���C������		==============================
		case TITLE_STATE_MAIN:
		{
			
			// �^�C�}�[��i�߂�
			++mTimer %= PUSHKEY_INTERVAL;

			// �����̕\���t���O��؂�ւ���
			if (mTimer == 0)
			{
				mIsDrawString = !mIsDrawString;
			}

			// �{�^���������ꂽ�玟��
			if (IsButtonPressed(PAD_INPUT_1) == TRUE)
			{
				// ���艹
				PlaySoundMem(mKeySe, DX_PLAYTYPE_BACK);

				mState = TITLE_STATE_FADEOUT;
			}

			break;
		}
		// �t�F�[�h�A�E�g	=============================-
		case TITLE_STATE_FADEOUT:
		{
			// �t�F�[�h�̍X�V
			int res = FadeOutUpdate(FADE_TIME);

			//�t�F�[�h���I�������玟�̏�Ԃ�
			if (res == FALSE)
			{
				mState = TITLE_STATE_FINALIZE;
			}

			StopSoundMem(TitleBGM);
			break;
		}
		// �I������			===============================
		case TITLE_STATE_FINALIZE:
		{
			// ���̃V�[����
			nextScene = GAME_SCENE_PLAY;

			// �ϐ��Ȃǂ̃��Z�b�g
			Reset();

			break;
		}	
	}

	return nextScene;
}

/*------------------------------------------------
�`��
------------------------------------------------*/
void TitleScene::Draw(void)
{
	// �^�C�g���w�i�̕\��
	mSprite.Draw();

	// �^�C�g�����S�̕\��
	int defaultSize = GetFontSize();

	SetFontSize(TITLE_LOGO_SIZE);

	DrawFormatString(
		TITLE_POS_X,
		TITLE_POS_Y - 10,
		GetColor(255, 255, 0),
		"�q�i������āI\n���V�S�C�����I"
	);

	SetFontSize(defaultSize);

	// �L�[���͂𑣂������̕\��
	if (mIsDrawString == TRUE)
	{
		DrawFormatString(
			PUSHKEY_POS_X,
			PUSHKEY_POS_Y,
			GetColor(255, 255, 0),
			"Push 1 Key"
		);
	}
}

/*------------------------------------------------------
�I������
-------------------------------------------------------*/
void TitleScene::Finalize(void)
{
	DeleteSoundMem(TitleBGM);
	DeleteGraph(mMovieTitle);
}