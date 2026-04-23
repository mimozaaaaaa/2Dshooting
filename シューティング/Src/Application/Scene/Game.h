#pragma once
#include"SceneBase.h"
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

//Init//
	void InitTex();

//Draw//
	void DrawPlayer();
	void DrawBackGround();

//else
	void PlayerMove();	//プレイヤーの移動
	void PlayerLimit();

private:

	Math::Vector2 playerPos;
	Math::Vector2 playerAccPos;

	KdTexture playerTex;

	Math::Matrix playerMat;

};