//�G���W��
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"
//�e�N���X
#include "EnemyNormalBulletLeft.h"
//�q�N���X
//���̑�
#include "Enemy.h"

//�R���X�g���N�^
EnemyNormalBulletLeft::EnemyNormalBulletLeft(GameObject * parent)
	:GameObject(parent, "EnemyNormalBulletLeft"), hModel_(-1), BulletFlg_(false)
{
}

//�f�X�g���N�^
EnemyNormalBulletLeft::~EnemyNormalBulletLeft()
{
}

//������
void EnemyNormalBulletLeft::Initialize()
{
	//���f���f�[�^�̃��[�h
	hModel_ = Model::Load("EnemyBullet.fbx");
	assert(hModel_ >= 0);

	//�����蔻�萶��
	SphereCollider* collision = new SphereCollider(XMVectorSet(0, 0, 0, 0), 0.5f);
	AddCollider(collision);
}

//�X�V
void EnemyNormalBulletLeft::Update()
{
	//�����ʒu
	if (BulletFlg_ == false)
	{
		BulletFlg_ = true;
		transform_.position_.vecX = 0.8f + ((Enemy*)FindObject("Enemy"))->GetPosX();
		transform_.position_.vecY += ((Enemy*)FindObject("Enemy"))->GetRotZ() * -0.01f;
	}

	//�e�̈ړ�
	transform_.position_.vecZ -= 0.6f;

	//�e�̗L���͈�
	if (transform_.position_.vecZ < -1)
	{
		KillMe();
	}
}

//�`��
void EnemyNormalBulletLeft::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//�J��
void EnemyNormalBulletLeft::Release()
{
}