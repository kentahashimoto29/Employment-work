//========================================================
//
//ウインドウの生成等 (bullet.cpp)
//Author 橋本賢太
//
//========================================================
#include "enemy3D.h"
#include "game.h"
#include "Player3D.h"
#include "block3D.h"

int CEnemy3D::m_nIdxTexture = 0;
int CEnemy3D::m_nNum = 0;

//========================================================
//コンストラクタ
//========================================================
CEnemy3D::CEnemy3D(int nPriority) : CObjectX(nPriority)
{
	m_nNum++;
}

//========================================================
//オーバーライドされたコンストラクタ
//========================================================
CEnemy3D::CEnemy3D(D3DXVECTOR3 pos, int nPriority) : CObjectX(nPriority)
{
	m_pos = pos;
	m_nLife = 3;
	m_nNum++;
}

//========================================================
//デストラクタ
//========================================================
CEnemy3D::~CEnemy3D()
{

}

//========================================================
//生成処理
//========================================================
CEnemy3D *CEnemy3D::Create(D3DXVECTOR3 pos)
{
	CEnemy3D *pEnemy3D;

	//2Dオブジェクトの生成
	pEnemy3D = new CEnemy3D(pos);

	//初期化処理
	pEnemy3D->Init();

	return pEnemy3D;
}

//========================================================
//初期化処理
//========================================================
HRESULT CEnemy3D::Init(void)
{
	int nNumVtx;				//頂点数
	DWORD dwSizeFVF;			//頂点フォーマットのサイズ
	BYTE *pVtxBuff;				//頂点バッファへのポインタ

	//デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();

	//Xファイルの読み込み
	D3DXLoadMeshFromX("data\\MODEL\\enemy_Sample000.x",
		D3DXMESH_SYSTEMMEM,
		pDevice,
		NULL,
		&m_pBuffMat,
		NULL,
		&m_dwNumMat,
		&m_pMesh);

	//頂点数を取得
	nNumVtx = m_pMesh->GetNumVertices();

	//頂点フォーマットのサイズを取得
	dwSizeFVF = D3DXGetFVFVertexSize(m_pMesh->GetFVF());


	//頂点バッファをロック
	m_pMesh->LockVertexBuffer(D3DLOCK_READONLY, (void**)&pVtxBuff);

	for (int nCntVtx = 0; nCntVtx < nNumVtx; nCntVtx++)
	{
		D3DXVECTOR3 vtx = *(D3DXVECTOR3*)pVtxBuff;					//頂点座標の代入

		if (m_VtxMin.x > vtx.x)
		{
			m_VtxMin.x = vtx.x;
		}

		else if (m_VtxMax.x < vtx.x)
		{
			m_VtxMax.x = vtx.x;
		}

		if (m_VtxMin.y > vtx.y)
		{
			m_VtxMin.y = vtx.y;
		}

		else if (m_VtxMax.y < vtx.y)
		{
			m_VtxMax.y = vtx.y;
		}

		if (m_VtxMin.z > vtx.z)
		{
			m_VtxMin.z = vtx.z;
		}

		else if (m_VtxMax.z < vtx.z)
		{
			m_VtxMax.z = vtx.z;
		}

		pVtxBuff += dwSizeFVF;					//頂点フォーマットのサイズ分ポインタを進める
	}

	//頂点バッファをアンロック
	m_pMesh->UnlockVertexBuffer();

	CObjectX::Init();

	m_VtxMax = D3DXVECTOR3(10.0f, 20.0f, 10.0f);
	m_VtxMin = D3DXVECTOR3(-10.0f, 0.0f, -10.0f);

	CObject::SetType(TYPE_ENEMY);

	return S_OK;
}

//========================================================
//終了処理
//========================================================
void CEnemy3D::Uninit(void)
{
	m_nNum--;

	CObjectX::Uninit();
}

//========================================================
//更新処理
//========================================================
void CEnemy3D::Update(void)
{
	float fDistance;

	//プレイヤーの情報を取得
	CPlayer3D *pPlayer = CGame::GetPlayer3D();

	//ブロック3Dの取得
	CBlock3D *pBlock = CGame::GetBlock3D();

	//キーボードの取得
	CInputKeyboard *pInputKeyboard = CManager::GetInstance()->GetInputKeyboard();

	m_Oldpos = m_pos;

	//対角線の角度を算出
	m_rot.y = atan2f(m_pos.x - pPlayer->GetPos().x, m_pos.z - pPlayer->GetPos().z);

	//対角線の長さを算出
	fDistance = sqrtf((m_pos.x - pPlayer->GetPos().x) * (m_pos.x - pPlayer->GetPos().x)
		+ (m_pos.z - pPlayer->GetPos().z) * (m_pos.z - pPlayer->GetPos().z));

	if (fDistance <= 200.0f)
	{
		m_move.x = sinf(D3DX_PI * 0.0f + m_rot.y);
		m_move.z = cosf(D3DX_PI * 0.0f + m_rot.y);

		m_pos += m_move;
	}

	/*if (pInputKeyboard->GetTrigger(DIK_U) == TRUE)
	{
		CBullet3D::Create(m_pos, m_rot, 1.0f);
	}*/

	//pBlock->Collision(&m_pos, &m_Oldpos, &m_move, m_VtxMax, m_VtxMin);
	if (pPlayer->CollisionEnemy(m_pos, m_VtxMax, m_VtxMin) == true)
	{
		Uninit();
	}

	if (m_nLife <= 0)
	{
		Release();
	}
}

//========================================================
//描画処理
//========================================================
void CEnemy3D::Draw(void)
{
	CObjectX::Draw();
}

//========================================================
//位置を返す
//========================================================
D3DXVECTOR3 CEnemy3D::GetPos(void)
{
	return m_pos;
}

//========================================================
//位置を返す
//========================================================
int CEnemy3D::GetNum(void)
{
	return m_nNum;
}

//========================================================
//敵のダメージ処理
//========================================================
void CEnemy3D::HitEnemy(void)
{
	 m_nLife -= 1;
}