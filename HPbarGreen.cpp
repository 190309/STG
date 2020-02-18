//�G���W��
#include "Engine/Image.h"
//�e�N���X
#include "HPbarGreen.h"
//�q�N���X
//���̑�
#include "Enemy.h"

//�R���X�g���N�^
HPbarGreen::HPbarGreen(GameObject * parent)
	:GameObject(parent, "HPbarGreen"), hPict_(-1), InitHP_(((Enemy*)FindObject("Enemy"))->GetHP_())
{
}

//�f�X�g���N�^
HPbarGreen::~HPbarGreen()
{
}

//������
void HPbarGreen::Initialize()
{
	//�摜�f�[�^�̃��[�h
	hPict_ = Image::Load("GreenHPBae.png");
	assert(hPict_ >= 0);

	//�����ʒu
	transform_.position_.vecY = 4.0f;
	transform_.position_.vecZ = -0.0001f;
	transform_.rotate_.vecX = 15.0f;
}

//�X�V
void HPbarGreen::Update()
{
	//����HP�̎擾����ё傫���ύX
	HP_ = ((Enemy*)FindObject("Enemy"))->GetHP_();
	if (HP_ < 0)
	{
		HP_ = 0;
	}
	transform_.scale_.vecX = HP_ * 20 / InitHP_ * 1.0f;
	transform_.position_.vecX = ( HP_ * 20 / InitHP_ / 2 - 10 ) / 2;
}

//�`��
void HPbarGreen::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//�J��
void HPbarGreen::Release()
{
}