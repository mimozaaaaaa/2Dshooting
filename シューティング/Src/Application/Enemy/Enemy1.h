#pragma once

#include"../TextureManager.h"
#include"../Def.h"

struct Turret
{
	Math::Matrix Mat;
	Math::Vector2 Pos;
	int Life;
	bool Flag;
};

class Enemy1
{
public:
	Enemy1(){}
	~Enemy1(){}

	void Update();
	void Init();
	void Draw();

//Update//
	void UpdateMat();
	void UpdateLife();

//Init//
	void InitTex();
	void InitTurretPos();

//Draw//

	Math::Vector2 GetLeftTurretPos(int num)const { return LeftTurret[num].Pos; }
	Math::Vector2 GetRightTurretPos(int num)const { return RightTurret[num].Pos; }

	void SetEnemy1LeftLife(int num, int life) { LeftTurret[num].Life = life; }
	int GetEnemy1LeftLife(int num)const { return LeftTurret[num].Life; }
	void SetEnemy1RightLife(int num, int life) { RightTurret[num].Life = life; }
	int GetEnemy1RightLife(int num)const { return RightTurret[num].Life; }

	bool GetEnemy1LeftFlag(int num)const { return LeftTurret[num].Flag; }
	bool GetEnemy1RightFlag(int num)const { return RightTurret[num].Flag; }

private:
	Turret LeftTurret[10];
	Turret RightTurret[10];

	KdTexture* Lefttex;
	KdTexture* Righttex;

	int enemyDownSpd = -3;
};
