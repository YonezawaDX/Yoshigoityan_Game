/*
�e�̏���
�쐬�� : 2020/07/14
�쐬�� : ���V�x��
*/
#include "Bullet.h"
#include <math.h>
#include "../GameMain.h"

// �e���������Ă����ʊO�v���X���͈̔�
#define BULLET_ALIVE_AREA		50

#define PI 3.14f
#define PLAYER_VEL 10.0f
#define LIMITH 20.0f
/*---------------------------------------------
������
����: int textureHandle(�e�̉摜�n���h��), int bulletType(�e�̎��),Float2 pos
----------------------------------------------*/
void Bullet::Initialize(int textureHandle, int bulletType, int shooterType, Float2 pos)
{
	// �e�̎�ނ�ۑ�
	mBulletType = bulletType;

	// ���ˑΏۂ̕ۑ�
	mShooterType = shooterType;

	// �e�̏����擾
	const BulletData data = Database::msBulletDate[bulletType];

	//�摜�̐ݒ�
	mSprite.SetTexture(textureHandle);
	mSprite.src.x = data.mRectX1;
	mSprite.src.y = data.mRectY1;
	mSprite.size.x = data.mRectX2;
	mSprite.size.y = data.mRectY2;

	// �������W�̐ݒ�
	mPos.x = pos.x;
	mPos.y = pos.y;

	// �摜�ɍ��W�𔽉f
	mSprite.pos.x = mPos.x;
	mSprite.pos.y = mPos.y;

	// �g�p��ԂƂ���
	mIsActive = TRUE;

	// �З͂̐ݒ�
	mPower = data.mPower;

	// �����蔻����̏�����
	mCollision.mRadius = data.mRadius;
	mCollision.mPos.x = hx;
	mCollision.mPos.y = hy;

	// �ړ����x
	v = PLAYER_VEL;

	// ���S
	rx = SCREEN_CENTER_X;
	ry = SCREEN_CENTER_Y;

	// ��[
	hx = rx;
	hy = ry;

	// �����̌��E
	limith = LIMITH;

}

/*----------------------------------------------
�X�V
-----------------------------------------------*/
void Bullet::Update(void)
{

	// �g�p���łȂ���Ώ������Ȃ�
	if (mIsActive == FALSE)
	{
		return;
	}

	// �e�̏����擾
	const BulletData data = Database::msBulletDate[mBulletType];

	// �e�̎�ނɉ������ړ�����
	switch (mBulletType)
	{
		case BULLET_TYPE_PLAYER_NORMAL:		// �v���C���[�ʏ�e
		case BULLET_TYPE_PLAYER_POWER:		// �v���C���[�����e
		{
			// ��[�̈ړ�����

			// �ړ�
			int inputUD = 0;
			int inputLR = 0;

			// �A�i���O�p�b�h����p�x���Z�o
			GetJoypadAnalogInput(&inputUD, &inputLR, DX_INPUT_PAD1);

			angle = atan2((float)inputUD, (float)inputLR) - PI / 2;
			//if (angle < 0)angle += PI;


			// ���͂�����Ă��Ȃ��Ȃ炱��ȏ㏈�����Ȃ�
			if (inputUD == 0 && inputLR == 0)
			{
				// �������^�[��
				return;
			}

			// ��[��x,y�����ړ���;
			etxv = cosf(angle) * v;
			etyv = -1 * sinf(angle) * v;


			if (IsButtonDown(PAD_INPUT_1) == TRUE)
			{

				// ��[��x,y�����ړ���
				v = 40.0f;
				limith = 220.0f;
			}
			else
			{
				v = PLAYER_VEL;
				limith = LIMITH;
			}



			//��[��x,y���W�w��
			hx = etxv + hx;
			hy = etyv + hy;


			// ��[�̈ړ����E�̌v�Z
			dx = hx - rx;
			dy = hy - ry;

			d = sqrtf((dx * dx) + (dy * dy));
			if (d > limith)
			{
				hx = dx * limith / d + rx;
				hy = dy * limith / d + ry;
			}

			break;
		}

		case BULLET_TYPE_ENEMY_NORMAL:		// �G�̒ʏ�e
		{
			//mPos.x -= data.mVel;
			break;
		}

	}

	// ��ʊO�ɏo����e�𖢎g�p��Ԃɂ���
	if (
		mPos.x < SCREEN_LEFT - BULLET_ALIVE_AREA ||
		mPos.x > SCREEN_RIGHT + BULLET_ALIVE_AREA ||
		mPos.y < SCREEN_TOP - BULLET_ALIVE_AREA ||
		mPos.y > SCREEN_BOTTOM + BULLET_ALIVE_AREA
		)
	{
		mIsActive = FALSE;
	}

	// �摜�ɍ��W�𔽉f
	mSprite.pos.x = mPos.x;
	mSprite.pos.y = mPos.y;

	// �����蔻��ɍ��W�𔽉f
	mCollision.mPos.x = hx;
	mCollision.mPos.y = hy;
}

/*----------------------------------------------------
�`��
----------------------------------------------------*/
void Bullet::Draw(void)
{
	// �g�p���łȂ���Ώ������Ȃ�
	if (mIsActive == FALSE)
	{
		return;
	}

	// ���@�̕\��
	//mSprite.Draw();
}