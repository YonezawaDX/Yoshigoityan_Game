/*
�e�̏���
�쐬�� : 2020/07/02
�쐬�� : ���V�x��
*/
#pragma once

#include "../Utility.h"
#include "Database.h"
#include "Collision.h"

// �e�𔭎˂����Ώ�
enum SHOOTER_TYPE
{
	SHOOTER_TYPE_PLAYER,		// �v���C���[
	SHOOTER_TYPE_ENEMY,			// �G

	SHOOTER_TYPE_NUM,			// ���ˑΏۂ̑���
};

struct Bullet
{
	// �ϐ� ======================================

	// �e�̎��
	int mBulletType;

	// ���ˑΏ�
	int mShooterType;

	// �摜�`��\����
	SpriteData mSprite;

	// ���W
	Float2 mPos;

	// ���x
	Float2 mVel;

	// �g�p����Ă��邩�̃t���O
	BOOL mIsActive;

	// �З�
	int mPower;

	// �~�̓����蔻��
	CircleCollider mCollision;


	// �G��̈ړ����x
	float v;

	//�G��̒��Sx,y
	float rx;
	float ry;

	// �G��̐�[x,y
	float hx;
	float hy;

	// �G��̘r�̒����̌��E
	float limith;

	// �ړ��ʂ̕ϐ�
	float etxv;
	float etyv;

	// ��[�̌v�Z
	float dx;
	float dy;

	float d;

	int i;

	float angle;
	// �֐� ==========================================

	// ������
	void Initialize(int textureHandle, int bulletType, int shooterType, Float2 pos);

	// �X�V
	void Update(void);

	// �`��
	void Draw(void);
};