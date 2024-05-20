#pragma once

#include "../0402/GameObject.h"
#include<vector>

class Player :public GameObject
{
private:
	Vector2D velocity;//加速度
	std::vector<int>animation_data;//アニメーションデータ
	int animation_const; //アニメーションの時間

public:
	Player();
	virtual~Player();

	//初期化処理
	virtual void Initialize() override;
	//更新処理
	virtual void Update() override;
	//描画処理
	virtual void Draw()const override;
	//終了処理
	virtual void Finalize() override;

private:
	//移動処理
	void Movement();
	//アニメーションの制御
	void AnimationControl();


};

