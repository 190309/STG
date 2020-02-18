//親クラス
#include "Player.h"
//子クラス
#include "PlBullet.h"
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
	:GameObject(parent, "Player"), hModel_(-1), HP_(10), Form_(false), BulletFlg_(false)
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
	SphereCollider* collision = new SphereCollider(XMVectorSet(0, 0, 0, 0), 1.8f);
	AddCollider(collision);
}

//更新
void Player::Update()
{
	//弾未生成時、Zキーを押したら弾生成
	if (Input::IsKey(DIK_Z) && BulletFlg_ == false)
	{
		BulletFlg_ = true;
		PlBullet* pBullet = Instantiate<PlBullet>(GetParent());
		pBullet->SetPosition(transform_.position_);
	}

	//弾生成後、Zキーを離したら弾発射
	if (Input::IsKeyUp(DIK_Z))
	{
		BulletFlg_ = false;
	}

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
	if(Input::IsKey(DIK_RIGHT))
	{
		//移動可能
		if (transform_.position_.vecX < 6)
		{
			transform_.position_.vecX += 0.1f;
		}
		Form_ = 0;
	}

	//左キー入力で左へ移動
	if (Input::IsKey(DIK_LEFT))
	{
		//移動可能
		if (transform_.position_.vecX > -6)
		{
			transform_.position_.vecX -= 0.1f;
		}
		Form_ = 1;
	}

	//HPがない
	if (HP_ <= 0)
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

//ゲッター(posX)
float Player::GetPosX()
{
	return transform_.position_.vecX;
}

//ゲッター(posY)
float Player::GetPosY()
{
	return transform_.position_.vecY;
}

//何かに当たった
void Player::OnCollision(GameObject * pTarget)
{
	//弾に当たったときの処理
	if (pTarget->GetObjectName() == "EnemyNormalBulletLeft" || pTarget->GetObjectName() == "EnemyNormalBulletRight")
	{
		HP_--;
		//当たった弾を殺す
		pTarget->KillMe();
	}

	//Enemyに当たったときの処理
	if (pTarget->GetObjectName() == "Enemy")
	{
		HP_--;
	}
}