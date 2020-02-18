//�G���W��
#include "Engine/Image.h"
//�e�N���X
#include "HPbarRed.h"
//�q�N���X
//���̑�

//�R���X�g���N�^
HPbarRed::HPbarRed(GameObject * parent)
	:GameObject(parent, "HPbarRed"), hPict_(-1)
{
}

//�f�X�g���N�^
HPbarRed::~HPbarRed()
{
}

//������
void HPbarRed::Initialize()
{
	//�摜�f�[�^�̃��[�h
	hPict_ = Image::Load("RedHPBar.png");
	assert(hPict_ >= 0);

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
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//�J��
void HPbarRed::Release()
{
}