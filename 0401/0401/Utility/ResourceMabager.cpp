#include"ResourceMabager.h"
#include"DxLib.h"

//�ÓI�����o�ϐ���`
ResourceManager* ResourceManager::instance = nullptr;

ResourceManager* ResourceManager::GetInstance()
{
	//�C���X�^���X��������ΐ�������
	if (instance == nullptr)
	{
		instance = new ResourceManager();

	}

	return instance;

}
//���\�[�X�Ǘ��N���X�̃C���X�^���X�폜���鏈��
void ResourceManager::DeleteInstance()
{
	if (instance != nullptr)
	{
		delete instance;
		instance = nullptr;
	}
}

//�摜�擾����
const std::vector<int>& ResourceManager::GetImages(std::string file_path)
{
	//�R���e�i���ɉ摜���Ȃ���Ή摜��ǂݍ���
	if (image_container.count(file_path) == NULL)
	{
		//�摜��ǂݍ��ݏ���
		int handle = LoadGraph(file_path.c_str());
		//�G���[�`�F�b�N
		if (handle == -1)
		{
			throw(file_path + "�̉摜���ǂݍ��߂܂���ł���\n");
		}
		//�R���e�i���ɉ摜���i�[����
		image_container[file_path].push_back(handle);
	}
	//�R���e�i���ɉ摜�f�[�^��ԋp
	return image_container[file_path];

}


//�摜�擾����
const std::vector<int>& ResourceManager::GetImages(std::string file_path, int	all_num, int x_num, int y_num, int x_size, int y_size)
{
	//�R���e�i���ɉ摜��������΁A�摜��ǂݍ���
	if (image_container.count(file_path) == NULL)
	{
		//���I�z��̊m�ہi���������̃��������m�ہj
		int* handle = new int[all_num];

		//�摜�̕����Ǎ���
		int result = LoadDivGraph(file_path.c_str(), all_num, x_num, y_num,
			x_size, y_size, handle);

			//�G���[�`�F�b�N
		if (result == -1)
		{
			throw(file_path + "�̉摜���ǂݍ��߂܂���ł���\n");
		}

		//�R���e�i���ɉ摜���i�[����
		for (int i = 0; i < all_num; i++)
		{
			image_container[file_path].push_back(handle[i]);
		}

		//���I�������̊J��
		delete[] handle;
	}
	//�R���e�i���̃f�[�^��ԋp
	return image_container[file_path];
}


//�ǂݍ��񂾉摜�̊J��
void ResourceManager::DeleteImages()
{
	//�R���e�i���Ƀf�[�^���Ȃ���΁A�������I������
	if (image_container.size() == NULL)
	{
		return;
	}

	//������ƃn���h���f�[�^�̃Z�b�g�Ń��[�v���s��
	for (std::pair<std::string, std::vector<int>>velue : image_container)
	{
		//�ǂݍ��񂾉摜�̊J��
		DeleteSharingGraph(velue.second[0]);
		//���I�z��̊J��
		velue.second.clear();

	}
	//�摜�R���e�i�̊J��
	image_container.clear();

}













