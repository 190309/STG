#include "Global.h"
#include "Model.h"

//3Dモデル（FBXファイル）を管理する
namespace Model
{
	//ロード済みのモデルデータ一覧
	std::vector<ModelData*>	datas_;

	//初期化
	void Initialize()
	{
		AllRelease();
	}

	//モデルをロード
	int Load(std::string fileName)
	{
			ModelData* pData = new ModelData;


			//開いたファイル一覧から同じファイル名のものが無いか探す
			bool isExist = false;
			for (int i = 0; i < datas_.size(); i++)
			{
				//すでに開いている場合
				if (datas_[i] != nullptr && datas_[i]->fileName == fileName)
				{
					pData->pFbx = datas_[i]->pFbx;
					isExist = true;
					break;
				}
			}

			//新たにファイルを開く
			if (isExist == false)
			{
				pData->pFbx = new Fbx;
				if (FAILED(pData->pFbx->Load(fileName)))
				{
					//開けなかった
					SAFE_DELETE(pData->pFbx);
					SAFE_DELETE(pData);
					return -1;
				}

				//無事開けた
				pData->fileName = fileName;
			}


			//使ってない番号が無いか探す
			for (int i = 0; i < datas_.size(); i++)
			{
				if (datas_[i] == nullptr)
				{
					datas_[i] = pData;
					return i;
				}
			}

			//新たに追加
			datas_.push_back(pData);
			return (int)datas_.size() - 1;
	}



	//描画
	void Draw(int handle)
	{
		if (handle < 0 || handle >= datas_.size() || datas_[handle] == nullptr)
		{
			return;
		}

		//アニメーションを進める
		datas_[handle]->nowFrame += datas_[handle]->animSpeed;

		//最後までアニメーションしたら戻す
		if (datas_[handle]->nowFrame > (float)datas_[handle]->endFrame)
			datas_[handle]->nowFrame = (float)datas_[handle]->startFrame;



		if (datas_[handle]->pFbx)
		{
			datas_[handle]->pFbx->Draw(datas_[handle]->transform, (int)datas_[handle]->nowFrame);
		}
	}


	//任意のモデルを開放
	void Release(int handle)
	{
		if (handle < 0 || handle >= datas_.size() || datas_[handle] == nullptr)
		{
			return;
		}

		//同じモデルを他でも使っていないか
		bool isExist = false;
		for (int i = 0; i < datas_.size(); i++)
		{
			//すでに開いている場合
			if (datas_[i] != nullptr && i != handle && datas_[i]->pFbx == datas_[handle]->pFbx)
			{
				isExist = true;
				break;
			}
		}

		//使ってなければモデル解放
		if (isExist == false )
		{
			SAFE_DELETE(datas_[handle]->pFbx);
		}


		SAFE_DELETE(datas_[handle]);
	}


	//全てのモデルを解放
	void AllRelease()
	{
		for (int i = 0; i < datas_.size(); i++)
		{
			if (datas_[i] != nullptr)
			{
				Release(i);
			}
		}
		datas_.clear();
	}


	//アニメーションのフレーム数をセット
	void SetAnimFrame(int handle, int startFrame, int endFrame, float animSpeed)
	{
		datas_[handle]->SetAnimFrame(startFrame, endFrame, animSpeed);
	}


	//現在のアニメーションのフレームを取得
	int GetAnimFrame(int handle)
	{
		return (int)datas_[handle]->nowFrame;
	}


	//任意のボーンの位置を取得
	XMVECTOR GetBonePosition(int handle, std::string boneName)
	{
		XMVECTOR pos = datas_[handle]->pFbx->GetBonePosition(boneName);
		return  XMVector3TransformCoord(pos, datas_[handle]->transform.GetWorldMatrix());
	}


	//ワールド行列を設定
	void SetTransform(int handle, Transform & transform)
	{
		if (handle < 0 || handle >= datas_.size())
		{
			return;
		}

		datas_[handle]->transform = transform;
	}


	//ワールド行列の取得
	XMMATRIX GetMatrix(int handle)
	{
		return datas_[handle]->transform.GetWorldMatrix();
	}


	//レイキャスト（レイを飛ばして当たり判定）
	void RayCast(int handle, RayCastData *data)
	{
			XMVECTOR target = data->start + data->dir;
			XMMATRIX matInv = XMMatrixInverse(nullptr, datas_[handle]->transform.GetWorldMatrix());
			data->start = XMVector3TransformCoord(data->start, matInv);
			target = XMVector3TransformCoord(target, matInv);
			data->dir = target - data->start;

			datas_[handle]->pFbx->RayCast(data); 
	}
}