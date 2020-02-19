//�e�N���X
#include "StartScene.h"
//�q�N���X
#include "StartLogo.h"
//����
//�G���W���E���̑�
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

//�R���X�g���N�^
StartScene::StartScene(GameObject * parent)
	: GameObject(parent, "StartScene")
{
}

//������
void StartScene::Initialize()
{
	Instantiate<StartLogo>(this);
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
}

//�J��
void StartScene::Release()
{
}
