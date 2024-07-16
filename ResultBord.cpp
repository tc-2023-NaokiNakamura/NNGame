/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: ResultBord.cpp
	NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------

	リザルトボード

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */
#include <windows.h>
#include <stdio.h>	// --- コンソール用

#include "Common.h"

ResultBord::ResultBord(){
	init();
}

ResultBord::~ResultBord() {

}

void ResultBord::init() {
	m_xp = 300;
	m_yp = 200;
	m_usebmp = RESULT_ID;
	m_alpha = 0;
	m_alphaOnFlg = 0;
	m_useflg = 1;
}

int ResultBord::action() {
	// ビッグバブルがある程度大きくなった時
	if (m_alphaOnFlg == 1) {
		reSpawnFlg = 0;
		if (m_alpha < 255)
			m_alpha += ALPHA_SPD;
	}
	// 獲得シャボン玉数が0の時
	if (totalCatchBbl == 0) {
		if (m_alpha < 255)
			m_alpha += ALPHA_SPD;
	}
	g_sprite[OBJ_RESULTBORD].setSprite
	(
		m_usebmp,
		(int)(m_xp - 115.5),
		(int)(m_yp - 44.5),
		0,		// 現在の画像座標を取得して左右のRECT構造体座標を更新
		0,
		RESULT_SIZEX,
		RESULT_SIZEY,
		1,
		1,
		SPR_ALPHA,
		m_alpha
	);

	return (false);
}

