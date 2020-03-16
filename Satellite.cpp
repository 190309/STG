//親クラス
#include "Satellite.h"
//子クラス
//相互
//エンジン・その他
#include "Engine/Model.h"

//コンストラクタ
Satellite::Satellite(GameObject * parent)
	:GameObject(parent, "Satellite"), hModel_(-1)
{
}

//デストラクタ
Satellite::~Satellite()
{
}

//初期化
void Satellite::Initialize()
{
	//モデルデータのロード
	hModel_ = Model::Load("Satellite/Satellite.fbx");
	assert(hModel_ >= 0);

	transform_.position_ = XMVectorSet(30,0,150,0);
}

//更新
void Satellite::Update()
{
	if (transform_.position_.vecZ < 0)
	{
		transform_.position_.vecZ = 1000.0f;
	}
}

//描画
void Satellite::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//開放
void Satellite::Release()
{
}