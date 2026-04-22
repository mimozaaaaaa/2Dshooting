#pragma once
#include"SceneBase.h"

class Setting :public SceneBase
{
public:
	Setting() {}
	~Setting() {}

	void Update()override;
	void Draw()override;
	void Init()override;

private:

};