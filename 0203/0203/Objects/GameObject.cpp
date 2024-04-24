#include"GameObject.h"
#include"DxLib.h"

//コンストラクタ
GameObject::GameObject() :color(0x0), location(0.0f), box_size(0.0f)
{
	//カラー、位置情報、ボックスサイズの初期化
}

//デストラクタ
GameObject::~GameObject()
{

}

//初期化処理
void GameObject::Initialize()
{
	color = GetColor(255, 0, 0);//色を赤色にする
	box_size = Vector2D(100.0f);//ボックスのサイズを設定する
	location = box_size;
}


//更新処理
void GameObject::Update()
{
	location.x += 1.0f;

	if (location.x >= 640.0f)
	{
		location.x = 0.0f;
	}
}


//描画処理
void GameObject::Draw() const
{
	Vector2D upper_left = location - (box_size / 2.0f);
	Vector2D lower_right = location +(box_size / 2.0f);

	DrawBoxAA(upper_left.x, upper_left.y, lower_right.x, lower_right.y, color,
		TRUE);
}


//終了時処理
void GameObject::Finalize()
{

}



//位置情報を設定する
void GameObject::SetLocation(Vector2D location)
{
	this->location = location;

}

//位置情報を取得する
Vector2D GameObject::GetLocation()const
{
	return  this->location;

}

//ボックスのサイズを取得する
Vector2D GameObject::GetBoxSize()const
{
	return  this->box_size;

}











