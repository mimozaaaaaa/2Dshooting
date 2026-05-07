#include"Bullet.h"

void Bullet::Init()
{
    TEXTUREMANAGER.ReadFile("TextureData.txt");
    InitTex();
}

void Bullet::Update()
{   

	NormalBulletUpdate();

    UpdateMat();

    BreakFlag();
}

void Bullet::Draw()
{
	DrawNormalBullet();
	DrawHomingBullet();
	DrawEnemyBullet();
}

void Bullet::NormalBulletUpdate()
{
	for (int i = 0;i < 100;i++)
    {
        if (!normalBullet[i].Flag)continue;
        normalBullet[i].Pos += accelerationMat_Normal;
        accelerationMat_Normal = { 0.0f, 5.0f };
    }
}

void Bullet::HomingBulletUpdate()
{
}

void Bullet::EnemyBulletUpdate()
{
}

void Bullet::InitTex()
{
	normalBulletTex = TEXTUREMANAGER.GetTex("NormalBullet");
}

void Bullet::DrawNormalBullet()
{
    for (int i = 0;i < 100;i++)
    {
        if (!normalBullet[i].Flag)continue;
        SHADER.m_spriteShader.SetMatrix(normalBullet[i].Mat);
        SHADER.m_spriteShader.DrawTex(normalBulletTex, Math::Rectangle(0, 0, 10, 24), 1.0f);
    }
}

void Bullet::DrawHomingBullet()
{
}

void Bullet::DrawEnemyBullet()
{
}

void Bullet::BreakFlag()
{
	for (int i = 0;i < 100;i++)
    {
		if (normalBullet[i].Pos.y > 400)normalBullet[i].Flag = false;
		if (homingBullet[i].Pos.y > 400)homingBullet[i].Flag = false;
		if (enemyBullet[i].Pos.y < -400)enemyBullet[i].Flag = false;
    }
}

void Bullet::BulletSpawn(const Math::Vector2& a_spawnPos,int count)
{
    normalBullet[count].Mat = Math::Matrix::CreateTranslation(a_spawnPos.x, a_spawnPos.y, 0.0f);
    normalBullet[count].Pos = a_spawnPos;
    normalBullet[count].Flag = true;
}

void Bullet::UpdateMat()
{
	for (int i = 0;i < 100;i++)
    {
        if (!normalBullet[i].Flag)continue;
        normalBullet[i].Mat = Math::Matrix::CreateTranslation(normalBullet[i].Pos.x, normalBullet[i].Pos.y, 0.0f);
    
        if (!homingBullet[i].Flag)continue;
        homingBullet[i].Mat = Math::Matrix::CreateTranslation(homingBullet[i].Pos.x, homingBullet[i].Pos.y, 0.0f);
    
        if (!enemyBullet[i].Flag)continue;
        enemyBullet[i].Mat = Math::Matrix::CreateTranslation(enemyBullet[i].Pos.x, enemyBullet[i].Pos.y, 0.0f);
    }
}