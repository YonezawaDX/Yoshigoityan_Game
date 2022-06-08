/*
�v���C�V�[��
�쐬�� : 2020/07/02
�ŏI����:2020/10/01
�쐬�� : ���V�x��
*/
#pragma once

#include "Player.h"

#include"YoungBird.h"

#include "EnemyManager.h"
#include "BackGround.h"
#include "UserInterface.h"
#include "CountDown.h"

struct PlayScene
{
	// �ϐ� ==================================

	// ���
	int mState;

	// �摜�n���h��
	int mShootingHandle;		// �V���[�e�B���O�n���h��

	int mEnemyHandle;
	
	// ��������
	int timediff;

	// BGM
	int TitleBGM;

	int PlayBGM;

	// ��Q��
	int mObs;
	int mX;

	// �v���C���[
	Player mPlayer;

	Enemy mEnemy;

	Young mYoung;

	// �G�̊Ǘ���
	EnemyManager mEnemyManager;

	// �w�i
	BackGround mBackGround;

	UserInterface mUserInterface;

	Countdown mCountdown;
	
	// �֐� ==================================

	// ������
	void Initialize();

	// ��񃊃Z�b�g
	void Reset();

	// �X�V
	int Update();

	// �`��
	void Draw();

	// �I������
	void Finalize();

};
