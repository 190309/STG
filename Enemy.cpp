//�G���W��
#include "Engine/Input.h"
#include "Engine/Model.h"
#include "Engine/SceneManager.h"
#include "Engine/SphereCollider.h"
//�e�N���X
#include "Enemy.h"
//�q�N���X
#include "EnemyNormalBulletLeft.h"
#include "EnemyNormalBulletRight.h"
//���̑�
#include "PlayerBullet.h"
#include "Player.h"

//�R���X�g���N�^
Enemy::Enemy(GameObject * parent)
	:GameObject(parent, "Enemy"), hModel_(-1), AtcCnt_(0), AtcPtr_(0), HP_(50.00f), Dec_(false)
{
}

//�f�X�g���N�^
Enemy::~Enemy()
{
}

//������
void Enemy::Initialize()
{
	//���f���f�[�^�̃��[�h
	hModel_ = Model::Load("Enemy.fbx");
	assert(hModel_ >= 0);

	//�����ʒu
	transform_.position_.vecZ = 50;
	transform_.rotate_.vecY = 180;

	//�����蔻�萶��
	SphereCollider* collision = new SphereCollider(XMVectorSet(0, -0.24f, 0, 0), 1.0f);
	AddCollider(collision);
}

//�X�V
void Enemy::Update()
{
	RoleFlg_ = false;

	//�㉺�^��
	if (AtcCnt_ < 240)
	{
		//�㉺�؂�ւ�
		if (AtcCnt_ % 30 == 0)
		{
			Dec_ = !Dec_;
		}
		//������ւ̈ړ�
		if (Dec_ == true)
		{
			transform_.position_.vecY += 0.05f;
		}
		//�������ւ̈ړ�
		if (Dec_ == false)
		{
			transform_.position_.vecY -= 0.05f;
		}
		AtcCnt_++;
	}

	//�U���p�^�[������
	if (AtcCnt_ == 240)
	{
		AtcPtr_ = rand() % 2 + 1;
		pos= ((Player*)FindObject("Player"))->GetPlayerPos();
		PlX_ = pos.vecX;
		PlY_ = pos.vecY;
	}

	//�U���p�^�[�������ƂɍU��
	//�ˌ�
	if (AtcPtr_ == 1)
	{
		if (AtcCnt_ < 300)
		{	
			transform_.position_.vecZ -= 0.84f;
			if (transform_.position_.vecX < PlX_)
			{
				transform_.position_.vecX += 0.1f;
				RoleFlg_ = true;
				if (transform_.rotate_.vecZ < 45)
				{
					transform_.rotate_.vecZ++;
				}
			}
			else if (transform_.position_.vecX > PlX_)
			{
				transform_.position_.vecX -= 0.1f;
				RoleFlg_ = true;
				if (transform_.rotate_.vecZ > -45)
				{
					transform_.rotate_.vecZ--;
				}
			}
			if (transform_.position_.vecY < PlY_)
			{
				transform_.position_.vecY += 0.1f;
			}
			else if (transform_.position_.vecY > PlY_)
			{
				transform_.position_.vecY -= 0.1f;
			}
		}
		else
		{
			transform_.position_.vecZ += 0.84f;
		}
		if (AtcCnt_++ == 360)
		{
			AtcCnt_ = 0;
			AtcPtr_ = 0;
		}
	}

	//�e��ʎˏo
	if (AtcPtr_ == 2)
	{
		pos = ((Player*)FindObject("Player"))->GetPlayerPos();
		PlX_ = pos.vecX;
		PlY_ = pos.vecY;

		if (AtcCnt_ < 600)
		{
			if (transform_.position_.vecX < PlX_)
			{
				transform_.position_.vecX += 0.1f;
				RoleFlg_ = true;
				if (transform_.rotate_.vecZ < 45)
				{
					transform_.rotate_.vecZ++;
				}
			}
			else if (transform_.position_.vecX > PlX_)
			{
				transform_.position_.vecX -= 0.1f;
				RoleFlg_ = true;
				if (transform_.rotate_.vecZ > -45)
				{
					transform_.rotate_.vecZ--;
				}
			}
			if (transform_.position_.vecY < PlY_)
			{
				transform_.position_.vecY += 0.1f;
			}
			else if (transform_.position_.vecY > PlY_)
			{
				transform_.position_.vecY -= 0.1f;
			}
		}
		if (AtcCnt_ % 20 == 0)
		{
			EnemyNormalBulletLeft* pBulletL = Instantiate<EnemyNormalBulletLeft>(GetParent());
			EnemyNormalBulletRight* pBulletR = Instantiate<EnemyNormalBulletRight>(GetParent());
			pBulletL->SetPosition(transform_.position_);
			pBulletR->SetPosition(transform_.position_);
		}
		if (AtcCnt_++ == 600)
		{
			AtcCnt_ = 0;
			AtcPtr_ = 0;
		}
	}

	//��]���Ă��Ȃ��Ċp�x�����Ă���ꍇ�߂�
	if (RoleFlg_ == false)
	{
		if (transform_.rotate_.vecZ < 0)
		{
			transform_.rotate_.vecZ++;
		}
		if (transform_.rotate_.vecZ > 0)
		{
			transform_.rotate_.vecZ--;
		}
	}

	//HP���Ȃ�
	if (HP_ <= 0)
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_CLEAR);
	}
}

//�`��
void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//�J��
void Enemy::Release()
{
}

//�Q�b�^�[(HP_)
float Enemy::GetHP_()
{
	return HP_;
}

//�Q�b�^�[(PosX)
float Enemy::GetPosX()
{
	return 	transform_.position_.vecX;
}

//�Q�b�^�[(PosY)
float Enemy::GetPosY()
{
	return 	transform_.position_.vecY;
}

float Enemy::GetRotZ()
{
	return 	transform_.rotate_.vecZ;
}

//�����ɓ�������
void Enemy::OnCollision(GameObject * pTarget)
{
	//�e�ɓ��������Ƃ��̏���
	if(pTarget->GetObjectName() == "PlayerBullet")
	{
		HP_ -= ((PlayerBullet*)pTarget)->GetBulletSize() / 60.00f;
		//���Ă��e���E��
		pTarget->KillMe();
	}
}