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
	int result = 0;

	try 
	{
		//�v���C��[�I�u�W�F�N�g
		object=new Player();

		//�I�u�W�F�N�g�̏�����
		object->Initialize();

		//���C�����[�v
		while (ProcessMessage() != -1)
		{
			//���͏��̃C���X�^���X���擾
			InputControl* input = InputControl::GetInstance();
			//���͏��̍X�V
			input->Update();
			//�I�u�W�F�N�g�̍X�V����
			object->Update();
			//��ʂ̏�����
			ClearDrawScreen();

			//�I�u�W�F�N�g�̕`�揈��
			object->Draw();

			//����ʂ̓��e��\��ʂɔ��f
			ScreenFlip();

			//ESC�L�[�����͂��ꂽ��A���[�v���I������
			if (input->GetKeyUp(KEY_INPUT_ESCAPE))
			{
				break;
			}

		}
	}
	catch (std::string error_log)
	{
		//Log.txt�ɃG���[���e���o�͂���
		OutputDebugString(error_log.c_str());
		//�I����Ԃ��ُ�ɐݒ肷��
		result = -1;
	}

	//�I�u�W�F�N�g�̍폜
	if (object != nullptr)
	{
		object->Finalize();
		delete object;
		object = nullptr;
	}

	//���͋@�\�̃C���X�^���X���������傷��
	InputControl::DeleteInstance();

	//�ǂݍ��񂾉摜�̊J��
	rm->DeleteImages();

	//���\�[�X�Ǘ��̃C���X�^���X���폜����
	ResourceManager::DeleteInstance();

	//Dx���C�u�����̎g�p���I������
	DxLib_End();

	//�I����Ԃ̒l��ԋp����
	return result;


}