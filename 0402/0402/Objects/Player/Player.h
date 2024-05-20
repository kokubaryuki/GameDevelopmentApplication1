#pragma once

#include "../0402/GameObject.h"
#include<vector>

class Player :public GameObject
{
private:
	Vector2D velocity;//�����x
	std::vector<int>animation_data;//�A�j���[�V�����f�[�^
	int animation_const; //�A�j���[�V�����̎���

public:
	Player();
	virtual~Player();

	//����������
	virtual void Initialize() override;
	//�X�V����
	virtual void Update() override;
	//�`�揈��
	virtual void Draw()const override;
	//�I������
	virtual void Finalize() override;

private:
	//�ړ�����
	void Movement();
	//�A�j���[�V�����̐���
	void AnimationControl();


};

