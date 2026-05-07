#pragma once

#include"TextureManager.h"

#include"Player.h"

struct UITex
{
	KdTexture *Tex;
	Math::Matrix Mat;
};

enum UIName
{
	HP,
	HIT,
	GRAZE,
	SPD
};

class UI
{
public:
	UI(){}
	~UI(){}
	void Update();
	void Init();
	void Draw();

	void UpdateMat();

	void InitTex();

	void DrawBlank_HP(int hp);
	void DrawBlank_HIT(int hit);
	void DrawBlank_GRAZE(int graze);
	void DrawBlank_SPD(int spd);

	void UpdateBlank_HP();
	void UpdateBlank_HIT();
	void UpdateBlank_GRAZE();
	void UpdateBlank_SPD();

	void SetPlayer(Player* _player) {player = _player; }


private:

	Player *player;

	UITex hp;
	UITex hit;
	UITex graze;
	UITex spd;

	Math::Matrix blankMat[4][4];
	KdTexture *blankTex;

};

