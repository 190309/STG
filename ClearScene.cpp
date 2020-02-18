//�G���W��
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
//�e�N���X
#include "ClearScene.h"
//�q�N���X
//���̑�

//�R���X�g���N�^
ClearScene::ClearScene(GameObject * parent)
	: GameObject(parent, "ClearScene"), hPict_(-1)
{
}

//������
void ClearScene::Initialize()
{
	//�摜�f�[�^�̃��[�h
	hPict_ = Image::Load("ClearLogo.png");
	assert(hPict_ >= 0);
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
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//�J��
void ClearScene::Release()
{
}
