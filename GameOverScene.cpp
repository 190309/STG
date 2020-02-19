//�e�N���X
#include "GameOverScene.h"
//�q�N���X
#include "OverLogo.h"
//����
//�G���W���E���̑�
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

//�R���X�g���N�^
GameOverScene::GameOverScene(GameObject * parent)
	: GameObject(parent, "GameOverScene")
{
}

//������
void GameOverScene::Initialize()
{
	Instantiate<OverLogo>(this);
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
}

//�J��
void GameOverScene::Release()
{
}
