//�e�N���X
#include "PlBullet.h"
//�q�N���X
//����
//�G���W���E���̑��̃N���X
#include "Engine/Input.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"

//�R���X�g���N�^
PlBullet::PlBullet(GameObject * parent)
	:GameObject(parent, "PlBullet"),
	MAX_SIZE(180), AJUST_COLL(60.0f), AJUST_SIZE(120.0f), MAX_RANGE(100.0f), MOVE(0.6f), POS(3.0f),
	Flg_(false), hModel_(-1), Size_(20), pPlayer_((Player*)FindObject("Player"))
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
	//�e�����ˎ��AZ�L�[�������Ă���Ԓe���g�储��шړ�
	if (Input::IsKey(DIK_Z) && Flg_ == false)
	{
		//�e�̈ʒu
		transform_.position_ = pPlayer_->GetPosition();
		transform_.position_.vecZ += POS;

		//�e�̊g��
		if (Size_ < MAX_SIZE)
		{
			Size_++;
			transform_.scale_ = XMVectorSet(Size_ / AJUST_SIZE, Size_ / AJUST_SIZE, Size_ / AJUST_SIZE, Size_ / AJUST_SIZE);
		}
	}

	//�e�����ˎ��AZ�L�[�𗣂�����t���O�ύX
	if (Input::IsKeyUp(DIK_Z) && Flg_ == false)
	{
		Flg_ = true;
		//�����蔻�萶��
		SphereCollider* collision = new SphereCollider(XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f), Size_ / AJUST_COLL);
		AddCollider(collision);
	}

	//�e�̈ړ�
	if (Flg_ == true)
	{
		transform_.position_.vecZ += MOVE;
	}

	//�e�̗L���͈�
	if (transform_.position_.vecZ > MAX_RANGE)
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