//�e�N���X
#include "StartLogo.h"
//�q�N���X
//����
//�G���W���E���̑�
#include "Engine/Image.h"

//�R���X�g���N�^
StartLogo::StartLogo(GameObject * parent)
	: GameObject(parent, "StartLogo"), hPict_(-1)
{
}

//�f�X�g���N�^
StartLogo::~StartLogo()
{
}

//������
void StartLogo::Initialize()
{
	//�摜�f�[�^�̃��[�h
	hPict_ = Image::Load("StartLogo.png");
	assert(hPict_ >= 0);
}

//�X�V
void StartLogo::Update()
{
}

//�`��
void StartLogo::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//�J��
void StartLogo::Release()
{
}
