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



CPlayer3D *CGame::m_pPlayer3D = NULL;
CEnemy3D *CGame::m_pEnemy3D = NULL;
CBlock3D *CGame::m_pBlock3D = NULL;
CDeathBlock *CGame::m_pDeathBlock = NULL;
CThroughBlock *CGame::m_pThroughBlock = NULL;
CTime *CGame::m_pTime = NULL;
CField *CGame::m_pField = NULL;

//========================================================
//�R���X�g���N�^
//========================================================
CGame::CGame()
{
	
	
	
	
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

	m_pEnemy3D = CEnemy3D::Create(D3DXVECTOR3(200.0f, 0.0f, 200.0f));

	m_pEnemy3D = CEnemy3D::Create(D3DXVECTOR3(-200.0f, 0.0f, 200.0f));


	m_pField = CField::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	CManager::GetInstance()->GetCamera()->SetPosGame(m_pPlayer3D->GetPos(), m_pPlayer3D->GetPos());

	//============================================================================================================================================



	//����

	/*m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-40.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-80.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-120.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-160.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-200.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-240.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-280.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-320.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-360.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-400.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-440.0f, -40.0f, 0.0f));

	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(0.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(40.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(80.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(120.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(160.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(200.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(240.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(280.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(320.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(360.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(400.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(440.0f, -40.0f, 0.0f));


	//���

	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-40.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-80.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-120.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-160.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-200.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-240.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-280.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-320.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-360.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-400.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-440.0f, 600.0f, 0.0f));

	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(0.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(40.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(80.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(120.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(160.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(200.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(240.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(280.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(320.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(360.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(400.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(440.0f, 600.0f, 0.0f));


	//����

	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-440.0f, 560.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-440.0f, 520.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-440.0f, 480.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-440.0f, 440.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-440.0f, 400.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-440.0f, 360.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-440.0f, 320.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-440.0f, 280.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-440.0f, 240.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-440.0f, 200.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-440.0f, 160.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-440.0f, 120.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-440.0f, 80.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-440.0f, 40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-440.0f, 0.0f, 0.0f));


	//�E��

	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(440.0f, 560.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(440.0f, 520.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(440.0f, 480.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(440.0f, 280.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(440.0f, 240.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(440.0f, 200.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(440.0f, 160.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(440.0f, 120.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(440.0f, 80.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(440.0f, 40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(440.0f, 0.0f, 0.0f));





	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-80.0f, 0.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-80.0f, 40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-80.0f, 80.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-80.0f, 120.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-80.0f, 160.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-80.0f, 200.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-80.0f, 240.0f, 0.0f));

	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-120.0f, 240.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-160.0f, 240.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-200.0f, 240.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-240.0f, 240.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-280.0f, 240.0f, 0.0f));

	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-400.0f, 120.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-360.0f, 120.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-320.0f, 120.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-280.0f, 120.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-240.0f, 120.0f, 0.0f));


	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(160.0f, 400.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(120.0f, 400.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(80.0f, 400.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(40.0f, 400.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(0.0f, 400.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-40.0f, 400.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-80.0f, 400.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-120.0f, 400.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-160.0f, 400.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-200.0f, 400.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-240.0f, 400.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(-280.0f, 400.0f, 0.0f));



	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(40.0f, 120.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(40.0f, 160.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(40.0f, 200.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(40.0f, 240.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(40.0f, 280.0f, 0.0f));


	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(80.0f, 120.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(80.0f, 160.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(80.0f, 200.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(80.0f, 240.0f, 0.0f));


	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(120.0f, 120.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(120.0f, 160.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(120.0f, 200.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(120.0f, 240.0f, 0.0f));


	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(160.0f, 120.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(160.0f, 160.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(160.0f, 200.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(160.0f, 240.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(160.0f, 280.0f, 0.0f));




	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(400.0f, 0.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(400.0f, 40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(400.0f, 80.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(400.0f, 120.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(400.0f, 160.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(400.0f, 200.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(400.0f, 240.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(400.0f, 280.0f, 0.0f));

	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(360.0f, 0.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(360.0f, 40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(360.0f, 80.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(360.0f, 120.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(360.0f, 160.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(360.0f, 200.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(360.0f, 240.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(360.0f, 280.0f, 0.0f));



	m_pDeathBlock = CDeathBlock::Create(D3DXVECTOR3(80.0f, 280.0f, 0.0f));
	m_pDeathBlock = CDeathBlock::Create(D3DXVECTOR3(120.0f, 280.0f, 0.0f));


	m_pThroughBlock = CThroughBlock::Create(D3DXVECTOR3(25.0f, 320.0f, 0.0f));
	m_pThroughBlock = CThroughBlock::Create(D3DXVECTOR3(25.0f, 360.0f, 0.0f));

	m_pThroughBlock = CThroughBlock::Create(D3DXVECTOR3(175.0f, 320.0f, 0.0f));
	m_pThroughBlock = CThroughBlock::Create(D3DXVECTOR3(175.0f, 360.0f, 0.0f));



	//============================================================================================================================================



	//����

	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(880.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(840.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(800.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(760.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(720.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(680.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(640.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(600.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(560.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(520.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(480.0f, -40.0f, 0.0f));

	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(920.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(960.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1000.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1040.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1080.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1120.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1160.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1200.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1240.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1280.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1320.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1360.0f, -40.0f, 0.0f));


	//���

	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(880.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(840.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(800.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(760.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(720.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(680.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(640.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(600.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(560.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(520.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(480.0f, 600.0f, 0.0f));

	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(920.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(960.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1000.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1040.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1080.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1120.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1160.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1200.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1240.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1280.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1320.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1360.0f, 600.0f, 0.0f));


	//����

	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(480.0f, 560.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(480.0f, 520.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(480.0f, 480.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(480.0f, 280.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(480.0f, 240.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(480.0f, 200.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(480.0f, 160.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(480.0f, 120.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(480.0f, 80.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(480.0f, 40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(480.0f, 0.0f, 0.0f));


	//�E��

	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1360.0f, 560.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1360.0f, 520.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1360.0f, 480.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1360.0f, 440.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1360.0f, 400.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1360.0f, 360.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1360.0f, 320.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1360.0f, 280.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1360.0f, 240.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1360.0f, 200.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1360.0f, 160.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1360.0f, 120.0f, 0.0f));




	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(520.0f, 560.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(520.0f, 520.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(520.0f, 480.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(560.0f, 560.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(560.0f, 520.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(560.0f, 480.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(600.0f, 560.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(600.0f, 520.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(600.0f, 480.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(600.0f, 440.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(600.0f, 400.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(600.0f, 360.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(600.0f, 320.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(600.0f, 280.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(600.0f, 240.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(600.0f, 200.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(600.0f, 160.0f, 0.0f));





	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(760.0f, 440.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(760.0f, 400.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(760.0f, 360.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(760.0f, 320.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(760.0f, 280.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(760.0f, 240.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(760.0f, 200.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(760.0f, 160.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(760.0f, 120.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(760.0f, 80.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(760.0f, 40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(760.0f, 0.0f, 0.0f));

	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(800.0f, 440.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(800.0f, 400.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(800.0f, 360.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(800.0f, 320.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(800.0f, 280.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(800.0f, 240.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(800.0f, 200.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(800.0f, 160.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(800.0f, 120.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(800.0f, 80.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(800.0f, 40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(800.0f, 0.0f, 0.0f));





	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(960.0f, 560.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(960.0f, 520.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(960.0f, 480.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(960.0f, 440.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(960.0f, 400.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(960.0f, 360.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(960.0f, 320.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(960.0f, 280.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(960.0f, 240.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(960.0f, 200.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(960.0f, 160.0f, 0.0f));





	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1120.0f, 440.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1120.0f, 400.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1120.0f, 360.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1120.0f, 320.0f, 0.0f));
	m_pDeathBlock = CDeathBlock::Create(D3DXVECTOR3(1120.0f, 280.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1120.0f, 240.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1120.0f, 200.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1120.0f, 160.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1120.0f, 120.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1120.0f, 80.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1120.0f, 40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1120.0f, 0.0f, 0.0f));

	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1160.0f, 440.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1160.0f, 400.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1160.0f, 360.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1160.0f, 320.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1160.0f, 280.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1160.0f, 240.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1160.0f, 200.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1160.0f, 160.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1160.0f, 120.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1160.0f, 80.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1160.0f, 40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1160.0f, 0.0f, 0.0f));




	//============================================================================================================================================

	

	//����

	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1800.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1760.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1720.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1680.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1640.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1600.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1560.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1520.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1480.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1440.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1400.0f, -40.0f, 0.0f));

	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1840.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1880.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1920.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1960.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(2000.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(2040.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(2080.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(2120.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(2160.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(2200.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(2240.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(2280.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(2320.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(2360.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(2400.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(2440.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(2480.0f, -40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(2520.0f, -40.0f, 0.0f));



	//���

	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1800.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1760.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1720.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1680.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1640.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1600.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1560.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1520.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1480.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1440.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1400.0f, 600.0f, 0.0f));

	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1840.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1880.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1920.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1960.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(2000.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(2040.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(2080.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(2120.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(2160.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(2200.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(2240.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(2280.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(2320.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(2360.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(2400.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(2440.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(2480.0f, 600.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(2520.0f, 600.0f, 0.0f));


	//����

	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1400.0f, 560.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1400.0f, 520.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1400.0f, 480.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1400.0f, 440.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1400.0f, 400.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1400.0f, 360.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1400.0f, 320.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1400.0f, 280.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1400.0f, 240.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1400.0f, 200.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1400.0f, 160.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(1400.0f, 120.0f, 0.0f));


	//�E��

	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(2520.0f, 560.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(2520.0f, 520.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(2520.0f, 480.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(2520.0f, 440.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(2520.0f, 400.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(2520.0f, 360.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(2520.0f, 320.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(2520.0f, 280.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(2520.0f, 240.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(2520.0f, 200.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(2520.0f, 160.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(2520.0f, 120.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(2520.0f, 80.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(2520.0f, 40.0f, 0.0f));
	m_pBlock3D = CBlock3D::Create(D3DXVECTOR3(2520.0f, 0.0f, 0.0f));*/




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
	}

	//NULL�`�F�b�N
	if (m_pPlayer3D != NULL)
	{
		//�I������
		m_pPlayer3D->Uninit();
	}

	//NULL�`�F�b�N
	if (m_pEnemy3D != NULL)
	{
		//�I������
		m_pEnemy3D->Uninit();
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

//========================================================
//�G�l�~�[3D�̃|�C���^��Ԃ��֐�
//========================================================
CEnemy3D *CGame::GetEnemy3D(void)
{
	return m_pEnemy3D;
}

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
CField *CGame::GetField(void)
{
	return m_pField;
}
