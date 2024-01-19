//========================================================
//
//�E�C���h�E�̐����� (goal.h)
//Author ���{����
//
//========================================================
#ifndef _GAME_H_
#define _GAME_H_
#include "main.h"
#include "manager.h"
#include "player3D.h"
#include "block3D.h"
#include "death_block.h"
#include "through_block.h"
#include "time.h"

//===================================
//�w�i�̃N���X
//===================================
class CGame : public CScene
{
public:
	CGame();								//�R���X�g���N�^
	~CGame();								//�f�X�g���N�^

	HRESULT Init(void);						//����������
	void Uninit(void);						//�I������
	void Update(void);						//�X�V����
	void Draw(void);						//�`�揈��

	D3DXVECTOR3 m_pos;						//�I�u�W�F�N�g�̈ʒu

	static CPlayer3D *GetPlayer3D();									//�v���C���[3D�̃|�C���^��Ԃ��֐�
	static CBlock3D *GetBlock3D();										//�u���b�N3D�̃|�C���^��Ԃ��֐�
	static CDeathBlock *GetDeathBlock();								//�����u���b�N�̃|�C���^��Ԃ��֐�
	static CThroughBlock *GetThroughBlock();							//�ʂ蔲�����u���b�N�̃|�C���^��Ԃ��֐�
	static CTime *GetTime();											//�^�C���̃|�C���^��Ԃ��֐�

private:

	static CPlayer3D *m_pPlayer3D;										//�v���C���[3D�̃|�C���^
	static CBlock3D *m_pBlock3D;										//�u���b�N3D�̃|�C���^
	static CDeathBlock *m_pDeathBlock;									//�����u���b�N�̃|�C���^
	static CThroughBlock *m_pThroughBlock;								//�ʂ蔲�����u���b�N�̃|�C���^
	static CTime *m_pTime;												//�^�C���̃|�C���^

	bool b;
};

#endif