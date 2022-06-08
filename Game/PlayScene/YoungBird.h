/*
�ЂȂ̓����蔻��
�쐬�� : 2020/9/26
�ŏI����:2020/10/01
�쐬�� : ���V�x��
*/
#pragma once

#include "../Utility.h"

#include "Collision.h"

// �O���錾
struct Enemy;

struct Young
{
	// �ϐ� ====================================

	// ���
	int mState;

	// �摜�`��\����
	SpriteData mSprite;

	// ���W(��[)
	Float2 mPos;

	// ���ʉ�
	int mBombSe;

	//=============================================

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

	// �_���[�W����
	void Damage(void);

	// ��e�����m�F
	BOOL IsDamage(void);
};
