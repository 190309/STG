//親クラス
#include "StartScene.h"
//子クラス
#include "StartLogo.h"
//相互
//エンジン・その他
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

//コンストラクタ
StartScene::StartScene(GameObject * parent)
	: GameObject(parent, "StartScene")
{
}

//初期化
void StartScene::Initialize()
{
	Instantiate<StartLogo>(this);
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
}

//開放
void StartScene::Release()
{
}
