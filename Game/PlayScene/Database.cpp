/*
�Q�[�����̏ڍ׃f�[�^
�쐬�� : 2020/06/28
�ŏI����:2020/10/01
�쐬�� : ���V�x��
*/

#include "Database.h"


#define SCREEN_WIDTH    (640)                  // ��ʂ̕�[pixel]
#define SCREEN_HEIGHT   (480)                  // ��ʂ̍���[pixel]

#define SCREEN_TOP      (0)                    // ��ʂ̏�[
#define SCREEN_BOTTOM   (SCREEN_HEIGHT)        // ��ʂ̉��[
#define SCREEN_LEFT     (0)                    // ��ʂ̍��[
#define SCREEN_RIGHT    (SCREEN_WIDTH)         // ��ʂ̉E�[

#define SCREEN_CENTER_X (SCREEN_WIDTH  / 2)    // ��ʂ̒���(X���W)
#define SCREEN_CENTER_Y (SCREEN_HEIGHT / 2)    // ��ʂ̒���(Y���W)


const EnemyData Database::msEnemyData[ENEMY_ARRIVAL_NUM] = {

	//		HP			���x		���a		�摜�؂�����				�X�R�A
	{		1,			1.2f,		19.0f,		 0,		0,		32,	32,			5},		// �ʏ큩60
	{		1,			1.2f,		19.0f,		 0,		0,		32,	32,			5},		// �ʏ큩120
	{		1,			1.2f,		19.0f,		 0,		0,		32,	32,			5},		// �ʏ큩180
	{		1,			1.2f,		19.0f,		 0,		0,		32,	32,			5},		// �ʏ큩240
	{		1,			1.2f,		19.0f,		 0,		0,		32,	32,			5},		// �ʏ큩300
	{		1,			1.2f,		19.0f,		 0,		0,		32,	32,			5},		// �ʏ큩360
	{		1,			1.2f,		19.0f,		 0,		0,		32,	32,			5},		// �ʏ큩420
						
						
	{		1,			1.2f,		19.0f,		32,		0,		32,	32,			5},		// �ʏ큨60
	{		1,			1.2f,		19.0f,		32,		0,		32,	32,			5},		// �ʏ큨120
	{		1,			1.2f,		19.0f,		32,		0,		32,	32,			5},		// �ʏ큨180
	{		1,			1.2f,		19.0f,		32,		0,		32,	32,			5},		// �ʏ큨240
	{		1,			1.2f,		19.0f,		32,		0,		32,	32,			5},		// �ʏ큨300
	{		1,			1.2f,		19.0f,		32,		0,		32,	32,			5},		// �ʏ큨360
	{		1,			1.2f,		19.0f,		32,		0,		32,	32,			5},		// �ʏ큨420
						
						
	{		1,			1.2f,		19.0f,		64,		0,		32,	32,			5},		// �ʏ큫80
	{		1,			1.2f,		19.0f,		64,		0,		32,	32,			5},		// �ʏ큫160
	{		1,			1.2f,		19.0f,		64,		0,		32,	32,			5},		// �ʏ큫240
	{		1,			1.2f,		19.0f,		64,		0,		32,	32,			5},		// �ʏ큫320
	{		1,			1.2f,		19.0f,		64,		0,		32,	32,			5},		// �ʏ큫400
	{		1,			1.2f,		19.0f,		64,		0,		32,	32,			5},		// �ʏ큫480
	{		1,			1.2f,		19.0f,		64,		0,		32,	32,			5},		// �ʏ큫560
						
						
	{		1,			1.2f,		19.0f,		96,		0,		32,	32,			5},		// �ʏ큪80
	{		1,			1.2f,		19.0f,		96,		0,		32,	32,			5},		// �ʏ큪160
	{		1,			1.2f,		19.0f,		96,		0,		32,	32,			5},		// �ʏ큪240
	{		1,			1.2f,		19.0f,		96,		0,		32,	32,			5},		// �ʏ큪320
	{		1,			1.2f,		19.0f,		96,		0,		32,	32,			5},		// �ʏ큪400
	{		1,			1.2f,		19.0f,		96,		0,		32,	32,			5},		// �ʏ큪480
	{		1,			1.2f,		19.0f,		96,		0,		32,	32,			5},		// �ʏ큪560

	{		6,			1.0f,		19.0f,		128,	0,		32,	32,			15},	// �G��]
};

