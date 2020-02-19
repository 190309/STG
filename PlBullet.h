#pragma once
//�e�N���X
#include "Player.h"
//�q�N���X
//����
//�G���W���E���̑��̃N���X
#include "Engine/GameObject.h"

//�e���Ǘ�����N���X
class PlBullet : public GameObject
{
private:
	//�x�N�g��(�萔)

	//�x�N�g��(�ϐ�)

	//�萔
	const int MAX_SIZE;			//�e�̑傫���ő�		(180)
	const float AJUST_COLL;		//�e�̓����蔻��𒲐�	(60.0f)
	const float AJUST_SIZE;		//�e�̃T�C�Y�𒲐�		(120.0f)
	const float MAX_RANGE;		//�e�̐����͈�			(POS - 1 < vecZ < 100.0f)
	const float MOVE;			//�e�̈ړ�				(0.6f)
	const float POS;			//�e�̏����ʒu(���s)	(3.0f)

	//�ϐ�
	bool Flg_;					//�e�̔��ˏ��			(0:������ / 1:���ˍς�)
	int hModel_;				//���f���ԍ�			(-1:�G���[ / 0:����ǂݍ���)
	int Size_;					//�e�̑傫��			(19 < Size < MAX_SIZE)
	Player* pPlayer_;			//Player�I�u�W�F�N�g�̃��f���ԍ�

public:
	//�R���X�g���N�^
	PlBullet(GameObject* parent);

	//�f�X�g���N�^
	~PlBullet();

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	//����:�Ȃ�
	//�ߒl:Size
	//Size_��Ԃ�
	int GetBulletSize() { return Size_; };
};