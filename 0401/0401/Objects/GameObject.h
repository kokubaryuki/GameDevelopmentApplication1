#pragma once

#include"../Utility/Vector2D.h"

//ゲームオブジェクトクラス(画面に出てくるオブジェクトの親クラス)4
class GameObject
{
protected:

	Vector2D location;
	Vector2D box_size;
	int image;
	int flip_flag;

public:
	GameObject();
	virtual~GameObject();

	virtual void Initialize();
	virtual void Update();
	virtual void Draw()const;
	virtual void Finalize();

public:
	Vector2D GetLocation() const;
	Vector2D GetBoxSize() const;

	void SetLocation(const Vector2D& location);
};
