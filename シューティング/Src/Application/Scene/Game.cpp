#include "Game.h"

void Game::Update()
{
	PlayerMove();
	UpdateBackGround();
	UpdateMat();
}

void Game::Draw()
{
	DrawBackGround();
	DrawPlayer();
}

void Game::Init()
{
	TEXTUREMANAGER.ReadFile("TextureData.txt");
	backGround1Y = 0;
	backGround2Y = backGroundHigh;
	backGroundAccY = 5;
	InitTex();
}

void Game::UpdateMat()
{
	backGround1Mat = Math::Matrix::CreateTranslation(0, backGround1Y, 0);
	backGround2Mat = Math::Matrix::CreateTranslation(0, backGround2Y, 0);
	playerMat = Math::Matrix::CreateTranslation(playerPos.x, playerPos.y, 0);
}

void Game::UpdateBackGround()
{
	BackGroundLimit();
	backGround1Y -= backGroundAccY;
	backGround2Y -= backGroundAccY;
}

void Game::InitTex()
{
	backGroundTex = TEXTUREMANAGER.GetTex("BackGround");
	/*playerTex.Load("");*/
	playerTex = TEXTUREMANAGER.GetTex("Player");
}

void Game::DrawPlayer()
{
	SHADER.m_spriteShader.SetMatrix(playerMat);
	SHADER.m_spriteShader.DrawTex(playerTex,0,0,166,193);
}

void Game::DrawBackGround()
{
	SHADER.m_spriteShader.SetMatrix(backGround1Mat);
	SHADER.m_spriteShader.DrawTex(backGroundTex, 0, 0, 1024, backGroundHigh);
	SHADER.m_spriteShader.SetMatrix(backGround2Mat);
	SHADER.m_spriteShader.DrawTex(backGroundTex, 0, 0, 1024, backGroundHigh);
}

void Game::PlayerMove()
{
	if (key('W') & 0x8000)playerPos.y += 7;
	if (key('A') & 0x8000)playerPos.x -= 7;
	if (key('S') & 0x8000)playerPos.y -= 7;
	if (key('D') & 0x8000)playerPos.x += 7;

	if (UP)playerPos.y += 3;
	if (DOWN)playerPos.y -= 3;
	if (RIGHT)playerPos.x += 3;
	if (LEFT)playerPos.x -= 3;

	PlayerLimit();
}

void Game::PlayerAct()
{
	if (SPACE);
}

void Game::PlayerLimit()
{
	if (SCREEN_MAX_X < playerPos.x)playerPos.x = SCREEN_MAX_X;
	if (SCREEN_MAX_Y < playerPos.y)playerPos.y = SCREEN_MAX_Y;
	if (SCREEN_MIN_X > playerPos.x)playerPos.x = SCREEN_MIN_X;
	if (SCREEN_MIN_Y > playerPos.y)playerPos.y = SCREEN_MIN_Y;
}

void Game::BackGroundLimit()
{
	if (backGround1Y < -backGroundHigh)backGround1Y = backGroundHigh;
	if (backGround2Y < -backGroundHigh)backGround2Y = backGroundHigh;

}
