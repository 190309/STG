//親クラス
#include "Stage.h"
//子クラス
#include "Satellite.h"
//相互
//エンジン・その他

//コンストラクタ
Stage::Stage(GameObject * parent)
	:GameObject(parent, "Stage")
{
}

//デストラクタ
Stage::~Stage()
{
}

//初期化
void Stage::Initialize()
{
	Instantiate<Satellite>(this);
}

//更新
void Stage::Update()
{
	//子供を動かす関数
	MoveChild();
}

//子供を動かす関数
void Stage::MoveChild()
{
	((Satellite*)FindObject("Satellite"))->Move();
}

//描画
void Stage::Draw()
{
}

//開放
void Stage::Release()
{
}