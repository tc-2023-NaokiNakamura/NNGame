/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: TitleButton.cpp
	NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------

	TitleButton�N���X�̎�����

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

#include <windows.h>
#include <stdio.h>

#include "Common.h"
#include<cmath>

TitleButton::TitleButton() {
	init();
}

TitleButton::~TitleButton() {

}

void TitleButton::init() {
	m_xp = WINDOW_W / 2;
	m_yp = 620.0;
	m_yspd = 0.5;
	m_usebmp = BMP_TITLEBUTTON;
	m_spdTim = 30;
	m_flashTim = 70;
	m_flashFlg = 0;
	m_useflg = 1;
}


/* -------------------------------------------------------------------------------- */
/*																					*/
/*				--- �}�E�X���X�^�[�g�{�^���N���b�N�q�b�g�`�F�b�N ---				*/
/*																					*/
/* -------------------------------------------------------------------------------- */
int TitleButton::ClickHitCheck() {
	double mx_pt = (double)clickDownPt.x;
	double my_pt = (double)clickDownPt.y;
	double m_xLength, m_yLength, m_Length;

	// �}�E�X�ƃo�u���̋������擾
	m_xLength = mx_pt - m_xp;
	m_yLength = my_pt - m_yp;

	// �}�C�i�X���v���X�ɂ��鏈��
	m_xLength = abs(m_xLength);
	m_yLength = abs(m_yLength);

	// �V���{���ʂ̒��S�_�ƃ}�E�X�N���b�N�ʒu�̋������擾
	m_Length = std::hypot(m_xLength, m_yLength);
	if (m_Length < 125) {
		m_flashFlg = 1;
	}

	return (false);
}


/* ---------------------------------------------------- */
/*														*/
/*				--- �X�^�[�g�{�^���_�� ---				*/
/*														*/
/* ---------------------------------------------------- */
int TitleButton::StartButtonFlash() {
	m_flashTim--;
	if (m_flashTim > 60) {
		m_useflg = 0;
	}
	else {
		if ((m_flashTim <= 60) && (m_flashTim >= 30)) {
			if (m_flashTim % 5 < 2) {
				m_useflg = 0;
			}
			else {
				m_useflg = 1;
			}
		}
		else {
			if ((m_flashTim & 1) != 1) {
				m_useflg = 0;
			}
			else {
				m_useflg = 1;
			}
		}
	}
	if (m_flashTim < 0)
		m_useflg = 0;

	return (false);
}

int TitleButton::action() {
	if (m_flashFlg == 1) {
		StartButtonFlash();
	}
	m_spdTim--;
	if (m_spdTim < 0) {
		m_yspd *= -1;
		m_spdTim = 30;
	}
	m_yp += m_yspd;

	if (m_useflg == 1) {
		g_sprite[OBJ_TITLE_BUTTON].setSprite
		(
			m_usebmp,
			(int)m_xp - 124,
			(int)m_yp - 125,
			0,		// ���݂̉摜���W���擾���č��E��RECT�\���̍��W���X�V
			0,
			TITLEBUTTONX,
			TITLEBUTTONY,
			1,
			1,
			SPR_SCALE,
			1
		);
	}

	return (false);
}

