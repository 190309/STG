#pragma once
#include "Engine/GameObject.h"

//HPbarRedを管理するクラス
class HPbarRed : public GameObject
{
	int hPict_;    //画像番号
public:
	//コンストラクタ
	HPbarRed(GameObject* parent);

	//デストラクタ
	~HPbarRed();

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};