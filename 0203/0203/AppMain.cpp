#include"DxLib.h"
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
		return -1;
	}

	//�I�u�W�F�N�g����
	GameObject* objects[2] = { nullptr,nullptr };
	objects[0] = new GameObject();
	objects[1] = new Player();

	//�I�u�W�F�N�g�̏���������
	for (int i = 0; i < 2; i++)
	{
		objects[i]->Initialize();
	}

	//�`���𗠉�ʂ���J�n�ł���悤�ɂ���
	SetDrawScreen(DX_SCREEN_BACK);

	//���C�����[�v
	while (ProcessMessage() != -1)
	{

		//���͋@�\�̍X�V
		InputControl::Update();

		//�I�u�W�F�N�g�̍X�V����
		for (int i = 0; i < 2; i++)
		{
			objects[i]->Update();
		}

		//��ʂ̏�����
		ClearDrawScreen();
		

		//�I�u�W�F�N�g�̕`�揈��
		for (int i = 0; i < 2; i++)
		{
			objects[i]->Draw();
		}

		//����ʂ̏���\��ʂɔ��f
		ScreenFlip();

		//ESC�������ƏI������
		if (InputControl::GetKeyUp(KEY_INPUT_ESCAPE))
		{
			//�I������
			break;
		}
	}

	//�I�u�W�F�N�g���폜����
	for (int i = 0; i < 2; i++)
	{
		objects[i]->Finalize();
		delete objects[i];

	}

	//Dx���C�u�����[���I������
	DxLib_End();

	//�I������
	return 0;
}