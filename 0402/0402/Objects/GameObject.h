#pragma once


#include "../0402/Vector2D.h"

//�Q�[���I�u�W�F�N�g�N���X�i��ʂɏo�Ă���I�u�W�F�N�g�̐e�N���X�j

class GameObject
{
	Vector2D location;
	Vettor2D box_size;
	int image;
	int flip_flag;

public:
	GameObject();
	virtual~GameObject();

	//����������
	virtual void Initialize();
	//�X�V����
	virtual void Update();
	//�`�揈��
	virtual void Draw()const;
	//�I������
	virtual void Finalize();

public:
	Vector2D GetLocation() const;
	Vector2D GetBoxSize() const;

	void SetLocation(const Vector2D\& location);



};