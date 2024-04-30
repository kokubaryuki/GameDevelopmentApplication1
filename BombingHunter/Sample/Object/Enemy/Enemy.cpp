#include"Enemy.h"
#include"../../Utility/InputControl.h"
#include"DxLib.h"
#include"../../Utility/Vector2D.h"

//コンストラクタ
Enemy::Enemy() :animation_count(0), flip_flag(FALSE)
{
	animation[0] = NULL;
	animation[1] = NULL;

}

//デストラクタ
Enemy::~Enemy()
{

}

//初期化処理
void Enemy::Initialize()
{
	//画像の読込み
	animation[0] = LoadGraph("Resource/Images/BoxEnemy/1.png");
	animation[1] = LoadGraph("Resource/Images/BoxEnemy/2.png");
	//エラーチェック
	if (animation[0] == -1 || animation[1] == -1)
	{
		throw("ハコテキの画像がありません\n");
	}

	//向きの設定
	radian = 0.0f;
	box_size = Vector2D(0.0f,490.0f);//ボックスの位置の設定
	location = box_size;

	//初期化処理
	image = animation[0];
}


//更新処理
void Enemy::Update()
{
	//敵が右から左に移動するときの速さを設定するところ
	location.x += 1.0f;

	//敵が端に行った時、左恥に戻る(移動距離がリセット)
	if (location.x >= 960.0f)
	{
		location.x = 0.0f;
	}
	
	//アニメージョン制御
	AnimeControl();
}



//描画処理
void Enemy::Draw()const
{
	//プレイヤー画像の描画
	DrawRotaGraphF(location.x, location.y, 1.0, radian, image, TRUE, flip_flag);

	//デバック用
#ifdef _DEBUG

		//当たり判定の可視化
	Vector2D ul = location - (scale / 2.0f);
	Vector2D br = location + (scale / 2.0f);

	DrawBoxAA(ul.x, ul.y, br.x, br.y, GetColor(255, 0, 0), FALSE);

#endif
}


//終了時処理
void Enemy::Finalize()
{
	//使用した画像を解放する
	DeleteGraph(animation[0]);
	DeleteGraph(animation[1]);
}



//位置情報を設定する
void Enemy::SetLocation(Vector2D location)
{
	this->location = location;
}

//位置情報を取得する
Vector2D Enemy::GetLocation()const
{
	return  this->location;

}

//ボックスのサイズを取得する
Vector2D Enemy::GetBoxSize()const
{
	return  this->box_size;

}

//アニメーション制御
void Enemy::AnimeControl()
{
	//フレームカウントを加算する
	animation_count++;

	//60フレーム＝1秒

	//60フレーム目に達したら
	if (animation_count >= 2)
	{
		//カウントのリセット
		animation_count = 0;

		//画像の切り替え
		if (image == animation[0])
		{
			image = animation[1];
		}
		else
		{
			image = animation[0];
		}
	}

}



