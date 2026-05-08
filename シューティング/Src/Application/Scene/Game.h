#pragma once

//処理系のファイル//
#include"SceneBase.h"
#include "../TextureManager.h"
#include"../Def.h"

//ゲームに直接関係するファイル//
#include"../BackGround.h"
#include"../Player.h"
#include"../Bullet.h"
#include"../UI.h"
#include"../Enemy/Enemy1.h"
#include"../Impact.h"

class Game :public SceneBase
{
public:
	Game() {}
	~Game() {}

	void Update()override;
	void Draw()override;
	void Init()override;

private:

	BackGround backGround;
	Player player;
	Bullet bullet;
	UI ui;
	Enemy1 enemy1;
	Impact impact;
};