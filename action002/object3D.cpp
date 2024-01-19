//========================================================
//
//�E�C���h�E�̐����� (Object3D.cpp)
//Author ���{����
//
//========================================================
#include "object3D.h"
#include "manager.h"

//========================================================
//�R���X�g���N�^
//========================================================
CObject3D::CObject3D(int nPriority) : CObject(nPriority)
{
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_aVerBuff = NULL;
	m_nTexture = 0;
}

//========================================================
//�R���X�g���N�^
//========================================================
CObject3D::~CObject3D()
{

}

//========================================================
//�|���S���̏���������
//========================================================
HRESULT CObject3D::Init(void)
{
	//�f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();

	//���_�o�b�t�@�𐶐�
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,
		D3DPOOL_MANAGED,
		&m_aVerBuff,
		NULL);

	VERTEX_3D *pVtx;

	//���_�o�b�t�@�����b�N
	m_aVerBuff->Lock(0, 0, (void**)&pVtx, 0);

	//���_���W�̐ݒ�
	pVtx[0].pos3D = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[1].pos3D = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[2].pos3D = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[3].pos3D = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	pVtx[0].nor3D = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[1].nor3D = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[2].nor3D = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[3].nor3D = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

	//���_�J���[�̐ݒ�
	pVtx[0].col3D = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[1].col3D = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[2].col3D = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[3].col3D = D3DCOLOR_RGBA(255, 255, 255, 255);

	//�e�N�X�`�����W�̐ݒ�
	pVtx[0].tex3D = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex3D = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex3D = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex3D = D3DXVECTOR2(1.0f, 1.0f);

	//���_�o�b�t�@���A�����b�N����
	m_aVerBuff->Unlock();

	return S_OK;
}

//========================================================
//�|���S���̏I������
//========================================================
void CObject3D::Uninit(void)
{
	//���_�o�b�t�@�̔j��
	if (m_aVerBuff != NULL)
	{
		m_aVerBuff->Release();
		m_aVerBuff = NULL;
	}

	Release();
}

//========================================================
//�|���S���̍X�V����
//========================================================
void CObject3D::Update(void)
{

}

//========================================================
//�|���S���̕`�揈��
//========================================================
void CObject3D::Draw(void)
{
	//�f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();

	CTexture *pTexture = CManager::GetInstance()->GetTexture();

	D3DXMATRIX mtxRot, mtxTrans;    //�v�Z�p�}�g���b�N�X

	//���[���h�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxWorld);

	//�����𔽉f
	D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rot.y, m_rot.x, m_rot.z);

	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);

	//�ʒu�𔽉f
	D3DXMatrixTranslation(&mtxTrans, m_pos.x, m_pos.y, m_pos.z);

	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

	//���[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

	//���_�o�b�t�@���f�[�^�X�g���[���ݒ�
	pDevice->SetStreamSource(0, m_aVerBuff, 0, sizeof(VERTEX_3D));

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_3D);

	//�e�N�X�`���̐ݒ�
	pDevice->SetTexture(0, pTexture->GetAddress(m_nTexture));

	pDevice->DrawPrimitive(
		D3DPT_TRIANGLESTRIP,                  //�v���~�e�B�u�̎��
		0,                                    //�ŏ��̒��_�C���f�b�N�X
		2);                                   //�v���~�e�B�u��
}

//========================================================
//�e�N�X�`���̔ԍ������蓖�Ă�
//========================================================
void CObject3D::BindTexture(int nTexture)
{
	m_nTexture = nTexture;
}

//========================================================
//�ʒu��Ԃ�
//========================================================
D3DXVECTOR3 CObject3D::GetPos(void)
{
	return m_pos;
}