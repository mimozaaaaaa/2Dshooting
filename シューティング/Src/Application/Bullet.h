#pragma once

#include"TextureManager.h"
#include"Def.h"

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
	void NormalBulletSpawn(const Math::Vector2& a_spawnPos, int count);
	void HomingBulletSpawn(const Math::Vector2& a_spawnPos, int count);
	void SetFlag(int num, bool flag) { normalBullet[num].Flag = flag; }
	Math::Vector2 GetPos(int num)const { return normalBullet[num].Pos; }

	bool GetFlag(int num)const { return normalBullet[num].Flag; }

	const int NormalBulletRadius = 12;

private:

	SomeBullet normalBullet[100];
	SomeBullet homingBullet[100];
	SomeBullet enemyBullet[100];

	KdTexture* normalBulletTex;

	Math::Vector2 accelerationMat_Normal;

};
