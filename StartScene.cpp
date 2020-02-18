//親クラス
#include "StartScene.h"
//子クラス
//相互
//エンジン・その他
#include "Engine/Input.h"
#include "Engine/Image.h"
#include "Engine/SceneManager.h"

//コンストラクタ
StartScene::StartScene(GameObject * parent)
	: GameObject(parent, "StartScene"), hPict_(-1)
{
}

//初期化
void StartScene::Initialize()
{
	//画像データのロード
	hPict_ = Image::Load("StartLogo.png");
	assert(hPict_ >= 0);
}

//更新
void StartScene::Update()
{
	//スペースキーを押したらメインゲームシーンへ移動
	if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}

}

//描画
void StartScene::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//開放
void StartScene::Release()
{
}
