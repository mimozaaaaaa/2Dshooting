#include "Game.h"

void Game::Update()
{
	backGround.Update();
	player.Update();
	bullet.Update();
}

void Game::Draw()
{
	backGround.Draw();
	player.Draw();
	bullet.Draw();
}

void Game::Init()
{
	backGround.Init();
	player.Init();
	bullet.Init();
}