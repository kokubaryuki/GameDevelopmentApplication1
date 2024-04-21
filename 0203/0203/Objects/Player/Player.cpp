#include"Player.h"
#include"../../Utility/InputControl.h"
#include"../../Utility/UserTemplate.h"
#include"DxLib.h"

//コンストラクタ
Player::Player() :velocity(0.0f)
{
	//velocity＝速度
}


//デストラクタ
Player::~Player()
{

}


//初期化処理
void Player::Initialize()
{
	color = GetColor(255, 255, 255);
	box_size = Vector2D(32.0f);
	location = Vector2D(320.0f, 240.0f);
}


//更新処理
void Player::Update()
{
	Movement();//移動処理
}



//描画処理
void Player::Draw() const
{
	Vector2D upper_left = location - (box_size / 2.0f);
	Vector2D lower_right = location + (box_size / 2.0f);

	DrawBoxAA(upper_left.x, upper_left.y, lower_right.x, lower_right.y, color, TRUE);
}

//終了時処理
void Player::Finalize()
{

}


//移動処理
void Player::Movement()

{//加速減速処理
	Vector2D direction = Vector2D(0.0f);

	//左方向に移動
		if (InputControl::GetKey(KEY_INPUT_LEFT))
		{
			// 進行方向を設定
			direction.x = -0.5f;
			// 移動速度の最大値
			float max_speed = Abs<float>((5.0f * direction.x));
			// 加速度を進行方向分加算する
			velocity.x += direction.x;
			// 加速度の値が// 加速度の値が減速していく
			velocity.x = Min<float>(MAX<float>(velocity.x, -max_speed), max_speed);
		}

		//右方向に移動
		else if(InputControl::GetKey(KEY_INPUT_RIGHT))
		{
			// 進行方向を設定
			direction.x = 0.5f;
			// 移動速度の最大値
			float max_speed = Abs<float>((5.0f * direction.x));
			// 加速度を進行方向分加算する
			velocity.x += direction.x;
			// 加速度の値が減速していく
			velocity.x = Min<float>(MAX<float>(velocity.x, -max_speed),max_speed);

		}

		//上とは逆(だんだん減速していく)
		else
		{
			if (velocity.x > 1e-6f)
			{
				float calc_speed = velocity.x - 0.1f;
				velocity.x = Min<float>(MAX<float>(calc_speed, 0.0f), velocity.x);
			}

			else if (velocity.x < -1e-6f)
			{
				float calc_speed = velocity.x + 0.1f;
				velocity.x = Min<float>(MAX<float>(calc_speed, velocity.x), 0.0f);
			}

		}


		if (location.x < (box_size.x / 2.0f))
		{
			velocity.x = 0.0f;
			location.x = box_size.x / 2.0f;
		}
		else if(location.x>(640.0f-box_size.x/2.0f))
		{
			velocity.x = 0.0f;
			location.x = 640.0f - box_size.x / 2.0f;
		}


		location += velocity;
}
















