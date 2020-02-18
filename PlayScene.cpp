//エンジン
//親クラス
#include "PlayScene.h"
//子クラス
#include "Player.h"
#include "Enemy.h"
#include "HPbarRed.h"
#include "HPbarGreen.h"
//その他

//コンストラクタ
PlayScene::PlayScene(GameObject * parent)
	: GameObject(parent, "PlayScene")
{
}

//初期化
void PlayScene::Initialize()
{
	Instantiate<Player>(this);
	Instantiate<Enemy>(this);
	Instantiate<HPbarRed>(this);
	Instantiate<HPbarGreen>(this);
}

//更新
void PlayScene::Update()
{
}

//描画
void PlayScene::Draw()
{
}

//開放
void PlayScene::Release()
{
}