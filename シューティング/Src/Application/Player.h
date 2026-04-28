#pragma once

#include"TextureManager.h"
#include"Def.h"

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

//Init//
	void InitTex();

//Draw//
	void DrawPlayer();

//else//
	//プレイヤーの動き
	void PlayerMove();
	void PlayerAct();
	void PlayerLimit();

private:

	Math::Vector2 playerPos;
	Math::Vector2 playerAccPos;

	KdTexture* playerTex;

	Math::Matrix playerMat;

};
