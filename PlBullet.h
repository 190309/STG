#pragma once
//親クラス
#include "Player.h"
//子クラス
//相互
//エンジン・その他のクラス
#include "Engine/GameObject.h"

//弾を管理するクラス
class PlBullet : public GameObject
{
private:
	//ベクトル(定数)

	//ベクトル(変数)

	//定数
	const int MAX_SIZE;			//弾の大きさ最大		(180)
	const float AJUST_COLL;		//弾の当たり判定を調整	(60.0f)
	const float AJUST_SIZE;		//弾のサイズを調整		(120.0f)
	const float MAX_RANGE;		//弾の生存範囲			(POS - 1 < vecZ < 100.0f)
	const float MOVE;			//弾の移動				(0.6f)
	const float POS;			//弾の初期位置(奥行)	(3.0f)

	//変数
	bool Flg_;					//弾の発射状態			(0:未発射 / 1:発射済み)
	int hModel_;				//モデル番号			(-1:エラー / 0:正常読み込み)
	int Size_;					//弾の大きさ			(19 < Size < MAX_SIZE)
	Player* pPlayer_;			//Playerオブジェクトのモデル番号

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

	//引数:なし
	//戻値:Size
	//Size_を返す
	int GetBulletSize() { return Size_; };
};