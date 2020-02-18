//エンジン
#include "Engine/Image.h"
//親クラス
#include "HPbarGreen.h"
//子クラス
//その他
#include "Enemy.h"

//コンストラクタ
HPbarGreen::HPbarGreen(GameObject * parent)
	:GameObject(parent, "HPbarGreen"), hPict_(-1), InitHP_(((Enemy*)FindObject("Enemy"))->GetHP_())
{
}

//デストラクタ
HPbarGreen::~HPbarGreen()
{
}

//初期化
void HPbarGreen::Initialize()
{
	//画像データのロード
	hPict_ = Image::Load("GreenHPBae.png");
	assert(hPict_ >= 0);

	//初期位置
	transform_.position_.vecY = 4.0f;
	transform_.position_.vecZ = -0.0001f;
	transform_.rotate_.vecX = 15.0f;
}

//更新
void HPbarGreen::Update()
{
	//現在HPの取得および大きさ変更
	HP_ = ((Enemy*)FindObject("Enemy"))->GetHP_();
	if (HP_ < 0)
	{
		HP_ = 0;
	}
	transform_.scale_.vecX = HP_ * 20 / InitHP_ * 1.0f;
	transform_.position_.vecX = ( HP_ * 20 / InitHP_ / 2 - 10 ) / 2;
}

//描画
void HPbarGreen::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//開放
void HPbarGreen::Release()
{
}