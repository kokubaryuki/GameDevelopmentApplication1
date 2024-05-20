#pragma once

#include<vector>
#include<string>
#include"../Object/Gameobject.h"

class Scene
{
private:
	std::vector<GameObject*>objects;
	int background_image;

public:
	Scene();
	~Scene();


	void Initialize();
	void Update();
	void Draw()const;
	void Finalize();

private:

	//当たり判定チェック処理
	void HitCheckObject(GameObject* a, GameObject* b);

	//オブジェクト生成処理
	template<class T>
	T* CreateObject(const Vector2D& location)
	{
		//指定したクラスを生成する
		T* new_instance = new T();
		//GameObjectクラスを継承できているか確認する
		GameObject* new_object = dynamic_cast<GameObject*>(new_instance);

		//エラーチェック
		if (new_object == nullptr)
		{
			delete new_instance;
			throw std::string("ゲームオブジェクトが生成できませんでした");
		}
		//初期化処理
		new_object->Initialize();

		//位置情報の設定
		new_object->SetLocation(location);

		//オブジェクトを生成
		objects.push_back(new_object);

		//インスタンスのポインタを返却
		return new_instance;
	}

};