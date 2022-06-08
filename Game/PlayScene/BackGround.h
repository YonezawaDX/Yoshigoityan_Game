/*
�w�i�̏���
�쐬�� : 2020/07/18
�ŏI����:2020/10/01
�쐬�� : ���V�x��
*/

#include "../Utility.h"

#pragma once

#define SCREEN_WIDTH    (640)                  // ��ʂ̕�[pixel]
#define SCREEN_HEIGHT   (480)                  // ��ʂ̍���[pixel]

#define SCREEN_TOP      (0)                    // ��ʂ̏�[
#define SCREEN_BOTTOM   (SCREEN_HEIGHT)        // ��ʂ̉��[
#define SCREEN_LEFT     (0)                    // ��ʂ̍��[
#define SCREEN_RIGHT    (SCREEN_WIDTH)         // ��ʂ̉E�[


#define SCREEN_CENTER_X (SCREEN_WIDTH  / 2)    // ��ʂ̒���(X���W)
#define SCREEN_CENTER_Y (SCREEN_HEIGHT / 2)    // ��ʂ̒���(Y���W)


struct BackGround
{
	// �ϐ� ==================================================
	
	// ���摜�̕ϐ�
	int mBackGroundHandle1;
	
	// �O�摜�̕ϐ�
	int mBackGroundHandle2;

	// �摜�𓮂����ϐ�
	int mX;
	int mX2;

	// �֐� ================================================

	// ������
	void Initialize(void);

	// �X�V
	void Draw(void);

	// ����
	void Move(void);

	// �I������
	void Finalize(void);
};