#include"InputControl.h"
#include"DxLib.h"

//�ÓI�����o�ϐ���`
InputControl* InputControl::instance = nullptr;  //�N���X�̃C���X�^���X�̃|�C���^

//���͐���N���X�̃C���X�^���X�擾���鏈��
InputControl* InputControl::GetInstance()
{
	//�C���X�^���X��������΁A��������
	if (instance == nullptr)
	{
		instance = new InputControl();
	}

	//�������g�̃|�C���^��ԋp����
	return instance;
}

//���͐���N���X�̃C���X�^���X�폜���鏈��
void InputControl::DeleteInstance()
{
	//�C���X�^���X�����݂��Ă��Ă���΁A�폜����
	if (instance != nullptr)
	{
		delete instance;
		instance = nullptr;
	}
}

void InputControl::Update()
{
	//�O����͒l�̍X�V
	memcpy(old_key, now_key, (sizeof(char) * D_KEYCODE_MAX));

	//���ݓ��͒l�̍X�V
	GetHitKeyStateAll(now_key);

	//XInput�R���g���[���[�̓��͒l���擾����
	XINPUT_STATE input_state = {};
	GetJoypadXInputState(DX_INPUT_PAD1, &input_state);

	//�{�^�����͒l�̍X�V
	for (int i = 0; i < 16; i++)
	{
		old_button[i] = now_button[i];
		now_button[i] = input_state.Buttons[i];
	}

	// �g���K�[���͒l�̍X�V
	trigger[0] = (float)input_state.LeftTrigger / (float)UCHAR_MAX;
	trigger[1] = (float)input_state.RightTrigger / (float)UCHAR_MAX;


	// �X�e�B�b�N���͒l�̍X�V
	
	//���X�e�B�b�N���͒l�̍X�V�i-1.0f�`1.0f�ɔ͈͂𐧌�����)
	if (fabs((double)input_state.ThumbLX) > DEEDZOON)
	{
		stick[0].x = (float)input_state.ThumbLX / (float)SHRT_MAX;
	}

	else
	{
		//stick[0].x = -((float)input_state.ThumbLX / (float)SHRT_MIN);
		stick[0].x = 0.0f;
	}


	if (fabs((double)input_state.ThumbLY) > DEEDZOON)
	{
		stick[0].y = -(float)input_state.ThumbLY / (float)SHRT_MAX;
	}

	else
	{
		//stick[0].y = ((float)input_state.ThumbLY / (float)SHRT_MIN);
		stick[0].y = 0.0f;
	}



	//�E�X�e�B�b�N���͒l�̍X�V(-1.0f�`1.0f�ɔ͈͂𐧌�����j
	if (input_state.ThumbRX > 0.0f)
	{
		stick[1].x = (float)input_state.ThumbRX / (float)SHRT_MAX;
	}

	else
	{
		stick[1].x = -((float)input_state.ThumbRX / (float)SHRT_MIN);
	}

	if (input_state.ThumbRY > 0.0f)
	{
		stick[1].y = (float)input_state.ThumbRY / (float)SHRT_MAX;
	}

	else
	{
		stick[1].y = -((float)input_state.ThumbRY / (float)SHRT_MIN);
	}

}


/*************************************************
*�L�[�{�[�h
*************************************************/

//�L�[��������Ă��邩�m�F���鏈��
bool InputControl::GetKey(int key_code)const
{
	return(CheckkeyCodRange(key_code) && (now_key[key_code] == TRUE &&
		old_key[key_code] == TRUE));
}

//�L�[�������ꂽ�u�Ԃ��m�F���鏈��
bool InputControl::GetKeyDown(int key_code)const
{
	return(CheckkeyCodRange(key_code) && (now_key[key_code] == TRUE &&
		old_key[key_code] == FALSE));
}

//�L�[�𗣂����u��
bool InputControl::GetKeyUp(int key_code)const
{
	return(CheckkeyCodRange(key_code) && ((now_key[key_code] == FALSE) &&
		old_key[key_code] == TRUE));
}


//�L�[�R�[�h�͈͓̔����m�F���鏈��
bool InputControl::CheckkeyCodRange(int key_code)const
{
	return (0 <= key_code && key_code < D_KEYCODE_MAX);
}

/*************************************
*�R���g���[���[
*************************************/

//�{�^���擾:�����Ă��
bool InputControl::GetButton(int button)
{
	return CheckButtonRange(button) && (now_button[button] &&
		old_button[button]);
}

//�{�^�����������u��
bool InputControl::GetButtonDown(int button)
{
	return CheckButtonRange(button) && (now_button[button] &&
		!old_button[button]);
}

//�{�^���擾:�������u��
bool InputControl::GetButtonUp(int button)
{
	return CheckButtonRange(button) && (!now_button[button] &&
		old_button[button]);
}


//�{�^���z��͈̓`�F�b�N
bool InputControl::CheckButtonRange(int button)
{
	return(0 <= button && button < 16);
}
