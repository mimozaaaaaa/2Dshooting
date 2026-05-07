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

	UpdateAnimeSQ();
}

void Title::Draw()
{
	DrawTitle();
	DrawUI();
	if (quitFlag)DrawYesNo();
	DrawAnimeSQ();
}

void Title::Init()
{
	titleY = 205.0f;
	titleMove = 0.125f;
	time = 5;
	selecterPos.x = okX;
	selecterPos.y = startY;
	quitFlag = false;
	white1Y = 0;
	white2Y = 0;
	white3X = 0;
	white4X = 0;
	InitClip();
	InitTex();
}

void Title::UpdateMat()
{
	title.Mat = Math::Matrix::CreateTranslation(-40.0f, titleY, 0.0f);
	start.Mat = Math::Matrix::CreateTranslation(0.0f, startY, 0.0f);
	tutorial.Mat = Math::Matrix::CreateTranslation(0.0f, tutorialY, 0.0f);
	option.Mat = Math::Matrix::CreateTranslation(0.0f, optionY, 0.0f);
	quit.Mat = Math::Matrix::CreateTranslation(0.0f, quitY, 0.0f);
	quitFrame.Mat = Math::Matrix::CreateTranslation(0.0f, -75.0f, 0.0f);
	white1.Mat = Math::Matrix::CreateTranslation(320.0f, white1Y/2.0f, 0.0f);
	white2.Mat = Math::Matrix::CreateTranslation(-320.0f, white2Y/2.0f, 0.0f);
	white3.Mat = Math::Matrix::CreateTranslation(white3X/2.0f, -180.0f, 0.0f);
	white4.Mat = Math::Matrix::CreateTranslation(white4X/2.0f, 180.0f, 0.0f);
	
}

void Title::UpdateTitle()
{
	titleY += titleMove;
	if (titleY > titleMax)titleMove *= -1.0f;
	if (titleY < titleMin)titleMove *= -1.0f;
}

void Title::UpdateSelecter()
{
	if (time == 0)
	{
		if (selecterPos.y != quitY && DOWN)
		{
			selecterPos.y -= 100.0f;
			time = 10;
		}
		else if (selecterPos.y == quitY && DOWN)
		{
			selecterPos.y = startY;
			time = 10;
		}
		if (selecterPos.y != startY && UP)
		{
			selecterPos.y += 100.0f;
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
			if (selecterPos.y == quitY)
			{
				quitFlag = true;
				selecterPos.x = okX;
				time = 10;
			}
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

void Title::UpdateAnimeSQ()
{
		white3X += 10.5;
		white4X -= 10.5;
	if (white3X > 640)
	white1Y += 6;
	white2Y -= 6;
	{
	}
	white1.Clip = { 0,0,640,(int)white1Y };
	white3.Clip = { 0,0,(int)white3X,360 };
}

void Title::InitClip()
{
	backGround.Clip = { 0,0,1280,720 };
	title.Clip = { 0,0,940,273 };
	buttonClip = { 0,0,398,81 };
	buttonClip_F = { 0,0,432,81 };

	white1.Clip = { 0,0,640,(int)white1Y };
	white3.Clip = { 0,0,(int)white3X,360 };
}

void Title::InitTex()
{
	backGround.Tex.Load("Texture/Title/backGround.png");
	title.Tex.Load("Texture/Title/title.png");
	quitFrame.Tex.Load("Texture/Title/quitFrame.png");
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

	white1.Tex.Load("Texture/Title/white.png");
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

void Title::DrawYesNo()
{
	SHADER.m_spriteShader.SetMatrix(quitFrame.Mat);
	SHADER.m_spriteShader.DrawTex(&quitFrame.Tex, Math::Rectangle(0, 0, 1100, 422), 1.0f);
	
	SHADER.m_spriteShader.SetMatrix(yes.Mat);
	SHADER.m_spriteShader.DrawTex(&yes.Tex, Math::Rectangle(0,0,100,100), 1.0f);

	SHADER.m_spriteShader.SetMatrix(No.Mat);
	SHADER.m_spriteShader.DrawTex(&No.Tex, Math::Rectangle(0,0,100,100), 1.0f);
}

void Title::DrawAnimeSQ()
{
	/*SHADER.m_spriteShader.SetMatrix(white1.Mat);
	SHADER.m_spriteShader.DrawTex(&white1.Tex, white1.Clip, 1.0f);
	SHADER.m_spriteShader.SetMatrix(white2.Mat);
	SHADER.m_spriteShader.DrawTex(&white1.Tex, white1.Clip, 1.0f);
	SHADER.m_spriteShader.SetMatrix(white3.Mat);
	SHADER.m_spriteShader.DrawTex(&white1.Tex, white3.Clip, 1.0f);
	SHADER.m_spriteShader.SetMatrix(white4.Mat);
	SHADER.m_spriteShader.DrawTex(&white1.Tex, white3.Clip, 1.0f);*/
}
