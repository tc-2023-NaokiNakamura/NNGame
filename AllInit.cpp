/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: AllInit.cpp
	NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------

	AllInitクラスの実装部

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

#include <windows.h>
#include <stdio.h>

#include "Common.h"


/* ------------------------------------------------ */
/*													*/
/*			--- 静的メンバ変数初期化 ---			*/
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
/*			--- タイトルバック初期化 ---			*/
/*													*/
/* ------------------------------------------------ */
void AllInit::init() {
	titleButton.init();									// タイトルボタン初期化
	title.init();										// タイトル文字＆ビッグバブル初期化
	titleBackButton.init();								// タイトルバックボタン初期化
	girl.init();
	for (int i = 0; i < OBJ_TITLEBUBBLE_MAX; i++) {
		ptrTitleBubble[i]->~TitleBubble();				// タイトル浮遊バブル初期化
	}
	for (int i = BUBBLES; i < MAXBUBBLES; i++) {
		bubbleSet[i].init();							// ゲームバブル初期化
		resultBubble[i].~ResultBubble();				// リザルトバブル初期化
	}
	for (int i = 0; i < OBJ_LOADBUBBLES_MAX; i++) {
		ptrLoadScene[i]->~LoadScene();
	}
	for (int i = 0; i < BIN_MAX; i++) {
		ptrBinarray[i]->~Bin();							// ビン初期化
	}
	for (int i = 0; i < MAXMINIBUBBLES; i++) {
		miniBubbles[i].~MiniBubbles();					// ミニバブル初期化
	}
	ptrScore->~Score();									// スコア初期化
	resultBord.init();									// リザルトボード初期化
	smoke.init();										// スモーク初期化
	bigBubble.init();									// リザルトビッグバブル初期化
	timeproc.~TimeProc();								// タイマー初期化
	star.~Star();

	// グローバル変数初期化
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


