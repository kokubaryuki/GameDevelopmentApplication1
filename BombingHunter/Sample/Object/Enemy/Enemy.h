#pragma once
#pragma once

#include"../GameObject.h"

class  Enemy : public GameObject
{
private:
	int animation[2];     //アニメーション画像
	int animation_count;  //アニメーション時間
	int flip_flag;        //反転フラグ

protected:
	Vector2D location;
	Vector2D box_size;
	
public:
	Enemy();
	~Enemy();

	virtual void Initialize() override;  //初期化処理
	virtual void Update() override;      //更新処理
	virtual void Draw() const override;  //描画処理
	virtual void Finalize() override;    //終了時処理


private:
	
	//アニメーション制御
	void AnimeControl();


public:

	void SetLocation(Vector2D location);
	Vector2D GetLocation() const;
	Vector2D GetBoxSize() const; 
	//当たり判定の大きさを取得
};


