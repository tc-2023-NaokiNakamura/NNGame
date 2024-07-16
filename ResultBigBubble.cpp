/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: ResultBigBubble.cpp
	NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------

	リザルトビッグバブル

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */
#include <windows.h>
#include <stdio.h>	// --- コンソール用

#include "Common.h"

ResultBigBubble::ResultBigBubble() {
	init();
}

void ResultBigBubble::init() {
	m_xp = WINDOW_W / 2;
	m_yp = 300;
	m_usebmp = (rand() % 4) + 2;
	m_scale = 0;

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
}

void ResultBigBubble::addScale() {
	// 7倍まで拡大
	if (m_scale < 7) {
		m_scale += 0.1;
	}
	// 5倍を超えた時
	if (m_scale > 5) {
		resultBord.setOnAlphaFlg();			// リザルト文字表示
		score.setOnAlphaFlg();				// 最終スコア表示
		titleBackButton.setAlphaOnFLg();	// タイトルバックボタン表示
	}
}

int ResultBigBubble::action() {
	addScale();
	m_anim.playAnim();		// アニメーション
	// --- 描画
	g_sprite[m_sprNo + OBJ_RESULTBUBBLE].setSprite
	(
		m_usebmp,
		(int)m_xp - (int)(m_scale * 40),
		(int)m_yp - (int)(m_scale * 40),
		m_anim.getNowAnim()->cutRect.left,		// 現在の画像座標を取得して左右のRECT構造体座標を更新
		0,
		BUBBLE_SIZE,
		BUBBLE_SIZE,
		m_scale,
		m_scale,
		SPR_SCALE,
		1
	);

	return (false);
}

