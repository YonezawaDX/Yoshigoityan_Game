/*
�����蔻��\����
�쐬�� : 2020/07/02
�쐬�� : ���V�x��
*/
#include "Collision.h"

/*-----------------------------------------------
���̉~�Ƃ̓����蔻��
-------------------------------------------------*/
BOOL CircleCollider::CheckHit(CircleCollider collider)
{
	// 2�_�̈ʒu�����_����̃x�N�g���ɂ���
	float x = collider.mPos.x - mPos.x;
	float y = collider.mPos.y - mPos.y;

	// �x�N�g���̒������v�Z
	float l = (x * x) + (y * y);

	// ���a�̍��v���擾
	float circleLen = mRadius + collider.mRadius;

	// ���a�̍��v��2�悷��(sqrt�͏������d���̂Ŏg��Ȃ����߂̏��u)
	circleLen *= circleLen;

	// �x�N�g����2�̉~�̔��a���Z����Γ������Ă���
	if (l <= circleLen)
	{
		return TRUE;
	}

	return FALSE;
}
