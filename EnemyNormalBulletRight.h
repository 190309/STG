#pragma once
#include "Engine/GameObject.h"

//�G�e���Ǘ�����N���X
class EnemyNormalBulletRight : public GameObject
{
	int hModel_;			//���f���ԍ�
	bool BulletFlg_;		//�e�̔��ˏ��(0:������ / 1:���ˍς�)
public:
	//�R���X�g���N�^
	EnemyNormalBulletRight(GameObject* parent);

	//�f�X�g���N�^
	~EnemyNormalBulletRight();

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};