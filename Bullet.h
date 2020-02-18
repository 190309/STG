#pragma once
#include "Engine/GameObject.h"

//弾を管理するクラス
class Bullet : public GameObject
{
	int hModel_;    //モデル番号
	int Counter_ ;	//弾の大きさ
	bool Flg_;		//弾の発射状態
public:
	//コンストラクタ
	Bullet(GameObject* parent);

	//デストラクタ
	~Bullet();

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	//ゲッター(Counter_)
	int GetCounter_();
};