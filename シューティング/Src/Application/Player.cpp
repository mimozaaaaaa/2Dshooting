#include"Player.h"

#define WASD key('W') & 0x8000 || key('S') & 0x8000 || key('A') & 0x8000 || key('D') & 0x8000
#define ARROW UP || DOWN || RIGHT || LEFT

void Player::Update()
{
	PlayerMove();
	UpdateMat();
	UpdateKeyTimer();
}

void Player::Init()
{
	TEXTUREMANAGER.ReadFile("TextureData.txt");

	InitTex();

	time = 5;
}

void Player::Draw()
{
	DrawPlayer();
}

void Player::UpdateMat()
{
	playerMat = Math::Matrix::CreateTranslation(playerPos.x, playerPos.y, 0.0f);
}

void Player::UpdateKeyTimer()
{
	time--;
	if (time < 0)
	{
		time = 0;
	}
}

void Player::InitTex()
{
	playerTex = TEXTUREMANAGER.GetTex("Player");
}

void Player::DrawPlayer()
{
	SHADER.m_spriteShader.SetMatrix(playerMat);
	SHADER.m_spriteShader.DrawTex(playerTex, 0.0f, 0.0f, 166.0f, 193.0f);
}

void Player::PlayerMove()
{
	if(CONTROL)playerAcceleration = 3.0f;
	else if(SHIFT)playerAcceleration = -4.0f;
	else playerAcceleration = 0.0f;

	if (key('W') & 0x8000)playerPos.y += 7.0f + playerAcceleration;
	if (key('A') & 0x8000)playerPos.x -= 7.0f + playerAcceleration;
	if (key('S') & 0x8000)playerPos.y -= 7.0f + playerAcceleration;
	if (key('D') & 0x8000)playerPos.x += 7.0f + playerAcceleration;

	if (UP)playerPos.y += 7.0f + playerAcceleration;
	if (DOWN)playerPos.y -= 7.0f + playerAcceleration;
	if (RIGHT)playerPos.x += 7.0f + playerAcceleration;
	if (LEFT)playerPos.x -= 7.0f + playerAcceleration;

	PlayerKey();
	if (time == 0)
	{
		if (SPACE)
		{
			SummonNormalBullet();
			time = 5;
		}
		if(key('V') & 0x8000)
		{
			SummonHomingBullet();
			time = 5;
		}
	}
	PlayerLimit();
}

void Player::PlayerLimit()
{
	if (SCREEN_MAX_X < playerPos.x)playerPos.x = SCREEN_MAX_X;
	if (SCREEN_MAX_Y < playerPos.y)playerPos.y = SCREEN_MAX_Y;
	if (SCREEN_MIN_X > playerPos.x)playerPos.x = SCREEN_MIN_X;
	if (SCREEN_MIN_Y > playerPos.y)playerPos.y = SCREEN_MIN_Y;
}

void Player::PlayerKey()
{

	if (WASD || ARROW)
	{
		if (playerAcceleration > 0)
		{
			playerSPD = 0;

		}
		else if (playerAcceleration < 0)
		{
			playerSPD = 2;
		}
		else
		{
			playerSPD = 1;
		}
	}
	
	else playerSPD = 3;
}

void Player::SummonNormalBullet()
{
	bullet->NormalBulletSpawn(playerPos, normalBulletCount);
	normalBulletCount++;
	if (normalBulletCount >= 100)normalBulletCount = 0;
}

void Player::SummonHomingBullet()
{
	bullet->HomingBulletSpawn(playerPos, homingBulletCount);
	homingBulletCount++;
	if (homingBulletCount >= 100)homingBulletCount = 0;
}

