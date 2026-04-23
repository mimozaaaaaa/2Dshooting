#include "Game.h"

void Game::Update()
{
	PlayerMove();
	UpdateMat();
}

void Game::Draw()
{
	DrawBackGround();
	DrawPlayer();
}

void Game::Init()
{
	InitTex();
}

void Game::UpdateMat()
{
	playerMat = Math::Matrix::CreateTranslation(playerPos.x, playerPos.y, 0);
}

void Game::InitTex()
{
	playerTex.Load("Texture/Game/player/player.png");
}

void Game::DrawPlayer()
{
	SHADER.m_spriteShader.SetMatrix(playerMat);
	SHADER.m_spriteShader.DrawTex(&playerTex,0,0,166,193);
}

void Game::DrawBackGround()
{

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

void Game::PlayerLimit()
{
	if (SCREEN_MAX_X < playerPos.x)playerPos.x = SCREEN_MAX_X;
	if (SCREEN_MAX_Y < playerPos.y)playerPos.y = SCREEN_MAX_Y;
	if (SCREEN_MIN_X > playerPos.x)playerPos.x = SCREEN_MIN_X;
	if (SCREEN_MIN_Y > playerPos.y)playerPos.y = SCREEN_MIN_Y;

}
