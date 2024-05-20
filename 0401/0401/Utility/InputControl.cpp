#include"InputControl.h"
#include"DxLib.h"

//静的メンバ変数定義
InputControl* InputControl::instance = nullptr;  //クラスのインスタンスのポインタ

//入力制御クラスのインスタンス取得する処理
InputControl* InputControl::GetInstance()
{
	//インスタンスが無ければ、生成する
	if (instance == nullptr)
	{
		instance = new InputControl();
	}

	//自分自身のポインタを返却する
	return instance;
}

//入力制御クラスのインスタンス削除する処理
void InputControl::DeleteInstance()
{
	//インスタンスが存在していていれば、削除する
	if (instance != nullptr)
	{
		delete instance;
		instance = nullptr;
	}
}

void InputControl::Update()
{
	//前回入力値の更新
	memcpy(old_key, now_key, (sizeof(char) * D_KEYCODE_MAX));

	//現在入力値の更新
	GetHitKeyStateAll(now_key);

	//XInputコントローラーの入力値を取得する
	XINPUT_STATE input_state = {};
	GetJoypadXInputState(DX_INPUT_PAD1, &input_state);

	//ボタン入力値の更新
	for (int i = 0; i < 16; i++)
	{
		old_button[i] = now_button[i];
		now_button[i] = input_state.Buttons[i];
	}

	// トリガー入力値の更新
	trigger[0] = (float)input_state.LeftTrigger / (float)UCHAR_MAX;
	trigger[1] = (float)input_state.RightTrigger / (float)UCHAR_MAX;


	// スティック入力値の更新
	
	//左スティック入力値の更新（-1.0f～1.0fに範囲を制限する)
	if (fabs((double)input_state.ThumbLX) > DEEDZOON)
	{
		stick[0].x = (float)input_state.ThumbLX / (float)SHRT_MAX;
	}

	else
	{
		//stick[0].x = -((float)input_state.ThumbLX / (float)SHRT_MIN);
		stick[0].x = 0.0f;
	}


	if (fabs((double)input_state.ThumbLY) > DEEDZOON)
	{
		stick[0].y = -(float)input_state.ThumbLY / (float)SHRT_MAX;
	}

	else
	{
		//stick[0].y = ((float)input_state.ThumbLY / (float)SHRT_MIN);
		stick[0].y = 0.0f;
	}



	//右スティック入力値の更新(-1.0f～1.0fに範囲を制限する）
	if (input_state.ThumbRX > 0.0f)
	{
		stick[1].x = (float)input_state.ThumbRX / (float)SHRT_MAX;
	}

	else
	{
		stick[1].x = -((float)input_state.ThumbRX / (float)SHRT_MIN);
	}

	if (input_state.ThumbRY > 0.0f)
	{
		stick[1].y = (float)input_state.ThumbRY / (float)SHRT_MAX;
	}

	else
	{
		stick[1].y = -((float)input_state.ThumbRY / (float)SHRT_MIN);
	}

}


/*************************************************
*キーボード
*************************************************/

//キーが押されているか確認する処理
bool InputControl::GetKey(int key_code)const
{
	return(CheckkeyCodRange(key_code) && (now_key[key_code] == TRUE &&
		old_key[key_code] == TRUE));
}

//キーが押された瞬間か確認する処理
bool InputControl::GetKeyDown(int key_code)const
{
	return(CheckkeyCodRange(key_code) && (now_key[key_code] == TRUE &&
		old_key[key_code] == FALSE));
}

//キーを離した瞬間
bool InputControl::GetKeyUp(int key_code)const
{
	return(CheckkeyCodRange(key_code) && ((now_key[key_code] == FALSE) &&
		old_key[key_code] == TRUE));
}


//キーコードの範囲内か確認する処理
bool InputControl::CheckkeyCodRange(int key_code)const
{
	return (0 <= key_code && key_code < D_KEYCODE_MAX);
}

/*************************************
*コントローラー
*************************************/

//ボタン取得:押してる間
bool InputControl::GetButton(int button)
{
	return CheckButtonRange(button) && (now_button[button] &&
		old_button[button]);
}

//ボタンを押した瞬間
bool InputControl::GetButtonDown(int button)
{
	return CheckButtonRange(button) && (now_button[button] &&
		!old_button[button]);
}

//ボタン取得:離した瞬間
bool InputControl::GetButtonUp(int button)
{
	return CheckButtonRange(button) && (!now_button[button] &&
		old_button[button]);
}


//ボタン配列範囲チェック
bool InputControl::CheckButtonRange(int button)
{
	return(0 <= button && button < 16);
}
