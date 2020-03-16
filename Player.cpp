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
	RANGE(XMVectorSet(6.0f, 2.75f, 0.0f, 0.0f)), SIZE(XMVectorSet(1.0f, 1.0f, 1.0f, 0)),
	MOVE(0.1f), COLL_SIZE(1.5f), DMG_CNT_MAX(30),
	BulletFlg_(false), DamageFlg_(false),
	DmgCnt_(DMG_CNT_MAX), hModel_(-1), HP_(10)
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
	//�e�̐�������є���
	Bullet();

	//�@�̂��ړ�������֐�
	Move();

	//�U�����󂯂��֐�
	GetAttack();

	//�����R�}���h
	if (Input::IsKeyDown(DIK_E) && HP_ > 0)
	{
		//Selt-Explosion
		HP_--;
	}
}

//�e�̐�������є���
void Player::Bullet()
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
}

//�@�̂��ړ�������֐�
void Player::Move()
{
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
	if (Input::IsKey(DIK_RIGHT))
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
}

//�U�����󂯂��֐�
void Player::GetAttack()
{
	//���G����
	if (DamageFlg_ == true)
	{
		transform_.scale_ = XMVectorSet(0, 0, 0, 0);

		//���G���ԏI��
		if (DmgCnt_-- < 0)
		{
			transform_.scale_ = SIZE;
			DmgCnt_ = DMG_CNT_MAX;
			DamageFlg_ = false;
		}
	}

	//HP���Ȃ�
	if (HP_ < 1)
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_GAMEOVER);
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
	//���ݍU�����󂯂Ă��Ȃ��ꍇ
	if (DamageFlg_ == false)
	{
		//�e�ɓ��������Ƃ��̏���
		if (pTarget->GetObjectName() == "EnemyNormalBulletLeft" || pTarget->GetObjectName() == "EnemyNormalBulletRight")
		{
			DamageFlg_ = true;
			HP_--;
			//���������e���E��
			pTarget->KillMe();
		}

		//Enemy�ɓ��������Ƃ��̏���
		if (pTarget->GetObjectName() == "Enemy")
		{
			DamageFlg_ = true;
			HP_--;
		}
	}
}