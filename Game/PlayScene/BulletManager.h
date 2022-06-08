/* 
�e�̊Ǘ�
�쐬�� : 2020/06/28 
�쐬�� : ���V�x��
*/
#pragma once

#include "Bullet.h"

#include "Collision.h"

// �O���錾
struct Enemy;
struct Player;

// �e�̐�
#define BULLET_NUM		512

struct BulletManager
{
	// �ϐ� ================================

	// �e�̉摜�n���h��
	int mTextureHandle;

	// �e
	Bullet mBullets[BULLET_NUM];

	// �e�̔��ˉ�
	int mBulletSe;


	// �֐� =================================

	// ������
	void Initialize(int textureHandle);

	// �X�V
	void Update(void);

	// �`��
	void Draw(void);

	// �e�̔���
	BOOL Shot(int bulletType, int shooterType, Float2 pos);

	// �e�ƓG�̓����蔻��
	void CheckHitEnemy(Enemy* pEnemy);

	// �G�ƃv���C���[�̓����蔻��
	void CheckHitPlayer(Player* pPlayer);
};