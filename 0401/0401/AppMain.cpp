#include"DxLib.h"
#include"Utility/InputControl.h"
#include"Objects/Player/Player.h"
#include"Utility/ResourceMabager.h"

//���C���֐�(�v���O�����J�n)
int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd
)
{
	//Window���[�h�ŋN��
	ChangeWindowMode(TRUE);

	//Window�T�C�Y�̐ݒ�
	SetGraphMode(640, 480, 32);

	//Dx���C�u�����̏�����
	if (DxLib_Init() == -1)
	{
		//�G���[��Ԃ�ʒm����
		OutputDebugString("Dx���C�u�������������ł��܂���ł���\n");
		return-1;
	}

	//�`�揈���𗠉�ʂɐݒ�
	SetDrawScreen(DX_SCREEN_BACK);

	//���[�J���ϐ���`
	GameObject* object = nullptr;
	ResourceManager* rm = ResourceManager::GetInstance();

	try 
	{







	}



}