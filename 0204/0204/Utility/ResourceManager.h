#pragma once

#include<map>
#include<string>
#include<vector>

class ResourceManager
{
private:
	std::map<std::string, std::vector<int>>image_constainer;

public:
	ResourceManager();
	~ResourceManager();

	const std::vector<int>& GetImage(std::string file_path);
	const std::vector<int>& GetImage(std::string file_path, int all_num, int
		x_num, int y_num, int x_size, int y_size);


	void DeleteImage();
};

ResourceManager* GetResourceManager();


