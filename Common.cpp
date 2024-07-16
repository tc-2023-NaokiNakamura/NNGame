/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: KeyManager.cpp
	NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------
       
	共通での処理、または汎用性がある関数や変数の実体宣言部

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

#include <windows.h>
#include <stdio.h>	// --- コンソール用

#include "Common.h"

/* -----------------------------------------------------------------------------------------
|
|       グローバル変数＆オブジェクトの実体宣言
|
+ --------------------------------------------------------------------------------------- */

// --- コンソールウィンドウ
//ConsoleWindow g_cWin;

// --- ウィンドウなどのタイトル
TCHAR g_szAppTitle[ ] = TEXT( "NNGame.exe" );
TCHAR g_szWndClass[ ] = TEXT( "MasterSample" );

// --- インスタンスハンドル
HINSTANCE g_hInstance = NULL;	

// --- ウインドウハンドル
HWND g_hWindow = NULL;	

// バックバッファ
HDC	g_hBackBuf = NULL ;

// 共用のデバイスコンテキスト
HDC	g_hWorkBuf = NULL ;

// --- シーン番号
int g_sceneNo = -1 ;

// --- クリック位置
POINT clickDownPt;

// ロード画面シーン切り替えフレーム数
int scene_Tim = LOADTIME;

// タイトルボタンのクリック判定
int clickcheck = 0;

// バブルがリスポーン時
BOOL reSpawnFlg = 0;

// １クリックで１バブルを判定させるためのトリガー
BOOL clTrigger = FALSE;

BOOL geneTimFlg[] { 0,0 };		// test

int anmflg[2];

int blBblFlg = 0;

int totalCatchBbl = 0;

int bubbleNum = 0;

BOOL destroyFlg = 0;

int bblColor[4]{ 0 };

BitmapData g_bDataBGTable[BMP_DATA_BG_MAX];
BitmapData g_bDataSprTable[BMP_DATA_SPR_MAX];

BackGround g_BG[OBJ_BG_MAX];

Sprite g_sprite[OBJ_SPR_MAX];

Girl girl;

LoadScene *ptrLoadScene[OBJ_LOADBUBBLES_MAX];

LoadScene loadScene[OBJ_LOADBUBBLES_MAX];

BubbleBase* ptrBubblesarray[OBJ_BUBBLE_MAX];

BubbleMove bubbleSet[OBJ_BUBBLE_MAX];

MiniBubbles miniBubbles[MAXMINIBUBBLES];

AnimationData girlAnmBlow[ANIM_PATTERN_BLOW];

AnimationData girlAnmStandby[ANIM_PATTERN_STANDBY];

AnimationData bubbleAnim[ANIM_PATTERN_FLOAT];

AnimationData hajikeAnim[ANIM_PATTERN_HAJIKE];

Bin* ptrBinarray[BIN_MAX];

Bin bin[BIN_MAX];

Score* ptrScore;

Score score;

TimeProc* ptrTimeProc;

TimeProc timeproc;

TitleButton titleButton;

Title title;

AnimationData titleAnm[ANIM_PATTERN_FLOAT];

TitleBubble* ptrTitleBubble[OBJ_TITLEBUBBLE_MAX];

TitleBubble titleBubble[OBJ_TITLEBUBBLE_MAX];

AnimationData titleBblAnim[ANIM_PATTERN_FLOAT];

Result* result[OBJ_BUBBLE_MAX];

ResultBord resultBord;

ResultBubble resultBubble[OBJ_BUBBLE_MAX];

Smoke smoke;

AnimationData smokeLoopAnim[3];

AnimationData smokeStopAnim[ANIM_PATTERN_SMOKE];

AnimationData binSmokeAnim[ANIM_PATTERN_SMOKE];

ResultBigBubble bigBubble;

TitleBackButton titleBackButton;

AllInit allInit;

Star star;

AnimationData starAnim[ANIM_PATTERN_STAR];

