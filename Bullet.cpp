#include "Bullet.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"
#include "Engine/Input.h"

//�R���X�g���N�^
Bullet::Bullet(GameObject * parent)
	:GameObject(parent, "Bullet"), hModel_(-1)
{
	Counter_ = 20;
	Flg_ = false;
}

//�f�X�g���N�^
Bullet::~Bullet()
{
}

//������
void Bullet::Initialize()
{
	//���f���f�[�^�̃��[�h
	hModel_ = Model::Load("Bullet.fbx");
	assert(hModel_ >= 0);
}

//�X�V
void Bullet::Update()
{
	//Z�L�[�������Ă����
	if (Input::IsKey(DIK_Z) && Flg_ == false)
	{
		//�e�̏����ʒu
		if (Counter_ == 20)
		{
			transform_.position_.vecZ = 3.0f;
		}

		//�e�̊g��
		if (Counter_ < 180)
		{
			Counter_++;
		}
		transform_.scale_.vecX = Counter_ / 120.0f;
		transform_.scale_.vecY = Counter_ / 120.0f;
		transform_.scale_.vecZ = Counter_ / 120.0f;

		//��L�[
		if (Input::IsKey(DIK_UP))
		{
			transform_.position_.vecY += 0.1f;
		}

		//���L�[
		if (Input::IsKey(DIK_DOWN))
		{
			transform_.position_.vecY -= 0.1f;
		}

		//�E�L�[
		if (Input::IsKey(DIK_RIGHT))
		{
			transform_.position_.vecX += 0.1f;
		}

		//���L�[
		if (Input::IsKey(DIK_LEFT))
		{
			transform_.position_.vecX -= 0.1f;
		}
	}

	//Z�L�[�𗣂�����
	if (Input::IsKeyUp(DIK_Z) && Flg_ == false)
	{
		Flg_ = true;
		//�����蔻�萶��
		SphereCollider* collision = new SphereCollider(XMVectorSet(0, 0, 0, 0), Counter_ / 60.0f * 1.2);
		AddCollider(collision);
	}

	//�e�̈ړ�
	if (Flg_ == true)
	{
		transform_.position_.vecZ += 0.6f;
	}

	//�e�̗L���͈�
	if (transform_.position_.vecZ > 100)
	{
		KillMe();
	}
}

//�`��
void Bullet::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//�J��
void Bullet::Release()
{
}

//�Q�b�^�[(Counter_)
int Bullet::GetCounter_()
{
	return Counter_;
}
