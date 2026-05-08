#include "Impact.h"
#include"Player.h"
#include"Enemy/Enemy1.h"
#include"Bullet.h"

void Impact::Update()
{
	UpdateDamegeCoolTime();
	for (int i = 0;i < 10;i++)
	{
		Enemy1PlayerCollision(player->GetPos(), enemy1->GetLeftTurretPos(i));
		Enemy1PlayerCollision(player->GetPos(), enemy1->GetRightTurretPos(i));
	}
	for(int i = 0;i < 10;i++)
	{
		for (int j = 0;j < 100;j++)
		{
			Enemy1LeftPlayerBulletCollision(bullet->GetPos(j), enemy1->GetLeftTurretPos(i), j,i);
			Enemy1RightPlayerBulletCollision(bullet->GetPos(j), enemy1->GetRightTurretPos(i), j,i);
		}
	}
}

void Impact::Init()
{
}

void Impact::UpdateDamegeCoolTime()
{
	damegeCoolTime--;
	if (damegeCoolTime < 0)
	{
		damegeCoolTime = 0;
	}
}

void Impact::Enemy1PlayerCollision(Math::Vector2 playerPos, Math::Vector2 enemyPos)
{
	if (player->GetPlayerDamege() == 4)return;
	if (sqrtf(powf(playerPos.x - enemyPos.x, 2) + powf(playerPos.y - enemyPos.y, 2)) < 60)
	{
		if (damegeCoolTime == 0)
		{
			player->SetPlayerDamege(player->GetPlayerDamege() + 1);
			damegeCoolTime = 30;
		}
	}
}

void Impact::Enemy1LeftPlayerBulletCollision(Math::Vector2 bulletPos, Math::Vector2 enemyPos, int bulletCount, int enemyCount)
{
	if (sqrtf(powf(bulletPos.x - enemyPos.x, 2) + powf(bulletPos.y - enemyPos.y, 2)) < 60)
	{
		if (enemy1->GetEnemy1LeftLife(enemyCount) == 0)return;
		if (!bullet->GetFlag(bulletCount))return;
		bullet->SetFlag(bulletCount, false);
		enemy1->SetEnemy1LeftLife(enemyCount, enemy1->GetEnemy1LeftLife(enemyCount) - 1);
	}
}

void Impact::Enemy1RightPlayerBulletCollision(Math::Vector2 bulletPos, Math::Vector2 enemyPos, int bulletCount, int enemyCount)
{
	if (sqrtf(powf(bulletPos.x - enemyPos.x, 2) + powf(bulletPos.y - enemyPos.y, 2)) < 60)
	{
		if (enemy1->GetEnemy1RightLife(enemyCount) == 0)return;
		if(!bullet->GetFlag(bulletCount))return;
		bullet->SetFlag(bulletCount, false);
		enemy1->SetEnemy1RightLife(enemyCount, enemy1->GetEnemy1RightLife(enemyCount) - 1);
	}
}

void Impact::AllCollision(Player& player, Enemy1& enemy, Bullet& bullet)
{

}
