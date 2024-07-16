/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: TitleBackButton.cpp
	NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------

	TitleBackButton�N���X�̎�����

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

#include <windows.h>
#include <stdio.h>

#include "Common.h"
#include<cmath>

TitleBackButton::TitleBackButton() {
	init();
}

void TitleBackButton::init() {
	m_xp = 150;
	m_yp = 600;
	m_usebmp = BMP_ID_PINKBUTTON;
	m_yspd = 0.5;
	m_spdTim = 30;
	m_alpha = 0;
	m_alphaOnFlg = 0;
	m_clickCheckOnFlg = 0;
	m_flashFlg = 0;
	m_flashTim = 70;
	m_useflg = 1;
}


/* -------------------------------------------- */
/*												*/
/*			--- �N���b�N�`�F�b�N ---			*/
/*												*/
/* -------------------------------------------- */
void TitleBackButton::clickCheck() {
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
}


/* ------------------------------------ */
/*										*/
/*			--- �{�^���_�� ---			*/
/*										*/
/* ------------------------------------ */
void TitleBackButton::TitleButtonFlash() {
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
	// �_�ŏI����
	if (m_flashTim < 0) {
		m_useflg = 0;
	}
}

int TitleBackButton::action() {
	// �Q�[�����[�h�����U���g�̎�
	if (g_sceneNo == eSceneFin) {
		if (ptrScore->getAlphaFlg() >= 255) {
			// ���������[�h�̎�
			if (m_alphaOnFlg == 1) {
				if (m_alpha < 255) {
					m_alpha += 3;
				}
				else {
					m_clickCheckOnFlg = 1;
				}
			}
			if (totalCatchBbl == 0) {
				if (m_alpha < 255)
					m_alpha += 3;
				else
					m_clickCheckOnFlg = 1;
			}
		}
	}
	m_spdTim--;
	// �㉺���V
	if (m_spdTim < 0) {
		m_yspd *= -1;
		m_spdTim = 30;
	}
	m_yp += m_yspd;

	// �^�C�g���o�b�N�{�^���_��
	if (m_flashFlg == 1) {
		TitleButtonFlash();
	}

	if (m_useflg == 1) {
		g_sprite[OBJ_PINKBUTTON].setSprite
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
			SPR_ALPHA,
			m_alpha
		);
	}

	return (false);
}


