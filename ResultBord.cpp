/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: ResultBord.cpp
	NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------

	���U���g�{�[�h

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */
#include <windows.h>
#include <stdio.h>	// --- �R���\�[���p

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
	// �r�b�O�o�u����������x�傫���Ȃ�����
	if (m_alphaOnFlg == 1) {
		reSpawnFlg = 0;
		if (m_alpha < 255)
			m_alpha += ALPHA_SPD;
	}
	// �l���V���{���ʐ���0�̎�
	if (totalCatchBbl == 0) {
		if (m_alpha < 255)
			m_alpha += ALPHA_SPD;
	}
	g_sprite[OBJ_RESULTBORD].setSprite
	(
		m_usebmp,
		(int)(m_xp - 115.5),
		(int)(m_yp - 44.5),
		0,		// ���݂̉摜���W���擾���č��E��RECT�\���̍��W���X�V
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

