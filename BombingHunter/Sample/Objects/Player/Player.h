#pragma once

#include"../GameObject.h"


class  Player : public GameObject
{
private:
	int animation[2];    //アニメーション画像
	int animation_count; //アニメーション時間
	int flip_flag;       //反転フラグ
	
	
	Vector2D location;//位置座標
	Vector2D box_size;//当たり判定


public:
	Player();
	~Player();

	
	virtual void Initialize() override;  //初期化処理
	virtual void Update() override;      //更新処理
	virtual void Draw() const override;  //描画処理
	virtual void Finalize() override;    //終了時処理
	
	
	//当たり判定通知処理
	virtual void OnHitCollision(GameObject*hit_object) override;

	//位置情報取得処理
	Vector2D GetLocation()const;

	//位置情報変更処理
	void SetLocation(const Vector2D& Location);

	//当たり判定の大きさを取得する
	Vector2D GetBoxSize() const;

private:
     //移動処理
	void Movement();
	//アニメーション制御
	void AnimeControl();
};

