/*
�^�C�g���V�[��
�쐬�� : 2020/08/10
�ŏI����:2020/10/01
�쐬�� : ���V�x��
*/
#pragma once

#include "../Utility.h"

#include "Collision.h"


#define  EMAX	20	//�G��̐� 

struct Enemy;

struct Player
{
	// �ϐ� ====================================

	// ���
	int mState;

	// �摜�`��\����
	SpriteData mSprite;

	SpriteData mSprite2;
	// ���W(��[)
	Float2 mPos;

	// ���ʉ�
	int mAttackSe;
	//=============================================
	// �G��̈ړ����x
	float v;

	//�G��̘r�̒��Ԃ�x,y���W
	float x[EMAX];
	float y[EMAX];

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

	// �摜�̃A���O��
	float angle;
	float angle_1;
	float angle2;
	float angle2_1;
	
	float cx;
	float cy;

	//===========================================


	// �e�̔��ˊԊu�Ǘ��p�̃^�C�}�[
	int mShootIntervalTimer;

	// �����蔻��
	CircleCollider mCollision;

	// �����p�^�C�}�[
	int mBombTimer;

	// ���G�^�C�}�[
	int mInvTimer;

	// �e�̔��ˉ�
	int mBulletSe;

	// �֐� =====================================

	// ������
	void Initialize(int textureHandle);

	// �X�V
	void Update(void);

	// �`��
	void Draw(void);

	// �ړ�
	void Move(void);

	// �_���[�W����
	void Damage(void);

	// ��e�����m�F
	BOOL IsDamage(void);

	// ������
	void CheckHitEnemy(Enemy* pEnemy);

};
