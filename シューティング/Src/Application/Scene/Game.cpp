#include "Game.h"

void Game::Update()
{
}

void Game::Draw()
{
	SHADER.m_spriteShader.DrawString(0, 0, "ゲーム", Math::Vector4(1, 1, 1, 1));
}

void Game::Init()
{
}
