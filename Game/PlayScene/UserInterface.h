/*
�w�i�̏���
�쐬�� : 2020/07/22
�ŏI����:2020/10/01
�쐬�� : ���V�x��
*/

#pragma once

struct UserInterface
{
	SpriteData mSprite;


	int mPlayerStock;

	// hp�\��

	// �P�[�W�̉���---------------------------------
	int HpSide;

	// �̗͂̍ő�l
	int HpMax;
	
	// �̗̓o�[
	int HpGauge;

	// �̗̓J���[
	float HpColor;

	// �F
	unsigned int Red;

	unsigned int Green;

	unsigned int Blue;

	// ������
	void Initialize(void);

	// �X�V
	void Update(void);

	//�`��
	void Draw(void);

};