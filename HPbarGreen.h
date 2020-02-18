#pragma once
#include "Engine/GameObject.h"

//HPbarGreenを管理するクラス
class HPbarGreen : public GameObject
{
	int hModel_;    //モデル番号
	float InitHP_;	//敵初期HP
	float HP_;		//敵HP
public:
	//コンストラクタ
	HPbarGreen(GameObject* parent);

	//デストラクタ
	~HPbarGreen();

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};