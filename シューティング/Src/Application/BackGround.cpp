#include"BackGround.h"

void BackGround::Update()
{
	BackGroundLimit();
	backGround1Y -= backGroundAccY;
	backGround2Y -= backGroundAccY;
	UpdateMat();
}

void BackGround::Init()
{
	backGround1Y = 0;
	backGround2Y = backGroundHigh;
	backGroundAccY = 5;
	InitTex();
}

void BackGround::Draw()
{
	DrawBackGround();
}

void BackGround::UpdateMat()
{
	backGround1Mat = Math::Matrix::CreateTranslation(0, backGround1Y, 0);
	backGround2Mat = Math::Matrix::CreateTranslation(0, backGround2Y, 0);
}

void BackGround::InitTex()
{
	backGroundTex = TEXTUREMANAGER.GetTex("BackGround");
}

void BackGround::DrawBackGround()
{
	SHADER.m_spriteShader.SetMatrix(backGround1Mat);
	SHADER.m_spriteShader.DrawTex(backGroundTex, 0, 0, 1024, backGroundHigh);
	SHADER.m_spriteShader.SetMatrix(backGround2Mat);
	SHADER.m_spriteShader.DrawTex(backGroundTex, 0, 0, 1024, backGroundHigh);
}

void BackGround::BackGroundLimit()
{
	if (backGround1Y < -backGroundHigh)backGround1Y = backGroundHigh;
	if (backGround2Y < -backGroundHigh)backGround2Y = backGroundHigh;
}
