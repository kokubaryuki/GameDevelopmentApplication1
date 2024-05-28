#pragma once

#include <map>
#include <string>
#include <vector>


struct MaterialParam
{
	std::string file_paht;
	int all_num;
	int num_x;
	int num_y;
	int size_x;
	int size_y;

};

//���\�[�X�Ǘ��N���X
class ResourceManager
{
private:
	//���N���X�̃|�C���^�i�A�h���X��Ɏ��̂�����j
	static ResourceManager* instance;

	//�摜�R���e�i
	std::map<std::string, std::vector<int>> images_container;

	//�����R���e�i
	std::map<std::string, std::vector<int>> sound_container;

private:
	//���N���X�̃����o�ł��������ł��Ȃ��悤�ɂ���
	ResourceManager() = default;

	//�R�s�[�K�[�h
	ResourceManager(const ResourceManager&) = delete;
	ResourceManager& operator=(const ResourceManager&) = delete;
	//~�R�s�[�K�[�h

public:
	~ResourceManager() = default;

public:


	static ResourceManager* GetInstance();

	///<summary>
	///���\�[�X�Ǘ��N���X�̃C���X�^���X�擾����
	/// <summary>
	/// <returns>�N���X�̃|�C���^</returns>
	static void DeleteInstance();

public:
	/**
	*�摜�𐶐�����
	*@param file_name �t�@�C���p�X
	*@param all_num    �摜�̑���
	*@param num_x      ���̑���
	*@param num_y      �c�̑���
	*@param size_x     ���̃T�C�Y(px)
	*@param size_y     �c�̃T�C�Y(px)
	*return �ǂݍ��񂾉摜�n���h����std::vector�z��
	*/


	//�摜
	const std::vector<int>& GetImages(std::string flie_name, int all_num = 1,int num_x = 1, int num_y = 1, int size_x = 0, int size_y= 0);
	const std::vector<int>& GetImages(const char* flie_name, int all_num = 1,int num_x = 1, int num_y = 1, int size_x = 0, int size_y= 0);
	const std::vector<int>& GetImages(MaterialParam element);

	//����
	const std::vector<int>& GetSounds(std::string flie_name, int all_num = 1, int num_x = 1, int num_y = 1, int size_x = 0, int size_y = 0);
	const std::vector<int>& GetSounds(const char* flie_name, int all_num = 1, int num_x = 1, int num_y = 1, int size_x = 0, int size_y = 0);
	const std::vector<int>& GetSounds(MaterialParam element);

	/**
	*���ׂẲ摜���폜����
	*@param material_handle �폜�������摜�n���h����std::vector�z��
	*/
	void UnloadResourceAll();

private:
	/**
	*�摜�n���h����Ǎ��݃��\�[�X���쐬����
	*@param file_name �t�@�C���p�X
	*/

	void CreateImagesResource(std::string file_name);

	/**
	*�摜�𐶐�����
	*@param file_name �t�@�C���p�X
	*@param all_num    �摜�̑���
	*@param num_x      ���̑���
	*@param num_y      �c�̑���
	*@param size_x     ���̃T�C�Y(px)
	*@param size_y     �c�̃T�C�Y(px)
	*/

	void CreateImagesResource(std::string file_name, int all_num, int num_x,
		int num_y, int size_x, int size_y);


};












