//�e�N���X
#include "Player.h"
#include "PlayerHP.h"
//�q�N���X
//����
//�G���W���E���̑��̃N���X
#include "Engine/Image.h"

//�R���X�g���N�^
PlayerHP::PlayerHP(GameObject * parent)
	:GameObject(parent, "PlayerHP"),
	HP_POS(XMVectorSet(-0.87f, -0.95f, 0.0f, 0.0f)),
	hHPNumberPict_{ -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 }, hHartPict_(-1), HP_(10)
{
}

//�f�X�g���N�^
PlayerHP::~PlayerHP()
{
}

//������
void PlayerHP::Initialize()
{
	//HP�̐����摜�f�[�^�̃��[�h
	hHPNumberPict_[0] = Image::Load("0.png");
	assert(hHPNumberPict_[0] >= 0);
	hHPNumberPict_[1] = Image::Load("1.png");
	assert(hHPNumberPict_[1] >= 0);
	hHPNumberPict_[2] = Image::Load("2.png");
	assert(hHPNumberPict_[2] >= 0);
	hHPNumberPict_[3] = Image::Load("3.png");
	assert(hHPNumberPict_[3] >= 0);
	hHPNumberPict_[4] = Image::Load("4.png");
	assert(hHPNumberPict_[4] >= 0);
	hHPNumberPict_[5] = Image::Load("5.png");
	assert(hHPNumberPict_[5] >= 0);
	hHPNumberPict_[6] = Image::Load("6.png");
	assert(hHPNumberPict_[6] >= 0);
	hHPNumberPict_[7] = Image::Load("7.png");
	assert(hHPNumberPict_[7] >= 0);
	hHPNumberPict_[8] = Image::Load("8.png");
	assert(hHPNumberPict_[8] >= 0);
	hHPNumberPict_[9] = Image::Load("9.png");
	assert(hHPNumberPict_[9] >= 0);
	hHPNumberPict_[10] = Image::Load("10.png");
	assert(hHPNumberPict_[10] >= 0);

	//�n�[�g�摜�f�[�^�̃��[�h
	hHartPict_ = Image::Load("HP.png");
	assert(hHartPict_ >= 0);

	//�ʒu�ύX
	transform_.position_ = HP_POS;
}

//�X�V
void PlayerHP::Update()
{
	//HP�̎擾
	HP_ = ((Player*)GetParent())->GetHP();
}

//�`��
void PlayerHP::Draw()
{
	//HP�̐����摜�̕`��
	Image::SetTransform(hHPNumberPict_[HP_], transform_);
	Image::Draw(hHPNumberPict_[HP_]);

	//�n�[�g�摜�̕`��
	Image::SetTransform(hHartPict_, transform_);
	Image::Draw(hHartPict_);
}

//�J��
void PlayerHP::Release()
{
}