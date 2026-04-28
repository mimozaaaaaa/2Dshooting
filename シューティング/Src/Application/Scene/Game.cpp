#include "Game.h"

void Game::Update()
{
	backGround.Update();
	player.Update();
}

void Game::Draw()
{
	backGround.Draw();
	player.Draw();
}

void Game::Init()
{
	backGround.Init();
	player.Init();
}