#pragma once

#include"GameObject.h"

//�v���C���[�N���X
class Player :public GameObject
{
private:

public:

	//�R���X�g���N�^
	Player();

	//�f�X�g���N�^
	~Player();

	virtual void Initialize();//����������
	virtual void Update();//�X�V����
	virtual void Draw() const;//�`�揈��
	virtual void Finalize();//�I��������

private:
	virtual void Movement();//�ړ�

};






