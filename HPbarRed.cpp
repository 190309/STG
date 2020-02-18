//エンジン
#include "Engine/Image.h"
//親クラス
#include "HPbarRed.h"
//子クラス
//その他

//コンストラクタ
HPbarRed::HPbarRed(GameObject * parent)
	:GameObject(parent, "HPbarRed"), hPict_(-1)
{
}

//デストラクタ
HPbarRed::~HPbarRed()
{
}

//初期化
void HPbarRed::Initialize()
{
	//画像データのロード
	hPict_ = Image::Load("RedHPBar.png");
	assert(hPict_ >= 0);

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
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//開放
void HPbarRed::Release()
{
}