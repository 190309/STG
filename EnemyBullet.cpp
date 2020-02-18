#include "EnemyBullet.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"

//�R���X�g���N�^
EnemyBullet::EnemyBullet(GameObject * parent)
	:GameObject(parent, "EnemyBullet"), hModel_(-1)
{
}

//�f�X�g���N�^
EnemyBullet::~EnemyBullet()
{
}

//������
void EnemyBullet::Initialize()
{
	//���f���f�[�^�̃��[�h
	hModel_ = Model::Load("EnemyBullet.fbx");
	assert(hModel_ >= 0);

	//�����蔻�萶��
	SphereCollider* collision = new SphereCollider(XMVectorSet(0, 0, 0, 0), 0.5f);
	AddCollider(collision);
}

//�X�V
void EnemyBullet::Update()
{
	//�e�̈ړ�
	transform_.position_.vecZ -= 0.6f;

	//�e�̗L���͈�
	if (transform_.position_.vecZ < 0)
	{
		KillMe();
	}
}

//�`��
void EnemyBullet::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//�J��
void EnemyBullet::Release()
{
}