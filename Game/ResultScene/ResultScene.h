/*
���U���g�V�[��
�쐬�� : 2020/07/06
�ŏI����:2020/10/01
�쐬�� : ���V�x��
*/
#pragma once

struct ResultScene
{
	// �ϐ� ======================================
	
	// ���
	int mState;

	// �T�E���h�n���h��
	int mKeySe;

	// BGM
	int mGameClear;
	int mGameOver;

	// �摜�n���h��
	int mTop;
	int mCen;
	int mBott;

	int mOver;

	// �֐� =======================================

	// ������
	void Initialize(void);

	// ��񃊃Z�b�g
	void Reset(void);

	// �X�V
	int Update(void);

	// �`��
	void Draw(void);

	// �I������
	void Finalize(void);

};