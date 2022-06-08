//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameMain.cpp
//!
//! @brief  �Q�[���֘A�̃\�[�X�t�@�C��
//!
//! @date   ���t		2020..08
//!
//! @author ����Җ�	���V�x��
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// �w�b�_�t�@�C���̓ǂݍ��� ================================================
#include "GameMain.h"

#include "TitleScene/TitleScene.h"
#include "PlayScene/PlayScene.h"
#include "ResultScene/ResultScene.h"


// �萔�̒�` ==============================================================



// �O���[�o���ϐ��̒�` ====================================================

// �V�[��
int g_scene = GAME_SCENE_TITLE;

// �V�[���\����
TitleScene g_titleScene;		// �^�C�g��	
PlayScene g_playScene;			// �v���C
ResultScene g_resultScene;


// �֐��̐錾 ==============================================================
// <�Q�[��> ------------------------------------------------------------
void InitializeGame(void);  // �Q�[���̏���������
void UpdateGame(void);      // �Q�[���̍X�V����
void RenderGame(void);      // �Q�[���̕`�揈��
void FinalizeGame(void);    // �Q�[���̏I������



// �֐��̒�` ==============================================================
//----------------------------------------------------------------------
//! @brief �Q�[���̏���������
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void InitializeGame(void)
{
	g_titleScene.Initialize();
	g_playScene.Initialize();
	g_resultScene.Initialize();
}



//----------------------------------------------------------------------
//! @brief �Q�[���̍X�V����
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void UpdateGame(void)
{
	int nextScene = GAME_SCENE_NONE;

	switch (g_scene)
	{
		// �^�C�g���V�[�� ===============================================
		case GAME_SCENE_TITLE:
		{
			nextScene = g_titleScene.Update();

			break;
		}
		// �v���C�V�[���@============================================
		case GAME_SCENE_PLAY:
		{
			nextScene = g_playScene.Update();

			break;
		}
		// ���U���g�V�[���@============================================
		case GAME_SCENE_RESULT:
		{
			nextScene = g_resultScene.Update();

			break;
		}

		// ��O
		default:
		{
			break;
		}
	}
		// ���̃V�[��������ΕύX
	if (nextScene != GAME_SCENE_NONE)
	{
		g_scene = nextScene;
	}
}




//----------------------------------------------------------------------
//! @brief �Q�[���̕`�揈��
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void RenderGame(void)
{
		switch (g_scene)
		{
			// �^�C�g���V�[�� ===============================================
			case GAME_SCENE_TITLE:
			{
				g_titleScene.Draw();

				break;
			}
			// �v���C�V�[���@============================================
			case GAME_SCENE_PLAY:
			{
				g_playScene.Draw();

				break;
			}
			// ���U���g�V�[���@============================================
			case GAME_SCENE_RESULT:
			{
				g_resultScene.Draw();
				break;
			}

			// ��O
			default:
			{
				break;
			}
		}

	// �t�F�[�h�̕`��
	FadeDraw(GetColor(0, 0, 0));
}



//----------------------------------------------------------------------
//! @brief �Q�[���̏I������
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void FinalizeGame(void)
{
	g_titleScene.Finalize();
	g_playScene.Finalize();
	g_resultScene.Finalize();
}
