//�e�N���X
#include "Stage.h"
//�q�N���X
#include "Satellite.h"
//����
//�G���W���E���̑�

//�R���X�g���N�^
Stage::Stage(GameObject * parent)
	:GameObject(parent, "Stage")
{
}

//�f�X�g���N�^
Stage::~Stage()
{
}

//������
void Stage::Initialize()
{
	Instantiate<Satellite>(this);
}

//�X�V
void Stage::Update()
{
	//�q���𓮂����֐�
	MoveChild();
}

//�q���𓮂����֐�
void Stage::MoveChild()
{
	((Satellite*)FindObject("Satellite"))->Move();
}

//�`��
void Stage::Draw()
{
}

//�J��
void Stage::Release()
{
}