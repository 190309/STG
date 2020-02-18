#include "TestScene.h"
#include "Engine/Model.h"
#include "Engine/Input.h"

//�R���X�g���N�^
TestScene::TestScene(GameObject * parent)
	: GameObject(parent, "TestScene"), hModel_(-1)
{

}

//������
void TestScene::Initialize()
{
//	transform_.position_.vecX = -10;
	hModel_ = Model::Load("Player.fbx");
}

//�X�V
void TestScene::Update()
{
	//transform_.rotate_.vecZ -= 5.0f;
	//transform_.position_.vecX += 0.1f;

	//�E�L�[��������Ă�����
	if(Input::IsKeyUp(DIK_RIGHT))
	{
		transform_.position_.vecX += 0.8f;
	}
	//���L�[��������Ă�����
	if(Input::IsKey(DIK_LEFT))
	{
		transform_.position_.vecX -= 0.1f;
	}
}

//�`��
void TestScene::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//�J��
void TestScene::Release()
{
}
