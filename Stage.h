#pragma once
//�e�N���X
//�q�N���X
//����
//�G���W���E���̑�
#include "Engine/GameObject.h"

//���@���Ǘ�����N���X
class Stage : public GameObject
{
private:
	//�x�N�g��(�萔)

	//�x�N�g��(�ϐ�)

	//�萔	

	//�ϐ�

	//�֐�

	//����:�Ȃ�
	//�ߒl:�Ȃ�
	//�q���𓮂����֐�
	void MoveChild();

public:
	//�R���X�g���N�^
	Stage(GameObject* parent);

	//�f�X�g���N�^
	~Stage();

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};