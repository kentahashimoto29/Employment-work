//========================================================
//
//ウインドウの生成等 (score.cpp)
//Author 橋本賢太
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
//コンストラクタ
//========================================================
CGame::CGame()
{
	
	
	
	
}

//========================================================
//デストラクタ
//========================================================
CGame::~CGame()
{

}

//========================================================
//初期化処理
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



	//下壁

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


	//上壁

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


	//左壁

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


	//右壁

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



	//下壁

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


	//上壁

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


	//左壁

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


	//右壁

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

	

	//下壁

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



	//上壁

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


	//左壁

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


	//右壁

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
//終了処理
//========================================================
void CGame::Uninit(void)
{
	//NULLチェック
	if (m_pTime != NULL)
	{
		//終了処理
		m_pTime->Uninit();
	}

	//NULLチェック
	if (m_pPlayer3D != NULL)
	{
		//終了処理
		m_pPlayer3D->Uninit();
	}

	//NULLチェック
	if (m_pEnemy3D != NULL)
	{
		//終了処理
		m_pEnemy3D->Uninit();
	}

	Release();
}

//========================================================
//更新処理
//========================================================
void CGame::Update(void)
{
	//キーボードの取得
	CInputKeyboard *pInputKeyboard = CManager::GetInstance()->GetInputKeyboard();

	//マウスの取得
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
//描画処理
//========================================================
void CGame::Draw(void)
{

}


//========================================================
//プレイヤー3Dのポインタを返す関数
//========================================================
CPlayer3D *CGame::GetPlayer3D(void)
{
	return m_pPlayer3D;
}

//========================================================
//エネミー3Dのポインタを返す関数
//========================================================
CEnemy3D *CGame::GetEnemy3D(void)
{
	return m_pEnemy3D;
}

//========================================================
//ブロック3Dのポインタを返す関数
//========================================================
CBlock3D *CGame::GetBlock3D(void)
{
	return m_pBlock3D;
}

//========================================================
//即死ブロックのポインタを返す関数
//========================================================
CDeathBlock *CGame::GetDeathBlock(void)
{
	return m_pDeathBlock;
}

//========================================================
//通り抜けれるブロックのポインタを返す関数
//========================================================
CThroughBlock *CGame::GetThroughBlock(void)
{
	return m_pThroughBlock;
}

//========================================================
//通り抜けれるブロックのポインタを返す関数
//========================================================
CTime *CGame::GetTime(void)
{
	return m_pTime;
}

//========================================================
//通り抜けれるブロックのポインタを返す関数
//========================================================
CField *CGame::GetField(void)
{
	return m_pField;
}
