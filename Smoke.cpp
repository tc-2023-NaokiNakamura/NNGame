/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: Smoke.cpp
	NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------

	スモーク

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */
#include <windows.h>
#include <stdio.h>	// --- コンソール用

#include "Common.h"


Smoke::Smoke() {
	init();
}

void Smoke::init() {
	m_xp = WINDOW_W / 2;
	m_yp = 300;
	m_usebmp = SMOKE_ID;
	m_alpha = 255;
	m_useflg = 1;

	for (int i = 0; i < 3; i++) {
		smokeLoopAnim[i].holdTime = 16;
		smokeLoopAnim[i].cutRect.left = 0;
		smokeLoopAnim[i].cutRect.right = SMOKE_SIZEX;
		smokeLoopAnim[i].cutRect.top = i * SMOKE_SIZE;
		smokeLoopAnim[i].cutRect.bottom = (i + 1) * SMOKE_SIZE;
		smokeLoopAnim[i].animMode = ANIM_MODE_NEXT;
		if (i == 2) {
			smokeLoopAnim[i].animMode = ANIM_MODE_LOOP;
		}
	}
	for (int i = 0; i < ANIM_PATTERN_SMOKE; i++) {
		smokeStopAnim[i].holdTime = 8;
		smokeStopAnim[i].cutRect.left = 0;
		smokeStopAnim[i].cutRect.right = SMOKE_SIZEX;
		smokeStopAnim[i].cutRect.top = i * SMOKE_SIZE;
		smokeStopAnim[i].cutRect.bottom = (i + 1) * SMOKE_SIZE;
		smokeStopAnim[i].animMode = ANIM_MODE_NEXT;
		if (i == 5) {
			smokeStopAnim[i].animMode = ANIM_MODE_STOP;
		}
	}
	m_anim.setAnimData(smokeLoopAnim);
}

int Smoke::action() {
	// 全てのリザルトバブルが消えた時
	if (totalCatchBbl == resultBubble->getResultBblCnt()) {
		m_alpha -= 5;
	}
	// 完全に透明になった時
	if (m_alpha <= 0){
		m_useflg = 0;
	}

	m_anim.playAnim();
	g_sprite[OBJ_SMOKE].setSprite
	(
		m_usebmp,
		(int)(m_xp - 134.5),
		(int)(m_yp - 80),
		0,		// 現在の画像座標を取得して左右のRECT構造体座標を更新
		m_anim.getNowAnim()->cutRect.top,
		SMOKE_SIZEX,
		SMOKE_SIZE,
		1,
		1,
		SPR_ALPHA,
		m_alpha
	);

	return (false);
}

