/* 
eĖĮ
ėŽú : 2020/06/28 
ėŽŌ : ÄāVxî
*/
#pragma once

#include "Bullet.h"

#include "Collision.h"

// Oûéū
struct Enemy;
struct Player;

// eĖ
#define BULLET_NUM		512

struct BulletManager
{
	// Ï ================================

	// eĖænh
	int mTextureHandle;

	// e
	Bullet mBullets[BULLET_NUM];

	// eĖ­Ëđ
	int mBulletSe;


	// Ö =================================

	// úŧ
	void Initialize(int textureHandle);

	// XV
	void Update(void);

	// `æ
	void Draw(void);

	// eĖ­Ë
	BOOL Shot(int bulletType, int shooterType, Float2 pos);

	// eÆGĖ―čŧč
	void CheckHitEnemy(Enemy* pEnemy);

	// GÆvC[Ė―čŧč
	void CheckHitPlayer(Player* pPlayer);
};