#pragma once

#define D_KEYCODE_MAX (256)

//���͐���N���X(�����o�͐ÓI�Ŏ擾����)
class InputControl
{

//��{�I�Ƀ����o�ϐ��̓v���C�x�[�g
private:

	//�L�[�̓��͏��
	static char now_key[D_KEYCODE_MAX];//���݂̓��͒l
	static char old_key[D_KEYCODE_MAX];//�ߋ��̓��͒l

	//�֐��̓p�u���b�N
public:
	static void Update();                //�X�V����

	//�L�[�̓��͏��
	static bool GetKey(int key_code);    //������Ă��邩�̔��菈��
	static bool GetKeyDown(int key_code);//�������u�Ԃ̔��菈��
	static bool GetKeyUp(int key_code);  //�������u�Ԃ̔��菈��


	//�O�����J�̕K�v���Ȃ���΃v���C�x�[�g
private:

	static bool CheckKeyCodeRange(int key_code);//�L�[�z��͈̓`�F�b�N

};
