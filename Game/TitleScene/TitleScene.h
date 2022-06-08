/*
�^�C�g���V�[��
�쐬�� : 2020/06/20
�ŏI����:2020/10/01
�쐬�� : ���V�x��
*/
#pragma once

struct TitleScene
{
	// �ϐ� ====================================

	// ���
	int mState;

	// �^�C�}�[
	int mTimer;

	// �����̐؂�ւ��t���O
	int mIsDrawString;

	// �T�E���h�n���h��
	int mKeySe;

	// �^�C�g��BGM
	int TitleBGM;

	// �摜�n���h��
	int mBackgroundTexture;

	// ���S�n���h��
	int mMovieTitle;

	// �摜���
	SpriteData mSprite;

	// �֐� =====================================

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