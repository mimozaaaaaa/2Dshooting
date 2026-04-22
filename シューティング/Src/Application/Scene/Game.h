#pragma once
#include"SceneBase.h"

class Game :public SceneBase
{
public:
	Game() {}
	~Game() {}

	void Update()override;
	void Draw()override;
	void Init()override;

private:

};