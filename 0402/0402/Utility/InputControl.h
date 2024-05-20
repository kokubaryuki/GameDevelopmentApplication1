#pragma once

//�}�N����`
#define D_KEYCODE_MAX (256)//�L�[�R�[�h�ő吔

//���͐���N���X
class Inputcontrol
{
private:
//���N���X�̃|�C���^�i�A�h���X�̐悎�C���X�^���X�𐶐�����j
	static Inputcontrol* instance;

	//�L�[�{�[�h���͒l
	char now_key[D_KEYCODE_MAX]; //���݂̓��͒l
	char old_key[D_KEYCODE_MAX]; //�O��̓��͒l

private:
	//�R���X�g���N�^��private�ɂ��邱�ƂŁA
	//���N���X�̃����o�֐��ł����C���X�^���X�𐶐��ł��Ȃ��悤�ɂ���
	Inputcontrol() = default;

	//�R�s�[�K�[�h
	//�N���X�O�ŃC���X�^���X�𐶐����ēn�����Ƃ��ł��Ȃ��悤�ɂ���
	Inputcontrol(Inputcontrol& v) = delete;
	Inputcontrol& operator=(const Inputcontrol& v) = delete;
	//~�R�s�[�K�[�h

public:
	~Inputcontrol() = default;

public:
	//�C���X�^���X�擾���鏈��
	static Inputcontrol* GetInstance();
	//�C���X�^���X�폜���鏈��
	static void Deleteinstance();

public:
	//�L�[���͍X�V����
	void Update();

	//�L�[���͏�Ԃ��擾����
	bool GetKey(int key_code)const;      //�����Ă����
	bool GetKeyDown(int key_code) const; //�������u��
	bool GetKeyUp(int key_code) const;   //�������u��

private:
	//�L�[���͈͂̔͂��m�F����
	bool CheckKeyCodeRange(int key_code) const;

};