#include"GameObject.h"
#include"DxLib.h"

//�R���X�g���N�^
GameObject::GameObject() :color(0x0), location(0.0f), box_size(0.0f)
{
	//�J���[�A�ʒu���A�{�b�N�X�T�C�Y�̏�����
}

//�f�X�g���N�^
GameObject::~GameObject()
{

}

//����������
void GameObject::Initialize()
{
	color = GetColor(255, 0, 0);//�F��ԐF�ɂ���
	box_size = Vector2D(100.0f);//�{�b�N�X�̃T�C�Y��ݒ肷��
	location = box_size;
}


//�X�V����
void GameObject::Update()
{
	location.x += 1.0f;

	if (location.x >= 640.0f)
	{
		location.x = 0.0f;
	}
}


//�`�揈��
void GameObject::Draw() const
{
	Vector2D upper_left = location - (box_size / 2.0f);
	Vector2D lower_right = location +(box_size / 2.0f);

	DrawBoxAA(upper_left.x, upper_left.y, lower_right.x, lower_right.y, color,
		TRUE);
}


//�I��������
void GameObject::Finalize()
{

}



//�ʒu����ݒ肷��
void GameObject::SetLocation(Vector2D location)
{
	this->location = location;

}

//�ʒu�����擾����
Vector2D GameObject::GetLocation()const
{
	return  this->location;

}

//�{�b�N�X�̃T�C�Y���擾����
Vector2D GameObject::GetBoxSize()const
{
	return  this->box_size;

}











