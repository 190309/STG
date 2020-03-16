#pragma once
//親クラス
//子クラス
//相互
//エンジン・その他
#include "Engine/GameObject.h"

//自機を管理するクラス
class Stage : public GameObject
{
private:
	//ベクトル(定数)

	//ベクトル(変数)

	//定数	

	//変数

	//関数

	//引数:なし
	//戻値:なし
	//子供を動かす関数
	void MoveChild();

public:
	//コンストラクタ
	Stage(GameObject* parent);

	//デストラクタ
	~Stage();

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};