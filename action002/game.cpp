//========================================================
//
//�E�C���h�E�̐����� (score.cpp)
//Author ���{����
//
//========================================================
#include "game.h"
#include "manager.h"
#include "fade.h"

#define PLAYER_SPAWN_X							(1400.0f)


//========================================================
//�ÓI�����o�ϐ�
//========================================================
CPlayer3D *CGame::m_pPlayer3D = NULL;
CEnemyManager *CGame::m_pEnemyManager = NULL;
CBlock3D *CGame::m_pBlock3D = NULL;
CDeathBlock *CGame::m_pDeathBlock = NULL;
CThroughBlock *CGame::m_pThroughBlock = NULL;
CTime *CGame::m_pTime = NULL;
int CGame::m_nScore = 0;

//========================================================
//�R���X�g���N�^
//========================================================
CGame::CGame()
{
	memset(&m_pField[0], NULL, sizeof(m_pField));		// 
	m_nScore = 0;
}

//========================================================
//�f�X�g���N�^
//========================================================
CGame::~CGame()
{

}

//========================================================
//����������
//========================================================
HRESULT CGame::Init(void)
{

	m_pTime = CTime::Create();

	m_pPlayer3D = CPlayer3D::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	m_pEnemyManager = CEnemyManager::Create();

	m_pField[0] = CField::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	m_pField[1] = CField::Create(D3DXVECTOR3(100.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	m_pField[2] = CField::Create(D3DXVECTOR3(200.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	m_pField[3] = CField::Create(D3DXVECTOR3(300.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	m_pField[4] = CField::Create(D3DXVECTOR3(0.0f, 0.0f, 100.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	m_pField[5] = CField::Create(D3DXVECTOR3(100.0f, 0.0f, 100.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	m_pField[6] = CField::Create(D3DXVECTOR3(200.0f, 0.0f, 100.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	m_pField[7] = CField::Create(D3DXVECTOR3(300.0f, 0.0f, 100.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	m_pField[8] = CField::Create(D3DXVECTOR3(0.0f, 0.0f, 200.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	m_pField[9] = CField::Create(D3DXVECTOR3(100.0f, 0.0f, 200.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	m_pField[10] = CField::Create(D3DXVECTOR3(200.0f, 0.0f, 200.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	m_pField[11] = CField::Create(D3DXVECTOR3(300.0f, 0.0f, 200.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	m_pField[12] = CField::Create(D3DXVECTOR3(0.0f, 0.0f, 300.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	m_pField[13] = CField::Create(D3DXVECTOR3(100.0f, 0.0f, 300.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	m_pField[14] = CField::Create(D3DXVECTOR3(200.0f, 0.0f, 300.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	m_pField[15] = CField::Create(D3DXVECTOR3(300.0f, 0.0f, 300.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	CManager::GetInstance()->GetCamera()->SetPosGame(m_pPlayer3D->GetPos(), m_pPlayer3D->GetPos());


	return S_OK;
}

//========================================================
//�I������
//========================================================
void CGame::Uninit(void)
{
	//NULL�`�F�b�N
	if (m_pTime != NULL)
	{
		//�I������
		m_pTime->Uninit();
		m_pTime = NULL;
	}

	//NULL�`�F�b�N
	if (m_pPlayer3D != NULL)
	{
		//�I������
		m_pPlayer3D->Uninit();
		m_pPlayer3D = NULL;
	}

	//NULL�`�F�b�N
	if (m_pEnemyManager != NULL)
	{
		//�I������
		m_pEnemyManager->Uninit();
		m_pEnemyManager = NULL;
	}

	for (int nCntField = 0; nCntField < 16; nCntField++)
	{
		//NULL�`�F�b�N
		if (m_pField[nCntField] != NULL)
		{
			m_pField[nCntField]->Uninit();
			m_pField[nCntField] = NULL;
		}
	}
	

	Release();
}

//========================================================
//�X�V����
//========================================================
void CGame::Update(void)
{
	//�L�[�{�[�h�̎擾
	CInputKeyboard *pInputKeyboard = CManager::GetInstance()->GetInputKeyboard();

	//�}�E�X�̎擾
	CInputMouse *pInputMouse = CManager::GetInstance()->GetInputMouse();

	if (pInputKeyboard->GetTrigger(DIK_RETURN) == true)
	{
		if (b != true)
		{
			if (CManager::GetInstance()->GetFade()->GetState() == CFade::FADE_NONE)
			{
				CManager::GetInstance()->GetFade()->SetFade(CManager::GetInstance()->GetScene()->MODE_RESULT);
				b = true;
			}
		}
	}

	if (CEnemyManager::GetNum() <= 0)
	{
		if (b != true)
		{
			if (CManager::GetInstance()->GetFade()->GetState() == CFade::FADE_NONE)
			{
				CManager::GetInstance()->GetFade()->SetFade(CManager::GetInstance()->GetScene()->MODE_RESULT);
				b = true;
			}
		}
	}

	m_pEnemyManager->Update();
}

//========================================================
//�`�揈��
//========================================================
void CGame::Draw(void)
{

}


//========================================================
//�v���C���[3D�̃|�C���^��Ԃ��֐�
//========================================================
CPlayer3D *CGame::GetPlayer3D(void)
{
	return m_pPlayer3D;
}

////========================================================
////�G�l�~�[3D�̃|�C���^��Ԃ��֐�
////========================================================
//CEnemy3D *CGame::GetEnemy3D(void)
//{
//	return m_pEnemy3D[0];
//}

//========================================================
//�u���b�N3D�̃|�C���^��Ԃ��֐�
//========================================================
CBlock3D *CGame::GetBlock3D(void)
{
	return m_pBlock3D;
}

//========================================================
//�����u���b�N�̃|�C���^��Ԃ��֐�
//========================================================
CDeathBlock *CGame::GetDeathBlock(void)
{
	return m_pDeathBlock;
}

//========================================================
//�ʂ蔲�����u���b�N�̃|�C���^��Ԃ��֐�
//========================================================
CThroughBlock *CGame::GetThroughBlock(void)
{
	return m_pThroughBlock;
}

//========================================================
//�ʂ蔲�����u���b�N�̃|�C���^��Ԃ��֐�
//========================================================
CTime *CGame::GetTime(void)
{
	return m_pTime;
}

//========================================================
//�ʂ蔲�����u���b�N�̃|�C���^��Ԃ��֐�
//========================================================
CEnemyManager *CGame::GetEnemyManager(void)
{
	return m_pEnemyManager;
}


//==========================================================================
// �G�擾
//==========================================================================
CField *CGame::GetField(void)
{
	return m_pField[0];
}


//==========================================================================
// �X�R�A�擾
//==========================================================================
int CGame::GetScore(void)
{
	return m_nScore;
}


//==========================================================================
// �X�R�A�ݒ�
//==========================================================================
void CGame::SetScore(int nScore)
{
	m_nScore = nScore;
}


//==========================================================================
// �X�R�A���Z
//==========================================================================
void CGame::AddScore()
{
	m_nScore++;
}