#include"GameObject.h"
#include"../Utility/ResoruceManager.h"
#include"DxLib.h"


//�R���X�g���N�^
GameObject::GameObject() :
	location(0.0f),
	box_size(0.0f),
	image(NULL),
	flip_flag(FALSE)
{

}

//�f�X�g���N�^
GameObject::~GameObject()
{

}


//����������
void GameObject::Initialize()
{
	image = NULL;
	box_size = Vector2D(32.0f);
	location = box_size;
}

//�X�V����
void GameObject::Update()
{

}

//�`�揈��
void GameObject::Draw()const
{
	//�����o�̏�����ɉ摜��`�悷��
	DrawRotaGraphF(location.x, location.y, 1.0, 0.0, image, TRUE, flip_flag);

	//�����蔻��̒Z�`����`�悷��
	Vector2D upper_left = location - (box_size / 2.0f);
	Vector2D lower_right = location + (box_size / 2.0f);
	DrawBoxAA(upper_left.x, upper_left.y, lower_right.x, lower_right.y, GetColor(255, 0, 0), FALSE);
}

//�I��������
void GameObject::Finalize()
{

}

//�ʒu���W�̎擾����
Vector2D GameObject::GetLocation() const
{
	return this->location;
}

//�Z�`�̑傫�����擾����
Vector2D GameObject::GetBoxSize() const
{
	return this->box_size;
}

//�ʒu���̐ݒ�
void GameObject::SetLocation(const Vector2D& location)
{
	this->location = location;
}




















