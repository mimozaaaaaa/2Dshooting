#pragma once

class Player;
class Enemy1;
class Bullet;

class Impact
{
public:
	Impact(){}
	~Impact(){}

	void Update();
	void Init();

	void UpdateDamegeCoolTime();

	void Enemy1PlayerCollision(Math::Vector2 playerPos, Math::Vector2 enemyPos,int enemyCount);

	void Enemy1LeftPlayerBulletCollision(Math::Vector2 bulletPos, Math::Vector2 enemyPos, int bulletCount, int enemyCount);
	void Enemy1RightPlayerBulletCollision(Math::Vector2 bulletPos, Math::Vector2 enemyPos, int bulletCount, int enemyCount);

	void UpdateHitCount();

	int GetPlayerHitCount()const { return playerHiCount; }
	float GetHitCount()const { return hitCount; }

	// 値渡しだと不完全な型ではエラーになるためポインタ/参照を使用する
	void SetInstance(Player* _player, Bullet* _bullet, Enemy1* _enemy1)
	{
		player = _player;
		bullet = _bullet;
		enemy1 = _enemy1;
	}

private:
	Player* player;
	Bullet* bullet;
	Enemy1* enemy1;

	float hitCount;
	int playerHiCount = 4;

	int damegeCoolTime;
};
