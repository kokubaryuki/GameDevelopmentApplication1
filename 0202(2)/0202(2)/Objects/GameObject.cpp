#include"GameObject.h"
#include"DxLib.h"

//コンストラクタ
GameObject::GameObject() : color(0x0), location(), box_size()//初期化リスト
{

}

//デストラクタ
GameObject::~GameObject()
{

}

//初期化処理
void GameObject::Initialize()
{
	location = Vector2D(32.0f, 24.0f);
	box_size = Vector2D(32.0f, 24.0f);
	color = GetColor(0, 255, 0);
}

void GameObject::Update()
{
	//どんどん右下に進む
	location += 0.1f;
}

//描画処理
void GameObject::Draw()const
{
	Vector2D t1 = this->location - (box_size / 2.0f);
	Vector2D br = this->location + (box_size / 2.0f);

	DrawBoxAA(t1.x, t1.y, br.x, br.y, color, TRUE);
}

//終了時処理
void GameObject::Finalize()
{

}


void GameObject::SetLocation(Vector2D location)
{
	this->location = location;
}

//位置情報
Vector2D GameObject::GetLocation()const
{
	return this->location;
}

//ボックスの大きさ
Vector2D GameObject::GetBoxSize()const
{
	return this->box_size;
}


