//�G���W��
#include "Engine/Model.h"
//�e�N���X
#include "HPbarRed.h"
//�q�N���X
//���̑�

//�R���X�g���N�^
HPbarRed::HPbarRed(GameObject * parent)
	:GameObject(parent, "HPbarRed"), hModel_(-1)
{
}

//�f�X�g���N�^
HPbarRed::~HPbarRed()
{
}

//������
void HPbarRed::Initialize()
{
	//���f���f�[�^�̃��[�h
	hModel_ = Model::Load("HPbarRed.fbx");
	assert(hModel_ >= 0);

	//�����ʒu
	transform_.position_.vecY = 4.0f;
	transform_.scale_.vecX = 20.0f;
	transform_.rotate_.vecX = 15.0f;
}

//�X�V
void HPbarRed::Update()
{
}

//�`��
void HPbarRed::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//�J��
void HPbarRed::Release()
{
}