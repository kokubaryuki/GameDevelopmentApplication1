#include"DxLib.h"
#include"Utility/InputControl.h"
#include"Objects/Player/Player.h"
#include"Utility/ResourceMabager.h"

//メイン関数(プログラム開始)
int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd
)
{
	//Windowモードで起動
	ChangeWindowMode(TRUE);

	//Windowサイズの設定
	SetGraphMode(640, 480, 32);

	//Dxライブラリの初期化
	if (DxLib_Init() == -1)
	{
		//エラー状態を通知する
		OutputDebugString("Dxライブラリが初期化できませんでした\n");
		return-1;
	}

	//描画処理を裏画面に設定
	SetDrawScreen(DX_SCREEN_BACK);

	//ローカル変数定義
	GameObject* object = nullptr;
	ResourceManager* rm = ResourceManager::GetInstance();

	try 
	{







	}



}