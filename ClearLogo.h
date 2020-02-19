#pragma once
//親クラス
//子クラス
//相互
//エンジン・その他
#include "Engine/GameObject.h"

//クリアロゴを管理するクラス
class ClearLogo : public GameObject
{
private:
	int hPict_;    //画像番号

public:
	//コンストラクタ
	ClearLogo(GameObject* parent);

	//デストラクタ
	~ClearLogo();

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};
