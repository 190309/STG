//親クラス
#include "PlBullet.h"
//子クラス
//エンジン・その他のクラス
#include "Engine/Input.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"

//コンストラクタ
PlBullet::PlBullet(GameObject * parent)
	:GameObject(parent, "PlBullet"), hModel_(-1), BulletSize_(20), BulletFlg_(false)
{
}

//デストラクタ
PlBullet::~PlBullet()
{
}

//初期化
void PlBullet::Initialize()
{
	//モデルデータのロード
	hModel_ = Model::Load("Bullet.fbx");
	assert(hModel_ >= 0);
}

//更新
void PlBullet::Update()
{
	//初期位置
	if (BulletFlg_ == false)
	{
		transform_.position_.vecZ = 3.0f;
	}

	//弾未発射時、Zキーを押している間弾を拡大
	if (Input::IsKey(DIK_Z) && BulletFlg_ == false)
	{
		//弾の拡大
		if (BulletSize_ < 180)
		{
			BulletSize_++;
		}
		transform_.scale_.vecX = BulletSize_ / 120.0f;
		transform_.scale_.vecY = BulletSize_ / 120.0f;
		transform_.scale_.vecZ = BulletSize_ / 120.0f;

		//上キー入力で上へ移動
		if (Input::IsKey(DIK_UP))
		{
			//移動可能
			if (transform_.position_.vecY < 2.75f)
			{
				transform_.position_.vecY += 0.1f;
			}
		}

		//下キー入力で下へ移動
		if (Input::IsKey(DIK_DOWN))
		{
			//移動可能
			if (transform_.position_.vecY > -2.75f)
			{
				transform_.position_.vecY -= 0.1f;
			}
		}

		//右キー入力で右へ移動
		if (Input::IsKey(DIK_RIGHT))
		{
			//移動可能
			if (transform_.position_.vecX < 6)
			{
				transform_.position_.vecX += 0.1f;
			}
		}

		//左キー入力で左へ移動
		if (Input::IsKey(DIK_LEFT))
		{
			//移動可能
			if (transform_.position_.vecX > -6)
			{
				transform_.position_.vecX -= 0.1f;
			}
		}
	}

	//弾未発射時、Zキーを離したらフラグ変更
	if (Input::IsKeyUp(DIK_Z) && BulletFlg_ == false)
	{
		BulletFlg_ = true;
		//当たり判定生成
		SphereCollider* collision = new SphereCollider(XMVectorSet(0, 0, 0, 0), BulletSize_ / 60.0f * 1.2f);
		AddCollider(collision);
	}

	//弾の移動
	if (BulletFlg_ == true)
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
void PlBullet::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//開放
void PlBullet::Release()
{
}

//ゲッター(BulletSize_)
int PlBullet::GetBulletSize_()
{
	return BulletSize_;
}
