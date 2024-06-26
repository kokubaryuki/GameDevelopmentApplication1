#pragma once

#define D_KEYCODE_MAX (256)

//入力制御クラス(メンバは静的で取得する)
class InputControl
{

//基本的にメンバ変数はプライベート
private:

	//キーの入力情報
	static char now_key[D_KEYCODE_MAX];//現在の入力値
	static char old_key[D_KEYCODE_MAX];//過去の入力値

	//関数はパブリック
public:
	static void Update();                //更新処理

	//キーの入力情報
	static bool GetKey(int key_code);    //押されているかの判定処理
	static bool GetKeyDown(int key_code);//押した瞬間の判定処理
	static bool GetKeyUp(int key_code);  //離した瞬間の判定処理


	//外部公開の必要がなければプライベート
private:

	static bool CheckKeyCodeRange(int key_code);//キー配列範囲チェック

};
