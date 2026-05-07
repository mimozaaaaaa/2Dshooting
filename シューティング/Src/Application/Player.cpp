#include"Player.h"

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
	if (key('W') & 0x8000)playerPos.y += 7.0f;
	if (key('A') & 0x8000)playerPos.x -= 7.0f;
	if (key('S') & 0x8000)playerPos.y -= 7.0f;
	if (key('D') & 0x8000)playerPos.x += 7.0f;

	if (UP)playerPos.y += 3.0f;
	if (DOWN)playerPos.y -= 3.0f;
	if (RIGHT)playerPos.x += 3.0f;
	if (LEFT)playerPos.x -= 3.0f;

	PlayerKey();

	if (SPACE && time == 0)
	{
		SummonBullet();
		time = 5;
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

	if (key('W') & 0x8000)
	{
		if (UP)playerSPD = 0;
		if (DOWN)playerSPD = 2;
	}
	else
	{
		playerSPD = 3;
	}
		
}

void Player::SummonBullet()
{
	bullet->BulletSpawn(playerPos, normalBulletCount);
	normalBulletCount++;
	if (normalBulletCount > 100)normalBulletCount = 0;
}

