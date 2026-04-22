#pragma once

class Player
{
public:
	Player();
	~Player();
	
	void Update();
	void Init();
	void Draw();



	//プレイヤーの動き//
	void PlayerMove();

private:

	Math::Vector2 pos;
	Math::Vector2 addPos;

};

Player::Player()
{
}

Player::~Player()
{
}

