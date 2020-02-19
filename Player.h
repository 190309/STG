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
	const XMVECTOR RANGE;		//行動可能範囲		(-6.0f < X < 6.0f, -2.75f < Y < 2.75f, Z:0.0f)

	//ベクトル(変数)

	//定数
	const float MOVE;			//自機の移動		(0.1f)
	const float COLL_SIZE;		//自機の当たり判定	(1.8f)

	//変数
	bool BulletFlg_;			//弾の生成フラグ	(0:未生成 / 1:生成済み)
	int hModel_;				//モデル番号		(-1:エラー / 0:正常読み込み)
	int HP_;					//自機体力			(-1 < HP_ < 11)

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
	//プレイヤーのポジションを返す
	XMVECTOR GetPlayerPos() { return transform_.position_; };

	//何かに当たった
	//引数：pTarget 当たった相手
	void OnCollision(GameObject *pTarget) override;
};