//エンジン
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"
//親クラス
#include "EnemyNormalBulletLeft.h"
//子クラス
//その他
#include "Enemy.h"

//コンストラクタ
EnemyNormalBulletLeft::EnemyNormalBulletLeft(GameObject * parent)
	:GameObject(parent, "EnemyNormalBulletLeft"), hModel_(-1), BulletFlg_(false)
{
}

//デストラクタ
EnemyNormalBulletLeft::~EnemyNormalBulletLeft()
{
}

//初期化
void EnemyNormalBulletLeft::Initialize()
{
	//モデルデータのロード
	hModel_ = Model::Load("EnemyBullet.fbx");
	assert(hModel_ >= 0);

	//当たり判定生成
	SphereCollider* collision = new SphereCollider(XMVectorSet(0, 0, 0, 0), 0.5f);
	AddCollider(collision);
}

//更新
void EnemyNormalBulletLeft::Update()
{
	//初期位置
	if (BulletFlg_ == false)
	{
		BulletFlg_ = true;
		transform_.position_.vecX = 0.8f + ((Enemy*)FindObject("Enemy"))->GetPosX();
		transform_.position_.vecY += ((Enemy*)FindObject("Enemy"))->GetRotZ() * -0.01f;
	}

	//弾の移動
	transform_.position_.vecZ -= 0.6f;

	//弾の有効範囲
	if (transform_.position_.vecZ < -1)
	{
		KillMe();
	}
}

//描画
void EnemyNormalBulletLeft::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//開放
void EnemyNormalBulletLeft::Release()
{
}