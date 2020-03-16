//エンジン
#include "Engine/Input.h"
#include "Engine/Model.h"
#include "Engine/SceneManager.h"
#include "Engine/SphereCollider.h"
//親クラス
#include "Enemy.h"
//子クラス
#include "EnemyNormalBulletLeft.h"
#include "EnemyNormalBulletRight.h"
//その他
#include "PlayerBullet.h"
#include "Player.h"

//コンストラクタ
Enemy::Enemy(GameObject * parent)
	:GameObject(parent, "Enemy"), hModel_(-1), AtcCnt_(0), AtcPtr_(0), HP_(50.00f), Dec_(false)
{
}

//デストラクタ
Enemy::~Enemy()
{
}

//初期化
void Enemy::Initialize()
{
	//モデルデータのロード
	hModel_ = Model::Load("Enemy.fbx");
	assert(hModel_ >= 0);

	//初期位置
	transform_.position_.vecZ = 50;
	transform_.rotate_.vecY = 180;

	//当たり判定生成
	SphereCollider* collision = new SphereCollider(XMVectorSet(0, -0.24f, 0, 0), 1.0f);
	AddCollider(collision);
}

//更新
void Enemy::Update()
{
	RoleFlg_ = false;

	//上下運動
	if (AtcCnt_ < 240)
	{
		//上下切り替え
		if (AtcCnt_ % 30 == 0)
		{
			Dec_ = !Dec_;
		}
		//上方向への移動
		if (Dec_ == true)
		{
			transform_.position_.vecY += 0.05f;
		}
		//下方向への移動
		if (Dec_ == false)
		{
			transform_.position_.vecY -= 0.05f;
		}
		AtcCnt_++;
	}

	//攻撃パターン生成
	if (AtcCnt_ == 240)
	{
		AtcPtr_ = rand() % 2 + 1;
		pos= ((Player*)FindObject("Player"))->GetPlayerPos();
		PlX_ = pos.vecX;
		PlY_ = pos.vecY;
	}

	//攻撃パターンをもとに攻撃
	//突撃
	if (AtcPtr_ == 1)
	{
		if (AtcCnt_ < 300)
		{	
			transform_.position_.vecZ -= 0.84f;
			if (transform_.position_.vecX < PlX_)
			{
				transform_.position_.vecX += 0.1f;
				RoleFlg_ = true;
				if (transform_.rotate_.vecZ < 45)
				{
					transform_.rotate_.vecZ++;
				}
			}
			else if (transform_.position_.vecX > PlX_)
			{
				transform_.position_.vecX -= 0.1f;
				RoleFlg_ = true;
				if (transform_.rotate_.vecZ > -45)
				{
					transform_.rotate_.vecZ--;
				}
			}
			if (transform_.position_.vecY < PlY_)
			{
				transform_.position_.vecY += 0.1f;
			}
			else if (transform_.position_.vecY > PlY_)
			{
				transform_.position_.vecY -= 0.1f;
			}
		}
		else
		{
			transform_.position_.vecZ += 0.84f;
		}
		if (AtcCnt_++ == 360)
		{
			AtcCnt_ = 0;
			AtcPtr_ = 0;
		}
	}

	//弾大量射出
	if (AtcPtr_ == 2)
	{
		pos = ((Player*)FindObject("Player"))->GetPlayerPos();
		PlX_ = pos.vecX;
		PlY_ = pos.vecY;

		if (AtcCnt_ < 600)
		{
			if (transform_.position_.vecX < PlX_)
			{
				transform_.position_.vecX += 0.1f;
				RoleFlg_ = true;
				if (transform_.rotate_.vecZ < 45)
				{
					transform_.rotate_.vecZ++;
				}
			}
			else if (transform_.position_.vecX > PlX_)
			{
				transform_.position_.vecX -= 0.1f;
				RoleFlg_ = true;
				if (transform_.rotate_.vecZ > -45)
				{
					transform_.rotate_.vecZ--;
				}
			}
			if (transform_.position_.vecY < PlY_)
			{
				transform_.position_.vecY += 0.1f;
			}
			else if (transform_.position_.vecY > PlY_)
			{
				transform_.position_.vecY -= 0.1f;
			}
		}
		if (AtcCnt_ % 20 == 0)
		{
			EnemyNormalBulletLeft* pBulletL = Instantiate<EnemyNormalBulletLeft>(GetParent());
			EnemyNormalBulletRight* pBulletR = Instantiate<EnemyNormalBulletRight>(GetParent());
			pBulletL->SetPosition(transform_.position_);
			pBulletR->SetPosition(transform_.position_);
		}
		if (AtcCnt_++ == 600)
		{
			AtcCnt_ = 0;
			AtcPtr_ = 0;
		}
	}

	//回転していなくて角度がついている場合戻す
	if (RoleFlg_ == false)
	{
		if (transform_.rotate_.vecZ < 0)
		{
			transform_.rotate_.vecZ++;
		}
		if (transform_.rotate_.vecZ > 0)
		{
			transform_.rotate_.vecZ--;
		}
	}

	//HPがない
	if (HP_ <= 0)
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_CLEAR);
	}
}

//描画
void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//開放
void Enemy::Release()
{
}

//ゲッター(HP_)
float Enemy::GetHP_()
{
	return HP_;
}

//ゲッター(PosX)
float Enemy::GetPosX()
{
	return 	transform_.position_.vecX;
}

//ゲッター(PosY)
float Enemy::GetPosY()
{
	return 	transform_.position_.vecY;
}

float Enemy::GetRotZ()
{
	return 	transform_.rotate_.vecZ;
}

//何かに当たった
void Enemy::OnCollision(GameObject * pTarget)
{
	//弾に当たったときの処理
	if(pTarget->GetObjectName() == "PlayerBullet")
	{
		HP_ -= ((PlayerBullet*)pTarget)->GetBulletSize() / 60.00f;
		//当てた弾も殺す
		pTarget->KillMe();
	}
}