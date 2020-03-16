#pragma once
//�e�N���X
//�q�N���X
//����
//�G���W���E���̑�
#include "Engine/GameObject.h"

//���@���Ǘ�����N���X
class Player : public GameObject
{
private:
	//�x�N�g��(�萔)
	const XMVECTOR RANGE;		//�s���\�͈�						(-6.0f < X < 6.0f, -2.75f < Y < 2.75f, Z:0.0f)
	const XMVECTOR SIZE;		//�@�̃T�C�Y						(1.0f, 1.0f, 1.0f)
		
	//�x�N�g��(�ϐ�)

	//�萔	
	const float MOVE;			//���@�̈ړ�						(0.1f)
	const float COLL_SIZE;		//���@�̓����蔻��					(1.8f)
	const int DMG_CNT_MAX;		//DmgCnt_�̍ő�l					(30)

	//�ϐ�
	bool BulletFlg_;			//�e�̐����t���O					(0:������ / 1:�����ς�)
	bool DamageFlg_;			//�U�����󂯂��t���O				(0:�󂯂ĂȂ� / 1:�󂯂�)
	int DmgCnt_;				//��x�U�����󂯂����莞�Ԗ��G	(0 <= DmgCnt_ <= 30)
	int hModel_;				//���f���ԍ�						(-1:�G���[ / 0:����ǂݍ���)
	int HP_;					//���@�̗�							(-1 < HP_ < 11)

	//�֐�

	//����:�Ȃ�
	//�ߒl:�Ȃ�
	//�e�̐�������є���
	void Bullet();

	//����:�Ȃ�
	//�ߒl:�Ȃ�
	//�@�̂��ړ�������֐�
	void Move();

	//����:�Ȃ�
	//�ߒl:�Ȃ�
	//�U�����󂯂��֐�
	void GetAttack();

public:
	//�R���X�g���N�^
	Player(GameObject* parent);

	//�f�X�g���N�^
	~Player();

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	//����:�Ȃ�
	//�ߒl:transform_.position_
	//���@�̃|�W�V������Ԃ�
	XMVECTOR GetPlayerPos() { return transform_.position_; };

	//����:�Ȃ�
	//�ߒl:HP_
	//���@��HP��Ԃ�
	int GetHP() { return HP_; };

	//�����ɓ�������
	//�����FpTarget ������������
	void OnCollision(GameObject *pTarget) override;
};