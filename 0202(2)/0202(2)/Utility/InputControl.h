#pragma once

#define D_KEYCODE_MAX (256)

class InputControl
{
private:

	//�L�[�̓��͏��
	static char now_key[D_KEYCODE_MAX];//���݂̓��͒l
	static char old_key[D_KEYCODE_MAX];//�ߋ��̓��͒l


public:
	static void Update();                //�X�V����

	//�L�[�̓��͏��
	static bool GetKey(int key_code);    //������Ă��邩�̔��菈��
	static bool GetKeyDown(int key_code);//�������u�Ԃ̔��菈��
	static bool GetKeyUp(int key_code);  //�������u�Ԃ̔��菈��


private:

	//�L�[�z��͈̓`�F�b�N
	static bool CheckKeyCodeRange(int key_code);

};