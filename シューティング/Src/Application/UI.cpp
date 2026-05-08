#include "UI.h"

#include"Player.h"

void UI::Update()
{
	UpdateMat();

	UpdateBlank_HP();
	UpdateBlank_HIT();
	UpdateBlank_GRAZE();
	UpdateBlank_SPD();
}

void UI::Init()
{
	TEXTUREMANAGER.ReadFile("TextureData.txt");
	InitTex();
}

void UI::Draw()
{
	SHADER.m_spriteShader.SetMatrix(hp.Mat);
	SHADER.m_spriteShader.DrawTex(hp.Tex, 0, 0, 338,46 );
	SHADER.m_spriteShader.SetMatrix(graze.Mat);
	SHADER.m_spriteShader.DrawTex(graze.Tex, 0, 0, 338,46 );
	SHADER.m_spriteShader.SetMatrix(hit.Mat);
	SHADER.m_spriteShader.DrawTex(hit.Tex, 0, 0, 338,46 );
	SHADER.m_spriteShader.SetMatrix(spd.Mat);
	SHADER.m_spriteShader.DrawTex(spd.Tex, 0, 0, 338,46 );

	DrawBlank_SPD(player->GetPlayerSPD());
	DrawBlank_HP(player->GetPlayerDamege());

}

void UI::UpdateMat()
{
	hp.Mat = Math::Matrix::CreateTranslation(-470, -300, 0);
	hit.Mat = Math::Matrix::CreateTranslation(180, -300, 0);
	graze.Mat = Math::Matrix::CreateTranslation(475, -300, 0);
	spd.Mat = Math::Matrix::CreateTranslation(-145, -300, 0);
}

void UI::InitTex()
{
	spd.Tex = TEXTUREMANAGER.GetTex("SPD");
	hp.Tex = TEXTUREMANAGER.GetTex("HP");
	hit.Tex = TEXTUREMANAGER.GetTex("HIT");
	graze.Tex = TEXTUREMANAGER.GetTex("GRAZE");

	blankTex = TEXTUREMANAGER.GetTex("Blank");
}

void UI::DrawBlank_HP(int dameage)
{
	for (int j = 0;j < dameage;j++)
	{
		SHADER.m_spriteShader.SetMatrix(blankMat[HP][j]);
		SHADER.m_spriteShader.DrawTex(blankTex, 0, 0, 54, 25);
	}
}

void UI::DrawBlank_HIT(int hit)
{
	for (int j = 0;j < hit;j++)
	{
		SHADER.m_spriteShader.SetMatrix(blankMat[HIT][j]);
		SHADER.m_spriteShader.DrawTex(blankTex, 0, 0, 54, 25);
	}
}

void UI::DrawBlank_GRAZE(int graze)
{
	for (int j = 0;j < graze;j++)
	{
		SHADER.m_spriteShader.SetMatrix(blankMat[GRAZE][j]);
		SHADER.m_spriteShader.DrawTex(blankTex, 0, 0, 54, 25);
	}
}

void UI::DrawBlank_SPD(int spd)
{
	for (int j = 0;j < spd;j++)
	{
		SHADER.m_spriteShader.SetMatrix(blankMat[SPD][j]);
		SHADER.m_spriteShader.DrawTex(blankTex, 0, 0, 54, 25);
	}
}

void UI::UpdateBlank_HP()
{
	for (int j = 0;j < 4;j++)
	{
		blankMat[HP][j] = Math::Matrix::CreateTranslation(-323 - j * 46, 322, 0);
	}
}

void UI::UpdateBlank_HIT()
{
	for (int j = 0;j < 4;j++)
	{
		blankMat[HIT][j] = Math::Matrix::CreateTranslation(-323 - j * 46, 322, 0);
	}
}

void UI::UpdateBlank_GRAZE()
{
	for (int j = 0;j < 4;j++)
	{
		blankMat[GRAZE][j] = Math::Matrix::CreateTranslation(-323 - j * 46, 322, 0);
	}
}

void UI::UpdateBlank_SPD()
{
	for (int j = 0;j < 4;j++)
	{
		blankMat[SPD][j] = Math::Matrix::CreateTranslation(-324 - j * 46, -298, 0);
	}
}
