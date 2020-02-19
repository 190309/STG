//�e�N���X
#include "OverLogo.h"
//�q�N���X
//����
//�G���W���E���̑�
#include "Engine/Image.h"
#include "Engine/SceneManager.h"

//�R���X�g���N�^
OverLogo::OverLogo(GameObject * parent)
	: GameObject(parent, "OverLogo"), hPict_(-1)
{
}

//�f�X�g���N�^
OverLogo::~OverLogo()
{
}

//������
void OverLogo::Initialize()
{
	//�摜�f�[�^�̃��[�h
	hPict_ = Image::Load("ClearLogo.png");
	assert(hPict_ >= 0);
}

//�X�V
void OverLogo::Update()
{
}

//�`��
void OverLogo::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//�J��
void OverLogo::Release()
{
}
