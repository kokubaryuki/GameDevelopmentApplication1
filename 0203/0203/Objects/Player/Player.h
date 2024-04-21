#pragma once

#include"../GameObject.h"


//�v���C���[�N���X
class Player :public GameObject
{
private:
	Vector2D velocity;          //�����x

public:
	//�R���X�g���N�^
	Player();

	//�f�X�g���N�^
	virtual~Player();

	virtual void Initialize();   //����������
	virtual void Update();       //�X�V����
	virtual void Draw() const;   //�`�揈��
	virtual void Finalize();     //�I��������

private:
	void Movement();//�ړ�����

};
