/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: Star.cpp
	NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------

	女の子の登場スター

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

#include <windows.h>
#include <stdio.h>	// --- コンソール用

#include "Common.h"

Star::Star() {
	init();
}


Star::~Star() {
	if (destroyFlg != 1)
		init();
}

void Star::init() {
	m_xp = STAR_INITPOSI_X;
	m_yp = STAR_INITPOSI_Y;
	m_usebmp = STAR_ID;
	m_scaleX = 0.5;
	m_scaleY = 0.5;
	m_useflg = 1;

	// バブル吹き出しアニメーション
	for (int i = 0; i < ANIM_PATTERN_STAR; i++) {
		starAnim[i].holdTime = 8;
		starAnim[i].cutRect.left = i * STAR_SIZE_X;
		starAnim[i].cutRect.right = (i + 1) * STAR_SIZE_X;
		starAnim[i].cutRect.top = 0;
		starAnim[i].cutRect.bottom = STAR_SIZE_Y;
		starAnim[i].animMode = ANIM_MODE_NEXT;
		if (i == 0) {
			starAnim[i].cutRect.left = i * 100;
			starAnim[i].cutRect.right = (i + 1) * 100;
		}
		if (i == 3) {
			starAnim[i].animMode = ANIM_MODE_STOP;
		}
	}
	m_anim.setAnimData(starAnim);
}


int Star::action() {
	if (m_anim.getNowAnim()->cutRect.left >= 288)
		setUseFlg();

	m_anim.playAnim();		// アニメーション
	// --- 描画
	g_sprite[OBJ_STAR].setSprite
	(
		m_usebmp,
		(int)m_xp - 24,
		(int)m_yp - 25,
		m_anim.getNowAnim()->cutRect.left,		// 現在の画像座標を取得して左右のRECT構造体座標を更新
		0,
		STAR_SIZE_X,
		STAR_SIZE_Y,
		m_scaleX,
		m_scaleY,
		SPR_SCALE,
		1
	);


	return (false);
}

