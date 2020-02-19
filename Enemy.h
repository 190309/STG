#pragma once
#include "Engine/GameObject.h"

//敵を管理するクラス
class Enemy : public GameObject
{
	XMVECTOR pos;
	GameObject * pTarget;
	int hModel_;		//モデル番号
	int AtcCnt_;		//行動タイミング
	int AtcPtr_;		//攻撃の種類
	float HP_;			//体力
	float PlX_;			//PlayerのX座標
	float PlY_;			//PlayerのY座標
	bool Dec_;			//上下の方向(0:上方向への移動 / 1:下方向への移動)
	bool RoleFlg_;		//回転フラグ
public:
	//コンストラクタ
	Enemy(GameObject* parent);

	//デストラクタ
	~Enemy();

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	//ゲッター(HP_)
	float GetHP_();

	//ゲッター(posX)
	float GetPosX();

	//ゲッター(posY)
	float GetPosY();

	//ゲッター(rotZ)
	float GetRotZ();

	//何かに当たった
	//引数：pTarget 当たった相手
	void OnCollision(GameObject *pTarget) override;
};