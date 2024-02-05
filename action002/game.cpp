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


//========================================================
//静的メンバ変数
//========================================================
CPlayer3D *CGame::m_pPlayer3D = NULL;
CEnemyManager *CGame::m_pEnemyManager = NULL;
CBlock3D *CGame::m_pBlock3D = NULL;
CDeathBlock *CGame::m_pDeathBlock = NULL;
CThroughBlock *CGame::m_pThroughBlock = NULL;
CTime *CGame::m_pTime = NULL;
int CGame::m_nScore = 0;

//========================================================
//コンストラクタ
//========================================================
CGame::CGame()
{
	memset(&m_pField[0], NULL, sizeof(m_pField));		// 
	m_nScore = 0;
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
//終了処理
//========================================================
void CGame::Uninit(void)
{
	//NULLチェック
	if (m_pTime != NULL)
	{
		//終了処理
		m_pTime->Uninit();
		m_pTime = NULL;
	}

	//NULLチェック
	if (m_pPlayer3D != NULL)
	{
		//終了処理
		m_pPlayer3D->Uninit();
		m_pPlayer3D = NULL;
	}

	//NULLチェック
	if (m_pEnemyManager != NULL)
	{
		//終了処理
		m_pEnemyManager->Uninit();
		m_pEnemyManager = NULL;
	}

	for (int nCntField = 0; nCntField < 16; nCntField++)
	{
		//NULLチェック
		if (m_pField[nCntField] != NULL)
		{
			m_pField[nCntField]->Uninit();
			m_pField[nCntField] = NULL;
		}
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

////========================================================
////エネミー3Dのポインタを返す関数
////========================================================
//CEnemy3D *CGame::GetEnemy3D(void)
//{
//	return m_pEnemy3D[0];
//}

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
CEnemyManager *CGame::GetEnemyManager(void)
{
	return m_pEnemyManager;
}


//==========================================================================
// 敵取得
//==========================================================================
CField *CGame::GetField(void)
{
	return m_pField[0];
}


//==========================================================================
// スコア取得
//==========================================================================
int CGame::GetScore(void)
{
	return m_nScore;
}


//==========================================================================
// スコア設定
//==========================================================================
void CGame::SetScore(int nScore)
{
	m_nScore = nScore;
}


//==========================================================================
// スコア加算
//==========================================================================
void CGame::AddScore()
{
	m_nScore++;
}