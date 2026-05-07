#pragma once

#include "TextureManager.h"

class BackGround
{
public:
	BackGround(){}
	~BackGround(){}

	void Update();
	void Init();
	void Draw();

//Update//
	void UpdateMat();

//Init//
	void InitTex();

//Draw//
	void DrawBackGround();

//else/
	void BackGroundLimit(); //背景の制限

private:

	float backGround1Y;
	float backGround2Y;
	float backGroundAccY;

	KdTexture* backGroundTex;

	Math::Matrix backGround1Mat;
	Math::Matrix backGround2Mat;
	
	//マジックナンバーを消すため//
	const float backGroundHigh = 1920;

};
