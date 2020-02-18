#pragma once
#include "Engine/GameObject.h"

//�G�e���Ǘ�����N���X
class EnemyBullet : public GameObject
{
	int hModel_;    //���f���ԍ�
public:
	//�R���X�g���N�^
	EnemyBullet(GameObject* parent);

	//�f�X�g���N�^
	~EnemyBullet();

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};