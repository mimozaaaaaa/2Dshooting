#include "Game.h"

void Game::Update()
{
	backGround.Update();
	player.Update();
	bullet.Update();
	enemy1.Update();
	impact.Update();
	effect.Update();
	ui.Update();
}

void Game::Draw()
{
	backGround.Draw();
	player.Draw();
	bullet.Draw();
	enemy1.Draw();
	effect.Draw();
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
	effect.Init();
	ui.SetPlayer(&player);
	player.SetBullet(&bullet);
	impact.SetInstance(&player, &bullet, &enemy1);
	enemy1.SetEffect(&effect);
}