#pragma once
#include "Engine/GameObject.h"

//HPbarRed���Ǘ�����N���X
class HPbarRed : public GameObject
{
	int hPict_;    //�摜�ԍ�
public:
	//�R���X�g���N�^
	HPbarRed(GameObject* parent);

	//�f�X�g���N�^
	~HPbarRed();

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};