#pragma once
//�e�N���X
//�q�N���X
//����
//�G���W���E���̑��̃N���X
#include "Engine/GameObject.h"

//�v���C���[��HP�̕\�����Ǘ�����N���X
class PlayerHP : public GameObject
{
private:
	//�x�N�g��(�萔)
	const XMVECTOR HP_POS;		//�摜�̈ʒu		(X:-0.87f, Y:-0.95f, Z:0.0f)

	//�x�N�g��(�ϐ�)

	//�萔

	//�ϐ�
	int hHPNumberPict_[11];		//HP�̐����摜�ԍ�	(-1:�G���[ / 0:����ǂݍ���)
	int HP_;					//���@��HP			(-1 < HP_ < 11)

public:
	//�R���X�g���N�^
	PlayerHP(GameObject* parent);

	//�f�X�g���N�^
	~PlayerHP();

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};