//エンジン
#include "Engine/Model.h"
//親クラス
#include "HPbarRed.h"
//子クラス
//その他

//コンストラクタ
HPbarRed::HPbarRed(GameObject * parent)
	:GameObject(parent, "HPbarRed"), hModel_(-1)
{
}

//デストラクタ
HPbarRed::~HPbarRed()
{
}

//初期化
void HPbarRed::Initialize()
{
	//モデルデータのロード
	hModel_ = Model::Load("HPbarRed.fbx");
	assert(hModel_ >= 0);

	//初期位置
	transform_.position_.vecY = 4.0f;
	transform_.scale_.vecX = 20.0f;
	transform_.rotate_.vecX = 15.0f;
}

//更新
void HPbarRed::Update()
{
}

//描画
void HPbarRed::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//開放
void HPbarRed::Release()
{
}