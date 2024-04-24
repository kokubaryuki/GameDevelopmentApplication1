#include"ResourceManager.h"
#include"DxLib.h"


ResourceManager resource_manager;

ResourceManager* GetResourceManager()
{
	return &resource_manager;
}

ResourceManager::ResourceManager() :image_constainer()
{

}

ResourceManager::~ResourceManager()
{

}

const std::vector<int>& ResourceManager::GetImage(std::string file_path)
{
	if (image_constainer.count(file_path) == NULL)
	{
		int handle = LoadGraph(file_path.c_str());

		if (handle == -1)
		{
			throw(file_path + "‰æ‘œ‚ª“Ç‚İ‚ß‚Ü‚¹‚ñ‚Å‚µ‚½");
		}
		image_constainer[file_path].push_back(handle);
	}
	return image_constainer[file_path];
}

const std::vector<int>& ResourceManager::GetImage(std::string file_path, int all_num
	, int x_num, int y_num, int x_size, int y_size)
{
	if ( image_constainer.count(file_path)==NULL)
	{
		int* handle = new int[all_num];

		int result = LoadDivGraph(file_path.c_str(), all_num, x_num, y_num,
			x_size, y_size, handle);

		if (result == -1)
		{
			throw(file_path + "‚Ì‰æ‘œ‚ª“Ç‚İ‚ß‚Ü‚¹‚ñ‚Å‚µ‚½");
		}

		for (int i = 0; i < all_num; i++)
		{
			image_constainer[file_path].push_back(handle[i]);
		}
		delete[] handle;
	}

	return image_constainer[file_path];

}

void ResourceManager::DeleteImage()
{
	if (image_constainer.size() == NULL)
	{
		return;
	}
	for (std::pair<std::string, std::vector<int>>value:image_constainer)
	{
		DeleteSharingGraph(value.second[0]);
		value.second.clear();
	}
	image_constainer.clear();
}






