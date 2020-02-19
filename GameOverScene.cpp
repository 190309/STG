//親クラス
#include "GameOverScene.h"
//子クラス
#include "OverLogo.h"
//相互
//エンジン・その他
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

//コンストラクタ
GameOverScene::GameOverScene(GameObject * parent)
	: GameObject(parent, "GameOverScene")
{
}

//初期化
void GameOverScene::Initialize()
{
	Instantiate<OverLogo>(this);
}

//更新
void GameOverScene::Update()
{
	//スペースキーを押したら
	if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_START);
	}
}

//描画
void GameOverScene::Draw()
{
}

//開放
void GameOverScene::Release()
{
}
