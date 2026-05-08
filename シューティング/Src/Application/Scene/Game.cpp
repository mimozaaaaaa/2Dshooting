#include "Game.h"

void Game::Update()
{
	backGround.Update();
	player.Update();
	bullet.Update();
	enemy1.Update();
	impact.Update();
	ui.Update();
}

void Game::Draw()
{
	backGround.Draw();
	player.Draw();
	bullet.Draw();
	enemy1.Draw();
	ui.Draw();
}

void Game::Init()
{
	backGround.Init();
	player.Init();
	bullet.Init();
	ui.Init();
	enemy1.Init();
	impact.Init();
	ui.SetPlayer(&player);
	player.SetBullet(&bullet);
	impact.SetInstance(&player, &bullet, &enemy1);
}