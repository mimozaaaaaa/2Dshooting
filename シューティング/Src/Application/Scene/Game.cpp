#include "Game.h"

void Game::Update()
{
	backGround.Update();
	player.Update();
	bullet.Update();
	ui.Update();
}

void Game::Draw()
{
	backGround.Draw();
	player.Draw();
	bullet.Draw();
	ui.Draw();
}

void Game::Init()
{
	backGround.Init();
	player.Init();
	bullet.Init();
	ui.Init();
	ui.SetPlayer(&player);
	player.SetBullet(&bullet);
}