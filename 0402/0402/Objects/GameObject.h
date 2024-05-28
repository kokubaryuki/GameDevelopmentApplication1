#pragma once


#include "../Utility/Vector2D.h"

//�Q�[���I�u�W�F�N�g�N���X�i��ʂɏo�Ă���I�u�W�F�N�g�̐e�N���X�j

class GameObject
{
protected:
	Vector2D location;  //�ʒu���W���
	Vector2D box_size;  //�Z�`�̑傫��
	int image;         //�`�悷��摜�f�[�^
	int flip_flag;     //�摜���]�O���t

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

	void SetLocation(const Vector2D& location);



};