#include"Player.h"

void Player::Update()
{
	PlayerMove();
	UpdateMat();
}

void Player::Init()
{
	TEXTUREMANAGER.ReadFile("TextureData.txt");

	InitTex();
}

void Player::Draw()
{
	DrawPlayer();
}

void Player::UpdateMat()
{
	playerMat = Math::Matrix::CreateTranslation(playerPos.x, playerPos.y, 0);
}

void Player::InitTex()
{
	playerTex = TEXTUREMANAGER.GetTex("Player");
}

void Player::DrawPlayer()
{
	SHADER.m_spriteShader.SetMatrix(playerMat);
	SHADER.m_spriteShader.DrawTex(playerTex, 0, 0, 166, 193);
}

void Player::PlayerMove()
{
	if (key('W') & 0x8000)playerPos.y += 7;
	if (key('A') & 0x8000)playerPos.x -= 7;
	if (key('S') & 0x8000)playerPos.y -= 7;
	if (key('D') & 0x8000)playerPos.x += 7;

	if (UP)playerPos.y += 3;
	if (DOWN)playerPos.y -= 3;
	if (RIGHT)playerPos.x += 3;
	if (LEFT)playerPos.x -= 3;

	PlayerLimit();
}

void Player::PlayerAct()
{
	if (SPACE);
}

void Player::PlayerLimit()
{
	if (SCREEN_MAX_X < playerPos.x)playerPos.x = SCREEN_MAX_X;
	if (SCREEN_MAX_Y < playerPos.y)playerPos.y = SCREEN_MAX_Y;
	if (SCREEN_MIN_X > playerPos.x)playerPos.x = SCREEN_MIN_X;
	if (SCREEN_MIN_Y > playerPos.y)playerPos.y = SCREEN_MIN_Y;
}