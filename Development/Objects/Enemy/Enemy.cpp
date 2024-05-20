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

	box_size = Vector2D(0.0f, 490.0f);//�{�b�N�X�̈ʒu�̐ݒ�

	//����������
	image = animation[0];

	//�������i�s�����̐ݒ�
	direction = Vector2D(1.0f, -0.5f);

}


//�X�V����
void Enemy::Update()
{
//	//�G���E���獶�Ɉړ�����Ƃ��̑�����ݒ肷��Ƃ���
//	location.x += 1.0f;
//
//	//�G���[�ɍs�������A���p�ɖ߂�(�ړ����������Z�b�g)
//	if (location.x >= 960.0f)
//	{
//		location.x = 0.0f;
//	}

	//�ړ�����
	Movement();

	//�A�j���[�W��������
	AnimeControl();
}



//�`�揈��
void Enemy::Draw()const
{
	int flig_flag = FALSE;

	//�i�s�����ɂ���āA���]��Ԃ����肷��
	if (direction.x > 0.0f)
	{
		flig_flag = FALSE;
	}
	else
	{
		flig_flag = TRUE;
	}


	//������Ƀn�R�e�L�摜��`�悷��
	DrawRotaGraphF(location.x, location.y, 1.0, radian, image, TRUE, flip_flag);

	//�e�N���X�̕`�揈�����Ăяo��
	__super::Draw();
}


//�I��������
void Enemy::Finalize()
{
	//�g�p�����摜���������
	DeleteGraph(animation[0]);
	DeleteGraph(animation[1]);
}

//�����蔻��ʒm
void Enemy::OnHitCollision(GameObject* hit_object)
{
	//�����������̏���
	direction = 0.0f;
}

//�ړ�����
void Enemy::Movement()
{
	//��ʊO�ɒB������i�s�����𔽓]����
	if (((location.x + direction.x) < box_size.x) ||
		(640.0f - box_size.x) < (location.x + direction.x))
	{
		direction.x *= -1.0f;
	}

	if (((location.y + direction.y) < box_size.y) ||
		(640.0f - box_size.y) < (location.y + direction.y))
	{
		direction.y *= -1.0f;
	}
	//�i�s�����Ɍ������āA�ʒu���W��ύX����
	location += direction;

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



