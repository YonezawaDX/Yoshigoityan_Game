/*
�����蔻��\����
�쐬�� : 2020/07/02
�쐬�� : ���V�x��
*/
#pragma once

#include "../Utility.h"

// �~�̔���p�\����
struct CircleCollider
{
	// �ϐ� ===================================

	// ���a
	float mRadius;

	// ���W
	Float2 mPos;

	// �֐� ====================================

	// ���̉~�Ƃ̓����蔻��
	BOOL CheckHit(CircleCollider collider);
};