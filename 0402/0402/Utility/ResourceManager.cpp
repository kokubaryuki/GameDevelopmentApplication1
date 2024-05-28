#include"ResoruceManager.h"
#include"DxLib.h"

//静的メンバ変数定義
ResourceManager* ResourceManager::instance = nullptr;

///<summary>
///リソース管理クラスのインスタンス削除処理
/// </summary>
ResourceManager*ResourceManager::GetInstance()
{
	//インスタンスが生成されない場合、生成する
	if (instance == nullptr)
	{
		instance = new ResourceManager();
	}

	//インスタンスのポインタを返却する
	return instance;
}

///<summary>
///リソース管理クラスのインスタンス削除処理
/// </summary>
void ResourceManager::DeleteInstance()
{
	//インスタンスが存在していれば、削除する
	if (instance != nullptr)
	{
		instance->UnloadResourceAll();
		delete instance;
		instance = nullptr;
	}
}

/**
*画像を取得する
* @param file_name ファイルパス
* @param all_num    画像総数
* @param num_x      横の総数
* @param num_y      縦の総数  
* @param size_x     横のサイズ(px)
* @param size_y     縦のサイズ(px)
* @return 読み込んだ画像ハンドルのstd::vector配列
**/

/************************************************************************************************
*画像
*************************************************************************************************/

const std::vector<int>& ResourceManager::GetImages(std::string file_name, int all_num,
	int num_x, int num_y, int size_x, int size_y)
{
	//コンテナ内に指定ファイルがなければ、生成する
	if (images_container.count(file_name) == NULL)
	{
		if (all_num == 1)
		{
			//画像の値あり
			CreateImagesResource(file_name);
		}
		else
		{
			//画像の値なし(サイズｘ、ｙの値がゼロなのでall_numを-1にすると画像が表示されない)
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
*音源
*************************************************************************************************/
const std::vector<int>& ResourceManager::GetSounds(std::string file_name, int all_num,
	int num_x, int num_y, int size_x, int size_y)
{
	//コンテナ内に指定ファイルがなければ、生成する
	if (images_container.count(file_name) == NULL)
	{
		if (all_num == 1)
		{
			//画像の値あり
			CreateImagesResource(file_name);
		}
		else
		{
			//画像の値なし(サイズｘ、ｙの値がゼロなのでall_numを-1にすると画像が表示されない)
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
*すべての画像を削除する
*@param material_handle 削除したいハンドルのstd::vector配列
*/


/************************************************************************************************
*画像
*************************************************************************************************/
void ResourceManager::UnloadResourceAll()
{
	//コンテナ内に画像がなければ、終了する
	if (images_container.size() == NULL)
	{
		return;
	}

	//すべての画像を削除する
	for (std::pair<std::string, std::vector<int>>value : images_container)
	{
		DeleteSharingGraph(value.second[0]);
	}
	//コンテナを開放する
	images_container.clear();
}
/************************************************************************************************
*音源
*************************************************************************************************/
void ResourceManager::UnloadResourceAll()
{
	//コンテナ内に画像がなければ、終了する
	if (images_container.size() == NULL)
	{
		return;
	}

	//すべての画像を削除する
	for (std::pair<std::string, std::vector<int>>value : sound_container)
	{
		DeleteSharingGraph(value.second[0]);
	}
	//コンテナを開放する
	images_container.clear();
}

/**
*画像ハンドルを読み込みリソースを作成する
*@param  file_name ファイルパス
*/

void ResourceManager::CreateImagesResource(std::string file_name)
{
	//指定されたファイルを読み込む
	int handle = LoadGraph(file_name.c_str());

	if (handle == -1)
	{
		throw(file_name + "がありません\n");
	}
	//コンテナに読み込んだ画像を追加する
	images_container[file_name].push_back(handle);
}

/**
*画像ハンドルを読込みリソースを作成する
* @param file_name ファイルパス
* @param　all_num   画像の総数
* @param  num_x　　X横の総数
* @param  num_y　　Y縦の総数
* @param  size_x　　横のサイズ(px)
* @param  size_y    縦のサイズ(px)
*/

void ResourceManager::CreateImagesResource(std::string file_name, int all_num,
	int num_x, int num_y, int size_x, int size_y)
{
	//指定されたファイルを読み込む
	int* handle = new int[all_num];
	int err = LoadDivGraph(file_name.c_str(), all_num, num_x, num_y, size_x, size_y, handle);

	//エラーチェック
	if(err==-1)
	{
		throw(file_name + "がありません\n");
	}
	//コンテナに読込こんだ画像を追加する
	for (int i = 0; i < all_num; i++)
	{
		images_container[file_name].push_back(handle[i]);
	}
	//動的メモリの開放
	delete[]handle;
}