const EnemyArrivalData Database::mEnemyArrivalData[ENEMY_ARRIVAL_NUM] = {
	//		�o������		�G�̎��	
	{		60,				ENEMY_TYPE_RIGHT_180,		},
	{		60,				ENEMY_TYPE_LEFT_300,		},
	{		60,				ENEMY_TYPE_TOP_160,			},
	{		60,				ENEMY_TYPE_BOTTOM_400,		},

	{		200,			ENEMY_TYPE_RIGHT_180,		},
	{		225,			ENEMY_TYPE_RIGHT_120,		},
	{		250,			ENEMY_TYPE_RIGHT_60,		},
	
	{		330,			ENEMY_TYPE_LEFT_300,		},
	{		360,			ENEMY_TYPE_LEFT_360,		},
	{		390,			ENEMY_TYPE_LEFT_420,		},
	
	{		420,			ENEMY_TYPE_RIGHT_60,		},
	{		420,			ENEMY_TYPE_RIGHT_180,		},
	{		520,			ENEMY_TYPE_LEFT_120,		},
	{		520,			ENEMY_TYPE_LEFT_240,		},
	
	{		600,			ENEMY_TYPE_BOTTOM_320,		},
	{		630,			ENEMY_TYPE_BOTTOM_400,		},
	{		660,			ENEMY_TYPE_BOTTOM_480,		},

	{		800,			ENEMY_TYPE_RIGHT_240,		},
	{		800,			ENEMY_TYPE_RIGHT_240,		},
	{		800,			ENEMY_TYPE_RIGHT_240,		},

	{		820,			ENEMY_TYPE_LEFT_240,		},
	{		850,			ENEMY_TYPE_LEFT_240,		},
	{		870,			ENEMY_TYPE_LEFT_240,		},

	{		900,			ENEMY_TYPE_RIGHT_240,		},
	{		920,			ENEMY_TYPE_RIGHT_240,		},
	{		950,			ENEMY_TYPE_RIGHT_240,		},
	
	{		990,			ENEMY_TYPE_TOP_320,			},
	{		1020,			ENEMY_TYPE_TOP_320,			},
	{		1050,			ENEMY_TYPE_TOP_320,			},

	{		1100,			ENEMY_TYPE_BOTTOM_320,		},
	{		1130,			ENEMY_TYPE_BOTTOM_320,		},
	{		1160,			ENEMY_TYPE_BOTTOM_320,		},

	{		1400,			ENEMY_TYPE_CIRCLE,			},
	{		1450,			ENEMY_TYPE_CIRCLE,			},
	{		1500,			ENEMY_TYPE_CIRCLE,			},

	{		2000,			ENEMY_TYPE_TOP_320,			},
	{		2000,			ENEMY_TYPE_TOP_400,			},
	{		2000,			ENEMY_TYPE_TOP_480,			},
	{		2000,			ENEMY_TYPE_TOP_560,			},
		
	{		2050,			ENEMY_TYPE_BOTTOM_80,			},
	{		2050,			ENEMY_TYPE_BOTTOM_160,			},
	{		2050,			ENEMY_TYPE_BOTTOM_240,			},
	{		2050,			ENEMY_TYPE_BOTTOM_320,			},
	
	{		2100,			ENEMY_TYPE_LEFT_420,			},
	{		2100,			ENEMY_TYPE_LEFT_360,			},
	{		2100,			ENEMY_TYPE_LEFT_300,			},
	{		2100,			ENEMY_TYPE_LEFT_240,			},

	{		2150,			ENEMY_TYPE_RIGHT_60,			},
	{		2150,			ENEMY_TYPE_RIGHT_120,			},
	{		2150,			ENEMY_TYPE_RIGHT_180,			},
	{		2150,			ENEMY_TYPE_RIGHT_240,			},

	{		2500,			ENEMY_TYPE_CIRCLE,			},
	{		2550,			ENEMY_TYPE_CIRCLE,			},
	{		2600,			ENEMY_TYPE_CIRCLE,			},


	
};

