#include"Enemy.h"
#include"../../Utility/InputControl.h"
#include"DxLib.h"
#include"../../Utility/Vector2D.h"

//�R���X�g���N�^
Enemy::Enemy() :animation_count(0), flip_flag(FALSE)
{
	animation[0] = NULL;
	animation[1] = NULL;

}

//�f�X�g���N�^
Enemy::~Enemy()
{

}

//����������
void Enemy::Initialize()
{
	//�摜�̓Ǎ���
	animation[0] = LoadGraph("Resource/Images/BoxEnemy/1.png");
	animation[1] = LoadGraph("Resource/Images/BoxEnemy/2.png");
	//�G���[�`�F�b�N
	if (animation[0] == -1 || animation[1] == -1)
	{
		throw("�n�R�e�L�̉摜������܂���\n");
	}

	//�����̐ݒ�
	radian = 0.0f;
	box_size = Vector2D(0.0f,490.0f);//�{�b�N�X�̈ʒu�̐ݒ�
	location = box_size;

	//����������
	image = animation[0];
}


//�X�V����
void Enemy::Update()
{
	//�G���E���獶�Ɉړ�����Ƃ��̑�����ݒ肷��Ƃ���
	location.x += 1.0f;

	//�G���[�ɍs�������A���p�ɖ߂�(�ړ����������Z�b�g)
	if (location.x >= 960.0f)
	{
		location.x = 0.0f;
	}
	
	//�A�j���[�W��������
	AnimeControl();
}



//�`�揈��
void Enemy::Draw()const
{
	//�v���C���[�摜�̕`��
	DrawRotaGraphF(location.x, location.y, 1.0, radian, image, TRUE, flip_flag);

	//�f�o�b�N�p
#ifdef _DEBUG

		//�����蔻��̉���
	Vector2D ul = location - (scale / 2.0f);
	Vector2D br = location + (scale / 2.0f);

	DrawBoxAA(ul.x, ul.y, br.x, br.y, GetColor(255, 0, 0), FALSE);

#endif
}


//�I��������
void Enemy::Finalize()
{
	//�g�p�����摜���������
	DeleteGraph(animation[0]);
	DeleteGraph(animation[1]);
}



//�ʒu����ݒ肷��
void Enemy::SetLocation(Vector2D location)
{
	this->location = location;
}

//�ʒu�����擾����
Vector2D Enemy::GetLocation()const
{
	return  this->location;

}

//�{�b�N�X�̃T�C�Y���擾����
Vector2D Enemy::GetBoxSize()const
{
	return  this->box_size;

}

//�A�j���[�V��������
void Enemy::AnimeControl()
{
	//�t���[���J�E���g�����Z����
	animation_count++;

	//60�t���[����1�b

	//60�t���[���ڂɒB������
	if (animation_count >= 2)
	{
		//�J�E���g�̃��Z�b�g
		animation_count = 0;

		//�摜�̐؂�ւ�
		if (image == animation[0])
		{
			image = animation[1];
		}
		else
		{
			image = animation[0];
		}
	}

}



