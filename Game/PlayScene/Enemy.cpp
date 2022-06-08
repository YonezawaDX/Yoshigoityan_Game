#include "Enemy.h"

#include "../GameMain.h"
#include "Database.h"
#include "../GameData.h"
#include <math.h>

// �G�̏��
enum ENEMY_STATE
{
	ENEMY_STATE_ACTIVE,		// �ʏ���
	ENEMY_STATE_BOMB,		// ������
};

// �G�̐����͈�
#define ENEMY_ALIVE_AREA		100


// �J�n���W
#define ENEMY_START				110
#define ENEMY_START_POS_X		(SCREEN_RIGHT - ENEMY_ALIVE_AREA + ENEMY_START)
#define ENEMY_START_POS_X_LEFT	(SCREEN_LEFT + ENEMY_ALIVE_AREA - ENEMY_START)
#define ENEMY_START_POS_Y_TOP	(SCREEN_TOP + ENEMY_ALIVE_AREA - ENEMY_START)
#define ENEMY_START_POS_Y_BOTTOM (SCREEN_BOTTOM - ENEMY_ALIVE_AREA + ENEMY_START)

#define ENEMY_START_POS_Y		(SCREEN_BOTTOM - 50)

// �ʏ�G�̒e���ˊԊu
#define ENEMY_NORMAL_SHOT_INTERVAL		60

// �~����
#define PI						3.141593f
#define COUNT_1					40.0f
#define COUNT_2					4.0f

/*---------------------------------------------------------
������
����	:int textureHandle(�摜�n���h��), int enemyType(���)
---------------------------------------------------------*/
void Enemy::Initialize(int textureHandle, int enemyType)
{
	// �e�̎�ނ�ۑ�
	mType = enemyType;

	// �e�̏����擾
	const EnemyData data = Database::msEnemyData[enemyType];

	// �摜�̐ݒ�
	mSprite.SetTexture(textureHandle);
	mSprite.src.x = data.mRectX1;
	mSprite.src.y = data.mRectY1;
	mSprite.size.x = data.mRectX2;
	mSprite.size.y = data.mRectY2;

	mSprite.scale.x = 1.0f;
	mSprite.scale.y = 1.0f;

	// HP�̏�����
	mHp = data.mHp;


	switch (mType)
	{

		// �E����@Y���W���ς��---------------------------------
		case ENEMY_TYPE_RIGHT_60:
		{
			mPos.x = ENEMY_START_POS_X;
			mPos.y = 60;
			break;
		}
		case ENEMY_TYPE_RIGHT_120:
		{
			mPos.x = ENEMY_START_POS_X;
			mPos.y = 120;
			break;
		}
		case ENEMY_TYPE_RIGHT_180:
		{
			mPos.x = ENEMY_START_POS_X;
			mPos.y = 180;
			break;
		}
		case ENEMY_TYPE_RIGHT_240:
		{
			mPos.x = ENEMY_START_POS_X;
			mPos.y = 240;
			break;
		}
		case ENEMY_TYPE_RIGHT_300:
		{	
			mPos.x = ENEMY_START_POS_X;
			mPos.y = 300;
			break;
		}
		case ENEMY_TYPE_RIGHT_360:
		{
			mPos.x = ENEMY_START_POS_X;
			mPos.y = 360;
			break;
		}
		case ENEMY_TYPE_RIGHT_420:
		{
			mPos.x = ENEMY_START_POS_X;
			mPos.y = 420;
			break;
		}


		// ������ Y���W���ς��------------------------------------------
		case ENEMY_TYPE_LEFT_60:
		{	
			mPos.x = ENEMY_START_POS_X_LEFT;
			mPos.y = 60;
			break;
		}
		case ENEMY_TYPE_LEFT_120:
		{
			mPos.x = ENEMY_START_POS_X_LEFT;
			mPos.y = 120;
			break;
		}
		case ENEMY_TYPE_LEFT_180:
		{
			mPos.x = ENEMY_START_POS_X_LEFT;
			mPos.y = 180;
			break;
		}
		case ENEMY_TYPE_LEFT_240:
		{
			mPos.x = ENEMY_START_POS_X_LEFT;
			mPos.y = 240;
			break;
		}
		case ENEMY_TYPE_LEFT_300:
		{
			mPos.x = ENEMY_START_POS_X_LEFT;
			mPos.y = 300;
			break;
		}
		case ENEMY_TYPE_LEFT_360:
		{
			mPos.x = ENEMY_START_POS_X_LEFT;
			mPos.y = 360;
			break;
		}
		case ENEMY_TYPE_LEFT_420:
		{
			mPos.x = ENEMY_START_POS_X_LEFT;
			mPos.y = 420;
			break;
		}

		// �ォ�� X���W���ς��-------------------------------------------
		case ENEMY_TYPE_TOP_80:
		{
			mPos.x = 80;
			mPos.y = ENEMY_START_POS_Y_TOP;
			break;
		}
		case ENEMY_TYPE_TOP_160:
		{
			mPos.x = 160;
			mPos.y = ENEMY_START_POS_Y_TOP;
			break;
		}
		case ENEMY_TYPE_TOP_240:
		{
			mPos.x = 240;
			mPos.y = ENEMY_START_POS_Y_TOP;
			break;
		}
		case ENEMY_TYPE_TOP_320:
		{
			mPos.x = 320;
			mPos.y = ENEMY_START_POS_Y_TOP;
			break;
		}
		case ENEMY_TYPE_TOP_400:
		{
			mPos.x = 400;
			mPos.y = ENEMY_START_POS_Y_TOP;
			break;
		}
		case ENEMY_TYPE_TOP_480:
		{
			mPos.x = 480;
			mPos.y = ENEMY_START_POS_Y_TOP;
			break;
		case ENEMY_TYPE_TOP_560:
		{
			mPos.x = 560;
			mPos.y = ENEMY_START_POS_Y_TOP;
			break;
		}
		}
		// ������ X���W���ς��-------------------------------------------
		case ENEMY_TYPE_BOTTOM_80:
		{
			mPos.x = 80;
			mPos.y = ENEMY_START_POS_Y_BOTTOM;
			break;
		}
		case ENEMY_TYPE_BOTTOM_160:
		{
			mPos.x = 160;
			mPos.y = ENEMY_START_POS_Y_BOTTOM;
			break;
		}
		case ENEMY_TYPE_BOTTOM_240:
		{
			mPos.x = 240;
			mPos.y = ENEMY_START_POS_Y_BOTTOM;
			break;
		}
		case ENEMY_TYPE_BOTTOM_320:
		{
			mPos.x = 320;
			mPos.y = ENEMY_START_POS_Y_BOTTOM;
			break;
		}
		case ENEMY_TYPE_BOTTOM_400:
		{
			mPos.x = 400;
			mPos.y = ENEMY_START_POS_Y_BOTTOM;
			break;
		}
		case ENEMY_TYPE_BOTTOM_480:
		{
			mPos.x = 480;
			mPos.y = ENEMY_START_POS_Y_BOTTOM;
			break;
		}
		case ENEMY_TYPE_BOTTOM_560:
		{
			mPos.x = 560;
			mPos.y = ENEMY_START_POS_Y_BOTTOM;
			break;
		}

		// ��]---------------------------------------------
		case ENEMY_TYPE_CIRCLE:
		{
			mPos.x = SCREEN_CENTER_X;
			mPos.y = ENEMY_START_POS_Y_TOP;
			break;
		}

	}


	// �摜�ɍ��W�𔽉f
	mSprite.pos.x = mPos.x;
	mSprite.pos.y = mPos.y;

	// ��Ԃ̏�����
	mState = ENEMY_STATE_ACTIVE;

	// �g�p��ԂƂ���
	mIsActive = TRUE;

	// �����蔻��̏�����
	mCollision.mRadius = data.mRadius;
	mCollision.mPos.x = mPos.x;
	mCollision.mPos.y = mPos.y;

	// �^�C�}�[�̏�����
	mBombTimer = 0;

	// �G�̂��ꉹ
	mBombSe = LoadSoundMem("Resources/Audio/swing34.wav");
	// ���ʕύX
	ChangeVolumeSoundMem(80, mBombSe);
}

