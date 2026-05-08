#include "UI.h"

#include"Player.h"
#include"Impact.h"

void UI::Update()
{
	UpdateMat();

	UpdateHitClip();

	UpdateBlank_HP();
	UpdateBlank_HIT(impact->GetPlayerHitCount());
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
	SHADER.m_spriteShader.DrawTex(hp.Tex, 0, 0, 300,40 );
	SHADER.m_spriteShader.SetMatrix(graze.Mat);
	SHADER.m_spriteShader.DrawTex(graze.Tex, 0, 0, 300,40 );
	SHADER.m_spriteShader.SetMatrix(hit.Mat);
	SHADER.m_spriteShader.DrawTex(hit.Tex, 0, 0, 300,40 );
	SHADER.m_spriteShader.SetMatrix(spd.Mat);
	SHADER.m_spriteShader.DrawTex(spd.Tex, 0, 0, 300,40 );

	DrawBlank_SPD(player->GetPlayerSPD());
	DrawBlank_HP(player->GetPlayerDamege());
	DrawBlank_HIT(impact->GetPlayerHitCount());
	DrawBlank_GRAZE(4);

}

void UI::UpdateMat()
{
	hp.Mat = Math::Matrix::CreateTranslation(-450, -340, 0);
	hit.Mat = Math::Matrix::CreateTranslation(150, -340, 0);
	graze.Mat = Math::Matrix::CreateTranslation(450, -340, 0);
	spd.Mat = Math::Matrix::CreateTranslation(-150, -340, 0);
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
		SHADER.m_spriteShader.DrawTex(blankTex, 0, 0, 46, 22);
	}
}

void UI::DrawBlank_HIT(int hit)
{
	for (int j = 0;j < hit;j++)
	{
		SHADER.m_spriteShader.SetMatrix(blankMat[HIT][j]);
		if (j == hit - 1)
		{
			SHADER.m_spriteShader.DrawTex(blankTex, hitClip, 0, 46.0f - hitClip, 22);
		}
		else SHADER.m_spriteShader.DrawTex(blankTex, 0, 0, 46, 22);
	}
}

void UI::DrawBlank_GRAZE(int graze)
{
	for (int j = 0;j < 4;j++)
	{
		SHADER.m_spriteShader.SetMatrix(blankMat[GRAZE][j]);
		SHADER.m_spriteShader.DrawTex(blankTex, 0, 0, 46, 22);
	}
}

void UI::DrawBlank_SPD(int spd)
{
	for (int j = 0;j < spd;j++)
	{
		SHADER.m_spriteShader.SetMatrix(blankMat[SPD][j]);
		SHADER.m_spriteShader.DrawTex(blankTex, 0, 0, 46, 22);
	}
}

void UI::UpdateBlank_HP()
{
	for (int j = 0;j < 4;j++)
	{
		blankMat[HP][j] = Math::Matrix::CreateTranslation(-338 - j * 40, -338, 0);
	}
}

void UI::UpdateBlank_HIT(int hit)
{
	for (int j = 0;j < 4;j++)
	{
		if (j == hit - 1 )
		{
			blankMat[HIT][j] = Math::Matrix::CreateTranslation(262 - j * 40 - hitClip, -338, 0);
		}
		else blankMat[HIT][j] = Math::Matrix::CreateTranslation(262 - j * 40, -338, 0);
	}
}

void UI::UpdateBlank_GRAZE()
{
	for (int j = 0;j < 4;j++)
	{
		blankMat[GRAZE][j] = Math::Matrix::CreateTranslation(561 - j * 40, -338, 0);
	}
}

void UI::UpdateBlank_SPD()
{
	for (int j = 0;j < 4;j++)
	{
		blankMat[SPD][j] = Math::Matrix::CreateTranslation(-39 - j * 39.5, -338, 0);
	}
}

void UI::UpdateHitClip()
{
	hitClip = 46.0f * (impact->GetHitCount() / 10.0f);
}
