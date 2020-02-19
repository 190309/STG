//�e�N���X
#include "ClearScene.h"
//�q�N���X
#include "ClearLogo.h"
//����
//�G���W���E���̑�
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

//�R���X�g���N�^
ClearScene::ClearScene(GameObject * parent)
	: GameObject(parent, "ClearScene")
{
}

//������
void ClearScene::Initialize()
{
	Instantiate<ClearLogo>(this);
}

//�X�V
void ClearScene::Update()
{
	//�X�y�[�X�L�[����������
	if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_START);
	}
}

//�`��
void ClearScene::Draw()
{
}

//�J��
void ClearScene::Release()
{
}
