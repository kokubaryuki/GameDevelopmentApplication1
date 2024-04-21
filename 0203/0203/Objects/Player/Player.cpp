#include"Player.h"
#include"../../Utility/InputControl.h"
#include"../../Utility/UserTemplate.h"
#include"DxLib.h"

//�R���X�g���N�^
Player::Player() :velocity(0.0f)
{
	//velocity�����x
}


//�f�X�g���N�^
Player::~Player()
{

}


//����������
void Player::Initialize()
{
	color = GetColor(255, 255, 255);
	box_size = Vector2D(32.0f);
	location = Vector2D(320.0f, 240.0f);
}


//�X�V����
void Player::Update()
{
	Movement();//�ړ�����
}



//�`�揈��
void Player::Draw() const
{
	Vector2D upper_left = location - (box_size / 2.0f);
	Vector2D lower_right = location + (box_size / 2.0f);

	DrawBoxAA(upper_left.x, upper_left.y, lower_right.x, lower_right.y, color, TRUE);
}

//�I��������
void Player::Finalize()
{

}


//�ړ�����
void Player::Movement()

{//������������
	Vector2D direction = Vector2D(0.0f);

	//�������Ɉړ�
		if (InputControl::GetKey(KEY_INPUT_LEFT))
		{
			// �i�s������ݒ�
			direction.x = -0.5f;
			// �ړ����x�̍ő�l
			float max_speed = Abs<float>((5.0f * direction.x));
			// �����x��i�s���������Z����
			velocity.x += direction.x;
			// �����x�̒l��// �����x�̒l���������Ă���
			velocity.x = Min<float>(MAX<float>(velocity.x, -max_speed), max_speed);
		}

		//�E�����Ɉړ�
		else if(InputControl::GetKey(KEY_INPUT_RIGHT))
		{
			// �i�s������ݒ�
			direction.x = 0.5f;
			// �ړ����x�̍ő�l
			float max_speed = Abs<float>((5.0f * direction.x));
			// �����x��i�s���������Z����
			velocity.x += direction.x;
			// �����x�̒l���������Ă���
			velocity.x = Min<float>(MAX<float>(velocity.x, -max_speed),max_speed);

		}

		//��Ƃ͋t(���񂾂񌸑����Ă���)
		else
		{
			if (velocity.x > 1e-6f)
			{
				float calc_speed = velocity.x - 0.1f;
				velocity.x = Min<float>(MAX<float>(calc_speed, 0.0f), velocity.x);
			}

			else if (velocity.x < -1e-6f)
			{
				float calc_speed = velocity.x + 0.1f;
				velocity.x = Min<float>(MAX<float>(calc_speed, velocity.x), 0.0f);
			}

		}


		if (location.x < (box_size.x / 2.0f))
		{
			velocity.x = 0.0f;
			location.x = box_size.x / 2.0f;
		}
		else if(location.x>(640.0f-box_size.x/2.0f))
		{
			velocity.x = 0.0f;
			location.x = 640.0f - box_size.x / 2.0f;
		}


		location += velocity;
}
















