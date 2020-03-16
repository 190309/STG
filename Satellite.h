#pragma once
//親クラス
//子クラス
//相互
//エンジン・その他
#include "Engine/GameObject.h"

//自機を管理するクラス
class Satellite : public GameObject
{
private:
	//ベクトル(定数)

	//ベクトル(変数)

	//定数	

	//変数
	int hModel_;		//モデル番号	(-1:エラー / 0:正常読み込み)

public:
	//コンストラクタ
	Satellite(GameObject* parent);

	//デストラクタ
	~Satellite();

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};