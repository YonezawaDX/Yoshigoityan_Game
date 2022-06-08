/*
�v���C���[
�쐬�� : 2020/9/26
�쐬�� : ���V�x��
*/
#include <math.h>

#include "YoungBird.h"

#include "../GameMain.h"
#include "../GameData.h"

// �v���C���[�̏��
enum YOUNG_STATE
{
	YOUNG_STATE_ACTIVE,		// ����ł�����
	YOUNG_STATE_BOMB,			// ������
};


// ��s�@�~�j�摜
#define PLAYER_MINI_X1			192
#define PLAYER_MINI_Y1			0
#define PLAYER_MINI_X2			60
#define PLAYER_MINI_Y2			32


// �����̎c�@
#define PLAYER_STOCK_DEFAULT		2

// �v���C���[�̓����蔻��
#define PLAYER_RADIUS				4.0f

// �~����
#define PI						3.141592f

#define LIMITH					50.0f


/*----------------------------------------------------
������
----------------------------------------------------*/
void Young::Initialize(int textureHandle)
{
	// ��Ԃ̏�����
	mState = YOUNG_STATE_ACTIVE;

	// �摜�̐ݒ�
	mSprite.SetTexture(textureHandle);
	mSprite.src.x = PLAYER_MINI_X1;
	mSprite.src.y = PLAYER_MINI_Y1;
	mSprite.size.x = PLAYER_MINI_X2;
	mSprite.size.y = PLAYER_MINI_Y2;

	mSprite.scale.x = 1.0f;
	mSprite.scale.y = 1.0f;

	mSprite.alpha = 1.0f;

	// �������W�̐ݒ�
	mPos.x = SCREEN_CENTER_X;
	mPos.y = SCREEN_CENTER_Y;

	// �摜�ɍ��W�𔽉f
	mSprite.pos.x = SCREEN_CENTER_X;
	mSprite.pos.y = SCREEN_CENTER_Y;

	mCollision.mRadius = PLAYER_RADIUS;
	mCollision.mPos.x = mPos.x;
	mCollision.mPos.y = mPos.y;

	// �G�̂��ꉹ
	mBombSe = LoadSoundMem("Resources/Audio/swing34.wav");
	// ���ʕύX
	ChangeVolumeSoundMem(80, mBombSe);

}

/*----------------------------------------------------
�X�V
-----------------------------------------------------*/
void Young::Update(void)
{
	switch (mState)
	{
		// �ҋ@���		=========================
		case YOUNG_STATE_ACTIVE:
		{
			break;
		}
		// ������        =======================================
		case YOUNG_STATE_BOMB:
		{
			// �^�C�}�[��i�߂�
			mBombTimer++;

			if (mBombTimer == 5)
			{
				PlaySoundMem(mBombSe, DX_PLAYTYPE_BACK, TRUE);
				mSprite.src.x = 48;
			}
			else if (mBombTimer == 10)
			{
				mSprite.src.x = 64;
			}
			else if (mBombTimer == 15)
			{
				mSprite.src.x = 80;
			}
			else if (mBombTimer == 20)
			{
				mSprite.alpha = 0.0f;
			}
			else if (mBombTimer >= 60)
			{
				// ���j���I�������畜�A������
				mSprite.src.x = PLAYER_MINI_X1;
				mSprite.src.y = PLAYER_MINI_Y1;
				mSprite.size.x = PLAYER_MINI_X2;
				mSprite.size.y = PLAYER_MINI_Y2;


				mSprite.scale.x = 0.8f;
				mSprite.scale.y = 0.8f;

				mSprite.alpha = 1.0f;

				// �����^�C�}�[�̏�����
				mBombTimer = 0;

				// ������Ԃ�
				mState = YOUNG_STATE_ACTIVE;
			}

			break;
		}
	}

	// �摜�ɍ��W�𔽉f
	mSprite.pos.x = SCREEN_CENTER_X;
	mSprite.pos.y = SCREEN_CENTER_Y;

	mCollision.mRadius = PLAYER_RADIUS;
	mCollision.mPos.x = mPos.x;
	mCollision.mPos.y = mPos.y;


}

/*-------------------------------------------------
�`��
-------------------------------------------------*/
void Young::Draw(void)
{
	//���@�̕\��
	mSprite.Draw();
}


/*----------------------------------------------------
�_���[�W����
------------------------------------------------------*/
void Young::Damage(void)
{
	g_gameData.mStock--;

	// �����Ԃɂ���
	mState = YOUNG_STATE_BOMB;

	// �����ڂ𔚔j��Ԃ�
	mSprite.src.x = 32;
	mSprite.src.y = 80;
	mSprite.size.x = 16;
	mSprite.size.y = 16;

	mSprite.scale.x = 3.0f;
	mSprite.scale.y = 3.0f;
}


/*-------------------------------------------------------
�X�V
----------------------------------------------------*/
BOOL Young::IsDamage(void)
{
	BOOL res = mState == YOUNG_STATE_BOMB;

	return res;
}
