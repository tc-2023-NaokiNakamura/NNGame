/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: Bin.cpp
	NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------

	ビン

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */
#include <windows.h>
#include <stdio.h>	// --- コンソール用

#include "Common.h"

#define BIN_MOVE_X 180

/* ---------------------------------------------------- */
/*														*/
/*			--- 静的メンバ変数初期セット ---			*/
/*														*/
/* ---------------------------------------------------- */
int Bin::m_IDNo = 0;			// IDカウンタ
double Bin::m_moveXp = 130;		// ビンのX座標ポジション移動
double Bin::m_ColorNo = 0;		// ビンの色を変更
double Bin::m_hitZoneXp = 0;	// 当たり判定のXポジション移動
double Bin::m_moveFinXp = 100;	// リザルト画面時ビンのX座標ポジション移動


Bin::Bin() {
	init();
}

Bin::~Bin() {
	if (destroyFlg != 1)
		init();
}

void Bin::StaticInit() {
	m_IDNo = 0;			// IDカウンタ
	m_moveXp = 130;		// ビンのX座標ポジション移動
	m_ColorNo = 0;		// ビンの色を変更
	m_hitZoneXp = 0;	// 当たり判定のXポジション移動
	m_moveFinXp = 100;
}

void Bin::init() {
	m_ID = m_IDNo;
	m_sprNo = m_IDNo;
	// ビンIDごとにセット
	if (m_ID == m_IDNo) {
		m_xp = m_moveXp;
		m_yp = 700;
		m_hitZone.left = 50 + (long)m_hitZoneXp;
		m_hitZone.right = 150 + (long)m_hitZoneXp;
		m_hitZone.top = 660;
		m_hitZone.bottom = 740;
	}

	m_usebmp = BIN_ID;

	m_BinColor = m_ColorNo;

	m_bblCorrectFlg = 0;
	m_bblInOutFlg = 0;
	m_objBin = OBJ_BIN_FORWORD;

	// ビンの色セット
	switch ((int)m_BinColor)
	{
		case 0:
			m_BinColorNo = 2;
			break;
		case 100:
			m_BinColorNo = 3;
			break;
		case 200:
			m_BinColorNo = 4;
			break;
		case 300:
			m_BinColorNo = 5;
			break;
	}

	m_IDNo++;
	m_moveXp += BIN_MOVE_X;
	m_hitZoneXp += BIN_MOVE_X;
	m_ColorNo += BIN_SIZE;

	// スモークアニメーション
	for (int i = 0; i < ANIM_PATTERN_SMOKE; i++) {
		binSmokeAnim[i].bmpNo = BIN_SMOKE_ID;
		binSmokeAnim[i].holdTime = 5;
		binSmokeAnim[i].cutRect.left = 0;
		binSmokeAnim[i].cutRect.right = BIN_SMOKE_SIZE;
		binSmokeAnim[i].cutRect.top = i * BIN_SMOKE_SIZE;
		binSmokeAnim[i].cutRect.bottom = (i+1) * BIN_SMOKE_SIZE;
		binSmokeAnim[i].animMode = ANIM_MODE_NEXT;
		if (i == 5) {
			binSmokeAnim[i].animMode = ANIM_MODE_STOP;
		}
	}
}


/* -------------------------------------------- */
/*												*/
/*			--- ビンの色をチェンジ ---			*/
/*												*/
/* -------------------------------------------- */
void Bin::changeBinColor() {
	int cnt = 0;
	m_anim.setAnimData(binSmokeAnim);		// アニメーションセット
	while (1) {
		m_BinColor = (double)(rand() % 4) * BIN_SIZE;
		switch ((int)m_BinColor)
		{
			case 0:
				m_BinColorNo = 2;
				break;
			case 100:
				m_BinColorNo = 3;
				break;
			case 200:
				m_BinColorNo = 4;
				break;
			case 300:
				m_BinColorNo = 5;
				break;
		}
		// ビンの色が被らないようにする処理
		for (int i = 0; i < (BIN_MAX - 1); i++) {
			if (i == m_ID) {
				continue;
			}
			if (ptrBinarray[i]->getBinColorNo() != m_BinColorNo) {
				cnt++;
			}
		}
		if (cnt >= 2) {
			break;
		}
		cnt = 0;
	}
}


/* -------------------------------------------------------- */
/*															*/
/*			--- バブルとビンのヒットチェック ---			*/
/*															*/
/* -------------------------------------------------------- */
int Bin::BinHitCheck() {
	int id = -1;

	for (int i = 0; i < MAXBUBBLES; i++) {
		// バブルが表示されている時
		if (ptrBubblesarray[i]->getUseFlg() == 1) {
			// Y座標の当たり判定
			if ((m_hitZone.top <= ptrBubblesarray[i]->getYp()) && (m_hitZone.bottom >= ptrBubblesarray[i]->getYp())) {
				// X座標の当たり判定
				if ((m_hitZone.left <= ptrBubblesarray[i]->getXp()) && (m_hitZone.right >= ptrBubblesarray[i]->getXp())) {
					id = m_ID;	// どのビンに当たったのかビンの識別子を返す
				}
			}
		}
	}
	return id;
}


void Bin::changeBinPos() {
	m_BinColor = (double)m_ID * BIN_SIZE;
	m_xp = m_moveFinXp;
	m_objBin = OBJ_BIN_FIN;
	m_moveFinXp += 120;
}


int Bin::action() {
	// --- ビン描画
	g_sprite[m_sprNo + m_objBin].setSprite
	(
		m_usebmp,
		(int)m_xp - 50,
		(int)m_yp - 50,
		0,		// 現在の画像座標を取得して左右のRECT構造体座標を更新
		(int)m_BinColor,
		BIN_SIZE,
		BIN_SIZE,
		1,
		1,
		SPR_SCALE,
		1
	);

	if (m_anim.getAnimState() != ANIM_MODE_STOP) {
		m_anim.playAnim();
		// --- スモーク描画
		g_sprite[m_sprNo + OBJ_BIN_SMOKE].setSprite
		(
			BIN_SMOKE_ID,
			(int)m_xp - 50,
			(int)m_yp - 50,
			0,		// 現在の画像座標を取得して左右のRECT構造体座標を更新
			m_anim.getNowAnim()->cutRect.top,
			BIN_SIZE,
			BIN_SIZE,
			1,
			1,
			SPR_SCALE,
			1
		);
	}
	return (false);
}



