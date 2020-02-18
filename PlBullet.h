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
	//ベクトル(定数)
	const XMVECTOR POS;         //弾の奥行位置        (X:0.0f / Y:0.0f / Z:1.5f)
	const XMVECTOR CENTER;      //当たり判定の中心    (X:0.0f / Y:0.0f / Z:0.0f)
	const XMVECTOR MOVE;        //弾の奥行位置        (X:0.0f / Y:0.0f / Z:0.6f)
	//ベクトル(変数)
	XMVECTOR Scale;             //弾のサイズ          (X,Y,Z:Size / AJUST_SIZE)
	//定数
	const int AJUST_COLL;       //弾の当たり判定を調整(72)
	const int MAX_SIZE;         //弾の大きさ最大      (180)
	const float AJUST_SIZE;     //弾のサイズを調整    (120.0f)
	const float MAX_RANGE;      //弾の生存範囲        (vecZ < 100.0f)
	//変数
	int hModel_;		        //モデル番号          (-1:エラー / 0:正常読み込み)
	int Size;                   //弾の大きさ          (19 < Size < MAX_SIZE)
	bool Flg;                   //弾の発射状態        (0:未発射 / 1:発射済み)
	Player* pPlayer;            //Playerオブジェクトのモデル番号
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
	int GetBulletSize() { return Size; };

	//引数:なし
	//戻値:Flg_
	//Flg_をを返す
	bool GetBulletFlg() { return Flg; };
};