/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: AllInit.cpp
	NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------

	AllInit�N���X�̎�����

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

#include <windows.h>
#include <stdio.h>

#include "Common.h"


/* ------------------------------------------------ */
/*													*/
/*			--- �ÓI�����o�ϐ������� ---			*/
/*													*/
/* ------------------------------------------------ */
void AllInit::StaticInit() {
	titleBubble[0].StaticInit();
	bubbleSet[0].StaticInit();
	bin[0].StaticInit();
	miniBubbles[0].StaticInit();
	timeproc.StaticInit();
	ptrScore->StaticInit();
	resultBubble[0].StaticInit();
	ptrLoadScene[0]->StaticInit();
}

/* ------------------------------------------------ */
/*													*/
/*			--- �^�C�g���o�b�N������ ---			*/
/*													*/
/* ------------------------------------------------ */
void AllInit::init() {
	titleButton.init();									// �^�C�g���{�^��������
	title.init();										// �^�C�g���������r�b�O�o�u��������
	titleBackButton.init();								// �^�C�g���o�b�N�{�^��������
	girl.init();
	for (int i = 0; i < OBJ_TITLEBUBBLE_MAX; i++) {
		ptrTitleBubble[i]->~TitleBubble();				// �^�C�g�����V�o�u��������
	}
	for (int i = BUBBLES; i < MAXBUBBLES; i++) {
		bubbleSet[i].init();							// �Q�[���o�u��������
		resultBubble[i].~ResultBubble();				// ���U���g�o�u��������
	}
	for (int i = 0; i < OBJ_LOADBUBBLES_MAX; i++) {
		ptrLoadScene[i]->~LoadScene();
	}
	for (int i = 0; i < BIN_MAX; i++) {
		ptrBinarray[i]->~Bin();							// �r��������
	}
	for (int i = 0; i < MAXMINIBUBBLES; i++) {
		miniBubbles[i].~MiniBubbles();					// �~�j�o�u��������
	}
	ptrScore->~Score();									// �X�R�A������
	resultBord.init();									// ���U���g�{�[�h������
	smoke.init();										// �X���[�N������
	bigBubble.init();									// ���U���g�r�b�O�o�u��������
	timeproc.~TimeProc();								// �^�C�}�[������
	star.~Star();

	// �O���[�o���ϐ�������
	clickcheck = 0;
	reSpawnFlg = 0;
	clTrigger = FALSE;
	geneTimFlg[0] = 0;		// test
	geneTimFlg[1] = 0;
	blBblFlg = 0;
	totalCatchBbl = 0;
	scene_Tim = LOADTIME;
	bubbleNum = 0;
	for (int i = 0; i < 4; i++) {
		bblColor[i] = 0;
	}
}


