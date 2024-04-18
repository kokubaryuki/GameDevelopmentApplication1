#pragma once

#include"GameObject.h"

//プレイヤークラス
class Player :public GameObject
{
private:

public:

	//コンストラクタ
	Player();

	//デストラクタ
	~Player();

	virtual void Initialize();//初期化処理
	virtual void Update();//更新処理
	virtual void Draw() const;//描画処理
	virtual void Finalize();//終了時処理

private:
	virtual void Movement();//移動

};






