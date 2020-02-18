#include "Global.h"
#include "Model.h"

//3D���f���iFBX�t�@�C���j���Ǘ�����
namespace Model
{
	//���[�h�ς݂̃��f���f�[�^�ꗗ
	std::vector<ModelData*>	datas_;

	//������
	void Initialize()
	{
		AllRelease();
	}

	//���f�������[�h
	int Load(std::string fileName)
	{
			ModelData* pData = new ModelData;


			//�J�����t�@�C���ꗗ���瓯���t�@�C�����̂��̂��������T��
			bool isExist = false;
			for (int i = 0; i < datas_.size(); i++)
			{
				//���łɊJ���Ă���ꍇ
				if (datas_[i] != nullptr && datas_[i]->fileName == fileName)
				{
					pData->pFbx = datas_[i]->pFbx;
					isExist = true;
					break;
				}
			}

			//�V���Ƀt�@�C�����J��
			if (isExist == false)
			{
				pData->pFbx = new Fbx;
				if (FAILED(pData->pFbx->Load(fileName)))
				{
					//�J���Ȃ�����
					SAFE_DELETE(pData->pFbx);
					SAFE_DELETE(pData);
					return -1;
				}

				//�����J����
				pData->fileName = fileName;
			}


			//�g���ĂȂ��ԍ����������T��
			for (int i = 0; i < datas_.size(); i++)
			{
				if (datas_[i] == nullptr)
				{
					datas_[i] = pData;
					return i;
				}
			}

			//�V���ɒǉ�
			datas_.push_back(pData);
			return (int)datas_.size() - 1;
	}



	//�`��
	void Draw(int handle)
	{
		if (handle < 0 || handle >= datas_.size() || datas_[handle] == nullptr)
		{
			return;
		}

		//�A�j���[�V������i�߂�
		datas_[handle]->nowFrame += datas_[handle]->animSpeed;

		//�Ō�܂ŃA�j���[�V����������߂�
		if (datas_[handle]->nowFrame > (float)datas_[handle]->endFrame)
			datas_[handle]->nowFrame = (float)datas_[handle]->startFrame;



		if (datas_[handle]->pFbx)
		{
			datas_[handle]->pFbx->Draw(datas_[handle]->transform, (int)datas_[handle]->nowFrame);
		}
	}


	//�C�ӂ̃��f�����J��
	void Release(int handle)
	{
		if (handle < 0 || handle >= datas_.size() || datas_[handle] == nullptr)
		{
			return;
		}

		//�������f���𑼂ł��g���Ă��Ȃ���
		bool isExist = false;
		for (int i = 0; i < datas_.size(); i++)
		{
			//���łɊJ���Ă���ꍇ
			if (datas_[i] != nullptr && i != handle && datas_[i]->pFbx == datas_[handle]->pFbx)
			{
				isExist = true;
				break;
			}
		}

		//�g���ĂȂ���΃��f�����
		if (isExist == false )
		{
			SAFE_DELETE(datas_[handle]->pFbx);
		}


		SAFE_DELETE(datas_[handle]);
	}


	//�S�Ẵ��f�������
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


	//�A�j���[�V�����̃t���[�������Z�b�g
	void SetAnimFrame(int handle, int startFrame, int endFrame, float animSpeed)
	{
		datas_[handle]->SetAnimFrame(startFrame, endFrame, animSpeed);
	}


	//���݂̃A�j���[�V�����̃t���[�����擾
	int GetAnimFrame(int handle)
	{
		return (int)datas_[handle]->nowFrame;
	}


	//�C�ӂ̃{�[���̈ʒu���擾
	XMVECTOR GetBonePosition(int handle, std::string boneName)
	{
		XMVECTOR pos = datas_[handle]->pFbx->GetBonePosition(boneName);
		return  XMVector3TransformCoord(pos, datas_[handle]->transform.GetWorldMatrix());
	}


	//���[���h�s���ݒ�
	void SetTransform(int handle, Transform & transform)
	{
		if (handle < 0 || handle >= datas_.size())
		{
			return;
		}

		datas_[handle]->transform = transform;
	}


	//���[���h�s��̎擾
	XMMATRIX GetMatrix(int handle)
	{
		return datas_[handle]->transform.GetWorldMatrix();
	}


	//���C�L���X�g�i���C���΂��ē����蔻��j
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