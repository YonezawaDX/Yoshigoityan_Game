#include "BulletManager.h"

#include "Enemy.h"
#include "Player.h"


/*-----------------------------------------------
������
����	: int textureHandle(�e�̉摜�n���h��)
---------------------------------------------------*/
void BulletManager::Initialize(int textureHandle)
{
	mTextureHandle = textureHandle;

	
	// ���ׂĂ̒e�𖢎g�p��Ԃɂ���
	for (int i = 0; i < BULLET_NUM; i++)
	{
		mBullets[i].mIsActive = FALSE;
	}
}

/*------------------------------------------------
�X�V
---------------------------------------------------*/
void BulletManager::Update(void)
{
	// �v���C���[�̒e�̍X�V
	for (int i = 0; i < BULLET_NUM; i++)
	{
		mBullets[i].Update();
	}
}

/*------------------------------------------------
�`��
------------------------------------------------------*/
void BulletManager::Draw(void)
{
	// �v���C���[�̒e�̍X�V
	for (int i = 0; i < BULLET_NUM; i++)
	{
		mBullets[i].Draw();
	}
}

/*--------------------------------------------------
�e�̔���
------------------------------------------------------*/
BOOL BulletManager::Shot(int bulletType, int shooterType, Float2 pos)
{
	BOOL res = FALSE;

	// ���ˉ\�Ȓe��T��
	for (int i = 0; i < BULLET_NUM; i++)
	{
		// �A�N�e�B�u(�g�p��)�Ȃ玟��
		if (mBullets[i].mIsActive == TRUE)
		{
			continue;
		}

		 //�g�p����Ă��Ȃ��Ȃ珉����
		mBullets[i].Initialize(mTextureHandle, bulletType, shooterType, pos);

		// �e�̔��˂ɐ���
		res = TRUE;

		// �����𒆒f����
		break;
	}

	return res;
}

/*--------------------------------------------
�e�Ɠn���ꂽ�ΏۂƂ̓����蔻��
----------------------------------------------*/
void BulletManager::CheckHitEnemy(Enemy* pEnemy)
{
	// ���ׂĂ̒e�Ɠn���ꂽ�Ώۂ̔�������
	for (int i = 0; i < BULLET_NUM; i++)
	{
		// ����̏������Ȃ�Ώ������Ȃ�
		if (
			mBullets[i].mIsActive == FALSE ||				 // �e���g�p��ԂłȂ�								// �G�̗̑͂��Ȃ�
			pEnemy->mHp <= 0 ||								 // �G�̗̑͂��Ȃ�
			mBullets[i].mShooterType == SHOOTER_TYPE_ENEMY   // �G�̔��˂����e������
			)
		{
			continue;
		}

		// �������Ă��Ȃ���Ύ���
		if (mBullets[i].mCollision.CheckHit(pEnemy->mCollision) == FALSE)
		{
			continue;
		}

		// �̗͂����炷
		pEnemy->Damage(mBullets[i].mPower);

		// �e�𖢎g�p��Ԃɂ���
		mBullets[i].mIsActive = FALSE;
	}
}

/*---------------------------------------------
�e�ƃv���C���[�̓����蔻��
----------------------------------------------*/
void BulletManager::CheckHitPlayer(Player* pPlayer)
{
	// ���ׂĂ̒e�Ɠn���ꂽ�Ώۂ����
	for (int i = 0; i < BULLET_NUM; i++)
	{
		// ����̏����Ȃ�Ώ������Ȃ�
		if (
			mBullets[i].mIsActive == FALSE ||					// �e���g�p��ԂłȂ�
			mBullets[i].mShooterType == SHOOTER_TYPE_PLAYER ||	// �v���C���[�̔��˂����e������
			pPlayer->IsDamage() == TRUE							// �v���C���[����e��
			)
		{
			continue;
		}

		// �������Ă��Ȃ���Ύ���
		if (mBullets[i].mCollision.CheckHit(pPlayer->mCollision) == FALSE)
		{
			continue;
		}

		// �_���[�W����
		pPlayer->Damage();

		// �e�𖢎g�p��Ԃɂ���
		mBullets[i].mIsActive = FALSE;
	}
}
