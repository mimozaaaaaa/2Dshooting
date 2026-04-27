#pragma once
#include"SceneBase.h"
#include "../TextureManager.h"
#include"../Def.h"

class Game :public SceneBase
{
public:
	Game() {}
	~Game() {}

	void Update()override;
	void Draw()override;
	void Init()override;

//Update//
	void UpdateMat();
	void UpdateBackGround();

//Init//
	void InitTex();

//Draw//
	void DrawPlayer();
	void DrawBackGround();

//else
	void PlayerMove();	//プレイヤーの移動
	void PlayerAct();
	void PlayerLimit();
	void BackGroundLimit();

private:

	Math::Vector2 playerPos;
	Math::Vector2 playerAccPos;

	float backGround1Y;
	float backGround2Y;
	float backGroundAccY;

	KdTexture *playerTex;
	KdTexture *backGroundTex;

	Math::Matrix playerMat;
	Math::Matrix backGround1Mat;
	Math::Matrix backGround2Mat;

	

	//マジックナンバーを消すため//
	const float backGroundHigh = 1536;

};