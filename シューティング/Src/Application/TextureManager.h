#pragma once
#include<string>
#include <unordered_map>
#include <fstream>

using namespace std;

class TextureManager
{
public:
	~TextureManager(){}

	static TextureManager& GetInstance()
	{
		static TextureManager Instance;
		return Instance;
	}

	void ReadFile(const string& a_filename)
	{
		//括弧内はファイル名を書く
		ifstream ifs(a_filename);

		string name, path;

		while (getline(ifs, name, ' ') && getline(ifs, path))
		{
			LoadTex(name, path);
		}
	}

	void LoadTex(const string &name ,const string &path )
	{
		//m_texMap[key値].Load("value値");
		//m_texMapに、もうnameの画像が格納されていたらリターン
		if (m_texMap.count(name) > 0)return;
		m_texMap[name].Load(path);
	}
		//m_texMapにnameが1つ存在していないと画像ロードができない
	KdTexture *GetTex(const string& name)
	{
		if (m_texMap.count(name) > 0)return &m_texMap[name];
		return nullptr;
	}

private:
	TextureManager(){}

	unordered_map<string, KdTexture> m_texMap;
};

#define TEXTUREMANAGER TextureManager::GetInstance()