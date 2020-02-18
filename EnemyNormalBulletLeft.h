#pragma once
#include "Engine/GameObject.h"

//敵弾を管理するクラス
class EnemyNormalBulletLeft : public GameObject
{
	int hModel_;			//モデル番号
	bool BulletFlg_;		//弾の発射状態(0:未発射 / 1:発射済み)
public:
	//コンストラクタ
	EnemyNormalBulletLeft(GameObject* parent);

	//デストラクタ
	~EnemyNormalBulletLeft();

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};