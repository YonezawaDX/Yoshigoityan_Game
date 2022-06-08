/*
�v���C���[
�쐬�� : 2020/08/10
�ŏI����:2020/10/01
�쐬�� : ���V�x��
*/
#include <math.h>

#include "Player.h"
#include "Enemy.h"

#include "../GameMain.h"


// �v���C���[�̏��
enum PLAYER_STATE
{
	PLAYER_STATE_ACTIVE,		// ����ł�����
	PLAYER_STATE_BOMB,			// ������
};

// ��s�@�̉摜�̐؂�����
#define PLAYER_RECT_X1			0
#define PLAYER_RECT_Y1			0
#define PLAYER_RECT_X2			32
#define PLAYER_RECT_Y2			32

// ��s�@�~�j�摜
#define PLAYER_MINI_X1			192
#define PLAYER_MINI_Y1			0
#define PLAYER_MINI_X2			60
#define PLAYER_MINI_Y2			32

// �ړ��X�s�[�h
#define PLAYER_VEL				10.0f

// �e�̔��ˊԊu
#define PLAYER_BULLET_INTERVAL		5

// �����̎c�@
#define PLAYER_STOCK_DEFAULT		2

// �v���C���[�̓����蔻��
#define PLAYER_RADIUS				5.0f

// �~����
#define PI						3.141592f

#define LIMITH					50.0f


/*----------------------------------------------------
������
----------------------------------------------------*/
void Player::Initialize(int textureHandle)
{
	// ��Ԃ̏�����
	mState = PLAYER_STATE_ACTIVE;

	// �摜�̐ݒ�
	mSprite.SetTexture(textureHandle);
	mSprite.src.x = PLAYER_RECT_X1;
	mSprite.src.y = PLAYER_RECT_Y1;
	mSprite.size.x = PLAYER_RECT_X2;
	mSprite.size.y = PLAYER_RECT_Y2;

	mSprite.scale.x = 1.0f;
	mSprite.scale.y = 1.0f;

	mSprite.alpha = 1.0f;

	// �摜�̐ݒ�2
	mSprite2.SetTexture(textureHandle);
	mSprite2.src.x = 128;
	mSprite2.src.y = PLAYER_RECT_Y1;
	mSprite2.size.x = PLAYER_RECT_X2 + 2;
	mSprite2.size.y = PLAYER_RECT_Y2;

	mSprite2.scale.x = 1.1f;
	mSprite2.scale.y = 1.1f;

	mSprite2.alpha = 1.0f;

	// �������W�̐ݒ�
	mPos.x = SCREEN_CENTER_X;
	mPos.y = SCREEN_CENTER_Y;

	// �摜�ɍ��W�𔽉f
	mSprite.pos.x = hx;
	mSprite.pos.y = hy;

	// �摜�ɍ��W�𔽉f
	mSprite2.pos.x = cx;
	mSprite2.pos.y = cy;


	// �e�̔��ˊԊu�Ǘ��p�^�C�}�[�̏�����
	mShootIntervalTimer = 0;



	//-----------------------------------------------------
	// �ړ����x
	v = PLAYER_VEL;

	// ���S
	rx = SCREEN_CENTER_X;
	ry = SCREEN_CENTER_Y;

	cx = rx;
	cy = ry;

	// ��[
	hx = rx;
	hy = ry;

	// �����̌��E
	limith = LIMITH;



	for (int i = 0; i < EMAX; i++)
	{
		x[i] = rx;
		y[i] = ry;
	}

	// ���ʉ�
	mAttackSe = LoadSoundMem("Resources/Audio/Slash.mp3");
	// ���ʕύX
	ChangeVolumeSoundMem(50, mAttackSe);
}

