#pragma once

#include"../Utility/Vector2D.h"

class GameObject
{
protected:
	unsigned int color;//�J���[
	Vector2D location;//�ʒu���
	Vector2D box_size;//�{�b�N�X�T�C�Y

public:
	//�R���X�g���N�^
	GameObject();

	//�f�X�g���N�^
	virtual~GameObject();


	virtual void Initialize();//����������
	virtual void Update();//�X�V����
	virtual void Draw()const;//�`�揈��
	virtual void Finalize();//�I��������

public:
	void SetLocation(Vector2D location);//�ʒu���
	Vector2D GetLocation()const;
	Vector2D GetBoxSize()const;

};









