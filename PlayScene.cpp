//�e�N���X
#include "PlayScene.h"
//�q�N���X
#include "Player.h"
#include "Enemy.h"
//����
//�G���W���E���̑�


//�R���X�g���N�^
PlayScene::PlayScene(GameObject * parent)
	: GameObject(parent, "PlayScene")
{
}

//������
void PlayScene::Initialize()
{
	Instantiate<Player>(this);
//	Instantiate<Enemy>(this);
}

//�X�V
void PlayScene::Update()
{
}

//�`��
void PlayScene::Draw()
{
}

//�J��
void PlayScene::Release()
{
}