/*-------------------------------------------------------
�X�V
-----------------------------------------------------*/
void Enemy::Update(void)
{

	// �A�N�e�B�u��ԂłȂ���Ώ������Ȃ�
	if (mIsActive == FALSE)
	{
		return;
	}

	// �G���̎擾
	const EnemyData data = Database::msEnemyData[mType];

	// �G�̎�ނɉ���������
	if (mState == ENEMY_STATE_ACTIVE)
	{
		switch (mType)
		{

			// �E����------------------------------------------------
			case ENEMY_TYPE_RIGHT_60:
			{
				//counter++;
				//sin�J�[�u
				//mPos.y -= sinf(PI*counter/COUNT_1) * COUNT_2;
				mPos.x -= data.mVel;

				break;
			}
			case ENEMY_TYPE_RIGHT_120:
			{
				mPos.x -= data.mVel;
				break;
			}
			case ENEMY_TYPE_RIGHT_180:
			{
				mPos.x -= data.mVel;
				break;
			}
			case ENEMY_TYPE_RIGHT_240:
			{
				mPos.x -= data.mVel;
				break;
			}
			case ENEMY_TYPE_RIGHT_300:
			{
				mPos.x -= data.mVel;
				break;
			}
			case ENEMY_TYPE_RIGHT_360:
			{
				mPos.x -= data.mVel;
				break;
			}
			case ENEMY_TYPE_RIGHT_420:
			{
				mPos.x -= data.mVel;
				break;
			}

			// ������----------------------------------------------------------
			case ENEMY_TYPE_LEFT_60:
			{
				mPos.x += data.mVel;
				break;
			}
			case ENEMY_TYPE_LEFT_120:
			{
				mPos.x += data.mVel;
				break;
			}
			case ENEMY_TYPE_LEFT_180:
			{
				mPos.x += data.mVel;
				break;
			}
			case ENEMY_TYPE_LEFT_240:
			{
				mPos.x += data.mVel;
				break;
			}
			case ENEMY_TYPE_LEFT_300:
			{
				mPos.x += data.mVel;
				break;
			}
			case ENEMY_TYPE_LEFT_360:
			{
				mPos.x += data.mVel;
				break;
			}
			case ENEMY_TYPE_LEFT_420:
			{
				mPos.x += data.mVel;
				break;
			}

			// �ォ�炭��G----------------------------------------------------
			case ENEMY_TYPE_TOP_80:
			{
				mPos.y += data.mVel;
				break;
			}
			case ENEMY_TYPE_TOP_160:
			{
				mPos.y += data.mVel;
				break;
			}
			case ENEMY_TYPE_TOP_240:
			{
				mPos.y += data.mVel;
				break;
			}
			case ENEMY_TYPE_TOP_320:
			{
				mPos.y += data.mVel;
				break;
			}
			case ENEMY_TYPE_TOP_400:
			{
				mPos.y += data.mVel;
				break;
			}
			case ENEMY_TYPE_TOP_480:
			{
				mPos.y += data.mVel;
				break;
			}
			case ENEMY_TYPE_TOP_560:
			{
				mPos.y += data.mVel;
				break;
			}

			// �����炭��G-----------------------------------------------------
			case ENEMY_TYPE_BOTTOM_80:
			{
				mPos.y -= data.mVel;
				break;
			}
			case ENEMY_TYPE_BOTTOM_160:
			{
				mPos.y -= data.mVel;
				break;
			}
			case ENEMY_TYPE_BOTTOM_240:
			{
				mPos.y -= data.mVel;
				break;
			}
			case ENEMY_TYPE_BOTTOM_320:
			{
				mPos.y -= data.mVel;
				break;
			}
			case ENEMY_TYPE_BOTTOM_400:
			{
				mPos.y -= data.mVel;
				break;
			}
			case ENEMY_TYPE_BOTTOM_480:
			{
				mPos.y -= data.mVel;
				break;
			}
			case ENEMY_TYPE_BOTTOM_560:
			{
				mPos.y -= data.mVel;
				break;
			}

			// ��]����G
			case ENEMY_TYPE_CIRCLE:
			{
				mPos.x += clox * (cosf((angle + 2.0f) * (PI / 180.0f)) - cosf(angle * (PI / 180.0f)));
				mPos.y += cloy * (sinf((angle + 2.0f) * (PI / 180.0f)) - sinf(angle * (PI / 180.0f)));

				angle += 2.0f;
				clox -= 0.3f;
				cloy -= 0.3f;
			}
		}
	}



	// ������
	else if (mState == ENEMY_STATE_BOMB)
	{
		// �^�C�}�[�������߂�
		mBombTimer++;

		// �X�R�A
		g_gameData.mBreakScore += data.mScore;


		if (mBombTimer == 5)
		{
			// ������
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
		else if (mBombTimer >= 20)
		{
			// ���j���I�������疢�g�p��Ԃɂ���
			mIsActive = FALSE;

			// ���j����1�@���₷
			g_gameData.mBreakNum++;
		}


	}

	// �����͈͊O�ɏo���疢�g�p��Ԃɂ���
	if (
		mPos.x < SCREEN_LEFT - ENEMY_ALIVE_AREA ||
		mPos.x > SCREEN_RIGHT + ENEMY_ALIVE_AREA ||
		mPos.y < SCREEN_TOP - ENEMY_ALIVE_AREA ||
		mPos.y > SCREEN_BOTTOM + ENEMY_ALIVE_AREA
		)
	{
		mIsActive = FALSE;
	}

	// �摜�ɍ��W�𔽉f
	mSprite.pos.x = mPos.x;
	mSprite.pos.y = mPos.y;

	// �����蔻��ɍ��W���X�V
	mCollision.mPos.x = mPos.x;
	mCollision.mPos.y = mPos.y;
}

/*--------------------------------------------------
�`��
---------------------------------------------------*/
void Enemy::Draw(void)
{
	// �A�N�e�B�u��ԂłȂ���Ώ������Ȃ�
	if (mIsActive == FALSE)
	{
		return;
	}
	// �摜��؂���`��
	mSprite.Draw();
}

/*-------------------------------------------------
�_���[�W����
--------------------------------------------------*/
void Enemy::Damage(int damage)
{
	// �̗͂����
	mHp -= damage;

	// �̗͂��Ȃ��Ȃ��Ă����甚�j��Ԃ�
	if (mHp <= 0)
	{
		mState = ENEMY_STATE_BOMB;

		// �����ڂ𔚔j��Ԃ�
		mSprite.src.x = 32;
		mSprite.src.y = 80;
		mSprite.size.x = 16;
		mSprite.size.y = 16;

		mSprite.scale.x = 3.0f;
		mSprite.scale.y = 3.0f;
	}
}


/*-------------------------------------------------------
�X�V
----------------------------------------------------*/
BOOL Enemy::IsDamage(void)
{
	BOOL res = mState == ENEMY_STATE_BOMB;

	return res;
}