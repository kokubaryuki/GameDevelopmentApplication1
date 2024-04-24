#pragma once

#include"../GameObject.h"
#include<vector>


//�v���C���[�N���X
class Player :public GameObject
{
private:
	Vector2D velocity;          //�����x
	std::vector<int>animation_image;
	int animation_state;
	int animation_count;

public:
	//�R���X�g���N�^
	Player();
	//�f�X�g���N�^
	virtual~Player();

	virtual void Initialize() override;   //����������
	virtual void Update() override;      //�X�V����
	virtual void Draw() const override;   //�`�揈��
	virtual void Finalize() override;     //�I��������

private:
	void Movement();//�ړ�����
	void AnimationControl();

};

