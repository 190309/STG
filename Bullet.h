#pragma once
#include "Engine/GameObject.h"

//�e���Ǘ�����N���X
class Bullet : public GameObject
{
	int hModel_;    //���f���ԍ�
	int Counter_ ;	//�e�̑傫��
	bool Flg_;		//�e�̔��ˏ��
public:
	//�R���X�g���N�^
	Bullet(GameObject* parent);

	//�f�X�g���N�^
	~Bullet();

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	//�Q�b�^�[(Counter_)
	int GetCounter_();
};