//親クラス
#include "Player.h"
#include "PlayerBullet.h"
//子クラス
//相互
//エンジン・その他のクラス
#include "Engine/Input.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"

//コンストラクタ
PlayerBullet::PlayerBullet(GameObject * parent)
	:GameObject(parent, "PlayerBullet"),
	MAX_SIZE(180), AJUST_COLL(60.0f), AJUST_SIZE(120.0f), MAX_RANGE(100.0f), MOVE(0.6f), POS(3.0f),
	Flg_(false), hModel_(-1), Size_(20), pPlayer_((Player*)FindObject("Player"))
{
}

//デストラクタ
PlayerBullet::~PlayerBullet()
{
}

//初期化
void PlayerBullet::Initialize()
{
	//モデルデータのロード
	hModel_ = Model::Load("Bullet.fbx");
	assert(hModel_ >= 0);
}

//更新
void PlayerBullet::Update()
{
	//弾未発射時、Zキーを押している間弾を拡大および移動
	if (Input::IsKey(DIK_Z) && Flg_ == false)
	{
		//弾の位置
		transform_.position_ = pPlayer_->GetPosition();
		transform_.position_.vecZ += POS;

		//弾の拡大
		if (Size_ < MAX_SIZE)
		{
			Size_++;
			transform_.scale_ = XMVectorSet(Size_ / AJUST_SIZE, Size_ / AJUST_SIZE, Size_ / AJUST_SIZE, Size_ / AJUST_SIZE);
		}
	}

	//弾未発射時、Zキーを離したらフラグ変更
	if (Input::IsKeyUp(DIK_Z) && Flg_ == false)
	{
		Flg_ = true;
		//当たり判定生成
		SphereCollider* collision = new SphereCollider(XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f), Size_ / AJUST_COLL);
		AddCollider(collision);
	}

	//弾の移動
	if (Flg_ == true)
	{
		transform_.position_.vecZ += MOVE;
	}

	//弾の有効範囲
	if (transform_.position_.vecZ > MAX_RANGE)
	{
		KillMe();
	}
}

//描画
void PlayerBullet::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//開放
void PlayerBullet::Release()
{
}