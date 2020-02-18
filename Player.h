#pragma once
#include "Engine/GameObject.h"

//���@���Ǘ�����N���X
class Player : public GameObject
{
	int hModel_;			//���f���ԍ�
	int HP_;				//���@�̗�
	bool Form_;				//���@�̉�]����
	bool BulletFlg_;		//�e�̐����t���O(0:������ / 1:�����ς�)
public:
	//�R���X�g���N�^
	Player(GameObject* parent);

	//�f�X�g���N�^
	~Player();

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	//�Q�b�^�[(posX)
	float GetPosX();

	//�Q�b�^�[(posY)
	float GetPosY();

	//�����ɓ�������
	//�����FpTarget ������������
	void OnCollision(GameObject *pTarget) override;
};