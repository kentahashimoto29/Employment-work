//========================================================
//
//ウインドウの生成等 (main.h)
//Author 橋本賢太
//
//========================================================
#ifndef _MAIN_H_
#define _MAIN_H_
#include <windows.h>
#include "d3dx9.h"
#include <stdio.h>
#define DIRECTINPUT_VERSION (0x0800)			//ビルド時の警告対処用マクロ
#include "dinput.h"								//入力処理に必要
#include "xaudio2.h"

//ライブラリのリンク
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "winmm.lib") 
#pragma comment(lib, "dinput8.lib")									//入力処理に必要

//マクロ定義
#define CLASS_NAME           "WindowClass"								//ウインドウクラスの名前
#define SCREEN_WIDTH			(1280)									//ウインドウの幅
#define SCREEN_HEIGHT			(720)									//ウインドウの高さ
#define FVF_VERTEX_2D			(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)
#define FVF_VERTEX_3D			(D3DFVF_XYZ | D3DFVF_NORMAL |  D3DFVF_DIFFUSE | D3DFVF_TEX1)          //頂点フォーマット3D

//頂点情報の構造体
typedef struct
{
	D3DXVECTOR3 pos;
	D3DXVECTOR3 nor;
	D3DCOLOR col;
	D3DXVECTOR2 tex;
}VERTEX_3D;

//頂点情報の構造体を定義
typedef struct
{
	D3DXVECTOR3 pos;			//頂点座標
	float rhw;					//座標変換葉系数
	D3DCOLOR col;				//頂点カラー
	D3DXVECTOR2 tex;			//テクスチャの座標
}VERTEX_2D;

int GetFPSCount(void);

#endif