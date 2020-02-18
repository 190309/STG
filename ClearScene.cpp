//エンジン
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
//親クラス
#include "ClearScene.h"
//子クラス
//その他

//コンストラクタ
ClearScene::ClearScene(GameObject * parent)
	: GameObject(parent, "ClearScene"), hPict_(-1)
{
}

//初期化
void ClearScene::Initialize()
{
	//画像データのロード
	hPict_ = Image::Load("ClearLogo.png");
	assert(hPict_ >= 0);
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
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//開放
void ClearScene::Release()
{
}
