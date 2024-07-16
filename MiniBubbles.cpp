/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: MiniBubbles.cpp
	NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------

	吹き出し時の小さなシャボン玉をセット

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

#include <windows.h>
#include <stdio.h>	// --- コンソール用

#include "Common.h"


/* ---------------------------------------------------- */
/*														*/
/*			--- 静的メンバ変数初期セット ---			*/
/*														*/
/* ---------------------------------------------------- */
int MiniBubbles::m_bubblecnt = 0;


MiniBubbles::MiniBubbles() {
	init();
}

MiniBubbles::~MiniBubbles() {
	if (destroyFlg != 1)
		init();
}


void MiniBubbles::StaticInit() {
	m_bubblecnt = 0;
}

void MiniBubbles::init() {
	// ４つのミニしゃぼん玉の初期ポジションセット
	switch (m_bubblecnt)
	{
		case 0:
			m_bubbleInitPosiX = 540.0;
			m_bubbleInitPosiY = (double)MINIBUBBLE_YPOSI;
			m_bmpcnt = 1;
			break;
		case 1:
			m_bubbleInitPosiX = 530.0;
			m_bubbleInitPosiY = (double)(MINIBUBBLE_YPOSI + 10);
			m_bmpcnt = 2;
			break;
		case 2:
			m_bubbleInitPosiX = 525.0;
			m_bubbleInitPosiY = (double)(MINIBUBBLE_YPOSI + 25);
			m_bmpcnt = 3;
			break;
		case 3:
			m_bubbleInitPosiX = 545.0;
			m_bubbleInitPosiY = (double)(MINIBUBBLE_YPOSI + 15);
			m_bmpcnt = 4;
			break;
		default:
			break;
	}
	m_sprcnt = m_bubblecnt;
	m_bScaleX = 0.15;							// しゃぼん玉Xサイズをセット
	m_bScaleY = 0.15;							// しゃぼん玉Yサイズをセット
	m_bubblecnt++;
	m_bmptim = 20;
}

int MiniBubbles::action() {
	m_bmptim--;				// 画像切り替えタイマー
	if (m_bmptim == 0) {	// タイマー切り替えタイミング
		m_bmpcnt++;
		m_bmptim = 20;
	}
	// しゃぼん玉画像4枚分の切り替え
	if (m_bmpcnt > 4) {
		m_bmpcnt = 1;
	}

	// --- 描画
	g_sprite[m_sprcnt + OBJ_MINIBUBBLES].setSprite
	(
		BMP_ID_BUBBLE + m_bmpcnt,
		(int)m_bubbleInitPosiX,
		(int)girl.getYposi() + (int)m_bubbleInitPosiY,
		0,
		0,
		BUBBLE_SIZE,
		BUBBLE_SIZE,
		m_bScaleX,
		m_bScaleY,
		SPR_SCALE,
		1
	);
	return (false);
}


