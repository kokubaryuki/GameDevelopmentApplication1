#include"DxLib.h"
#include"Utility/ResourceManager.h"
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
		return-1;
	}
	ResourceManager* resource_manager = GetResourceManager();
	GameObject* object = new Player();

	
		//描画先を裏画面から開始できるようにする
		SetDrawScreen(DX_SCREEN_BACK);

	try
	{
		object->Initialize();

		while (ProcessMessage()!=-1)
		{
			InputControl::Update();

			object->Update();

			ClearDrawScreen();

			object->Draw();

			ScreenFlip();

			if (InputControl::GetKeyUp(KEY_INPUT_ESCAPE))
			{
				break;
			}

		}
	}
	catch (std::string error_log)
	{
		OutputDebugString(error_log.c_str());
	}

	object->Finalize();
	delete object;

	resource_manager->DeleteImage();

	//DXライブラリーを終了する
	DxLib_End();

	//終了する
	return 0;


}















