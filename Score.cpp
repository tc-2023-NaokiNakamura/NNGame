/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: Score.cpp
	NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------

	�X�R�A

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */
#include <windows.h>
#include <stdio.h>	// --- �R���\�[���p

#include "Common.h"

/* ---------------------------------------------------- */
/*														*/
/*			--- �ÓI�����o�ϐ������Z�b�g ---			*/
/*														*/
/* ---------------------------------------------------- */
int Score::totalScore = 0;
int Score::finFlg = 0;
int Score::m_sprFlg = 0;
int Score::m_alpha[2]{ 0 };
BOOL Score::m_alphaOnFlg = 0;
double Score::xp = 0;
int Score::m_MaxScore = 0;


Score::Score() {
	init();
}


Score::~Score() {
	if (destroyFlg != 1)
		init();
}


void Score::StaticInit() {
	totalScore = 0;
	finFlg = 0;
	m_sprFlg = 0;
	m_alpha[0] = 0;
	m_alpha[1] = 0;
	m_alphaOnFlg = 0;
	xp = 0;
}


void Score::init() {
	m_yp[0] = 44;
	m_yp[1] = 400;		// MAX�X�R�A���WY
	m_vp[0] = 0;
	m_vp[1] = SCORESIZEY;

	for (int i = 6; i < 11; i++) {
		m_sprNo[i] = i;
		m_xp[i] = 330 + xp;
		xp += 45;
	}
	m_xp[12] = 250;
	m_sprNo[11] = 11;

	xp = 0;
	for (int i = 0; i < 6; i++) {
		m_sprNo[i] = i;
		m_xp[i] = 480 + xp;
		xp += 45;
	}
	m_xp[5] = 400;

	for (int i = 0; i < 5; i++) {
		scoreNo[i] = 0;
	}
	for (int i = 0; i < 10; i++) {
		m_useflg[i] = 1;
		switch (i)
		{
			case 0:		// up�̒l�ɋC��t����(�ŏ��͂P����)
				m_cutSize[i] = 40;
				m_up[i] = 590;
				break;
			case 1:
				m_cutSize[i] = 40;
				m_up[i] = 230;
				break;
			case 2:
				m_cutSize[i] = 40;
				m_up[i] = 270;
				break;
			case 3:
				m_cutSize[i] = 40;
				m_up[i] = 310;
				break;
			case 4:
				m_cutSize[i] = 40;
				m_up[i] = 352;
				break;
			case 5:
				m_cutSize[i] = 40;
				m_up[i] = 390;
				break;
			case 6:
				m_cutSize[i] = 40;
				m_up[i] = 430;
				break;
			case 7:
				m_cutSize[i] = 40;
				m_up[i] = 470;
				break;
			case 8:
				m_cutSize[i] = 40;
				m_up[i] = 510;
				break;
			case 9:
				m_cutSize[i] = 40;
				m_up[i] = 550;
				break;
		}
	}
}


/* --------------------------------------------	*/
/*												*/
/*				--- �X�R�A���Z ---				*/
/*												*/
/* -------------------------------------------- */
void Score::addScore(int pnt) {
	int s0,s1,s2,s3,s4;
	totalScore += pnt * 100;

	s1 = totalScore / 10000;
	s0 = totalScore % 10000;
	s2 = s0 / 1000;
	s0 = s0 % 1000;
	s3 = s0 / 100;
	s0 = s0 % 100;
	s4 = s0 / 10;
	s0 = s0 % 10;

	if (totalScore >= 10000)
		scoreNo[0] = s1;
	if (totalScore >= 1000)
		scoreNo[1] = s2;
	scoreNo[2] = s3;
	scoreNo[3] = s4;
	scoreNo[4] = s0;

	if (m_MaxScore < totalScore) {
		m_MaxScore = totalScore;

		s1 = m_MaxScore / 10000;
		s0 = m_MaxScore % 10000;
		s2 = s0 / 1000;
		s0 = s0 % 1000;
		s3 = s0 / 100;
		s0 = s0 % 100;
		s4 = s0 / 10;
		s0 = s0 % 10;

		if (m_MaxScore >= 10000)
			scoreNo[5] = s1;
		if (m_MaxScore >= 1000)
			scoreNo[6] = s2;
		scoreNo[7] = s3;
		scoreNo[8] = s4;
		scoreNo[9] = s0;
	}
}


