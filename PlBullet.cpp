//�e�N���X
#include "PlBullet.h"
//�q�N���X
//�G���W���E���̑��̃N���X
#include "Engine/Input.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"

//�R���X�g���N�^
PlBullet::PlBullet(GameObject * parent)
	:GameObject(parent, "PlBullet"), hModel_(-1), BulletSize_(20), BulletFlg_(false)
{
}

//�f�X�g���N�^
PlBullet::~PlBullet()
{
}

//������
void PlBullet::Initialize()
{
	//���f���f�[�^�̃��[�h
	hModel_ = Model::Load("Bullet.fbx");
	assert(hModel_ >= 0);
}

//�X�V
void PlBullet::Update()
{
	//�����ʒu
	if (BulletFlg_ == false)
	{
		transform_.position_.vecZ = 3.0f;
	}

	//�e�����ˎ��AZ�L�[�������Ă���Ԓe���g��
	if (Input::IsKey(DIK_Z) && BulletFlg_ == false)
	{
		//�e�̊g��
		if (BulletSize_ < 180)
		{
			BulletSize_++;
		}
		transform_.scale_.vecX = BulletSize_ / 120.0f;
		transform_.scale_.vecY = BulletSize_ / 120.0f;
		transform_.scale_.vecZ = BulletSize_ / 120.0f;

		//��L�[���͂ŏ�ֈړ�
		if (Input::IsKey(DIK_UP))
		{
			//�ړ��\
			if (transform_.position_.vecY < 2.75f)
			{
				transform_.position_.vecY += 0.1f;
			}
		}

		//���L�[���͂ŉ��ֈړ�
		if (Input::IsKey(DIK_DOWN))
		{
			//�ړ��\
			if (transform_.position_.vecY > -2.75f)
			{
				transform_.position_.vecY -= 0.1f;
			}
		}

		//�E�L�[���͂ŉE�ֈړ�
		if (Input::IsKey(DIK_RIGHT))
		{
			//�ړ��\
			if (transform_.position_.vecX < 6)
			{
				transform_.position_.vecX += 0.1f;
			}
		}

		//���L�[���͂ō��ֈړ�
		if (Input::IsKey(DIK_LEFT))
		{
			//�ړ��\
			if (transform_.position_.vecX > -6)
			{
				transform_.position_.vecX -= 0.1f;
			}
		}
	}

	//�e�����ˎ��AZ�L�[�𗣂�����t���O�ύX
	if (Input::IsKeyUp(DIK_Z) && BulletFlg_ == false)
	{
		BulletFlg_ = true;
		//�����蔻�萶��
		SphereCollider* collision = new SphereCollider(XMVectorSet(0, 0, 0, 0), BulletSize_ / 60.0f * 1.2f);
		AddCollider(collision);
	}

	//�e�̈ړ�
	if (BulletFlg_ == true)
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
void PlBullet::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//�J��
void PlBullet::Release()
{
}

//�Q�b�^�[(BulletSize_)
int PlBullet::GetBulletSize_()
{
	return BulletSize_;
}
