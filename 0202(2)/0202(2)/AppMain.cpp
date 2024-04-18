#include"DxLib.h"
#include"Utility/InputControl.h"
#include"Objects/GameObject.h"
#include"Objects/Player.h"



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
		return-1;
	}

	//描画先を裏画面から開始できるようにする
	SetDrawScreen(DX_SCREEN_BACK);

	//オブジェクト生成
	GameObject* object1 = new GameObject();
	GameObject* object2 = new Player();

	//オブジェクトの更新処理
	object1->Initialize();
	object2->Initialize();

	//ESCを押すと終了
	while (ProcessMessage()!=-1&& InputControl::GetKeyUp(KEY_INPUT_ESCAPE)==false)
	{
		//更新処理
		InputControl::Update();

		object1->Update();
		object2->Update();

		//画面の初期化処理
		ClearDrawScreen();

		object1->Draw();
		object2->Draw();

		//裏画面の情報を表画面に反映する
		ScreenFlip();
	}
	//ゲームオブジェクトを削除する
	delete object1;
    //プレイヤーを削除する
	delete object2;

	//DXライブラリーを終了する
	DxLib_End();

	//終了する
	return 0;

		
}















