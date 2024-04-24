#include"DxLib.h"
#include"Utility/ResourceManager.h"
#include"Utility/InputControl.h"
#include"Objects/Player/Player.h"



//���C���֐�(�v���O�����J�n)
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	//Window���[�h�ŋN��
	ChangeWindowMode(TRUE);

	
	//Dx���C�u�����[������
	if (DxLib_Init() == -1)
	{

		//�ُ��ʒm
		return-1;
	}
	ResourceManager* resource_manager = GetResourceManager();
	GameObject* object = new Player();

	
		//�`���𗠉�ʂ���J�n�ł���悤�ɂ���
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

	//DX���C�u�����[���I������
	DxLib_End();

	//�I������
	return 0;


}















