
/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: SceneLoop.cpp
	NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------
       
    �V�[�����[�v�̏���

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

#include <windows.h>
#include <stdio.h>

#include "Common.h"

/* ------------------------------------------------------------ */
/*	�V�[�����[�v												*/
/*	�����ŃV�[���̑J�ڂ��s��									*/
/* ------------------------------------------------------------ */
int SceneLoop( )
{
	static int cnt = 0 ;						// 1�񂾂�������

	// --- �V�[���̖��O�ɂ���ĕ���
	switch( g_sceneNo )
	{
		// --- �u�����N
		case eSceneBlank :
			g_sceneNo++;
			break ;
		case eSceneTitle:
			if (ptrLoadScene[OBJ_LOADBUBBLES_MAX - 1]->getYp() > WINDOW_H) {
				titleButton.action();
				title.action();
				for (int i = 0; i < OBJ_TITLEBUBBLE_MAX; i++) {
					ptrTitleBubble[i]->action();
				}
			}
//g_sceneNo = eScenePlay;							// �f�o�b�O�p

			if (titleButton.getFlashFlg() == 1) {
				for (int i = 0; i < OBJ_LOADBUBBLES_MAX; i++) {
					if (ptrLoadScene[i]->UseFlg() == 1)
						ptrLoadScene[i]->action();
				}
				if (ptrLoadScene[OBJ_LOADBUBBLES_MAX - 1]->getYp() < WINDOW_H) {
//					girl.action();
					// �r���\��
					for (int i = 0; i < (BIN_MAX-1); i++) {
						ptrBinarray[i]->action();
					}
					ptrScore->action();
					ptrTimeProc->action();
				}
				if (ptrLoadScene[OBJ_LOADBUBBLES_MAX - 1]->UseFlg() == 0) {
					g_sceneNo = eSceneLoad;
				}
			}

			break;
		case eSceneLoad:
			scene_Tim--;
			clickDownPt.x = WINDOW_W;
			clickDownPt.y = WINDOW_H;
			// �r���\��
			for (int i = 0; i < (BIN_MAX-1); i++) {
				ptrBinarray[i]->action();
			}
			ptrScore->action();
			ptrTimeProc->action();
			ptrTimeProc->startTime();

			if (star.getUseFlg() == 1)
				star.action();

			girl.action();

//g_sceneNo++;							// �f�o�b�O�p
//			if (scene_Tim < 0) {	
//				scene_Tim = LOADTIME;
//				g_sceneNo++;
//				clickcheck = 0;
//				ptrTimeProc->startTime();
//			}
			break;
		case eScenePlay:
			girl.action();
			// Max�o�u���I�u�W�F�N�g���Afor����]
			for (int i = BUBBLES; i < OBJ_BUBBLE_MAX; i++) {
				if (ptrBubblesarray[i]->getLostFlg() == 0) {
					if (ptrBubblesarray[i]->getBubbleCnt() < 30) {
						ptrBubblesarray[bubbleNum]->BubbleGenerator();
						bubbleNum++;
					}
				}
				// �|�C���^�̒��g�����鎞
				if (ptrBubblesarray[i] != nullptr) {
					// �I�u�W�F�N�g�����݂��Ă��鎞
					if (ptrBubblesarray[i]->getUseFlg()) {
						ptrBubblesarray[i]->action();
					}
				}
			}
			// �V���{���ʐ����o����
			if (reSpawnFlg == 1) {
				for (int i = 0; i < MAXMINIBUBBLES; i++) {
					miniBubbles[i].action();
				}
			}

			// �r���\��
			for (int i = 0; i < (BIN_MAX-1); i++) {
				ptrBinarray[i]->action();
			}
			ptrScore->action();
			ptrTimeProc->action();
			if (TIME - ptrTimeProc->getTime() <= 0) {		// �^�C���A�b�v��
				g_sceneNo = eSceneFin;

				ptrLoadScene[0]->StaticInit();
				for (int i = 0; i < OBJ_LOADBUBBLES_MAX; i++) {
					ptrLoadScene[i]->~LoadScene();
				}

				for (int i = 0; i < BIN_MAX; i++) {
					ptrBinarray[i]->changeBinPos();
				}

				// 0�ȏ�擾������
				if (totalCatchBbl != 0)
					reSpawnFlg = 1;
				else
					reSpawnFlg = 0;
				// 0�ȏ�擾������
				if (totalCatchBbl != 0) {
					for (int i = 0; i < totalCatchBbl; i++) {
						result[i + 1] = &resultBubble[i];
					}
					for (int i = 0; i < totalCatchBbl; i++) {
//						resultBubble[i].setYPosi();
						resultBubble[i].setPosi();
					}
					result[totalCatchBbl + 2] = &smoke;
					result[totalCatchBbl + 3] = &bigBubble;
				}
			}
			break;
		case eSceneFin:
			if (ptrLoadScene[OBJ_LOADBUBBLES_MAX - 1]->getYp() > WINDOW_H) {
				for (int i = 0; i < totalCatchBbl + 1; i++) {
					if (result[i]->getUseFlg() == 1)
						result[i]->action();
				}
				ptrScore->action();
				titleBackButton.action();
				if (totalCatchBbl != 0) {
					if (result[totalCatchBbl + 2]->getUseFlg() == 1)
						result[totalCatchBbl + 2]->action();
					if (totalCatchBbl == resultBubble->getResultBblCnt())
						result[totalCatchBbl + 3]->action();
				}
				girl.action();
				for (int i = 0; i < BIN_MAX; i++) {
					ptrBinarray[i]->action();
				}
			}

			if (titleBackButton.getFlashFlg() == 1) {
				for (int i = 0; i < OBJ_LOADBUBBLES_MAX; i++) {
					if (ptrLoadScene[i]->UseFlg() == 1)
						ptrLoadScene[i]->action();
				}

				if (ptrLoadScene[OBJ_LOADBUBBLES_MAX - 1]->UseFlg() == 0) {
					g_sceneNo = eSceneBlank;	// �Q�[�����[�h���ŏ���
					allInit.StaticInit();		// �ÓI�����o�ϐ�������
					allInit.init();				// �����o�ϐ�������
				}
			}
			break;
	}

	return( false ) ;
}

