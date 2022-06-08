/*
�Q�[�����̏ڍ׃f�[�^
�쐬�� : 2020/06/28
�ŏI����:2020/10/01
�쐬�� : ���V�x��
*/
#pragma once

#include "../Utility.h"
#include "../GameData.h"




// �G�̎��
enum ENEMY_TYPE
{
	// �ʏ큩
	ENEMY_TYPE_RIGHT_60,
	ENEMY_TYPE_RIGHT_120,
	ENEMY_TYPE_RIGHT_180,
	ENEMY_TYPE_RIGHT_240,
	ENEMY_TYPE_RIGHT_300,
	ENEMY_TYPE_RIGHT_360,
	ENEMY_TYPE_RIGHT_420,
	
	// �ʏ큨
	ENEMY_TYPE_LEFT_60,
	ENEMY_TYPE_LEFT_120,
	ENEMY_TYPE_LEFT_180,
	ENEMY_TYPE_LEFT_240,
	ENEMY_TYPE_LEFT_300,
	ENEMY_TYPE_LEFT_360,
	ENEMY_TYPE_LEFT_420,
	
	// �ʏ큫
	ENEMY_TYPE_TOP_80,
	ENEMY_TYPE_TOP_160,
	ENEMY_TYPE_TOP_240,
	ENEMY_TYPE_TOP_320,
	ENEMY_TYPE_TOP_400,
	ENEMY_TYPE_TOP_480,
	ENEMY_TYPE_TOP_560,

	// �ʏ큪
	ENEMY_TYPE_BOTTOM_80,
	ENEMY_TYPE_BOTTOM_160,
	ENEMY_TYPE_BOTTOM_240,
	ENEMY_TYPE_BOTTOM_320,
	ENEMY_TYPE_BOTTOM_400,
	ENEMY_TYPE_BOTTOM_480,
	ENEMY_TYPE_BOTTOM_560,

	// �ʏ��]
	ENEMY_TYPE_CIRCLE,		

	// ��ނ̐�
	ENEMY_TYPE_NUM
};

// �G�̏��
struct EnemyData
{
	// HP
	int mHp;

	// �ړ����x
	float mVel;

	// �����蔼�a�̔��a
	float mRadius;

	// �摜�̐؂�����
	int mRectX1;
	int mRectY1;
	int mRectX2;
	int mRectY2;

	// �X�R�A
	int mScore;

};

// �G�̍ő�o����
#define ENEMY_ARRIVAL_NUM		128

// �G�̏o�����
struct EnemyArrivalData
{
	// �o������
	int mArrivalTime;

	// �o������G�̎��
	int mEnemyType;

};

// �f�[�^���܂Ƃ߂��\����
struct Database
{

	// �G�̎��
	static const EnemyData msEnemyData[ENEMY_ARRIVAL_NUM];

	// �G�̏o���p�^�[��
	static const EnemyArrivalData mEnemyArrivalData[ENEMY_ARRIVAL_NUM];
};