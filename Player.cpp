//�e�N���X
#include "Player.h"
//�q�N���X
#include "PlayerBullet.h"
#include "PlayerHP.h"
//����
#include "Enemy.h"
#include "EnemyNormalBulletLeft.h"
#include "EnemyNormalBulletRight.h"
//�G���W���E���̑�
#include "Engine/Input.h"
#include "Engine/Model.h"
#include "Engine/SceneManager.h"

//�R���X�g���N�^
Player::Player(GameObject * parent)
	:GameObject(parent, "Player"),
	RANGE(XMVectorSet(6.0f, 2.75f, 0.0f, 0.0f)),
	MOVE(0.1f), COLL_SIZE(1.5f),
	hModel_(-1), HP_(10), BulletFlg_(false)
{
}

//�f�X�g���N�^
Player::~Player()
{
}

//������
void Player::Initialize()
{
	//���f���f�[�^�̃��[�h
	hModel_ = Model::Load("character.fbx");
	assert(hModel_ >= 0);

	//�����蔻�萶��
	SphereCollider* collision = new SphereCollider(XMVectorSet(0, 0, 0, 0), COLL_SIZE);
	AddCollider(collision);

	//HP����
	Instantiate<PlayerHP>(this);;
}

//�X�V
void Player::Update()
{
	//�e���������AZ�L�[����������e����
	if (Input::IsKey(DIK_Z) && BulletFlg_ == false)
	{
		BulletFlg_ = true;
		PlayerBullet* pBullet = Instantiate<PlayerBullet>(GetParent());
		pBullet->SetPosition(transform_.position_);
	}

	//�e������AZ�L�[�𗣂�����e����
	if (Input::IsKeyUp(DIK_Z))
	{
		BulletFlg_ = false;
	}

	//��L�[���͂ŏ�ֈړ�
	if (Input::IsKey(DIK_UP))
	{
		//�ړ��\
		if (transform_.position_.vecY < RANGE.vecY)
		{
			transform_.position_.vecY += MOVE;
		}
	}

	//���L�[���͂ŉ��ֈړ�
	if (Input::IsKey(DIK_DOWN))
	{
		//�ړ��\
		if (transform_.position_.vecY > -RANGE.vecY)
		{
			transform_.position_.vecY -= MOVE;
		}
	}

	//�E�L�[���͂ŉE�ֈړ�
	if(Input::IsKey(DIK_RIGHT))
	{
		//�ړ��\
		if (transform_.position_.vecX < RANGE.vecX)
		{
			transform_.position_.vecX += MOVE;
		}
	}

	//���L�[���͂ō��ֈړ�
	if (Input::IsKey(DIK_LEFT))
	{
		//�ړ��\
		if (transform_.position_.vecX > -RANGE.vecX)
		{
			transform_.position_.vecX -= MOVE;
		}
	}

	//HP���Ȃ�
	if (HP_ < 1)
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_GAMEOVER);
	}

	//�����R�}���h
	if (Input::IsKeyDown(DIK_E) && HP_ > 0)
	{
		//Selt-Explosion
		HP_--;
	}
}

//�`��
void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//�J��
void Player::Release()
{
}

//�����ɓ�������
void Player::OnCollision(GameObject * pTarget)
{
	//�e�ɓ��������Ƃ��̏���
	if (pTarget->GetObjectName() == "EnemyNormalBulletLeft" || pTarget->GetObjectName() == "EnemyNormalBulletRight")
	{
		HP_--;
		//���������e���E��
		pTarget->KillMe();
	}

	//Enemy�ɓ��������Ƃ��̏���
	if (pTarget->GetObjectName() == "Enemy")
	{
		HP_--;
	}
}