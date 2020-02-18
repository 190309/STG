#include "EnemyBullet.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"

//コンストラクタ
EnemyBullet::EnemyBullet(GameObject * parent)
	:GameObject(parent, "EnemyBullet"), hModel_(-1)
{
}

//デストラクタ
EnemyBullet::~EnemyBullet()
{
}

//初期化
void EnemyBullet::Initialize()
{
	//モデルデータのロード
	hModel_ = Model::Load("EnemyBullet.fbx");
	assert(hModel_ >= 0);

	//当たり判定生成
	SphereCollider* collision = new SphereCollider(XMVectorSet(0, 0, 0, 0), 0.5f);
	AddCollider(collision);
}

//更新
void EnemyBullet::Update()
{
	//弾の移動
	transform_.position_.vecZ -= 0.6f;

	//弾の有効範囲
	if (transform_.position_.vecZ < 0)
	{
		KillMe();
	}
}

//描画
void EnemyBullet::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//開放
void EnemyBullet::Release()
{
}