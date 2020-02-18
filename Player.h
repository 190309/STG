#pragma once
#include "Engine/GameObject.h"

//自機を管理するクラス
class Player : public GameObject
{
	int hModel_;			//モデル番号
	int HP_;				//自機体力
	bool Form_;				//自機の回転方向
	bool BulletFlg_;		//弾の生成フラグ(0:未生成 / 1:生成済み)
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

	//ゲッター(posX)
	float GetPosX();

	//ゲッター(posY)
	float GetPosY();

	//何かに当たった
	//引数：pTarget 当たった相手
	void OnCollision(GameObject *pTarget) override;
};