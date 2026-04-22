#include "Title.h"

void Title::Update()
{

}

void Title::Draw()
{
	DrawTitle();
}

void Title::Init()
{
	InitClip();
	InitTex();
}

void Title::InitClip()
{
	backGround.Clip = { 0,0,1280,720 };
	title.Clip = { 0,0,896,597 };
	start.Clip = { 0,0,896,597 };
}

void Title::InitTex()
{
	backGround.Tex.Load("Texture/Title/backGround.png");
	title.Tex.Load("Texture/Title/title.png");
	title.Tex.Load("Texture/Title/start.png");
}

void Title::DrawTitle()
{
	SHADER.m_spriteShader.DrawTex(&backGround.Tex, backGround.Clip, 1.0f);
	SHADER.m_spriteShader.DrawTex(&title.Tex, title.Clip, 1.0f);
	
}

void Title::DrawUI()
{
	SHADER.m_spriteShader.DrawTex(&start.Tex, start.Clip, 1.0f);
	SHADER.m_spriteShader.DrawTex(&tutorial.Tex, tutorial.Clip, 1.0f);
	SHADER.m_spriteShader.DrawTex(&quit.Tex, quit.Clip, 1.0f);
}
