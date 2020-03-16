//親クラス
#include "Player.h"
//子クラス
#include "PlayerBullet.h"
#include "PlayerHP.h"
//相互
#include "Enemy.h"
#include "EnemyNormalBulletLeft.h"
#include "EnemyNormalBulletRight.h"
//エンジン・その他
#include "Engine/Input.h"
#include "Engine/Model.h"
#include "Engine/SceneManager.h"

//コンストラクタ
Player::Player(GameObject * parent)
	:GameObject(parent, "Player"),
	RANGE(XMVectorSet(6.0f, 2.75f, 0.0f, 0.0f)), SIZE(XMVectorSet(1.0f, 1.0f, 1.0f, 0)),
	MOVE(0.1f), COLL_SIZE(1.5f), DMG_CNT_MAX(30),
	BulletFlg_(false), DamageFlg_(false),
	DmgCnt_(DMG_CNT_MAX), hModel_(-1), HP_(10)
{
}

//デストラクタ
Player::~Player()
{
}

//初期化
void Player::Initialize()
{
	//モデルデータのロード
	hModel_ = Model::Load("character.fbx");
	assert(hModel_ >= 0);

	//当たり判定生成
	SphereCollider* collision = new SphereCollider(XMVectorSet(0, 0, 0, 0), COLL_SIZE);
	AddCollider(collision);

	//HP生成
	Instantiate<PlayerHP>(this);;
}

//更新
void Player::Update()
{
	//弾の生成および発射
	Bullet();

	//機体を移動させる関数
	Move();

	//攻撃を受けた関数
	GetAttack();

	//自爆コマンド
	if (Input::IsKeyDown(DIK_E) && HP_ > 0)
	{
		//Selt-Explosion
		HP_--;
	}
}

//弾の生成および発射
void Player::Bullet()
{
	//弾未生成時、Zキーを押したら弾生成
	if (Input::IsKey(DIK_Z) && BulletFlg_ == false)
	{
		BulletFlg_ = true;
		PlayerBullet* pBullet = Instantiate<PlayerBullet>(GetParent());
		pBullet->SetPosition(transform_.position_);
	}

	//弾生成後、Zキーを離したら弾発射
	if (Input::IsKeyUp(DIK_Z))
	{
		BulletFlg_ = false;
	}
}

//機体を移動させる関数
void Player::Move()
{
	//上キー入力で上へ移動
	if (Input::IsKey(DIK_UP))
	{
		//移動可能
		if (transform_.position_.vecY < RANGE.vecY)
		{
			transform_.position_.vecY += MOVE;
		}
	}

	//下キー入力で下へ移動
	if (Input::IsKey(DIK_DOWN))
	{
		//移動可能
		if (transform_.position_.vecY > -RANGE.vecY)
		{
			transform_.position_.vecY -= MOVE;
		}
	}

	//右キー入力で右へ移動
	if (Input::IsKey(DIK_RIGHT))
	{
		//移動可能
		if (transform_.position_.vecX < RANGE.vecX)
		{
			transform_.position_.vecX += MOVE;
		}
	}

	//左キー入力で左へ移動
	if (Input::IsKey(DIK_LEFT))
	{
		//移動可能
		if (transform_.position_.vecX > -RANGE.vecX)
		{
			transform_.position_.vecX -= MOVE;
		}
	}
}

//攻撃を受けた関数
void Player::GetAttack()
{
	//無敵時間
	if (DamageFlg_ == true)
	{
		transform_.scale_ = XMVectorSet(0, 0, 0, 0);

		//無敵時間終了
		if (DmgCnt_-- < 0)
		{
			transform_.scale_ = SIZE;
			DmgCnt_ = DMG_CNT_MAX;
			DamageFlg_ = false;
		}
	}

	//HPがない
	if (HP_ < 1)
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_GAMEOVER);
	}
}

//描画
void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//開放
void Player::Release()
{
}

//何かに当たった
void Player::OnCollision(GameObject * pTarget)
{
	//現在攻撃を受けていない場合
	if (DamageFlg_ == false)
	{
		//弾に当たったときの処理
		if (pTarget->GetObjectName() == "EnemyNormalBulletLeft" || pTarget->GetObjectName() == "EnemyNormalBulletRight")
		{
			DamageFlg_ = true;
			HP_--;
			//当たった弾を殺す
			pTarget->KillMe();
		}

		//Enemyに当たったときの処理
		if (pTarget->GetObjectName() == "Enemy")
		{
			DamageFlg_ = true;
			HP_--;
		}
	}
}