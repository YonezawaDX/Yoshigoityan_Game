/*
ゲーム内の詳細データ
作成日 : 2020/06/28
最終調整:2020/10/01
作成者 : 米澤駿介
*/

#include "Database.h"


#define SCREEN_WIDTH    (640)                  // 画面の幅[pixel]
#define SCREEN_HEIGHT   (480)                  // 画面の高さ[pixel]

#define SCREEN_TOP      (0)                    // 画面の上端
#define SCREEN_BOTTOM   (SCREEN_HEIGHT)        // 画面の下端
#define SCREEN_LEFT     (0)                    // 画面の左端
#define SCREEN_RIGHT    (SCREEN_WIDTH)         // 画面の右端

#define SCREEN_CENTER_X (SCREEN_WIDTH  / 2)    // 画面の中央(X座標)
#define SCREEN_CENTER_Y (SCREEN_HEIGHT / 2)    // 画面の中央(Y座標)


const EnemyData Database::msEnemyData[ENEMY_ARRIVAL_NUM] = {

	//		HP			速度		半径		画像切り取り情報				スコア
	{		1,			1.2f,		19.0f,		 0,		0,		32,	32,			5},		// 通常←60
	{		1,			1.2f,		19.0f,		 0,		0,		32,	32,			5},		// 通常←120
	{		1,			1.2f,		19.0f,		 0,		0,		32,	32,			5},		// 通常←180
	{		1,			1.2f,		19.0f,		 0,		0,		32,	32,			5},		// 通常←240
	{		1,			1.2f,		19.0f,		 0,		0,		32,	32,			5},		// 通常←300
	{		1,			1.2f,		19.0f,		 0,		0,		32,	32,			5},		// 通常←360
	{		1,			1.2f,		19.0f,		 0,		0,		32,	32,			5},		// 通常←420
						
						
	{		1,			1.2f,		19.0f,		32,		0,		32,	32,			5},		// 通常→60
	{		1,			1.2f,		19.0f,		32,		0,		32,	32,			5},		// 通常→120
	{		1,			1.2f,		19.0f,		32,		0,		32,	32,			5},		// 通常→180
	{		1,			1.2f,		19.0f,		32,		0,		32,	32,			5},		// 通常→240
	{		1,			1.2f,		19.0f,		32,		0,		32,	32,			5},		// 通常→300
	{		1,			1.2f,		19.0f,		32,		0,		32,	32,			5},		// 通常→360
	{		1,			1.2f,		19.0f,		32,		0,		32,	32,			5},		// 通常→420
						
						
	{		1,			1.2f,		19.0f,		64,		0,		32,	32,			5},		// 通常↓80
	{		1,			1.2f,		19.0f,		64,		0,		32,	32,			5},		// 通常↓160
	{		1,			1.2f,		19.0f,		64,		0,		32,	32,			5},		// 通常↓240
	{		1,			1.2f,		19.0f,		64,		0,		32,	32,			5},		// 通常↓320
	{		1,			1.2f,		19.0f,		64,		0,		32,	32,			5},		// 通常↓400
	{		1,			1.2f,		19.0f,		64,		0,		32,	32,			5},		// 通常↓480
	{		1,			1.2f,		19.0f,		64,		0,		32,	32,			5},		// 通常↓560
						
						
	{		1,			1.2f,		19.0f,		96,		0,		32,	32,			5},		// 通常↑80
	{		1,			1.2f,		19.0f,		96,		0,		32,	32,			5},		// 通常↑160
	{		1,			1.2f,		19.0f,		96,		0,		32,	32,			5},		// 通常↑240
	{		1,			1.2f,		19.0f,		96,		0,		32,	32,			5},		// 通常↑320
	{		1,			1.2f,		19.0f,		96,		0,		32,	32,			5},		// 通常↑400
	{		1,			1.2f,		19.0f,		96,		0,		32,	32,			5},		// 通常↑480
	{		1,			1.2f,		19.0f,		96,		0,		32,	32,			5},		// 通常↑560

	{		6,			1.0f,		19.0f,		128,	0,		32,	32,			15},	// 敵回転
};

const EnemyArrivalData Database::mEnemyArrivalData[ENEMY_ARRIVAL_NUM] = {
	//		出現時間		敵の種類	
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

