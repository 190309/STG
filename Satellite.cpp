//�e�N���X
#include "Satellite.h"
//�q�N���X
//����
//�G���W���E���̑�
#include "Engine/Model.h"

//�R���X�g���N�^
Satellite::Satellite(GameObject * parent)
	:GameObject(parent, "Satellite"), hModel_(-1)
{
}

//�f�X�g���N�^
Satellite::~Satellite()
{
}

//������
void Satellite::Initialize()
{
	//���f���f�[�^�̃��[�h
	hModel_ = Model::Load("Satellite/Satellite.fbx");
	assert(hModel_ >= 0);

	transform_.position_ = XMVectorSet(30,0,150,0);
}

//�X�V
void Satellite::Update()
{
	if (transform_.position_.vecZ < 0)
	{
		transform_.position_.vecZ = 1000.0f;
	}
}

//�`��
void Satellite::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//�J��
void Satellite::Release()
{
}