/*
�Q�[���f�[�^
�쐬�� : 2020/06/04
�쐬�� : ���V�x��
*/
#pragma once

struct GameData
{
	// �ϐ� ===================================

	// �G��|������
	int mBreakNum;

	// �G�̓��_
	int mBreakScore;

	// �c�@
	int mStock;

	// �֐� ===================================

	// ������
	void Initialize(void);
};

// �ǂ��ł��g����悤�ɂ���
extern GameData g_gameData;
