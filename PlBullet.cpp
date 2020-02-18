//親クラス
#include "PlBullet.h"
//子クラス
//相互
//エンジン・その他のクラス
#include "Engine/Input.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"

//コンストラクタ
PlBullet::PlBullet(GameObject * parent)
	:GameObject(parent, "PlBullet"),
	POS(XMVectorSet(0.0f, 0.0f, 3.0f, 0.0f)), CENTER(XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f)), MOVE(XMVectorSet(0.0f, 0.0f, 0.6f, 0.0f)),
	Scale(XMVectorSet(Size / AJUST_SIZE, Size / AJUST_SIZE, Size / AJUST_SIZE, Size / AJUST_SIZE)),
	AJUST_COLL(72), MAX_SIZE(180), AJUST_SIZE(120.0f), MAX_RANGE(100.0f),
	hModel_(-1), Size(20), Flg(false), pPlayer((Player*)FindObject("Player"))
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
	//弾未発射時、Zキーを押している間弾を拡大および移動
	if (Input::IsKey(DIK_Z) && Flg == false)
	{
		//弾の位置
		transform_.position_ = pPlayer->GetPosition() + POS;

		//弾の拡大
		if (Size < MAX_SIZE)
		{
			Size++;
			Scale = XMVectorSet(Size / AJUST_SIZE, Size / AJUST_SIZE, Size / AJUST_SIZE, Size / AJUST_SIZE);
			transform_.scale_ = Scale;
		}
	}

	//弾未発射時、Zキーを離したらフラグ変更
	if (Input::IsKeyUp(DIK_Z) && Flg == false)
	{
		Flg = true;
		//当たり判定生成
		SphereCollider* collision = new SphereCollider(CENTER, Size / AJUST_COLL);
		AddCollider(collision);
	}

	//弾の移動
	if (Flg == true)
	{
		transform_.position_ += MOVE;
	}

	//弾の有効範囲
	if (transform_.position_.vecZ < MAX_RANGE)
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