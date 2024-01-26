//========================================================
//
//ウインドウの生成等 (enemy3D.h)
//Author 橋本賢太
//
//========================================================
#ifndef _ENEMY3D_H_
#define _ENEMY3D_H_
#include "main.h"
#include "objectX.h"

//===================================
//敵のクラス
//===================================
class CEnemy3D : public CObjectX
{
public:
	CEnemy3D(int nPriority = 6);									//コンストラクタ
	CEnemy3D(D3DXVECTOR3 pos, int nPriority = 6);					//オーバーライドされたコンストラクタ
	~CEnemy3D();								//デストラクタ

	static CEnemy3D *Create(D3DXVECTOR3 pos);	//敵の生成

	HRESULT Init(void);							//初期化処理
	void Uninit(void);							//終了処理
	void Update(void);							//更新処理
	void Draw(void);							//描画処理

	D3DXVECTOR3 GetPos(void);					//位置を返す
	static int GetNum(void);					//総数を返す

	void HitEnemy(void);						//敵のダメージ処理

private:

	static int m_nIdxTexture;					//テクスチャの番号
	static int m_nNum;							//総数

	D3DXVECTOR3 m_VtxMax;						//モデルの最大値
	D3DXVECTOR3 m_VtxMin;						//モデルの最小値

	float m_Angle;								//敵とプレイヤーの角度
	D3DXVECTOR3 m_Oldpos;						//
	D3DXVECTOR3 m_move;							//移動量

	int m_nLife;								//体力
};

#endif