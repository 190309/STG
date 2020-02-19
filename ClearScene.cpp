//親クラス
#include "ClearScene.h"
//子クラス
#include "ClearLogo.h"
//相互
//エンジン・その他
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

//コンストラクタ
ClearScene::ClearScene(GameObject * parent)
	: GameObject(parent, "ClearScene")
{
}

//初期化
void ClearScene::Initialize()
{
	Instantiate<ClearLogo>(this);
}

//更新
void ClearScene::Update()
{
	//スペースキーを押したら
	if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_START);
	}
}

//描画
void ClearScene::Draw()
{
}

//開放
void ClearScene::Release()
{
}
