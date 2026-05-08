#pragma once

#include"TextureManager.h"
#include"Def.h"

#include"Bullet.h"

class Player
{
public:
	Player(){}
	~Player(){}
	
	void Update();
	void Init();
	void Draw();

//Update//
	void UpdateMat();
	void UpdateKeyTimer();

//Init//
	void InitTex();

//Draw//
	void DrawPlayer();

//else//
	//プレイヤーの動き
	void PlayerMove();
	void PlayerLimit();
	void PlayerKey();

	void SummonNormalBullet();
	void SummonHomingBullet();

	int GetPlayerSPD()const
	{
		return playerSPD;
	}
	Math::Vector2 GetPos()const { return playerPos; }

	int GetBulletCount()const { return normalBulletCount; }

	void SetBullet(Bullet* _bullet) { bullet = _bullet; }

	int GetPlayerDamege()const { return dameage; }

	void SetPlayerDamege(int _dameage) { dameage = _dameage; }
	

private:
	Bullet* bullet;

	Math::Vector2 playerPos;
	Math::Vector2 playerAccPos;

	KdTexture* playerTex;

	Math::Matrix playerMat;

	int playerSPD = 1;

	int normalBulletCount = 0;
	int homingBulletCount = 0;

	int time;

	int dameage = 0;

	bool reflectFlag = false;
	bool homingFlag = false;

};
