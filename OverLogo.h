#pragma once
//�e�N���X
//�q�N���X
//����
//�G���W���E���̑�
#include "Engine/GameObject.h"

//�Q�[���I�[�o�[���S���Ǘ�����N���X
class OverLogo : public GameObject
{
private:
	int hPict_;    //�摜�ԍ�

public:
	//�R���X�g���N�^
	OverLogo(GameObject* parent);

	//�f�X�g���N�^
	~OverLogo();

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};
