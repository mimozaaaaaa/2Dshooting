#include"Enemy1.h"

#include"../Effect.h"

void Enemy1::Update()
{
	UpdateLife();
	for(int i = 0;i < 10;i++)
	{
		if (!LeftTurret[i].Flag)continue;
		LeftTurret[i].Pos.y += enemyDownSpd;
	}
	for (int i = 0;i < 10;i++)
	{
		if (!RightTurret[i].Flag)continue;
		RightTurret[i].Pos.y += enemyDownSpd;
	}
	UpdateMat();
}

void Enemy1::Init()
{
	InitTurretPos();
	TEXTUREMANAGER.ReadFile("TextureData.txt");

	InitTex();
}

void Enemy1::Draw()
{
	for (int i = 0;i < 10;i++)
	{
		if (!LeftTurret[i].Flag)continue;
		SHADER.m_spriteShader.SetMatrix(LeftTurret[i].Mat);
		SHADER.m_spriteShader.DrawTex(Lefttex, 0, 0, 83, 62);

	}
	for (int i = 0;i < 10;i++)
	{
		if (!RightTurret[i].Flag)continue;
		SHADER.m_spriteShader.SetMatrix(RightTurret[i].Mat);
		SHADER.m_spriteShader.DrawTex(Righttex, 0, 0, -83, 62);
	}
}

void Enemy1::UpdateMat()
{
	for (int i = 0;i < 10;i++)
	{
		
		LeftTurret[i].Mat = Math::Matrix::CreateTranslation(LeftTurret[i].Pos.x, LeftTurret[i].Pos.y, 0.0f);
		RightTurret[i].Mat = Math::Matrix::CreateTranslation(RightTurret[i].Pos.x, RightTurret[i].Pos.y, 0.0f);
	}
}

void Enemy1::UpdateLife()
{
	for (int i = 0;i < 10;i++)
	{
		if (LeftTurret[i].Life <= 0)
		{
			LeftTurret[i].Flag = false;
			//effect->Spawn(LeftTurret[i].Pos,i);
		}
		if (RightTurret[i].Life <= 0)
		{
			RightTurret[i].Flag = false;
			//effect->Spawn(RightTurret[i].Pos,i);
		}
	}
}

void Enemy1::InitTex()
{
	Lefttex = TEXTUREMANAGER.GetTex("Enemy1");
	Righttex = TEXTUREMANAGER.GetTex("Enemy1");
}

void Enemy1::InitTurretPos()
{
	for (int i = 0;i < 10;i++)
	{
		RightTurret[i].Pos = { -400.0f, 600.0f + i * 600.0f };
		LeftTurret[i].Pos = { 400.0f, 600.0f + i * 600.0f };

		RightTurret[i].Life = 2;
		LeftTurret[i].Life = 2;

		RightTurret[i].Flag = true;
		LeftTurret[i].Flag = true;
	}
}
