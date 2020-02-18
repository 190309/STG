#pragma once
#include "Engine/GameObject.h"

//弾を管理するクラス
class PlBullet : public GameObject
{
	int hModel_;			//モデル番号
	int BulletSize_ ;		//弾の大きさ
	bool BulletFlg_;		//弾の発射状態(0:未発射 / 1:発射済み)
public:
	//コンストラクタ
	PlBullet(GameObject* parent);

	//デストラクタ
	~PlBullet();

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	//ゲッター(BulletSize_)
	int GetBulletSize_();
};