/*----------------------------------------------------
�X�V
-----------------------------------------------------*/
void Player::Update(void)
{
	switch (mState)
	{
		// ����ł�����		=========================
		case PLAYER_STATE_ACTIVE:
		{
			// �^�C�}�[����
			++mShootIntervalTimer %= PLAYER_BULLET_INTERVAL;

			// �ړ�����
			Move();

			break;
		}
		// ������        =======================================
		case PLAYER_STATE_BOMB:
		{
			// �^�C�}�[��i�߂�
			mBombTimer++;

			if (mBombTimer == 5)
			{
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
			else if(mBombTimer == 20)
			{
				mSprite.alpha = 0.0f;
			}
			else if (mBombTimer >= 60)
			{
				// ���j���I�������畜�A������
				mSprite.src.x = PLAYER_RECT_X1;
				mSprite.src.y = PLAYER_RECT_Y1;
				mSprite.size.x = PLAYER_RECT_X2;
				mSprite.size.y = PLAYER_RECT_Y2;


				mSprite.scale.x = 0.8f;
				mSprite.scale.y = 0.8f;

				mSprite.alpha = 1.0f;

				// �����^�C�}�[�̏�����
				mBombTimer = 0;

				// ����\��Ԃ�
				mState = PLAYER_STATE_ACTIVE;
			}

			break;
		}
	}

	// �摜�ɍ��W�𔽉f
	mSprite.pos.x = hx;
	mSprite.pos.y = hy;

	mSprite2.pos.x = rx;
	mSprite2.pos.y = ry;





}

/*-------------------------------------------------
�`��
-------------------------------------------------*/
void Player::Draw(void)
{

	// �̂̕\��
	for (int i = 0; i < EMAX - 2; i++)
	{

		x[i] = (x[i - 1] + x[i + 1]) / 2;
		y[i] = (y[i - 1] + y[i + 1]) / 2;
		
		if (i <= 1)
		{
			x[0] = hx;
			y[0] = hy;


		}

		else if (i == EMAX - 3)
		{
			x[EMAX - 3] = rx;
			y[EMAX - 3] = ry;
		}

		else if (i >= 1 && i != EMAX - 3)
		{
			DrawCircle((int)x[i], (int)y[i], 10, GetColor(192, 136, 105), true, true);
			DrawCircle((int)x[i], (int)y[i], 10, GetColor(0, 0, 0), false, true);

		}

	}

	//���@�̕\��
	mSprite.Draw();	
	mSprite2.Draw();
}

/*-----------------------------------------------------------------
�v���C���[�̈ړ�����
-------------------------------------------------------*/
void Player::Move(void)
{
	angle = angle;
	angle2 = angle2;
	////////////////////////////////////////////////////////////////////////////////////////
	// ��[�̈ړ�����

	// ���̈ړ�
	int inputUD = 0;
	int inputLR = 0;

	// �̂̈ړ�
	int bodyUD = 0;
	int bodyLR = 0;


	// �A�i���O�p�b�h����p�x���Z�o
	GetJoypadAnalogInput(&inputUD, &inputLR, DX_INPUT_PAD1);

	GetJoypadAnalogInputRight(&bodyLR, &bodyUD, DX_INPUT_PAD1);

	angle = atan2f((float)inputUD, (float)inputLR) - PI / 2;
	//if (angle < 0)angle += PI;
	angle_1 = atan2f((float)-bodyLR, (float)bodyUD) - PI / 2;

	angle2 = atan2f((float)-bodyLR, (float)bodyUD) - PI / 2;
	//if (angle < 0)angle += PI;


	// ���͂�����Ă��Ȃ��Ȃ炱��ȏ㏈�����Ȃ�
	if ((inputUD == 0 && inputLR == 0) && (bodyUD == 0 && bodyLR == 0))
	{
		// �������^�[��
		hx = hx;
		hy = hy;

		rx = rx;
		ry = ry;
		return;
	}

	if ((bodyUD < 0 || bodyUD > 0 || bodyLR < 0 || bodyLR > 0) && (inputUD == 0 && inputLR == 0))
	{
		// ���S�̈ړ�
		if (bodyLR == 1000)
		{
			rx += 4.0f;
		}
		if (bodyLR == -1000)
		{
			rx -= 4.0f;
		}
		if (bodyUD == 1000)
		{
			ry += 4.0f;
		}
		if (bodyUD == -1000)
		{
			ry -= 4.0f;
		}

		// ��[��x,y�����ړ���
		etxv = cosf(angle) * v;
		etyv = -1 * sinf(angle) * v;

		limith = LIMITH;

		//��[��x,y���W�w��
		hx = etxv + hx;
		hy = etyv + hy;



		// ��[�̈ړ����E�̌v�Z
		dx = hx - rx;
		dy = hy - ry;

		// ��[�̕����������߂�
		d = sqrtf((dx * dx) + (dy * dy));
		if (d > limith)
		{
			// ��[�̍��W�����E�Ȃ炻��ȏ�L�΂��Ȃ�
			hx = dx * limith / d + x[5];
			hy = dy * limith / d + y[5];
		}
		
		// �摜�̊p�x�̍X�V
		mSprite.rot = angle_1;
		mSprite2.rot = angle2;
	}
	else
	{
		// ��[��x,y�����ړ���
		etxv = cosf(angle) * v;
		etyv = -1 * sinf(angle) * v;

		// �U���������o��
		if (IsButtonPressed(PAD_INPUT_1))
		{
			PlaySoundMem(mAttackSe,DX_PLAYTYPE_BACK);
		}

		if (IsButtonDown(PAD_INPUT_1) == TRUE)
		{
			// ��[��x,y�����ړ���
			for (int i = 10; i < 40; i+=5)
			{
				v = (float)i;
			}
			limith = 250.0f;
		}
		else if (bodyUD == 0 && bodyLR == 0)
		{
			v = PLAYER_VEL;
			limith = LIMITH;
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

		//�摜�̊p�x�̍X�V
		mSprite.rot =  -angle;
		mSprite2.rot = -angle;
	}


	//////////////////////////////////////////////////////////////////////////////

	// �����蔻��
	mCollision.mRadius = PLAYER_RADIUS;
	mCollision.mPos.x = hx;
	mCollision.mPos.y = hy;

	rx = ClampF(rx, SCREEN_LEFT, SCREEN_RIGHT);
	ry = ClampF(ry, SCREEN_TOP, SCREEN_BOTTOM);
}

/*----------------------------------------------------
�_���[�W����
------------------------------------------------------*/
void Player::Damage(void)
{

	// �����Ԃɂ���
	mState = PLAYER_STATE_BOMB;

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
BOOL Player::IsDamage(void)
{
	BOOL res = mState == PLAYER_STATE_BOMB;

	return res;
}


/*-----------------------------------------------------------
�����蔻��
--------------------------------------------------------*/
void Player::CheckHitEnemy(Enemy* pEnemy)
{
	if (IsButtonDown(PAD_INPUT_1) == TRUE)
	{

		// ���ׂĂ̒e�Ɠn���ꂽ�Ώۂ̔�����Ƃ�
		for (int i = 0; i < 50; i++)
		{
			// ����̏����Ȃ�Ώ������Ȃ�
			if (
				pEnemy->IsDamage() == TRUE					// �v���C���[����e��
				)
			{
				continue;
			}

			// �������Ă��Ȃ���Ύ���
			if (mCollision.CheckHit(pEnemy->mCollision) == FALSE)
			{
				continue;
			}

			// �_���[�W����
			pEnemy->Damage(20);

			break;
		}
	}
}