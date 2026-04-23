#include "main.h"
#include "Scene.h"
#include"SceneManeger.h"

void Scene::Draw2D()
{
	SCENEMANAGER.Draw();
}

void Scene::Update()
{
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		SCENEMANAGER.ChangeScene(new Title());
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		SCENEMANAGER.ChangeScene(new Setting());
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		SCENEMANAGER.ChangeScene(new Game());
	}

	SCENEMANAGER.Update();
	
}

void Scene::Init()
{
	SCENEMANAGER.ChangeScene(new Title());
}

void Scene::Release()
{
	
}

void Scene::ImGuiUpdate()
{
	return;

	ImGui::SetNextWindowPos(ImVec2(20, 20), ImGuiSetCond_Once);
	ImGui::SetNextWindowSize(ImVec2(200, 100), ImGuiSetCond_Once);

	// デバッグウィンドウ
	if (ImGui::Begin("Debug Window"))
	{
		ImGui::Text("FPS : %d", APP.m_fps);
	}
	ImGui::End();
}
