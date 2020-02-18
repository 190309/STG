//�e�N���X
#include "StartScene.h"
//�q�N���X
//����
//�G���W���E���̑�
#include "Engine/Input.h"
#include "Engine/Image.h"
#include "Engine/SceneManager.h"

//�R���X�g���N�^
StartScene::StartScene(GameObject * parent)
	: GameObject(parent, "StartScene"), hPict_(-1)
{
}

//������
void StartScene::Initialize()
{
	//�摜�f�[�^�̃��[�h
	hPict_ = Image::Load("StartLogo.png");
	assert(hPict_ >= 0);
}

//�X�V
void StartScene::Update()
{
	//�X�y�[�X�L�[���������烁�C���Q�[���V�[���ֈړ�
	if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}

}

//�`��
void StartScene::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//�J��
void StartScene::Release()
{
}
