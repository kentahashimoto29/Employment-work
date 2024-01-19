//========================================================
//
//�E�C���h�E�̐����� (camera.h)
//Author ���{����
//
//========================================================
#include "camera.h"
#include "manager.h"
#include "input.h"
#include "game.h"

//========================================================
//�R���X�g���N�^
//========================================================
CCamera::CCamera()
{
	m_posV = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_posR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_vecU = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	//�Ίp���̒������Z�o
	m_Distance = sqrtf(50.0f * 50.0f + 100.0f * 100.0f);

	//�Ίp���̊p�x���Z�o
	m_Angle = atan2f(50.0f, 100.0f);

	m_type = TYPE_NONE;

	x = 0.0f;
	y = 0.0f;
}

//========================================================
//�f�X�g���N�^
//========================================================
CCamera::~CCamera()
{

}

//========================================================
//�J�����̏�����
//========================================================
HRESULT CCamera::Init(void)
{
	//�v���C���[3D�̎擾
	CPlayer3D *pPlayer3D = CGame::GetPlayer3D();

	m_posV = D3DXVECTOR3(pPlayer3D->GetPos().x, pPlayer3D->GetPos().y + 200.0f, pPlayer3D->GetPos().z - 500.0f);
	m_posR = D3DXVECTOR3(pPlayer3D->GetPos().x, pPlayer3D->GetPos().y + 40.0f, pPlayer3D->GetPos().z);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_vecU = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

	//�Ίp���̒������Z�o
	m_Distance = sqrtf(m_posV.y * m_posV.y + m_posV.z * m_posV.z);

	//�Ίp���̊p�x���Z�o
	m_Angle = atan2f(m_posV.y - m_posR.y, -(m_posV.z - m_posR.z));

	m_rot.x = m_Angle;

	y = m_rot.x;

	return S_OK;
}

//========================================================
//�J�����̏I��
//========================================================
void CCamera::Uninit(void)
{

}

//========================================================
//�J�����̍X�V
//========================================================
void CCamera::Update(void)
{
	//�L�[�{�[�h�̎擾
	CInputKeyboard *pInputKeyboard = CManager::GetInstance()->GetInputKeyboard();

	//�}�E�X�̎擾
	CInputMouse *pInputMouse = CManager::GetInstance()->GetInputMouse();

	//�v���C���[3D�̎擾
	CPlayer3D *pPlayer3D = CGame::GetPlayer3D();

	

	//m_posR.x += pPlayer3D->GetMove().x;
	//m_posV.x += pPlayer3D->GetMove().x;

	

	//�J�����̕␳
	if (m_rot.y > D3DX_PI)
	{
		m_rot.y = -D3DX_PI;
	}

	else if (m_rot.y < -D3DX_PI)
	{
		m_rot.y = D3DX_PI;
	}

	if (m_rot.x > D3DX_PI)
	{
		m_rot.x = -D3DX_PI;
	}

	else if (m_rot.x < -D3DX_PI)
	{
		m_rot.x = D3DX_PI;
	}
}

//========================================================
//�J�����̐ݒ�
//========================================================
void CCamera::SetCamera(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();

	//�v���W�F�N�V�����}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxProjection);

	//�v���W�F�N�V�����}�g���b�N�X���쐬
	D3DXMatrixPerspectiveFovLH(&m_mtxProjection,
		D3DXToRadian(45.0f),
		(float)SCREEN_WIDTH / (float)SCREEN_HEIGHT,
		10.0f,
		1000.0f);

	//�v���W�F�N�V�����}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_PROJECTION, &m_mtxProjection);

	//�r���[�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxView);

	//�r���[�}�g���b�N�X�̍쐬
	D3DXMatrixLookAtLH(&m_mtxView,
		&m_posV,
		&m_posR,
		&m_vecU);

	//�r���[�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_VIEW, &m_mtxView);
}

//========================================================
//�J�����̈ʒu
//========================================================
void CCamera::SetPos(D3DXVECTOR3 posV, D3DXVECTOR3 posR)
{
	m_posV = posV;
	m_posR = posR;
}

//========================================================
//�J�����̐ݒ�
//========================================================
D3DXVECTOR3 CCamera::GetRot(void)
{
	return m_rot;
}