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
	void UpdateAnimeSQ();

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
	void DrawYesNo();
	void DrawAnimeSQ();

private:

//根幹//
	Photo backGround;
	Photo title;
	Photo selecter;
	Photo frame;
	Photo quitFrame;
	Photo white1;
	Photo white2;
	Photo white3;
	Photo white4;
	
//肉付け//
	Photo start;
	Photo tutorial;
	Photo quit;
	Photo option;
	Photo yes;
	Photo No;
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

	float white1Y;
	float white2Y;
	float white3X;
	float white4X;

//マジックナンバー対策//
	const float titleMax = 210.0f;
	const float titleMin = 200.0f;

	const float startY = 35.0f;
	const float tutorialY = -65.0f;
	const float optionY = -165.0f;
	const float quitY = -265.0f;

	const float okX = -100.0f;
	const float noX = 100.0f;
};