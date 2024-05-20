#include"InputControl.h"
#include"DxLib.h"

//静的メンバ変数定義
char InputControl::now_key[D_KEYCODE_MAX] = {};
char InputControl::old_key[D_KEYCODE_MAX] = {};


//更新処理
void InputControl::Update()

{  //過去の入力値を更新
	memcpy(old_key, now_key, (sizeof(char) * D_KEYCODE_MAX));

	//現在の入力値を更新
	GetHitKeyStateAll(now_key);
}
//キーを押し続けたか
bool InputControl::GetKey(int key_code)
{
	return CheckKeyCodeRange(key_code) && ((now_key[key_code] == TRUE) &&

		(old_key[key_code] == TRUE));
}

//キーを押した瞬間
bool InputControl::GetKeyDown(int key_code)
{
	return CheckKeyCodeRange(key_code) && ((now_key[key_code] == TRUE) &&
		(old_key[key_code] == FALSE));
}
//キーを離した瞬間
bool InputControl::GetKeyUp(int key_code)
{
	return CheckKeyCodeRange(key_code) && ((now_key[key_code] == FALSE) &&
		(old_key[key_code] == TRUE));
}

//キーコード範囲チェック
bool InputControl::CheckKeyCodeRange(int key_code)
{
	return(0 <= key_code && key_code < D_KEYCODE_MAX);
}




