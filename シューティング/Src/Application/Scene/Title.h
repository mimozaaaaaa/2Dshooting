#pragma once
#include"SceneBase.h"

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

//Init//
	void InitClip();
	void InitTex();

//Draw//
	void DrawTitle();
	void DrawUI();

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
	Photo setting;
	


};