/* --------------------------------------------------------	*/
/*															*/
/*				--- �X�R�A�\���t���O�Ǘ� ---				*/
/*															*/
/* -------------------------------------------------------- */
int Score::getUseFlg(int no) {
	if (totalScore < 10000) {
		m_useflg[0] = 0;
	}
	else {
		m_useflg[0] = 1;
	}
	if (m_MaxScore < 10000) {
		m_useflg[5] = 0;
	}
	else {
		m_useflg[5] = 1;
	}

	if (totalScore < 1000) {
		m_useflg[1] = 0;
		m_useflg[6] = 0;
	}
	else {
		m_useflg[1] = 1;
		m_useflg[6] = 1;
	}
	if (m_MaxScore < 1000) {
		m_useflg[6] = 0;
	}
	else {
		m_useflg[6] = 1;
	}

	if (totalScore == 0) {
		for (int i = 2; i < 4; i++) {
			m_useflg[i] = 0;
		}
	}
	else {
		for (int i = 2; i < 4; i++) {
			m_useflg[i] = 1;
		}
	}
	if (m_MaxScore == 0) {
		for (int i = 7; i < 9; i++) {
			m_useflg[i] = 0;
		}
	}
	else {
		for (int i = 7; i < 9; i++) {
			m_useflg[i] = 1;
		}
	}

	return m_useflg[no];
}


int Score::action() {
	// ���U���g��ʂ̎�
	if (finFlg == 0) {
		if (g_sceneNo == eSceneFin) {
			for (int i = 0; i < 6; i++) {
				m_xp[i] = m_xp[i] - 150;
			}
			m_yp[0] = 300;
			finFlg = 1;
		}
	}

	// ���U���g��ʂ̎�
	if (g_sceneNo == eSceneFin) {
		m_sprFlg = 1;			// ���������[�h
		// ���������[�h�̎�
		if (resultBord.getAlphaFlg() >= 255) {
			if (m_alphaOnFlg == 1) {
				if (m_alpha[0] < 255) {
					m_alpha[0] += ALPHA_SPD;
				}
				if (m_alpha[0] >= 255) {
					if (m_alpha[1] < 255)
						m_alpha[1] += ALPHA_SPD;
				}
			}
			// �擾�o�u����0�̎�
			if (totalCatchBbl == 0) {
				if (m_alpha[0] < 255) {
					m_alpha[0] += ALPHA_SPD;
				}
				if (m_alpha[0] >= 255) {
					if (m_alpha[1] < 255)
						m_alpha[1] += ALPHA_SPD;
				}
			}
		}
	}
	else {
		m_sprFlg = 0;				// �g�k���[�h
	}

	// �`��(�X�R�A)
	for (int i = 0; i < 5; i++) {
		if (getUseFlg(i) == 1) {
			g_sprite[m_sprNo[i] + OBJ_SCORE].setSprite
			(
				m_usebmp,
				(int)m_xp[i] - 11,
				(int)m_yp[0] - 29,
				(int)m_up[scoreNo[i]],		// ���݂̉摜���W���擾���č��E��RECT�\���̍��W���X�V
				(int)m_vp[0],
				(int)m_cutSize[scoreNo[i]],
				SCORESIZEY,
				1,
				1,
				m_sprFlg,
				m_alpha[0]
			);
		}
	}

	// MAX�X�R�A
	if (g_sceneNo == eSceneFin) {
		for (int i = 6, j = 5; i < 11; i++, j++) {
			if (getUseFlg(j) == 1) {
				g_sprite[m_sprNo[i] + OBJ_SCORE].setSprite
				(
					m_usebmp,
					(int)m_xp[i] - 11,
					(int)m_yp[1] - 29,
					(int)m_up[scoreNo[j]],		// ���݂̉摜���W���擾���č��E��RECT�\���̍��W���X�V
					(int)m_vp[0],
					(int)m_cutSize[scoreNo[j]],
					SCORESIZEY,
					1,
					1,
					m_sprFlg,
					m_alpha[1]
				);
			}
		}


		// --- �`��(Max)
		g_sprite[m_sprNo[11] + OBJ_SCORE].setSprite
		(
			m_usebmp,
			(int)m_xp[12] - 115,
			(int)m_yp[1] - 29,
			0,		// ���݂̉摜���W���擾���č��E��RECT�\���̍��W���X�V
			(int)m_vp[1],
			230,
			SCORESIZEY,
			1,
			1,
			m_sprFlg,
			m_alpha[1]
		);
	}


	// --- �`��(Score)
	g_sprite[m_sprNo[5] + OBJ_SCORE].setSprite
	(
		m_usebmp,
		(int)m_xp[5] - 115,
		(int)m_yp[0] - 29,
		0,		// ���݂̉摜���W���擾���č��E��RECT�\���̍��W���X�V
		(int)m_vp[0],
		230,
		SCORESIZEY,
		1,
		1,
		m_sprFlg,
		m_alpha[0]
	);

	return (false);
}

