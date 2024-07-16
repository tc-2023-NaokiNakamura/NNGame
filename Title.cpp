/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: Title.cpp
	NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------

	Titleクラスの実装部

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

#include <windows.h>
#include <stdio.h>

#include "Common.h"

Title::Title(){
	init();
}

Title::~Title() {

}

void Title::init() {
	m_xp = 350;
	m_yp = 250;
	m_usebmp = 11;

	for (int i = 0; i < ANIM_PATTERN_FLOAT; i++) {
		titleAnm[i].holdTime = 8;
		titleAnm[i].cutRect.left = 0;
		titleAnm[i].cutRect.right = TITLE_SIZE;
		titleAnm[i].cutRect.top = i * TITLE_SIZE;
		titleAnm[i].cutRect.bottom = (i + 1) * TITLE_SIZE;
		titleAnm[i].animMode = ANIM_MODE_NEXT;
		if (i == 7) {
			titleAnm[i].animMode = ANIM_MODE_LOOP;
		}
	}
	m_anim.setAnimData(titleAnm);
}

int Title::action() {
	m_anim.playAnim();		// アニメーション
	g_sprite[OBJ_TITLE].setSprite
	(
		m_usebmp,
		(int)m_xp - 250,
		(int)m_yp - 250,
		0,		// 現在の画像座標を取得して左右のRECT構造体座標を更新
		m_anim.getNowAnim()->cutRect.top,
		TITLE_SIZE,
		TITLE_SIZE,
		1,
		1,
		SPR_SCALE,
		1
	);

	return (false);
}

