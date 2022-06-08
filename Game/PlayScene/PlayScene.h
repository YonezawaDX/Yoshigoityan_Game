/*
プレイシーン
作成日 : 2020/07/02
最終調整:2020/10/01
作成者 : 米澤駿介
*/
#pragma once

#include "Player.h"

#include"YoungBird.h"

#include "EnemyManager.h"
#include "BackGround.h"
#include "UserInterface.h"
#include "CountDown.h"

struct PlayScene
{
	// 変数 ==================================

	// 状態
	int mState;

	// 画像ハンドル
	int mShootingHandle;		// シューティングハンドル

	int mEnemyHandle;
	
	// 制限時間
	int timediff;

	// BGM
	int TitleBGM;

	int PlayBGM;

	// 障害物
	int mObs;
	int mX;

	// プレイヤー
	Player mPlayer;

	Enemy mEnemy;

	Young mYoung;

	// 敵の管理者
	EnemyManager mEnemyManager;

	// 背景
	BackGround mBackGround;

	UserInterface mUserInterface;

	Countdown mCountdown;
	
	// 関数 ==================================

	// 初期化
	void Initialize();

	// 情報リセット
	void Reset();

	// 更新
	int Update();

	// 描画
	void Draw();

	// 終了処理
	void Finalize();

};
