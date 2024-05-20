#pragma once

#include"Vector2D.h"
#include<math.h>

//�R���g���[���[�f�b�h�]�[��
#define DEEDZOON 10000.0f
//�}�N����`
#define D_KEYCODE_MAX (256)//�L�[�R�[�h�ő吔

//���͐���N���X
class InputControl
{
private:

	//���N���X�̃|�C���^�i�A�h���X�̐�ɃC���X�^���X�𐶐�����)
	static InputControl* instance;

	bool now_button[16];    //�ߋ��t���[�����͒l
	bool old_button[16];    //�ߋ��t���[�����͒l
	float    trigger[2];    //���E�g���K�[���͒l
	Vector2D stick[2];      //���E�X�e�B�b�N���͒l
	
	//�L�[�{�[�h���͒l
	char now_key[D_KEYCODE_MAX];//���݂̓��͒l
	char old_key[D_KEYCODE_MAX];//�ߋ��̓��͒l

	

private:
	
	InputControl() = default;

	//�R�s�[�K�[�h
	//���N���X�̃����o�֐��ł����C���X�^���X�𐶐��ł��Ȃ��悤�ɂ���
	InputControl(InputControl& v) = delete;
	InputControl& operator=(const InputControl& v) = delete;
	//�`�R�s�[�K�[�h

public:
	~InputControl() = default;


public:
	//�C���X�^���X���擾���鏈��
	static InputControl* GetInstance();
	//�C���X�^���X���폜���鏈��
	static void DeleteInstance();


public:
	//�L�[���͍X�V����
	void Update();



	//�L�[���͍X�V����
	bool GetKey(int key_code)const;
	bool GetKeyDown(int key_code)const;
	bool GetKeyUp(int key_code)const;




	//�{�^�����͎擾����
	bool GetButton(int button);    //���������Ă����
	bool GetButtonDown(int button);//�������u��
	bool GetButtonUp(int button);  //�������u��



private:
	//�L�[���͈͂̔͂��m�F����
	bool CheckkeyCodRange(int key_code)const;

	//�{�^���z��͈̓`�F�b�N
	bool CheckButtonRange(int button);
};
