#include"Player.h"
#include"../../Utility/InputControl.h"
#include"../../Utility/UserTemplate.h"
#include"../../Utility/ResoruceManager.h"
#include"DxLib.h"


Player::Player() :
	velocity(0.0f),
	animation_data(),
	animation_count(0)
{

}

Player::~Player()
{

}

void Player::Initialize()
{
	//�����蔻��̒Z�`�̑傫����ݒ�
	box_size = Vector2D(32.0f);

	//�����ʒu��ݒ肷��
	location = Vector2D(320.0f, 240.0f);

	//�A�j���V�����摜��ǂݍ���
	ResourceManager* rm = ResourceManager::GetInstance();
	std::vector<int>tmp;
	tmp = rm->GetImages("Resource/Images/Tri-pilot/1.png");
	animation_data.push_back(tmp[0]);
	tmp = rm->GetImages("Resource/Images/Tri-pilot/2.png");
	animation_data.push_back(tmp[0]);

	//�����摜�̐ݒ�
	image = animation_data[0];
	//�A�j���[�V�����Ɋւ��ݒ�
	animation_count = 0;
}

void Player::Update()
{
	//�ړ�����
	Movement();
	//�A�j���[�V��������
	AnimationControl();
}

//�`�揈��
void Player::Draw()const
{
	//�e�N���X�ɏ����ꂽ�`�揈���̓��e�����s����
	__super::Draw();
}


//�I������
void Player::Finalize()
{
	//�A�j���V�����Ɏg�p�������I�z����J������
	animation_data.clear();
}

//�ړ�����
void Player::Movement()
{
	//���͏��̎擾
	InputControl* input = InputControl::GetInstance();

	//���͏��ɂ���āA������ύX����
	float direction = 0.0f;
	if (input->GetKey(KEY_INPUT_LEFT))
	{
		direction = -1.0f;
		flip_flag = TRUE;
	}
	else if (input->GetKey(KEY_INPUT_RIGHT))
	{
		direction = 1.0f;
		flip_flag = FALSE;
	}

	//�����ɂ���āA�ړ��ʂ̉����Z���s��
	if (direction != 0.0f)
	{
		float max_speed = Abs<float>((5.0f * 0.5f * direction));
		velocity.x += 0.5f * direction;
		velocity.x = Min<float>(Max<float>(velocity.x, -max_speed),
			max_speed);
	}

	else

	{
		if (velocity.x < -1e-6f)
		{
			float calc_speed = velocity.x + 0.1f;
			velocity.x = Min<float>(calc_speed, 0.0f);
		}

		else if (1e-6f < velocity.x)
		{
			float calc_speed = velocity.x - 0.1f;
			velocity.x = Max<float>(calc_speed, 0.0f);
		}
	}

	//��ʊO�ɍs���Ȃ��悤�ɂ��鐧������
	if (location.x < (box_size.x / 2.0f))
	{
		velocity.x = 0.0f;
		location.x = box_size.x / 2.0f;
	}

	else if ((640.0f - (box_size.x / 2.0f)) < location.x)
	{
		velocity.x = 0.0f;
		location.x = 640.0f - (box_size.x / 2.0f);
	}

	//�ʒu���W�������x�����炵�Ă�����
	location += velocity;
}

//�A�j���[�V��������
void Player::AnimationControl()
{
	//�J�E���g�̍X�V
	animation_count++;

	//30�t���[���ɓ��B������
	if (animation_count >= 30)
	{
		//�J�E���g��0�N���A����
		animation_count = 0;

		//�摜�̐ؑւ��s��
		if (image == animation_data[0])
		{
			image = animation_data[1];
		}
		else
		{
			image = animation_data[0];
		}
	}
}
