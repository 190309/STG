//�G���W��
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
//�e�N���X
#include "GameOverScene.h"
//�q�N���X
//���̑�

//�R���X�g���N�^
GameOverScene::GameOverScene(GameObject * parent)
	: GameObject(parent, "GameOverScene"), hPict_(-1)
{
}

//������
void GameOverScene::Initialize()
{
	//�摜�f�[�^�̃��[�h
	hPict_ = Image::Load("ClearLogo.png");
	assert(hPict_ >= 0);
}

//�X�V
void GameOverScene::Update()
{
	//�X�y�[�X�L�[����������
	if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_START);
	}

}

//�`��
void GameOverScene::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//�J��
void GameOverScene::Release()
{
}
