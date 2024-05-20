#pragma once


#include "../0402/Vector2D.h"

//ゲームオブジェクトクラス（画面に出てくるオブジェクトの親クラス）

class GameObject
{
	Vector2D location;
	Vettor2D box_size;
	int image;
	int flip_flag;

public:
	GameObject();
	virtual~GameObject();

	//初期化処理
	virtual void Initialize();
	//更新処理
	virtual void Update();
	//描画処理
	virtual void Draw()const;
	//終了処理
	virtual void Finalize();

public:
	Vector2D GetLocation() const;
	Vector2D GetBoxSize() const;

	void SetLocation(const Vector2D\& location);



};