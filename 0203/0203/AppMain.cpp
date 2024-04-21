#include"DxLib.h"
#include"Utility/InputControl.h"
#include"Objects/Player/Player.h"

//メイン関数(プログラム開始)
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine, _In_ int nShowCmd)


{
	//Windowモードで起動
	ChangeWindowMode(TRUE);

	//Dxライブラリー初期化
	if (DxLib_Init() == -1)
	{
		//異常を通知
		return -1;
	}

	//オブジェクト生成
	GameObject* objects[2] = { nullptr,nullptr };
	objects[0] = new GameObject();
	objects[1] = new Player();

	//オブジェクトの初期化処理
	for (int i = 0; i < 2; i++)
	{
		objects[i]->Initialize();
	}

	//描画先を裏画面から開始できるようにする
	SetDrawScreen(DX_SCREEN_BACK);

	//メインループ
	while (ProcessMessage() != -1)
	{

		//入力機能の更新
		InputControl::Update();

		//オブジェクトの更新処理
		for (int i = 0; i < 2; i++)
		{
			objects[i]->Update();
		}

		//画面の初期化
		ClearDrawScreen();
		

		//オブジェクトの描画処理
		for (int i = 0; i < 2; i++)
		{
			objects[i]->Draw();
		}

		//裏画面の情報を表画面に反映
		ScreenFlip();

		//ESCを押すと終了する
		if (InputControl::GetKeyUp(KEY_INPUT_ESCAPE))
		{
			//終了する
			break;
		}
	}

	//オブジェクトを削除する
	for (int i = 0; i < 2; i++)
	{
		objects[i]->Finalize();
		delete objects[i];

	}

	//Dxライブラリーを終了する
	DxLib_End();

	//終了する
	return 0;
}