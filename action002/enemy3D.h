//========================================================
//
//�E�C���h�E�̐����� (enemy3D.h)
//Author ���{����
//
//========================================================
#ifndef _ENEMY3D_H_
#define _ENEMY3D_H_
#include "main.h"
#include "objectX.h"

//===================================
//�G�̃N���X
//===================================
class CEnemy3D : public CObjectX
{
public:
	CEnemy3D(int nPriority = 6);									//�R���X�g���N�^
	CEnemy3D(D3DXVECTOR3 pos, int nPriority = 6);					//�I�[�o�[���C�h���ꂽ�R���X�g���N�^
	~CEnemy3D();								//�f�X�g���N�^

	static CEnemy3D *Create(D3DXVECTOR3 pos);	//�G�̐���

	HRESULT Init(void);							//����������
	void Uninit(void);							//�I������
	void Update(void);							//�X�V����
	void Draw(void);							//�`�揈��

	D3DXVECTOR3 GetPos(void);					//�ʒu��Ԃ�
	static int GetNum(void);					//������Ԃ�

	void HitEnemy(void);						//�G�̃_���[�W����

private:

	static int m_nIdxTexture;					//�e�N�X�`���̔ԍ�
	static int m_nNum;							//����

	D3DXVECTOR3 m_VtxMax;						//���f���̍ő�l
	D3DXVECTOR3 m_VtxMin;						//���f���̍ŏ��l

	float m_Angle;								//�G�ƃv���C���[�̊p�x
	D3DXVECTOR3 m_Oldpos;						//
	D3DXVECTOR3 m_move;							//�ړ���

	int m_nLife;								//�̗�
};

#endif