#pragma once
#include "Engine/GameObject.h"

//�G�e���Ǘ�����N���X
class EnemyNormalBulletLeft : public GameObject
{
	int hModel_;			//���f���ԍ�
	bool BulletFlg_;		//�e�̔��ˏ��(0:������ / 1:���ˍς�)
public:
	//�R���X�g���N�^
	EnemyNormalBulletLeft(GameObject* parent);

	//�f�X�g���N�^
	~EnemyNormalBulletLeft();

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};