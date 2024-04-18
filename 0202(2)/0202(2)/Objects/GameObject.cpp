#include"GameObject.h"
#include"DxLib.h"

//�R���X�g���N�^
GameObject::GameObject() : color(0x0), location(), box_size()//���������X�g
{

}

//�f�X�g���N�^
GameObject::~GameObject()
{

}

//����������
void GameObject::Initialize()
{
	location = Vector2D(32.0f, 24.0f);
	box_size = Vector2D(32.0f, 24.0f);
	color = GetColor(0, 255, 0);
}

void GameObject::Update()
{
	//�ǂ�ǂ�E���ɐi��
	location += 0.1f;
}

//�`�揈��
void GameObject::Draw()const
{
	Vector2D t1 = this->location - (box_size / 2.0f);
	Vector2D br = this->location + (box_size / 2.0f);

	DrawBoxAA(t1.x, t1.y, br.x, br.y, color, TRUE);
}

//�I��������
void GameObject::Finalize()
{

}


void GameObject::SetLocation(Vector2D location)
{
	this->location = location;
}

//�ʒu���
Vector2D GameObject::GetLocation()const
{
	return this->location;
}

//�{�b�N�X�̑傫��
Vector2D GameObject::GetBoxSize()const
{
	return this->box_size;
}


