
/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: SceneLoop.cpp
	NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------
       
    シーンループの処理

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

#include <windows.h>
#include <stdio.h>

#include "Common.h"

/* ------------------------------------------------------------ */
/*	シーンループ												*/
/*	ここでシーンの遷移を行う									*/
/* ------------------------------------------------------------ */
int SceneLoop( )
{
	static int cnt = 0 ;						// 1回だけ初期化

	// --- シーンの名前によって分岐
	switch( g_sceneNo )
	{
		// --- ブランク
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
//g_sceneNo = eScenePlay;							// デバッグ用

			if (titleButton.getFlashFlg() == 1) {
				for (int i = 0; i < OBJ_LOADBUBBLES_MAX; i++) {
					if (ptrLoadScene[i]->UseFlg() == 1)
						ptrLoadScene[i]->action();
				}
				if (ptrLoadScene[OBJ_LOADBUBBLES_MAX - 1]->getYp() < WINDOW_H) {
//					girl.action();
					// ビン表示
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
			// ビン表示
			for (int i = 0; i < (BIN_MAX-1); i++) {
				ptrBinarray[i]->action();
			}
			ptrScore->action();
			ptrTimeProc->action();
			ptrTimeProc->startTime();

			if (star.getUseFlg() == 1)
				star.action();

			girl.action();

//g_sceneNo++;							// デバッグ用
//			if (scene_Tim < 0) {	
//				scene_Tim = LOADTIME;
//				g_sceneNo++;
//				clickcheck = 0;
//				ptrTimeProc->startTime();
//			}
			break;
		case eScenePlay:
			girl.action();
			// Maxバブルオブジェクト分、for文回転
			for (int i = BUBBLES; i < OBJ_BUBBLE_MAX; i++) {
				if (ptrBubblesarray[i]->getLostFlg() == 0) {
					if (ptrBubblesarray[i]->getBubbleCnt() < 30) {
						ptrBubblesarray[bubbleNum]->BubbleGenerator();
						bubbleNum++;
					}
				}
				// ポインタの中身がある時
				if (ptrBubblesarray[i] != nullptr) {
					// オブジェクトが存在している時
					if (ptrBubblesarray[i]->getUseFlg()) {
						ptrBubblesarray[i]->action();
					}
				}
			}
			// シャボン玉吹き出し時
			if (reSpawnFlg == 1) {
				for (int i = 0; i < MAXMINIBUBBLES; i++) {
					miniBubbles[i].action();
				}
			}

			// ビン表示
			for (int i = 0; i < (BIN_MAX-1); i++) {
				ptrBinarray[i]->action();
			}
			ptrScore->action();
			ptrTimeProc->action();
			if (TIME - ptrTimeProc->getTime() <= 0) {		// タイムアップ時
				g_sceneNo = eSceneFin;

				ptrLoadScene[0]->StaticInit();
				for (int i = 0; i < OBJ_LOADBUBBLES_MAX; i++) {
					ptrLoadScene[i]->~LoadScene();
				}

				for (int i = 0; i < BIN_MAX; i++) {
					ptrBinarray[i]->changeBinPos();
				}

				// 0個以上取得した時
				if (totalCatchBbl != 0)
					reSpawnFlg = 1;
				else
					reSpawnFlg = 0;
				// 0個以上取得した時
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
					g_sceneNo = eSceneBlank;	// ゲームモードを最初に
					allInit.StaticInit();		// 静的メンバ変数初期化
					allInit.init();				// メンバ変数初期化
				}
			}
			break;
	}

	return( false ) ;
}

