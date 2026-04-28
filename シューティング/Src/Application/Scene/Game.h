#pragma once
#include"SceneBase.h"
#include "../TextureManager.h"
#include"../Def.h"

#include"../BackGround.h"
#include"../Player.h"

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
};