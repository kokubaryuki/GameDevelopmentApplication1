#include"ResoruceManager.h"
#include"DxLib.h"

//�ÓI�����o�ϐ���`
ResourceManager* ResourceManager::instance = nullptr;

///<summary>
///���\�[�X�Ǘ��N���X�̃C���X�^���X�폜����
/// </summary>
ResourceManager*ResourceManager::GetInstance()
{
	//�C���X�^���X����������Ȃ��ꍇ�A��������
	if (instance == nullptr)
	{
		instance = new ResourceManager();
	}

	//�C���X�^���X�̃|�C���^��ԋp����
	return instance;
}

///<summary>
///���\�[�X�Ǘ��N���X�̃C���X�^���X�폜����
/// </summary>
void ResourceManager::DeleteInstance()
{
	//�C���X�^���X�����݂��Ă���΁A�폜����
	if (instance != nullptr)
	{
		instance->UnloadResourceAll();
		delete instance;
		instance = nullptr;
	}
}

/**
*�摜���擾����
* @param file_name �t�@�C���p�X
* @param all_num    �摜����
* @param num_x      ���̑���
* @param num_y      �c�̑���  
* @param size_x     ���̃T�C�Y(px)
* @param size_y     �c�̃T�C�Y(px)
* @return �ǂݍ��񂾉摜�n���h����std::vector�z��
**/

/************************************************************************************************
*�摜
*************************************************************************************************/

const std::vector<int>& ResourceManager::GetImages(std::string file_name, int all_num,
	int num_x, int num_y, int size_x, int size_y)
{
	//�R���e�i���Ɏw��t�@�C�����Ȃ���΁A��������
	if (images_container.count(file_name) == NULL)
	{
		if (all_num == 1)
		{
			//�摜�̒l����
			CreateImagesResource(file_name);
		}
		else
		{
			//�摜�̒l�Ȃ�(�T�C�Y���A���̒l���[���Ȃ̂�all_num��-1�ɂ���Ɖ摜���\������Ȃ�)
			CreateImagesResource(file_name, all_num, num_x, num_y, size_x, size_y);
		}
	}
	return images_container[file_name];
}


const std::vector<int>& ResourceManager::GetImages(const char* file_name, int all_num,
	int num_x, int num_y, int size_x, int size_y)
{
	return GetImages(std::string(file_name), all_num, num_x, num_y, size_x, size_y);
}

const std::vector<int>& ResourceManager::GetImages(MaterialParam element)
{
	return GetImages(element.file_paht, element.all_num, element.num_x,
		element.num_y, element.size_x, element.size_y);
}
/************************************************************************************************
*����
*************************************************************************************************/
const std::vector<int>& ResourceManager::GetSounds(std::string file_name, int all_num,
	int num_x, int num_y, int size_x, int size_y)
{
	//�R���e�i���Ɏw��t�@�C�����Ȃ���΁A��������
	if (images_container.count(file_name) == NULL)
	{
		if (all_num == 1)
		{
			//�摜�̒l����
			CreateImagesResource(file_name);
		}
		else
		{
			//�摜�̒l�Ȃ�(�T�C�Y���A���̒l���[���Ȃ̂�all_num��-1�ɂ���Ɖ摜���\������Ȃ�)
			CreateImagesResource(file_name, all_num, num_x, num_y, size_x, size_y);
		}
	}
	return images_container[file_name];
}


const std::vector<int>& ResourceManager::GetSounds(const char* file_name, int all_num,
	int num_x, int num_y, int size_x, int size_y)
{
	return GetImages(std::string(file_name), all_num, num_x, num_y, size_x, size_y);
}

const std::vector<int>& ResourceManager::GetSounds(MaterialParam element)
{
	return GetImages(element.file_paht, element.all_num, element.num_x, 
		element.num_y, element.size_x, element.size_y);
}

/**
*���ׂẲ摜���폜����
*@param material_handle �폜�������n���h����std::vector�z��
*/


/************************************************************************************************
*�摜
*************************************************************************************************/
void ResourceManager::UnloadResourceAll()
{
	//�R���e�i���ɉ摜���Ȃ���΁A�I������
	if (images_container.size() == NULL)
	{
		return;
	}

	//���ׂẲ摜���폜����
	for (std::pair<std::string, std::vector<int>>value : images_container)
	{
		DeleteSharingGraph(value.second[0]);
	}
	//�R���e�i���J������
	images_container.clear();
}
/************************************************************************************************
*����
*************************************************************************************************/
void ResourceManager::UnloadResourceAll()
{
	//�R���e�i���ɉ摜���Ȃ���΁A�I������
	if (images_container.size() == NULL)
	{
		return;
	}

	//���ׂẲ摜���폜����
	for (std::pair<std::string, std::vector<int>>value : sound_container)
	{
		DeleteSharingGraph(value.second[0]);
	}
	//�R���e�i���J������
	images_container.clear();
}

/**
*�摜�n���h����ǂݍ��݃��\�[�X���쐬����
*@param  file_name �t�@�C���p�X
*/

void ResourceManager::CreateImagesResource(std::string file_name)
{
	//�w�肳�ꂽ�t�@�C����ǂݍ���
	int handle = LoadGraph(file_name.c_str());

	if (handle == -1)
	{
		throw(file_name + "������܂���\n");
	}
	//�R���e�i�ɓǂݍ��񂾉摜��ǉ�����
	images_container[file_name].push_back(handle);
}

/**
*�摜�n���h����Ǎ��݃��\�[�X���쐬����
* @param file_name �t�@�C���p�X
* @param�@all_num   �摜�̑���
* @param  num_x�@�@X���̑���
* @param  num_y�@�@Y�c�̑���
* @param  size_x�@�@���̃T�C�Y(px)
* @param  size_y    �c�̃T�C�Y(px)
*/

void ResourceManager::CreateImagesResource(std::string file_name, int all_num,
	int num_x, int num_y, int size_x, int size_y)
{
	//�w�肳�ꂽ�t�@�C����ǂݍ���
	int* handle = new int[all_num];
	int err = LoadDivGraph(file_name.c_str(), all_num, num_x, num_y, size_x, size_y, handle);

	//�G���[�`�F�b�N
	if(err==-1)
	{
		throw(file_name + "������܂���\n");
	}
	//�R���e�i�ɓǍ����񂾉摜��ǉ�����
	for (int i = 0; i < all_num; i++)
	{
		images_container[file_name].push_back(handle[i]);
	}
	//���I�������̊J��
	delete[]handle;
}