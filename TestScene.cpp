#include "TestScene.h"
#include "Engine/Model.h"
#include "Engine/Input.h"

//コンストラクタ
TestScene::TestScene(GameObject * parent)
	: GameObject(parent, "TestScene"), hModel_(-1)
{

}

//初期化
void TestScene::Initialize()
{
//	transform_.position_.vecX = -10;
	hModel_ = Model::Load("Player.fbx");
}

//更新
void TestScene::Update()
{
	//transform_.rotate_.vecZ -= 5.0f;
	//transform_.position_.vecX += 0.1f;

	//右キーが押されていたら
	if(Input::IsKeyUp(DIK_RIGHT))
	{
		transform_.position_.vecX += 0.8f;
	}
	//左キーが押されていたら
	if(Input::IsKey(DIK_LEFT))
	{
		transform_.position_.vecX -= 0.1f;
	}
}

//描画
void TestScene::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//開放
void TestScene::Release()
{
}
