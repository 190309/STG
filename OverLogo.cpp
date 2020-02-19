//親クラス
#include "OverLogo.h"
//子クラス
//相互
//エンジン・その他
#include "Engine/Image.h"
#include "Engine/SceneManager.h"

//コンストラクタ
OverLogo::OverLogo(GameObject * parent)
	: GameObject(parent, "OverLogo"), hPict_(-1)
{
}

//デストラクタ
OverLogo::~OverLogo()
{
}

//初期化
void OverLogo::Initialize()
{
	//画像データのロード
	hPict_ = Image::Load("ClearLogo.png");
	assert(hPict_ >= 0);
}

//更新
void OverLogo::Update()
{
}

//描画
void OverLogo::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//開放
void OverLogo::Release()
{
}
