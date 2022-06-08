#include "PlayScene.h"

#include "../GameMain.h"
#include "../GameData.h"

// �V�[���̏��
enum PLAY_STATE
{
	PLAY_STATE_INITIALIZE,		// ������

	PLAY_STATE_FADEIN,			// �t�F�[�h�C���҂��̏��
	PLAY_STATE_MAIN,			// ���C������
	PLAY_STATE_FADEOUT,			// �t�F�[�h�A�E�g���

	PLAY_STATE_FINALIZE,		// �I������

};

/*------------------------------------------------------------------
������
--------------------------------------------------------------------*/
void PlayScene::Initialize(void)
{
	// �v���C���[�̉摜
	mShootingHandle = LoadGraph("Resources/Textures/allgame2.png");

	// �G�̉摜
	mEnemyHandle = LoadGraph("Resources/Textures/allgame3.png");
	
	// BGM�̃��[�h
	PlayBGM = LoadSoundMem("Resources/Audio/playscene.mp3");
	// ���ʕύX
	ChangeVolumeSoundMem(80, PlayBGM);
	// �ϐ��Ȃǂ̃��Z�b�g
	Reset();
}

/*----------------------------------------------------------
���̃��Z�b�g
------------------------------------------------------------*/
void PlayScene::Reset(void)
{
	// ��Ԃ̏�����
	mState = PLAY_STATE_INITIALIZE;


	// �v���C���[�̏�����
	mPlayer.Initialize(mShootingHandle);

	// ��
	mYoung.Initialize(mShootingHandle);

	// �G�̊Ǘ��҂̏�����
	mEnemyManager.Initialize(mEnemyHandle);

	// �w�i�̏�����
	mBackGround.Initialize();

	// ���[�U�[�C���^�[�t�F�C�X�̏�����
	mUserInterface.Initialize();

	// �J�E���g�_�E���̏�����
	mCountdown.Initialize();

	// ��Q��
	mObs = LoadGraph("Resources/Textures/jama.png");

	// ��Q���̏����ʒu
	mX = -640;
}

/*-----------------------------------------------------------
�X�V
-------------------------------------------------------------*/
int PlayScene::Update(void)
{
	int nextScene = GAME_SCENE_NONE;

	switch (mState)
	{
		// ������      =================================
		case PLAY_STATE_INITIALIZE:
		{
			
			// �ϐ��Ȃǂ̃��Z�b�g
			Reset();

			// �Q�[���f�[�^�̏�����
			g_gameData.Initialize();

			// �t�F�[�h�C����Ԃ�
			mState = PLAY_STATE_FADEIN;

			PlaySoundMem(PlayBGM, DX_PLAYTYPE_LOOP);
			break;
		}
			// �t�F�[�h�C���@�@�@========================
		case PLAY_STATE_FADEIN:
		{
			// �t�F�[�h�̍X�V
			int res = FadeInUpdate(FADE_TIME);

			// �t�F�[�h���I�������玟�̏�Ԃ�
			if (res == FALSE)
			{
				mState = PLAY_STATE_MAIN;
			}

			break;
		}
		// ���C������	    ========================
		case PLAY_STATE_MAIN:
		{
			// �v���C���[�̍X�V
			mPlayer.Update();

			// ���̓���
			mYoung.Update();

			//�w�i�̓���
			mBackGround.Move();

			// �G�̊Ǘ��҂̍X�V
			mEnemyManager.Update();

			// �J�E���g�_�E���̍X�V
			mCountdown.Update();

			// ���[�U�C���^�t�F�[�X�̕`��
			mUserInterface.Update();

			// ��Q���𓮂���
			mX -= 1;

			// ��Q��
			if (mX <= -330 * 2)
			{
				mX = 640;
			}

			// �G�ƒe�Ƃ̓����蔻��
			for (int i = 0; i < ENEMY_NUM; i++)
			{
				// ���g�p��ԂȂ珈�����Ȃ�
				if (mEnemyManager.mEnemies[i].mIsActive == FALSE)
				{
					continue;
				}
			}

			for (int i = 0; i < 50; i++)
			{	
				// �G�ƃv���C���[�Ƃ̓����蔻��
				mPlayer.CheckHitEnemy(&mEnemyManager.mEnemies[i]);
				
			}

			for (int i = 0; i < 50; i++)
			{

				mEnemyManager.CheckHitYoung(&mYoung);
			}

			// �G�����Ȃ��Ȃ�����Q�[���I��
			if (mEnemyManager.IsEnd() == TRUE)
			{
				mState = PLAY_STATE_FADEOUT;
			}

			// �X�g�b�N�������Ȃ�����I��
			if (g_gameData.mStock == 0)
			{
				mState = PLAY_STATE_FADEOUT;
			}

			// �^�C�}�[���O�ɂȂ�����I��
			if (mCountdown.mTimer <= 0)
			{
				mState = PLAY_STATE_FADEOUT;
			}
			break;
		}
		// �t�F�[�h�A�E�g�@�@====================
		case PLAY_STATE_FADEOUT:
		{
			// �t�F�[�h�̍X�V
			int res = FadeOutUpdate(FADE_TIME);

			// �t�F�[�h���I�������玟�̏�Ԃ�
			if (res == FALSE)
			{
				mState = PLAY_STATE_FINALIZE;
			}

			StopSoundMem(PlayBGM);
			break;
		}
		// �I�������@�@=========================
		case PLAY_STATE_FINALIZE:
		{
			// ���̃V�[����
			nextScene = GAME_SCENE_RESULT;

			// �ϐ��Ȃǂ̃��Z�b�g
			Reset();

			break;
		}
	}

	return nextScene;
}

/*-------------------------------------------------
�`��
-------------------------------------------------*/
void PlayScene::Draw(void)
{
	// �w�i�̕`��
	mBackGround.Draw();
	
	// �v���C���[�̕`��
	mPlayer.Draw();

	// �q�i�̕`��
	mYoung.Draw();

	// �G�̊Ǘ��҂̕`��
	mEnemyManager.Draw();

	// ��Q���̕`��
	DrawGraph(mX, SCREEN_TOP, mObs, TRUE);

	//���[�U�[�C���^�[�t�F�[�X�̕`��
	mUserInterface.Draw();

	// �J�E���g�_�E���̕`��
	mCountdown.Draw();
}

/*---------------------------------------------------
�I������
------------------------------------------------------*/
void PlayScene::Finalize(void)
{
	DeleteGraph(mShootingHandle);
	DeleteGraph(mEnemyHandle);
	DeleteSoundMem(PlayBGM);
	DeleteGraph(mObs);

	mBackGround.Finalize();
}



