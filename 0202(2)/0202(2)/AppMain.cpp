#include"DxLib.h"
#include"Utility/InputControl.h"
#include"Objects/GameObject.h"
#include"Objects/Player.h"



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

	//�`���𗠉�ʂ���J�n�ł���悤�ɂ���
	SetDrawScreen(DX_SCREEN_BACK);

	//�I�u�W�F�N�g����
	GameObject* object1 = new GameObject();
	GameObject* object2 = new Player();

	//�I�u�W�F�N�g�̍X�V����
	object1->Initialize();
	object2->Initialize();

	//ESC�������ƏI��
	while (ProcessMessage()!=-1&& InputControl::GetKeyUp(KEY_INPUT_ESCAPE)==false)
	{
		//�X�V����
		InputControl::Update();

		object1->Update();
		object2->Update();

		//��ʂ̏���������
		ClearDrawScreen();

		object1->Draw();
		object2->Draw();

		//����ʂ̏���\��ʂɔ��f����
		ScreenFlip();
	}
	//�Q�[���I�u�W�F�N�g���폜����
	delete object1;
    //�v���C���[���폜����
	delete object2;

	//DX���C�u�����[���I������
	DxLib_End();

	//�I������
	return 0;

		
}















