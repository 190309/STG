//親クラス
#include "ClearLogo.h"
//子クラス
//相互
//エンジン・その他
#include "Engine/Image.h"
#include "Engine/SceneManager.h"

//コンストラクタ
ClearLogo::ClearLogo(GameObject * parent)
	: GameObject(parent, "ClearLogo"), hPict_(-1)
{
}

//デストラクタ
ClearLogo::~ClearLogo()
{
}

//初期化
void ClearLogo::Initialize()
{
	//画像データのロード
	hPict_ = Image::Load("ClearLogo.png");
	assert(hPict_ >= 0);
}

//更新
void ClearLogo::Update()
{
}

//描画
void ClearLogo::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//開放
void ClearLogo::Release()
{
}
