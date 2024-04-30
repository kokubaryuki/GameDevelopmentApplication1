#include"Scene.h"
#include"../Object/Player/Player.h"
#include"../Object/Enemy/Enemy.h"
#include"DxLib.h"

//�R���X�g���N�^
Scene::Scene() :objects()
{

}

//�f�X�g���N�^
Scene::~Scene()
{
	Finalize();
}

//����������
void Scene::Initialize()
{
	//�w�i�摜
	background_image = LoadGraph("Resource/Images/BackGround.png");

	if (background_image == -1)
	{
		throw("Resource/Images/BackGround.png������܂���\n");
	}


	//�v���C���[�𐶐�����
	CreateObject<Player>(Vector2D(350.0f, 50.0f));
	//�G�̈ʒu���
	CreateObject<Enemy>(Vector2D(400.0f, 400.0f));
}

//�X�V����
void Scene::Update()
{
	//�V�[���ɑ��݂���I�u�W�F�N�g�̍X�V����
	for (GameObject* obj : objects)
	{
		obj->Update();
	}
}


//�`�揈��
void Scene::Draw()const
{

	DrawGraph(0, 0, background_image, FALSE);

	//�V�[���ɑ��݂���I�u�W�F�N�g�̕`�揈��
	for (GameObject* obj : objects)
	{
		obj->Draw();
	}
}


//�I��������
void Scene::Finalize()
{
	//���I�z�񂪋�Ȃ珈�����I������
	if (objects.empty())
	{
		return;
	}
	//�e�I�u�W�F�N�g���폜����
	for (GameObject* obj : objects)
	{
		obj->Finalize();
		delete obj;
	}
	//���I�z��̉��
	objects.clear();
}