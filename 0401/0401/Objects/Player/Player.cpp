#include"Player.h"
#include"../../Utility/InputControl.h"
#include"../../Utility/UserTemplate.h"
#include"../../Utility/ResourceMabager.h"
#include"DxLib.h"


Player::Player() :
	velocity(0.0f),
	animation_data(),
	animation_count(0)
{

}

Player::~Player()
{

}

void Player::Initialize()
{
	//当たり判定の短形の大きさを設定
	box_size = Vector2D(32.0f);

	//初期位置を設定する
	location = Vector2D(320.0f, 240.0f);

	//アニメション画像を読み込む
	ResourceManager* rm = ResourceManager::GetInstance();
	std::vector<int>tmp;
	tmp = rm->GetImages("Resource/Images/Tri-pilot/1.png");
	animation_data.push_back(tmp[0]);
	tmp = rm->GetImages("Resource/Images/Tri-pilot/2.png");
	animation_data.push_back(tmp[0]);
	//初期画像の設定

	image = animation_data[0];
    //アニメーションに関わる設定
	animation_count = 0;

}

void Player::Update()
{
	//移動処理
	Movement();
	//アニメーション制御
	AnimationControl();
}

//描画処理
void Player::Draw()const
{
	//親クラスに書かれた描画処理の内容を実行する
	__super::Draw();
}


//終了処理
void Player::Finalize()
{
	//アニメションに使用した動的配列を開放する
	animation_data.clear();
}

//移動処理
void Player::Movement()
{
	//入力情報の取得
	InputControl* input = InputControl::GetInstance();

	//入力情報によって、向きを変更する
	float direction = 0.0f;
	if (input->GetKey(KEY_INPUT_LEFT))
	{
		direction = -1.0f;
		flip_flag = TRUE;
	}
	else if (input->GetKey(KEY_INPUT_RIGHT))
	{
		direction = 1.0f;
		flip_flag = FALSE;
	}

	//入力情報によって、向きを変更する(コントローラー十字キー)
	if (input->GetButton(XINPUT_BUTTON_DPAD_LEFT))
	{
		direction = -1.0f;
		flip_flag = TRUE;
	}
	else if (input->GetButton(XINPUT_BUTTON_DPAD_RIGHT))
	{
		direction = 1.0f;
		flip_flag = FALSE;
	}

	//入力情報によって、向きを変更する(コントローラーRB,LB)
	if (input->GetButton(XINPUT_BUTTON_LEFT_SHOULDER))
	{
		direction = -1.0f;
		flip_flag = TRUE;
	}
	else if (input->GetButton(XINPUT_BUTTON_RIGHT_SHOULDER))
	{
		direction = 1.0f;
		flip_flag = FALSE;
	}

	//向きによって、移動量の加減算を行う
	if (direction != 0.0f)
	{
		float max_speed = Abs<float>((5.0f * 0.5f * direction));
		velocity.x += 0.5f * direction;
		velocity.x = Min<float>(Max<float>(velocity.x, -max_speed),
			max_speed);
	}

	else

	{
		if (velocity.x < -1e-6f)
		{
			float calc_speed = velocity.x + 0.1f;
			velocity.x = Min<float>(calc_speed, 0.0f);
		}

		else if (1e-6f < velocity.x)
		{
			float calc_speed = velocity.x - 0.1f;
			velocity.x = Max<float>(calc_speed, 0.0f);
		}
	}

//画面外に行かないようにする制限する
	if (location.x <(box_size.x / 2.0f))
	{
		velocity.x = 0.0f;
		location.x = box_size.x / 2.0f;
	}

	else if ((640.0f - (box_size.x / 2.0f)) < location.x)
	{
		velocity.x = 0.0f;
		location.x = 640.0f - (box_size.x / 2.0f);
	}

	//位置座標を加速度分ずらしてあげる
	location += velocity;
}

//アニメーション制御
void Player::AnimationControl()
{
	//カウントの更新
	animation_count++;

	//30フレームに到達したら
	if (animation_count >= 30)
	{
		//カウントを0クリアする
		animation_count=0;
		
		//画像の切替を行う
		if (image == animation_data[0])
		{
			image = animation_data[1];
		}
		else
		{
			image = animation_data[0];
		}
	}
}
