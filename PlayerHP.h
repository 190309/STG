#pragma once
//親クラス
//子クラス
//相互
//エンジン・その他のクラス
#include "Engine/GameObject.h"

//プレイヤーのHPの表示を管理するクラス
class PlayerHP : public GameObject
{
private:
	//ベクトル(定数)
	const XMVECTOR HP_POS;		//画像の位置		(X:-0.87f, Y:-0.95f, Z:0.0f)

	//ベクトル(変数)

	//定数

	//変数
	int hHPNumberPict_[11];		//HPの数字画像番号	(-1:エラー / 0:正常読み込み)
	int HP_;					//自機のHP			(-1 < HP_ < 11)

public:
	//コンストラクタ
	PlayerHP(GameObject* parent);

	//デストラクタ
	~PlayerHP();

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};