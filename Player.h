#pragma once
//親クラス
//子クラス
//相互
//エンジン・その他
#include "Engine/GameObject.h"

//自機を管理するクラス
class Player : public GameObject
{
private:
	//ベクトル(定数)
	const XMVECTOR RANGE;		//行動可能範囲						(-6.0f < X < 6.0f, -2.75f < Y < 2.75f, Z:0.0f)
	const XMVECTOR SIZE;		//機体サイズ						(1.0f, 1.0f, 1.0f)
		
	//ベクトル(変数)

	//定数	
	const float MOVE;			//自機の移動						(0.1f)
	const float COLL_SIZE;		//自機の当たり判定					(1.8f)
	const int DMG_CNT_MAX;		//DmgCnt_の最大値					(30)

	//変数
	bool BulletFlg_;			//弾の生成フラグ					(0:未生成 / 1:生成済み)
	bool DamageFlg_;			//攻撃を受けたフラグ				(0:受けてない / 1:受けた)
	int DmgCnt_;				//一度攻撃を受けたら一定時間無敵	(0 <= DmgCnt_ <= 30)
	int hModel_;				//モデル番号						(-1:エラー / 0:正常読み込み)
	int HP_;					//自機体力							(-1 < HP_ < 11)

	//関数

	//引数:なし
	//戻値:なし
	//弾の生成および発射
	void Bullet();

	//引数:なし
	//戻値:なし
	//機体を移動させる関数
	void Move();

	//引数:なし
	//戻値:なし
	//攻撃を受けた関数
	void GetAttack();

public:
	//コンストラクタ
	Player(GameObject* parent);

	//デストラクタ
	~Player();

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	//引数:なし
	//戻値:transform_.position_
	//自機のポジションを返す
	XMVECTOR GetPlayerPos() { return transform_.position_; };

	//引数:なし
	//戻値:HP_
	//自機のHPを返す
	int GetHP() { return HP_; };

	//何かに当たった
	//引数：pTarget 当たった相手
	void OnCollision(GameObject *pTarget) override;
};