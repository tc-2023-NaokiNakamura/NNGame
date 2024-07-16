/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: TitleBubble.cpp
	NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------

	タイトルバブルクラスの実装部

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

#include <windows.h>
#include <stdio.h>

#include "Common.h"


/* ---------------------------------------------------- */
/*														*/
/*			--- 静的メンバ変数初期セット ---			*/
/*														*/
/* ---------------------------------------------------- */
int TitleBubble::m_timer = 0;
double TitleBubble::m_xg = 0.05;
int TitleBubble::m_posChange = 0;
int TitleBubble::sprNo = 0;

TitleBubble::TitleBubble() {
	init();
}

TitleBubble::~TitleBubble() {
	if (destroyFlg != 1) {
		init();
	}
}

void TitleBubble::StaticInit() {
	m_timer = 0;
	m_xg = 0.05;
	m_posChange = 0;
	sprNo = 0;
}

void TitleBubble::init() {
	sprNo++;
	if (sprNo % 2 == 0) {
		m_posChange = rand() % 3;
		switch (m_posChange)
		{
			case 0:
				m_xpChange = 80;
				break;
			case 1:
				m_xpChange = 0;
				break;
			case 2:
				m_xpChange = -80;
				break;
		}
		m_xp = (double)(WINDOW_W - m_xpChange);
		m_xspd = -4.0;
	}
	else {
		switch (m_posChange)
		{
		case 0:
			m_xpChange = 0;
			break;
		case 1:
			m_xpChange = -80;
			break;
		case 2:
			m_xpChange = -160;
			break;
		}
		m_xp = m_xpChange;
		m_xspd = 4.0;
	}
	m_yspd = (double)(rand() % 3) + 1;
	m_yp = 750;
	// シャボン玉のBMPセット
	m_usebmp = (rand() % 4) + 2;
	m_sprNo = sprNo;

	m_geneTim = m_timer;
	m_timer += 700;

	// バブル吹き出しアニメーション
	for (int i = 0; i < ANIM_PATTERN_FLOAT; i++) {
		bubbleAnim[i].holdTime = 8;
		bubbleAnim[i].cutRect.left = i * BUBBLE_SIZE;
		bubbleAnim[i].cutRect.right = (i + 1) * BUBBLE_SIZE;
		bubbleAnim[i].cutRect.top = 0;
		bubbleAnim[i].cutRect.bottom = BUBBLE_SIZE;
		bubbleAnim[i].animMode = ANIM_MODE_NEXT;
		if (i == 7) {
			bubbleAnim[i].animMode = ANIM_MODE_LOOP;
		}
	}
	m_anim.setAnimData(bubbleAnim);

	m_useflg = 0;
}

void TitleBubble::moving() {
	if (m_sprNo % 2 == 0) {
		if (m_xspd < -0.5)
			m_xspd += m_xg;
	}
	else {
		if (m_xspd > 0.5)
			m_xspd -= m_xg;
	}
	m_xp += m_xspd;
	m_yp -= m_yspd;

	if (m_yp < -80) {
		if (m_sprNo % 2 == 0) {
			m_posChange = rand() % 3;
			switch (m_posChange)
			{
			case 0:
				m_xpChange = 50;
				break;
			case 1:
				m_xpChange = 20;
				break;
			case 2:
				m_xpChange = -10;
				break;
			}
			m_xp = (double)(WINDOW_W - m_xpChange);
			m_xspd = -4.0;
		}
		else {
			switch (m_posChange)
			{
			case 0:
				m_xpChange = 0;
				break;
			case 1:
				m_xpChange = -30;
				break;
			case 2:
				m_xpChange = -60;
				break;
			}
			m_xp = m_xpChange;
			m_xspd = 4.0;
		}
		m_yp = 750;
		m_usebmp = (rand() % 4) + 2;
	}
}

int TitleBubble::action() {
	static int timer = 0;
	timer++;
	if (m_geneTim < timer) {
		m_useflg = 1;
	}
	if (m_useflg == 1) {
		moving();
		m_anim.playAnim();		// アニメーション
		// --- 描画
		g_sprite[m_sprNo + OBJ_TITLEBUBBLE].setSprite
		(
			m_usebmp,
			(int)m_xp,
			(int)m_yp,
			m_anim.getNowAnim()->cutRect.left,		// 現在の画像座標を取得して左右のRECT構造体座標を更新
			0,
			BUBBLE_SIZE,
			BUBBLE_SIZE,
			1,
			1,
			SPR_SCALE,
			1
		);
	}

	return (false);
}

