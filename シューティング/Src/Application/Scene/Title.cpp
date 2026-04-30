#include "Title.h"
#include"../main.h"

void Title::Update()
{
	UpdateTitle();
	UpdateTimer();
	UpdateMat();
	if (quitFlag)UpdateQuit();
	UpdateSelecter();
	UpdateNextScene();
}

void Title::Draw()
{
	DrawTitle();
	DrawUI();
}

void Title::Init()
{
	titleY = 205;
	titleMove = 0.125;
	time = 5;
	selecterPos.x = okX;
	selecterPos.y = startY;
	quitFlag = false;
	InitClip();
	InitTex();
}

void Title::UpdateMat()
{
	title.Mat = Math::Matrix::CreateTranslation(-40, titleY, 0);
	start.Mat = Math::Matrix::CreateTranslation(0, startY, 0);
	tutorial.Mat = Math::Matrix::CreateTranslation(0, tutorialY, 0);
	option.Mat = Math::Matrix::CreateTranslation(0, optionY, 0);
	quit.Mat = Math::Matrix::CreateTranslation(0, quitY, 0);
}

void Title::UpdateTitle()
{
	titleY += titleMove;
	if (titleY > titleMax)titleMove *= -1;
	if (titleY < titleMin)titleMove *= -1;
}

void Title::UpdateSelecter()
{
	if (time == 0)
	{
		if (selecterPos.y != quitY && DOWN)
		{
			selecterPos.y -= 100;
			time = 10;
		}
		else if (selecterPos.y == quitY && DOWN)
		{
			selecterPos.y = startY;
			time = 10;
		}
		if (selecterPos.y != startY && UP)
		{
			selecterPos.y += 100;
			time = 10;
		}
		else if (selecterPos.y == startY && UP)
		{
			selecterPos.y = quitY;
			time = 10;
		}
	}
}

void Title::UpdateTimer()
{
	time--;
	if (time < 0)time = 0;
}

void Title::UpdateNextScene()
{
	if (time == 0)
	{
		if (ENTER)
		{
			if (selecterPos.y == startY)SCENEMANAGER.ChangeScene(new Game());
			//if (selecterPos.y == tutorialY)SCENEMANAGER.ChangeScene(new Tutorial());
			//if (selecterPos.y == optionY)SCENEMANAGER.ChangeScene(new Option());
			if (selecterPos.y == quitY)quitFlag = true;
			time = 10;
		}
	}
}

void Title::UpdateQuit()
{
	if (time == 0)
	{
		if (selecterPos.x == okX)
		{
			if (LEFT || RIGHT)
			{
				selecterPos.x = noX;
				time = 10;
			}
			if (ENTER)APP.End();
		}
		else if (selecterPos.x != okX)
		{
			if (LEFT || RIGHT)
			{
				selecterPos.x = okX;
				time = 10;
			}
			if (ENTER)
			{
				quitFlag = false;
			}
		}
	}
	return;
}

void Title::InitClip()
{
	backGround.Clip = { 0,0,1280,720 };
	title.Clip = { 0,0,940,273 };
	buttonClip = { 0,0,398,81 };
	buttonClip_F = { 0,0,432,81 };
}

void Title::InitTex()
{
	backGround.Tex.Load("Texture/Title/backGround.png");
	title.Tex.Load("Texture/Title/title.png");
	//UI//
	start.Tex.Load("Texture/Title/start.png");
	tutorial.Tex.Load("Texture/Title/tutorial.png");
	option.Tex.Load("Texture/Title/option.png");
	quit.Tex.Load("Texture/Title/quit.png");
	//UI光ってる//
	start_F.Tex.Load("Texture/Title/start_F.png");
	tutorial_F.Tex.Load("Texture/Title/tutorial_F.png");
	option_F.Tex.Load("Texture/Title/option_F.png");
	quit_F.Tex.Load("Texture/Title/quit_F.png");
}

void Title::DrawTitle()
{
	SHADER.m_spriteShader.SetMatrix(backGround.Mat);
	SHADER.m_spriteShader.DrawTex(&backGround.Tex, backGround.Clip, 1.0f);

	SHADER.m_spriteShader.SetMatrix(title.Mat);
	SHADER.m_spriteShader.DrawTex(&title.Tex, title.Clip, 1.0f);
}

void Title::DrawUI()
{
	DrawStart();
	DrawTutorial();
	DrawOption();
	DrawQuit();
}

void Title::DrawStart()
{
	SHADER.m_spriteShader.SetMatrix(start.Mat);
	SHADER.m_spriteShader.DrawTex(&start.Tex, buttonClip, 1.0f);
	if (selecterPos.y == startY)SHADER.m_spriteShader.DrawTex(&start_F.Tex, buttonClip_F, 1.0f);
}

void Title::DrawTutorial()
{
	SHADER.m_spriteShader.SetMatrix(tutorial.Mat);
	SHADER.m_spriteShader.DrawTex(&tutorial.Tex, buttonClip, 1.0f);
	if (selecterPos.y == tutorialY)SHADER.m_spriteShader.DrawTex(&tutorial_F.Tex, buttonClip_F, 1.0f);

}

void Title::DrawOption()
{
	SHADER.m_spriteShader.SetMatrix(option.Mat);
	SHADER.m_spriteShader.DrawTex(&option.Tex, buttonClip, 1.0f);
	if (selecterPos.y == optionY)SHADER.m_spriteShader.DrawTex(&option_F.Tex, buttonClip_F, 1.0f);

}

void Title::DrawQuit()
{
	SHADER.m_spriteShader.SetMatrix(quit.Mat);
	SHADER.m_spriteShader.DrawTex(&quit.Tex, buttonClip, 1.0f);
	if (selecterPos.y == quitY)SHADER.m_spriteShader.DrawTex(&quit_F.Tex, buttonClip_F, 1.0f);

}
