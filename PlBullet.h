#pragma once
#include "Engine/GameObject.h"

//�e���Ǘ�����N���X
class PlBullet : public GameObject
{
	int hModel_;			//���f���ԍ�
	int BulletSize_ ;		//�e�̑傫��
	bool BulletFlg_;		//�e�̔��ˏ��(0:������ / 1:���ˍς�)
public:
	//�R���X�g���N�^
	PlBullet(GameObject* parent);

	//�f�X�g���N�^
	~PlBullet();

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	//�Q�b�^�[(BulletSize_)
	int GetBulletSize_();
};