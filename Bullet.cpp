#include "Bullet.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"
#include "Engine/Input.h"

//コンストラクタ
Bullet::Bullet(GameObject * parent)
	:GameObject(parent, "Bullet"), hModel_(-1)
{
	Counter_ = 20;
	Flg_ = false;
}

//デストラクタ
Bullet::~Bullet()
{
}

//初期化
void Bullet::Initialize()
{
	//モデルデータのロード
	hModel_ = Model::Load("Bullet.fbx");
	assert(hModel_ >= 0);
}

//更新
void Bullet::Update()
{
	//Zキーを押している間
	if (Input::IsKey(DIK_Z) && Flg_ == false)
	{
		//弾の初期位置
		if (Counter_ == 20)
		{
			transform_.position_.vecZ = 3.0f;
		}

		//弾の拡大
		if (Counter_ < 180)
		{
			Counter_++;
		}
		transform_.scale_.vecX = Counter_ / 120.0f;
		transform_.scale_.vecY = Counter_ / 120.0f;
		transform_.scale_.vecZ = Counter_ / 120.0f;

		//上キー
		if (Input::IsKey(DIK_UP))
		{
			transform_.position_.vecY += 0.1f;
		}

		//下キー
		if (Input::IsKey(DIK_DOWN))
		{
			transform_.position_.vecY -= 0.1f;
		}

		//右キー
		if (Input::IsKey(DIK_RIGHT))
		{
			transform_.position_.vecX += 0.1f;
		}

		//左キー
		if (Input::IsKey(DIK_LEFT))
		{
			transform_.position_.vecX -= 0.1f;
		}
	}

	//Zキーを離したら
	if (Input::IsKeyUp(DIK_Z) && Flg_ == false)
	{
		Flg_ = true;
		//当たり判定生成
		SphereCollider* collision = new SphereCollider(XMVectorSet(0, 0, 0, 0), Counter_ / 60.0f * 1.2);
		AddCollider(collision);
	}

	//弾の移動
	if (Flg_ == true)
	{
		transform_.position_.vecZ += 0.6f;
	}

	//弾の有効範囲
	if (transform_.position_.vecZ > 100)
	{
		KillMe();
	}
}

//描画
void Bullet::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//開放
void Bullet::Release()
{
}

//ゲッター(Counter_)
int Bullet::GetCounter_()
{
	return Counter_;
}
