#pragma once
//�e�N���X
//�q�N���X
//����
//�G���W���E���̑�
#include "Engine/GameObject.h"

//���@���Ǘ�����N���X
class Satellite : public GameObject
{
private:
	//�x�N�g��(�萔)

	//�x�N�g��(�ϐ�)

	//�萔	

	//�ϐ�
	int hModel_;		//���f���ԍ�	(-1:�G���[ / 0:����ǂݍ���)

public:
	//�R���X�g���N�^
	Satellite(GameObject* parent);

	//�f�X�g���N�^
	~Satellite();

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};