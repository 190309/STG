#pragma once
//�e�N���X
//�q�N���X
//����
//�G���W���E���̑�
#include "Engine/GameObject.h"

//�X�^�[�g���S���Ǘ�����N���X
class StartLogo : public GameObject
{
private:
	int hPict_;    //�摜�ԍ�

public:
	//�R���X�g���N�^
	StartLogo(GameObject* parent);

	//�f�X�g���N�^
	~StartLogo();

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};
