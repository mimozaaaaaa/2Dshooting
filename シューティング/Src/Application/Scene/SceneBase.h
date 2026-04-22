#pragma once

class SceneBase
{
public:
	SceneBase(){}
	~SceneBase(){}

	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Init() = 0;

protected:
	

};