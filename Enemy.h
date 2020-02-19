#pragma once
#include "Engine/GameObject.h"

//�G���Ǘ�����N���X
class Enemy : public GameObject
{
	XMVECTOR pos;
	GameObject * pTarget;
	int hModel_;		//���f���ԍ�
	int AtcCnt_;		//�s���^�C�~���O
	int AtcPtr_;		//�U���̎��
	float HP_;			//�̗�
	float PlX_;			//Player��X���W
	float PlY_;			//Player��Y���W
	bool Dec_;			//�㉺�̕���(0:������ւ̈ړ� / 1:�������ւ̈ړ�)
	bool RoleFlg_;		//��]�t���O
public:
	//�R���X�g���N�^
	Enemy(GameObject* parent);

	//�f�X�g���N�^
	~Enemy();

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	//�Q�b�^�[(HP_)
	float GetHP_();

	//�Q�b�^�[(posX)
	float GetPosX();

	//�Q�b�^�[(posY)
	float GetPosY();

	//�Q�b�^�[(rotZ)
	float GetRotZ();

	//�����ɓ�������
	//�����FpTarget ������������
	void OnCollision(GameObject *pTarget) override;
};