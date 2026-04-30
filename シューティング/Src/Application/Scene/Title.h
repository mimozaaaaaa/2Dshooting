#pragma once
#include"SceneBase.h"
#include"../Def.h"
#include"../SceneManeger.h"

struct Photo
{
	KdTexture Tex;
	Math::Matrix Mat;
	Math::Rectangle Clip;
};

class Title :public SceneBase 
{
public: 
	Title(){}
	~Title(){}

	void Update()override;
	void Draw()override;
	void Init()override;

//Update//
	void UpdateMat();
	void UpdateTitle();
	void UpdateSelecter();
	void UpdateTimer();
	void UpdateNextScene();
	void UpdateQuit();

//Init//
	void InitClip();
	void InitTex();

//Draw//
	void DrawTitle();
	void DrawUI();
	void DrawStart();
	void DrawTutorial();
	void DrawOption();
	void DrawQuit();

private:

//根幹//
	Photo backGround;
	Photo title;
	Photo selecter;
	Photo frame;
//肉付け//
	Photo start;
	Photo tutorial;
	Photo quit;
	Photo option;
//光ってる//
	Photo start_F;
	Photo tutorial_F;
	Photo quit_F;
	Photo option_F;
	
	float titleY;
	float titleMove;

	Math::Vector2 selecterPos;

	int time;

	bool quitFlag;

	Math::Rectangle buttonClip;
	Math::Rectangle buttonClip_F;

//マジックナンバー対策//
	const float titleMax = 210;
	const float titleMin = 200;

	const float startY = 35;
	const float tutorialY = -65;
	const float optionY = -165;
	const float quitY = -265;

	const float okX = -100;
	const float noX = 100;


};