//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameMain.h
//!
//! @brief  �Q�[���S�̂Ɋւ���w�b�_�t�@�C��
//!
//! @date   ���t		2020.08.07
//!
//! @author ����Җ�	���V�x��
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ���d�C���N���[�h�̖h�~ ==================================================
#pragma once



// �萔�̒�` ==============================================================
// <�V�X�e��> ----------------------------------------------------------
#define GAME_TITLE "Yoshigoi Game"        // �Q�[���^�C�g��


// <���> --------------------------------------------------------------
#define SCREEN_WIDTH    (640)                  // ��ʂ̕�[pixel]
#define SCREEN_HEIGHT   (480)                  // ��ʂ̍���[pixel]

#define SCREEN_TOP      (0)                    // ��ʂ̏�[
#define SCREEN_BOTTOM   (SCREEN_HEIGHT)        // ��ʂ̉��[
#define SCREEN_LEFT     (0)                    // ��ʂ̍��[
#define SCREEN_RIGHT    (SCREEN_WIDTH)         // ��ʂ̉E�[

#define SCREEN_CENTER_X (SCREEN_WIDTH  / 2)    // ��ʂ̒���(X���W)
#define SCREEN_CENTER_Y (SCREEN_HEIGHT / 2)    // ��ʂ̒���(Y���W)

// <�V�[��> -------------------------------------------------------------
enum GAME_SCENE
{
	GAME_SCENE_NONE,	// �Ȃ�

	GAME_SCENE_TITLE,	// �^�C�g��
	GAME_SCENE_PLAY,	// �v���C
	GAME_SCENE_RESULT,	// ���U���g
};


// �t�F�[�h�C���̎���
#define FADE_TIME		0.5f




// �֐��̐錾 ==============================================================
// <�Q�[��> ------------------------------------------------------------
void InitializeGame(void);    // �Q�[���̏���������
void UpdateGame(void);        // �Q�[���̍X�V����
void RenderGame(void);        // �Q�[���̕`�揈��
void FinalizeGame(void);      // �Q�[���̏I������
