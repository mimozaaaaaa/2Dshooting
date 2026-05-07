#pragma once

class Player;
class Enemy1;
class Bullet;

class Impact
{
public:
	Impact(){}
	~Impact(){}

	//衝突判定をするオブジェクトをすべて引数として渡す
	void AllCollision(Player& player, Enemy1& enemy, Bullet& bullet);

	//プレイヤーと敵の衝突判定（テンプレート関数は、必ずヘッダーファイルに処理を書いてね！）
	template <typename T_Enemy>
	void PlayerEnemyCollision(Player& player, T_Enemy& enemy)
	{

	}

	//プレイヤーの弾と敵の衝突判定
	template<typename T_Bullet, typename T_Enemy>
	void BulletEnemyCollision(T_Bullet &a_bullet,T_Enemy &a_enemy)
	{

	}

	//プレイヤーと敵の弾の衝突判定
	template <typename T_Bullet>
	void PlayerBulletCollision(Player& a_player, T_Bullet& a_bullet)
	{
		if (60 > GetDistance(a_player.GetPos(), a_bullet.GetBulletPos()))
		{
			
		}
	}

	float GetDistance(const Math::Vector2 &a_pos1,const Math::Vector2 &a_pos2)
	{
		return sqrtf(powf(a_pos1.x - a_pos2.x, 2) + powf(a_pos1.y - a_pos2.y, 2));
	}

	float GetDistanceGraze(const Math::Vector2& a_pos1, const Math::Vector2& a_pos2)
	{
		return sqrtf(powf(a_pos1.x - a_pos2.x, 2) + powf(a_pos1.y - a_pos2.y, 2));
	}

private:



};
