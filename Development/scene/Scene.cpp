#include"Scene.h"
#include"../Objects/Player/Player.h"
#include"../Objects/Enemy/Enemy.h"
#include"../Utility/InputControl.h"
#include"DxLib.h"

//コンストラクタ
Scene::Scene() :objects()
{

}

//デストラクタ
Scene::~Scene()
{
	Finalize();
}

//初期化処理
void Scene::Initialize()
{
	//背景画像
	background_image = LoadGraph("Resource/Images/BackGround.png");

	if (background_image == -1)
	{
		throw("Resource/Images/BackGround.pngがありません\n");
	}


	//プレイヤーを生成する
	CreateObject<Player>(Vector2D(350.0f, 50.0f));
	//敵の位置情報
	CreateObject<Enemy>(Vector2D(400.0f, 400.0f));
}

//更新処理
void Scene::Update()
{
	//シーンに存在するオブジェクトの更新処理
	for (GameObject* obj : objects)
	{
		obj->Update();
	}

	//オブジェクト同士の当たり判定チェック
	for (int i = 0; i < objects.size(); i++)
	{
		for (int j = i + 1; j < objects.size(); j++)
		{
			//当たり判定チェック処理
			HitCheckObject(objects[i], objects[j]);
		}
	}

	//Zキーを押したら、敵を生成する
	if (InputControl::GetKeyDown(KEY_INPUT_Z))
	{
		CreateObject<Enemy>(Vector2D(100.0f, 400.0f));
	}

}


//描画処理
void Scene::Draw()const
{

	DrawGraph(0, 0, background_image, FALSE);

	//シーンに存在するオブジェクトの描画処理
	for (GameObject* obj : objects)
	{
		obj->Draw();
	}
}


//終了時処理
void Scene::Finalize()
{
	//動的配列が空なら処理を終了する
	if (objects.empty())
	{
		return;
	}
	//各オブジェクトを削除する
	for (GameObject* obj : objects)
	{
		obj->Finalize();
		delete obj;
	}
	//動的配列の解放
	objects.clear();
}


#ifdef D_PIVOT_CENTER

//当たり判定チェック（）
void Scene::HitCheckObject(GameObject* a, GameObject* b)
{
	//二つのオブジェクトの距離を取得
	Vector2D diff = a->GetLocation() - b->GameLocation();

	//二つのオブジェクトの当たりの判定の大きさを取得
	Vector2D box_size = (a->GetLocation() + b->GameLocation()) / 2.0f;

	//距離より大きさが大きい場合、Hit判定とする
	if ((fabsf(diff.x) < box_size.x) && (fabsf(diff.y) < box_size.y))
	{
		//当たったことをオブジェクトに通知する
		a->OnHitCollision(b);
		b->OnHitCollision(a);
	}
}

#else

//当たり判定チェック処理(左上頂点から座標から当たり判定計算を行う)
void Scene::HitCheckObject(GameObject* a, GameObject* b)
{
	//右上頂上座標を取得する
	Vector2D a_lower_right = a->GetLocation() + a->GetBoxSize();
	Vector2D b_lower_right = b->GetLocation() + b->GetBoxSize();

	//短径
	if ((a->GetLocation().x < b_lower_right.x) &&
		(a->GetLocation().y < b_lower_right.y) &&
		(a_lower_right.x > b->GetLocation().x) &&
		(a_lower_right.y > b->GetLocation().y))
	{
		//オブジェクトに対してHit判定を通知する
		a->OnHitCollision(b);
		b->OnHitCollision(a);
	}
}

#endif 








