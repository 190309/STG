//エンジン
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
//親クラス
#include "GameOverScene.h"
//子クラス
//その他

//コンストラクタ
GameOverScene::GameOverScene(GameObject * parent)
	: GameObject(parent, "GameOverScene"), hPict_(-1)
{
}

//初期化
void GameOverScene::Initialize()
{
	//画像データのロード
	hPict_ = Image::Load("ClearLogo.png");
	assert(hPict_ >= 0);
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
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//開放
void GameOverScene::Release()
{
}
