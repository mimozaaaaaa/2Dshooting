#pragma once

#include"TextureManager.h"

struct SomeBullet
{
	Math::Vector2 Pos;
	Math::Matrix Mat;
	bool Flag;
};

class Player;

class Bullet
{
public:
	Bullet(){}
	~Bullet(){}
	
	void Update();
	void Init();
	void Draw();

	//表示処理
	void Activate(const Math::Vector2& a_spawnPos);

//Update//
	void NormalBulletUpdate();
	void HomingBulletUpdate();
	void EnemyBulletUpdate();

	void UpdateMat();

//Init//
	void InitTex();

//Draw//
	void DrawNormalBullet();
	void DrawHomingBullet();
	void DrawEnemyBullet();


//else
	void BreakFlag();
	void BulletSpawn(const Math::Vector2& a_spawnPos, int count);

private:

	SomeBullet normalBullet[100];
	SomeBullet homingBullet[100];
	SomeBullet enemyBullet[100];

	KdTexture* normalBulletTex;

	Math::Vector2 accelerationMat_Normal;

};
