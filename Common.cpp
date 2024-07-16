/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: KeyManager.cpp
	NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------
       
	���ʂł̏����A�܂��͔ėp��������֐���ϐ��̎��̐錾��

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

#include <windows.h>
#include <stdio.h>	// --- �R���\�[���p

#include "Common.h"

/* -----------------------------------------------------------------------------------------
|
|       �O���[�o���ϐ����I�u�W�F�N�g�̎��̐錾
|
+ --------------------------------------------------------------------------------------- */

// --- �R���\�[���E�B���h�E
//ConsoleWindow g_cWin;

// --- �E�B���h�E�Ȃǂ̃^�C�g��
TCHAR g_szAppTitle[ ] = TEXT( "NNGame.exe" );
TCHAR g_szWndClass[ ] = TEXT( "MasterSample" );

// --- �C���X�^���X�n���h��
HINSTANCE g_hInstance = NULL;	

// --- �E�C���h�E�n���h��
HWND g_hWindow = NULL;	

// �o�b�N�o�b�t�@
HDC	g_hBackBuf = NULL ;

// ���p�̃f�o�C�X�R���e�L�X�g
HDC	g_hWorkBuf = NULL ;

// --- �V�[���ԍ�
int g_sceneNo = -1 ;

// --- �N���b�N�ʒu
POINT clickDownPt;

// ���[�h��ʃV�[���؂�ւ��t���[����
int scene_Tim = LOADTIME;

// �^�C�g���{�^���̃N���b�N����
int clickcheck = 0;

// �o�u�������X�|�[����
BOOL reSpawnFlg = 0;

// �P�N���b�N�łP�o�u���𔻒肳���邽�߂̃g���K�[
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

