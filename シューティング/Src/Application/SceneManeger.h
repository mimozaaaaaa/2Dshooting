#pragma once
#include"Scene/Game.h"
#include"Scene/Setting.h"
#include"Scene/Title.h"

class SceneManager 
{
public:
	~SceneManager(){}

	static SceneManager& GetInstance() 
	{
		static SceneManager Instance;
		return Instance;
	}

	void ChangeScene(SceneBase* newScene)
	{
		if (newScene)
		{
			delete currentScene;
		}
		currentScene = newScene;
		currentScene->Init();
	}
	void Update(){currentScene->Update();}
	void Draw(){currentScene->Draw();}


private:
	SceneManager(){}

	SceneBase* currentScene = nullptr;
};

#define SCENEMANAGER SceneManager::GetInstance()
