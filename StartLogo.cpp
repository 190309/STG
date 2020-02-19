//親クラス
#include "StartLogo.h"
//子クラス
//相互
//エンジン・その他
#include "Engine/Image.h"

//コンストラクタ
StartLogo::StartLogo(GameObject * parent)
	: GameObject(parent, "StartLogo"), hPict_(-1)
{
}

//デストラクタ
StartLogo::~StartLogo()
{
}

//初期化
void StartLogo::Initialize()
{
	//画像データのロード
	hPict_ = Image::Load("StartLogo.png");
	assert(hPict_ >= 0);
}

//更新
void StartLogo::Update()
{
}

//描画
void StartLogo::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//開放
void StartLogo::Release()
{
}
