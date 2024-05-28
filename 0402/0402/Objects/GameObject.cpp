#include"GameObject.h"
#include"../Utility/ResoruceManager.h"
#include"DxLib.h"


//コンストラクタ
GameObject::GameObject() :
	location(0.0f),
	box_size(0.0f),
	image(NULL),
	flip_flag(FALSE)
{

}

//デストラクタ
GameObject::~GameObject()
{

}


//初期化処理
void GameObject::Initialize()
{
	image = NULL;
	box_size = Vector2D(32.0f);
	location = box_size;
}

//更新処理
void GameObject::Update()
{

}

//描画処理
void GameObject::Draw()const
{
	//メンバの情報を基に画像を描画する
	DrawRotaGraphF(location.x, location.y, 1.0, 0.0, image, TRUE, flip_flag);

	//当たり判定の短形情報を描画する
	Vector2D upper_left = location - (box_size / 2.0f);
	Vector2D lower_right = location + (box_size / 2.0f);
	DrawBoxAA(upper_left.x, upper_left.y, lower_right.x, lower_right.y, GetColor(255, 0, 0), FALSE);
}

//終了時処理
void GameObject::Finalize()
{

}

//位置座標の取得する
Vector2D GameObject::GetLocation() const
{
	return this->location;
}

//短形の大きさを取得する
Vector2D GameObject::GetBoxSize() const
{
	return this->box_size;
}

//位置情報の設定
void GameObject::SetLocation(const Vector2D& location)
{
	this->location = location;
}




















