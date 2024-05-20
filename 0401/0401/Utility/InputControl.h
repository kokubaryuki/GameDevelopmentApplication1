#pragma once

#include"Vector2D.h"
#include<math.h>

//コントローラーデッドゾーン
#define DEEDZOON 10000.0f
//マクロ定義
#define D_KEYCODE_MAX (256)//キーコード最大数

//入力制御クラス
class InputControl
{
private:

	//自クラスのポインタ（アドレスの先にインスタンスを生成する)
	static InputControl* instance;

	bool now_button[16];    //過去フレーム入力値
	bool old_button[16];    //過去フレーム入力値
	float    trigger[2];    //左右トリガー入力値
	Vector2D stick[2];      //左右スティック入力値
	
	//キーボード入力値
	char now_key[D_KEYCODE_MAX];//現在の入力値
	char old_key[D_KEYCODE_MAX];//過去の入力値

	

private:
	
	InputControl() = default;

	//コピーガード
	//自クラスのメンバ関数でしかインスタンスを生成できないようにする
	InputControl(InputControl& v) = delete;
	InputControl& operator=(const InputControl& v) = delete;
	//～コピーガード

public:
	~InputControl() = default;


public:
	//インスタンスを取得する処理
	static InputControl* GetInstance();
	//インスタンスを削除する処理
	static void DeleteInstance();


public:
	//キー入力更新処理
	void Update();



	//キー入力更新処理
	bool GetKey(int key_code)const;
	bool GetKeyDown(int key_code)const;
	bool GetKeyUp(int key_code)const;




	//ボタン入力取得処理
	bool GetButton(int button);    //押し続けている間
	bool GetButtonDown(int button);//押した瞬間
	bool GetButtonUp(int button);  //離した瞬間



private:
	//キー入力の範囲を確認する
	bool CheckkeyCodRange(int key_code)const;

	//ボタン配列範囲チェック
	bool CheckButtonRange(int button);
};
