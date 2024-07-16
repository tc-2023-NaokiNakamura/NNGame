/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: ResultBord.cpp
	NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------

	リザルトボード

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */
#include <windows.h>
#include <stdio.h>	// --- コンソール用
#include "time.h"
#include <cmath>

#include "Common.h"


/* ---------------------------------------------------- */
/*														*/
/*			--- 静的メンバ変数初期セット ---			*/
/*														*/
/* ---------------------------------------------------- */
int ResultBubble::geneTimSet = 0;
int ResultBubble::geneTimer = 0;
int ResultBubble::resultBblCnt = 0;
int ResultBubble::sprNo = 0;


ResultBubble::ResultBubble() {
	init();
}

ResultBubble::~ResultBubble() {
	if (destroyFlg != 1) {
		init();
	}
}


void ResultBubble::StaticInit() {
	geneTimSet = 0;
	geneTimer = 0;
	resultBblCnt = 0;
	sprNo = 0;
}


void ResultBubble::init() {
	m_xp = (double)girl.getXposi();
//	m_usebmp = (rand() % 4) + 2;
	m_usebmp = 2;
	m_scale = 0;
	m_xspd = (double)(rand() % 3);
	m_yspd = 3.0;
	m_sprNo = sprNo;
	sprNo++;

	geneTim = geneTimSet;
//	geneTimSet += (rand() % 6) + 200;
	geneTimSet += (rand() % 300);

	m_useflg = 1;

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
}


/* ------------------------------------ */
/*										*/
/*			--- バブル上昇 ---			*/
/*										*/
/* ------------------------------------ */
void ResultBubble::moving() {
	if (m_usebmp != 4) {
		m_xspd -= 0.07;
		m_xp -= m_xspd;
	}
	else {
		m_xspd -= 0.02;
		m_xp -= m_xspd;
	}
	if (m_usebmp == 5) {
		m_xspd += 0.07;
		m_xp -= m_xspd;
	}
	m_yspd -= 0.19;
	m_yp += m_yspd;
}


/* ------------------------------------ */
/*										*/
/*			--- Y座標セット ---			*/
/*										*/
/* ------------------------------------ */
void ResultBubble::setYPosi() {
	m_yp = (double)girl.getYposi() + 55;
};


/* ------------------------------------ */
/*										*/
/*			--- バブル拡大 ---			*/
/*										*/
/* ------------------------------------ */
void ResultBubble::addScale() {
	// 正規サイズになるまでスケールを徐々に拡大
	if (m_scale < 1.0) {
		m_scale += 0.025;
	}
}


/* ------------------------------------ */
/*										*/
/*			--- ホーミング ---			*/
/*										*/
/* ------------------------------------ */
void ResultBubble::homing() {
	double pi = 3.14;
	double xspd, yspd;
	static double x, y, z, c;
	double Length = 74;

	// スモークへホーミング
	x = smoke.getXp() - m_xp;	// X軸距離
	y = smoke.getYp() - m_yp;	// Y軸距離
	z = atan2(y, x);								// 角度
	c = z / (pi / 180);								// 進む角度

	xspd = cos(c * (pi / 180)) * 3;
	yspd = sin(c * (pi / 180)) * 3;

	m_xp += xspd;
	m_yp += yspd;

	// スモーク内へ入った時に消去
	if ((m_yp < smoke.getYp() + 40) && (m_yp > smoke.getYp() - 40)) {
		if ((m_xp > smoke.getXp() - 40) && (m_xp < smoke.getXp() + 40)) {
			m_useflg = 0;
			resultBblCnt++;
		}
	}
}


void ResultBubble::setPosi() {
	switch (m_usebmp)
	{
		case 2:
			m_xp = ptrBinarray[0]->getXp();
			break;
		case 3:
			m_xp = ptrBinarray[1]->getXp();
			break;
		case 4:
			m_xp = ptrBinarray[2]->getXp();
			break;
		case 5:
			m_xp = ptrBinarray[3]->getXp();
			break;
	}
	m_yp = ptrBinarray[0]->getYp();
}

int ResultBubble::action() {
	geneTimer++;

	if (geneTim < geneTimer) {
		if (m_yp > 400)
			moving();
		homing();
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
	}
	return (false);
}

