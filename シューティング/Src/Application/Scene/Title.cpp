#include "Title.h"

void Title::Update()
{
	UpdateTitle();
	UpdateMat();
}

void Title::Draw()
{
	DrawTitle();
	DrawUI();
}

void Title::Init()
{
	titleY = 165;
	titleMove = 0.125;
	InitClip();
	InitTex();
}

void Title::UpdateMat()
{
	title.Mat = Math::Matrix::CreateTranslation(-40, titleY, 0);
	button.Mat = Math::Matrix::CreateTranslation(0, -60, 0);
}

void Title::UpdateTitle()
{
	titleY += titleMove;
	if (titleY > titleMax)titleMove *= -1;
	if (titleY < titleMin)titleMove *= -1;
}

void Title::InitClip()
{
	backGround.Clip = { 0,0,1280,720 };
	title.Clip = { 0,0,1000,310 };
	button.Clip = { 0,0,428,500 };
	start.Clip = { 0,0,896,597 };
}

void Title::InitTex()
{
	backGround.Tex.Load("Texture/Title/backGround.png");
	title.Tex.Load("Texture/Title/title.png");
	button.Tex.Load("Texture/Title/button.png");
	start.Tex.Load("Texture/Title/start.png");
}

void Title::DrawTitle()
{
	SHADER.m_spriteShader.SetMatrix(backGround.Mat);
	SHADER.m_spriteShader.DrawTex(&backGround.Tex, backGround.Clip, 1.0f);
	SHADER.m_spriteShader.DrawLine(0, 360, 0, -360);

	SHADER.m_spriteShader.SetMatrix(title.Mat);
	SHADER.m_spriteShader.DrawTex(&title.Tex, title.Clip, 1.0f);
}

void Title::DrawUI()
{
	SHADER.m_spriteShader.SetMatrix(button.Mat);
	SHADER.m_spriteShader.DrawTex(&button.Tex, button.Clip, 1.0f);
	SHADER.m_spriteShader.DrawTex(&start.Tex, start.Clip, 1.0f);
	SHADER.m_spriteShader.DrawTex(&tutorial.Tex, tutorial.Clip, 1.0f);
	SHADER.m_spriteShader.DrawTex(&quit.Tex, quit.Clip, 1.0f);
}
