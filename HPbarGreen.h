#pragma once
#include "Engine/GameObject.h"

//HPbarGreen���Ǘ�����N���X
class HPbarGreen : public GameObject
{
	int hModel_;    //���f���ԍ�
	float InitHP_;	//�G����HP
	float HP_;		//�GHP
public:
	//�R���X�g���N�^
	HPbarGreen(GameObject* parent);

	//�f�X�g���N�^
	~HPbarGreen();

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};