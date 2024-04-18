#pragma once

#define D_KEYCODE_MAX (256)

class InputControl
{
private:

	//キーの入力情報
	static char now_key[D_KEYCODE_MAX];//現在の入力値
	static char old_key[D_KEYCODE_MAX];//過去の入力値


public:
	static void Update();                //更新処理

	//キーの入力情報
	static bool GetKey(int key_code);    //押されているかの判定処理
	static bool GetKeyDown(int key_code);//押した瞬間の判定処理
	static bool GetKeyUp(int key_code);  //離した瞬間の判定処理


private:

	//キー配列範囲チェック
	static bool CheckKeyCodeRange(int key_code);

};