#include"player.h"
#include"../Utility/InputControl.h"
#include "DxLib.h"

//コンストラクタ
Player::Player()
{
}
//デストラクタ
Player::~Player()
{
}

//初期化処理
void Player::Initialize()
{
	location = Vector2D(320.0f, 240.0f);//プレイヤーの初期座標
	box_size = Vector2D(320.0f, 24.0f);//プレイヤーの初期面積
	color = GetColor(255, 0, 0);//プレイヤーの初期カラー
}

//更新処理
void Player::Update()
{
	Movement();
}

//描画処理
void Player::Draw()const
{
	Vector2D t1 = this->location - (this->box_size / 2.0f);
	Vector2D br = this->location + (this->box_size / 2.0f);

	DrawBoxAA(t1.x, t1.y, br.x, br.y, color, TRUE);
}

//終了時処理
void Player::Finalize()
{

}

//プレイヤー移動設定
void  Player::Movement()
{
	Vector2D direction = Vector2D(0.0f);

	if (InputControl::GetKey(KEY_INPUT_UP))
	{
		direction.y = -1.0f;
	}

	if (InputControl::GetKey(KEY_INPUT_DOWN))
	{
		direction.y = +1.0f;
	}

	if (InputControl::GetKey(KEY_INPUT_RIGHT))
	{
		direction.x = +1.0f;
	}

	if (InputControl::GetKey(KEY_INPUT_LEFT))
	{
		direction.x = -1.0f;
	}

	location += direction;
}









