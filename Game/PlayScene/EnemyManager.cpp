/*
�G�̊Ǘ�
�쐬�� : 2020/06/30
�ŏI����:2020/10/01
�쐬�� : ���V�x��
*/
#include "EnemyManager.h"

#include "Database.h"
#include "YoungBird.h"

/*----------------------------------------------------
������
���� : int textureHandle(�G�̉摜�n���h��)
-------------------------------------------------------*/
void EnemyManager::Initialize(int textureHandle)
{
	// �G�̉摜�ϐ�
	mTextureHandle = textureHandle;

	// �^�C�}�[�̏�����
	mTimer = 0;

	// �v�f�ԍ��̏�����
	mArrivalIdx = 0;

	// ���ׂĂ̓G�𖢎g�p��Ԃɂ���
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		mEnemies[i].mIsActive = FALSE;
	}
}

/*----------------------------------------------------
�X�V
------------------------------------------------------*/
void EnemyManager::Update()
{
	// �^�C�}�[��i�߂�
	mTimer++;

	// �G�̏o�������𖞂����Ă����琶��
	EnemyArrivalData arrival = Database::mEnemyArrivalData[mArrivalIdx];

	while (arrival.mArrivalTime == mTimer && mArrivalIdx < ENEMY_ARRIVAL_NUM)
	{
		// �G�̐�������
		for (int i = 0; i < ENEMY_NUM; i++)
		{
			// ���łɓ����Ă���G�͖���
			if (mEnemies[i].mIsActive == TRUE)
			{
				continue;
			}

			// �G�̐���
			mEnemies[i].Initialize(mTextureHandle, arrival.mEnemyType);

			// ���̐�����Ԃ�����
			mArrivalIdx++;

			// ���̗v�f���擾
			arrival = Database::mEnemyArrivalData[mArrivalIdx];

			break;
		}
	}

	// �G�̍X�V
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		mEnemies[i].Update();
	}
}

/*-----------------------------------------------
�`��
------------------------------------------------*/
void EnemyManager::Draw()
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		mEnemies[i].Draw();
	}
}

/*-------------------------------------------------
�G�ƃv���C���[�̓����蔻��
--------------------------------------------------*/
void EnemyManager::CheckHitYoung(Young *pYoung)
{
	// ���ׂĂ̒e�Ɠn���ꂽ�Ώۂ̔�����Ƃ�
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		// ����̏����Ȃ�Ώ������Ȃ�
		if (
			mEnemies[i].mIsActive == FALSE	||		// �e���g�p��ԂłȂ�
			pYoung->IsDamage() == TRUE				// �v���C���[����e��
			)
		{
			continue;
		}

		// �������Ă��Ȃ���Ύ���
		if (mEnemies[i].mCollision.CheckHit(pYoung->mCollision) == FALSE)
		{
			continue;
		}

		// �_���[�W����
		pYoung->Damage();

		break;
	}
}

/*------------------------------------------------------
�I������
----------------------------------------------------*/
BOOL EnemyManager::IsEnd(void)
{
	EnemyArrivalData arrival = Database::mEnemyArrivalData[mArrivalIdx];

	if (arrival.mArrivalTime != 0)
	{
		return FALSE;
	}

	// �G���o�����Ă��Ȃ����m�F
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (mEnemies[i].mIsActive ==TRUE)
		{
			return FALSE;
		}
	}

	return TRUE;
}