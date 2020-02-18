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
	//�x�N�g��(�萔)
	const XMVECTOR POS;         //�e�̉��s�ʒu        (X:0.0f / Y:0.0f / Z:1.5f)
	const XMVECTOR CENTER;      //�����蔻��̒��S    (X:0.0f / Y:0.0f / Z:0.0f)
	const XMVECTOR MOVE;        //�e�̉��s�ʒu        (X:0.0f / Y:0.0f / Z:0.6f)
	//�x�N�g��(�ϐ�)
	XMVECTOR Scale;             //�e�̃T�C�Y          (X,Y,Z:Size / AJUST_SIZE)
	//�萔
	const int AJUST_COLL;       //�e�̓����蔻��𒲐�(72)
	const int MAX_SIZE;         //�e�̑傫���ő�      (180)
	const float AJUST_SIZE;     //�e�̃T�C�Y�𒲐�    (120.0f)
	const float MAX_RANGE;      //�e�̐����͈�        (vecZ < 100.0f)
	//�ϐ�
	int hModel_;		        //���f���ԍ�          (-1:�G���[ / 0:����ǂݍ���)
	int Size;                   //�e�̑傫��          (19 < Size < MAX_SIZE)
	bool Flg;                   //�e�̔��ˏ��        (0:������ / 1:���ˍς�)
	Player* pPlayer;            //Player�I�u�W�F�N�g�̃��f���ԍ�
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
	int GetBulletSize() { return Size; };

	//����:�Ȃ�
	//�ߒl:Flg_
	//Flg_����Ԃ�
	bool GetBulletFlg() { return Flg; };
};