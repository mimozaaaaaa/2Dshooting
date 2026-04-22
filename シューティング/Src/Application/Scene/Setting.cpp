#include "Setting.h"

void Setting::Update()
{

}

void Setting::Draw()
{
	SHADER.m_spriteShader.DrawString(0, 0, "バッティング", Math::Vector4(1, 1, 1, 1));
}

void Setting::Init()
{

}
