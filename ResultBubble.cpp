/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: ResultBord.cpp
	NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------

	���U���g�{�[�h

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */
#include <windows.h>
#include <stdio.h>	// --- �R���\�[���p
#include "time.h"
#include <cmath>

#include "Common.h"


/* ---------------------------------------------------- */
/*														*/
/*			--- �ÓI�����o�ϐ������Z�b�g ---			*/
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

	// �o�u�������o���A�j���[�V����
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
/*			--- �o�u���㏸ ---			*/
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
/*			--- Y���W�Z�b�g ---			*/
/*										*/
/* ------------------------------------ */
void ResultBubble::setYPosi() {
	m_yp = (double)girl.getYposi() + 55;
};


/* ------------------------------------ */
/*										*/
/*			--- �o�u���g�� ---			*/
/*										*/
/* ------------------------------------ */
void ResultBubble::addScale() {
	// ���K�T�C�Y�ɂȂ�܂ŃX�P�[�������X�Ɋg��
	if (m_scale < 1.0) {
		m_scale += 0.025;
	}
}


/* ------------------------------------ */
/*										*/
/*			--- �z�[�~���O ---			*/
/*										*/
/* ------------------------------------ */
void ResultBubble::homing() {
	double pi = 3.14;
	double xspd, yspd;
	static double x, y, z, c;
	double Length = 74;

	// �X���[�N�փz�[�~���O
	x = smoke.getXp() - m_xp;	// X������
	y = smoke.getYp() - m_yp;	// Y������
	z = atan2(y, x);								// �p�x
	c = z / (pi / 180);								// �i�ފp�x

	xspd = cos(c * (pi / 180)) * 3;
	yspd = sin(c * (pi / 180)) * 3;

	m_xp += xspd;
	m_yp += yspd;

	// �X���[�N���֓��������ɏ���
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
		m_anim.playAnim();		// �A�j���[�V����
		// --- �`��
		g_sprite[m_sprNo + OBJ_RESULTBUBBLE].setSprite
		(
			m_usebmp,
			(int)m_xp - (int)(m_scale * 40),
			(int)m_yp - (int)(m_scale * 40),
			m_anim.getNowAnim()->cutRect.left,		// ���݂̉摜���W���擾���č��E��RECT�\���̍��W���X�V
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

