#include"Player.h"
#include"../../Utility/InputControl.h"
#include"DxLib.h"

//�R���X�g���N�^
Player::Player() :animation_count(0), flip_flag(FALSE)
{
	animation[0] = NULL;
	animation[1] = NULL; 

}


//�f�X�g���N�^
Player::~Player()
{

}

//����������
void Player::Initialize()
{
	//�摜�̓Ǎ���
	animation[0] = LoadGraph("Resource/Images/Tri-pilot/1.png");
	animation[1] = LoadGraph("Resource/Images/Tri-pilot/2.png");
	//�G���[�`�F�b�N
	if (animation[0] == -1 || animation[1] == -1)
	{
		throw("�g���p�C���b�g�̉摜������܂���\n");
	}

	//�����̐ݒ�
	radian = 0.0f;

	//�傫���̐ݒ�
	scale =64.0f;

	//����������
	image = animation[0];


}


//�X�V����
void Player::Update()
{
	//�ړ�����
	Movement();

	//�A�j���[�W��������
	AnimeControl();
}



//�`�揈��
void Player::Draw()const
{
	//�v���C���[�摜�̕`��
	DrawRotaGraphF(location.x, location.y, 1.0, radian, image, TRUE, flip_flag);

	//�f�o�b�N�p
#ifdef _DEBUG

		//�����蔻��̉���
		Vector2D ul = location - (scale / 2.0f);
	    Vector2D br = location + (scale / 2.0f);

		DrawBoxAA(ul.x,ul.y,br.x, br.y,GetColor(255, 0, 0), FALSE);

#endif
}


//�I��������
void Player::Finalize()
{
	//�g�p�����摜���������
	DeleteGraph(animation[0]);
	DeleteGraph(animation[1]);
}


//�����蔻��ʒm����
void Player::OnHitCollision(GameObject* hit_object)
{
	//�����������̏���
}




//�ړ�����
void Player::Movement()
{
	//�ړ��̑���
	Vector2D velocity = 0.0f;

	//���E�ړ�
	if (InputControl::GetKey(KEY_INPUT_LEFT))
	{
		velocity.x += -5.0f;
		flip_flag = TRUE;
	}

	else if(InputControl::GetKey(KEY_INPUT_RIGHT))
	{
		velocity.x += 5.0f;
		flip_flag = FALSE;
	}


	//�㉺�ړ�
	if (InputControl::GetKey(KEY_INPUT_UP))
	{
		velocity.y += -5.0f;
		flip_flag = TRUE;
	}

	else if (InputControl::GetKey(KEY_INPUT_DOWN))
	{
		velocity.y += 5.0f;
		flip_flag = FALSE;
	}


	else
	{
		velocity.x == 0.0f;
	}

	//���݂̈ʒu���W�ɑ��������Z����
	location += velocity;
}




//�A�j���[�V��������
void Player::AnimeControl()
{
	//�t���[���J�E���g�����Z����
	animation_count++;

	//60�t���[���ڂɒB������
	if (animation_count >= 60)
	{
		//�J�E���g�̃��Z�b�g
		animation_count = 0;

		//�摜�̐؂�ւ�
		if(image==animation[0])
		{
			image = animation[1];
		}
		else
		{
			image = animation[0];
		}
	}

}



