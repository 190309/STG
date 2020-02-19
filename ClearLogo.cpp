//�e�N���X
#include "ClearLogo.h"
//�q�N���X
//����
//�G���W���E���̑�
#include "Engine/Image.h"
#include "Engine/SceneManager.h"

//�R���X�g���N�^
ClearLogo::ClearLogo(GameObject * parent)
	: GameObject(parent, "ClearLogo"), hPict_(-1)
{
}

//�f�X�g���N�^
ClearLogo::~ClearLogo()
{
}

//������
void ClearLogo::Initialize()
{
	//�摜�f�[�^�̃��[�h
	hPict_ = Image::Load("ClearLogo.png");
	assert(hPict_ >= 0);
}

//�X�V
void ClearLogo::Update()
{
}

//�`��
void ClearLogo::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//�J��
void ClearLogo::Release()
{
}
