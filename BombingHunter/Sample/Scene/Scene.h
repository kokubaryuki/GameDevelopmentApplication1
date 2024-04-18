#pragma once

#include<vector>
#include<string>
#include"../Objects/Gameobject.h"

class Scene
{
private:
	std::vector<GameObject*>objects;

public:
	Scene();
	~Scene();


	void Initialize();
	void Update();
	void Draw()const;
	void Finalize();

private:
	//オブジェクト生成処理




}






