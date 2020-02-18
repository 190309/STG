//�e�N���X
#include "Player.h"
//�q�N���X
#include "PlBullet.h"
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
	:GameObject(parent, "Player"), hModel_(-1), HP_(10), Form_(false), BulletFlg_(false)
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
	SphereCollider* collision = new SphereCollider(XMVectorSet(0, 0, 0, 0), 1.8f);
	AddCollider(collision);
}

//�X�V
void Player::Update()
{
	//�e���������AZ�L�[����������e����
	if (Input::IsKey(DIK_Z) && BulletFlg_ == false)
	{
		BulletFlg_ = true;
		PlBullet* pBullet = Instantiate<PlBullet>(GetParent());
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
	if(Input::IsKey(DIK_RIGHT))
	{
		//�ړ��\
		if (transform_.position_.vecX < 6)
		{
			transform_.position_.vecX += 0.1f;
		}
		Form_ = 0;
	}

	//���L�[���͂ō��ֈړ�
	if (Input::IsKey(DIK_LEFT))
	{
		//�ړ��\
		if (transform_.position_.vecX > -6)
		{
			transform_.position_.vecX -= 0.1f;
		}
		Form_ = 1;
	}

	//HP���Ȃ�
	if (HP_ <= 0)
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

//�Q�b�^�[(posX)
float Player::GetPosX()
{
	return transform_.position_.vecX;
}

//�Q�b�^�[(posY)
float Player::GetPosY()
{
	return transform_.position_.vecY;
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