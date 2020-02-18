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
	POS(XMVectorSet(0.0f, 0.0f, 3.0f, 0.0f)), CENTER(XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f)), MOVE(XMVectorSet(0.0f, 0.0f, 0.6f, 0.0f)),
	Scale(XMVectorSet(Size / AJUST_SIZE, Size / AJUST_SIZE, Size / AJUST_SIZE, Size / AJUST_SIZE)),
	AJUST_COLL(72), MAX_SIZE(180), AJUST_SIZE(120.0f), MAX_RANGE(100.0f),
	hModel_(-1), Size(20), Flg(false), pPlayer((Player*)FindObject("Player"))
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
	if (Input::IsKey(DIK_Z) && Flg == false)
	{
		//�e�̈ʒu
		transform_.position_ = pPlayer->GetPosition() + POS;

		//�e�̊g��
		if (Size < MAX_SIZE)
		{
			Size++;
			Scale = XMVectorSet(Size / AJUST_SIZE, Size / AJUST_SIZE, Size / AJUST_SIZE, Size / AJUST_SIZE);
			transform_.scale_ = Scale;
		}
	}

	//�e�����ˎ��AZ�L�[�𗣂�����t���O�ύX
	if (Input::IsKeyUp(DIK_Z) && Flg == false)
	{
		Flg = true;
		//�����蔻�萶��
		SphereCollider* collision = new SphereCollider(CENTER, Size / AJUST_COLL);
		AddCollider(collision);
	}

	//�e�̈ړ�
	if (Flg == true)
	{
		transform_.position_ += MOVE;
	}

	//�e�̗L���͈�
	if (transform_.position_.vecZ < MAX_RANGE)
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