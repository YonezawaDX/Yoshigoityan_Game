/*
�G�̊Ǘ�
�쐬�� : 2020/06/30
�ŏI����:2020/10/01
�쐬�� : ���V�x��
*/
#pragma once

#include "Enemy.h"

// �O���錾
struct Young;

// �G�̐�
#define ENEMY_NUM		32

struct EnemyManager
{
	// �ϐ� ====================================

	// �G�̉摜�n���h��
	int mTextureHandle;

	// �G
	Enemy mEnemies[ENEMY_NUM];

	// �G�����p�̃^�C�}�[
	int mTimer;

	// �G�̐����z����Q�Ɣԍ�
	int mArrivalIdx;

	// �֐� ===========================

	// ������
	void Initialize(int txtureHandle);

	// �X�V
	void Update();

	// �`��
	void Draw();

	// �I������
	BOOL IsEnd(void);

	// �v���C���[�̓����蔻��
	void CheckHitYoung(Young* pYoung);
};