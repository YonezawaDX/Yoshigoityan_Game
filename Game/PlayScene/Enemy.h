/*
�v���C���[
�쐬�� : 2020/06/04
�ŏI����:2020/10/01
�쐬�� : ���V�x��
*/
#pragma once

#include "../Utility.h"

#include "Collision.h"

struct Enemy
{
	// �ϐ� ============================

	// �G�̎��
	int mType;

	// ���
	int mState;

	// HP
	int mHp;

	// �摜���
	SpriteData mSprite;

	// ���W
	Float2 mPos;

	// ���x
	Float2 mVel;

	// �g�p����Ă��邩�̃t���O
	BOOL mIsActive;

	// �����蔻����
	CircleCollider mCollision;

	// ���j�����p�̃^�C�}�[
	int mBombTimer;

	// �G�̂��ꉹ
	int mBombSe;

	// �J�E���^�[
	int counter;

	// ��]����G�p�̊֐�
	float angle = -90.0f;	// �A���O��
	float clox = 200.0f;	// ��]��
	float cloy = 200.0f;	// ��]y

	// �֐� ==================================

	// ������
	void Initialize(int textureHandle, int enemyType);

	// �X�V
	void Update(void);

	// �`��
	void Draw(void);

	// �_���[�W����
	void Damage(int damage);

	// �_���[�W����
	BOOL IsDamage(void);
};