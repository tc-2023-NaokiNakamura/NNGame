/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: BubbleBase.cpp
	NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------

	�v���C���[�̃V���{���ʃx�[�X

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

#include <windows.h>
#include <stdio.h>	// --- �R���\�[���p

#include "Common.h"


// --- �}�E�X�|�C���^��X���W���擾
double BubbleBase::getMXposi() {
	double px = clickDownPt.x;
	return px;
}

// --- �}�E�X�|�C���^��Y���W���擾
double BubbleBase::getMYposi() {
	double py = clickDownPt.y;
	return py;
}


/* ---------------------------------------------------------------- */
/*																	*/
/*			--- �I�u�W�F�N�g�̕\���E��\���t���O�擾 ---			*/
/*																	*/
/* ---------------------------------------------------------------- */
int BubbleBase::getUseFlg() {
	return m_flg;
}





