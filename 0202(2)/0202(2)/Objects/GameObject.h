#pragma once

#include"../Utility/Vector2D.h"

class GameObject
{
protected:
	unsigned int color;//カラー
	Vector2D location;//位置情報
	Vector2D box_size;//ボックスサイズ

public:
	//コンストラクタ
	GameObject();

	//デストラクタ
	virtual~GameObject();


	virtual void Initialize();//初期化処理
	virtual void Update();//更新処理
	virtual void Draw()const;//描画処理
	virtual void Finalize();//終了時処理

public:
	void SetLocation(Vector2D location);//位置情報
	Vector2D GetLocation()const;
	Vector2D GetBoxSize()const;

};










