
/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: Common.h
	NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------
       
	�S�Ẵt�@�C���ŋ��ʂ̃w�b�_�[�t�@�C��

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

/* -----------------------------------------------------------------------------------------
|
|       DEFINE�錾
|
+ --------------------------------------------------------------------------------------- */

#define GAME_FPS	60					// --- �P�b�ԂłU�O��̉�ʍX�V
#define GAME_FRAME	( 1000 / GAME_FPS )	// --- 1000�~���b��FPS�ŏ��Z�łP�t���[���̃X�s�[�h�����߂�

#define BMP_DATA_SPR_MAX	100		// �X�v���C�g�ő�o�^�\����
#define BMP_DATA_BG_MAX		3		// --- �w�i�ő�o�^�\����

// �E�B���h�E�T�C�Y
#define WINDOW_W 700				// �E�C���h�E�T�C�Y�@�Z�o
#define WINDOW_H 800				// �E�C���h�E�T�C�Y�@�Z�o

// �I�u�W�F�N�g�ԍ�
#define OBJ_BG_MAX 3
#define OBJ_SPR_MAX 4000			// �I�u�W�F�N�g��(�X�v���C�g�\���\��)
#define OBJ_TITLEBUBBLE 10			// �^�C�g���o�u��
#define OBJ_TITLEBUBBLE_MAX 20		// �^�C�g���̃V���{���ʂ�30�p��
#define OBJ_TITLE 35				// �^�C�g��
#define OBJ_TITLE_BUTTON 40			// �^�C�g���{�^���̃I�u�W�F�N�g�ԍ�
#define OBJ_MINIBUBBLES 70			// �~�j�V���{���ʕ\���I�u�W�F�N�g�ԍ�	70-73
#define OBJ_BIN_FORWORD 100			// �r��(100-103)
#define OBJ_BUBBLES 120				// (120-620)
#define OBJ_BUBBLE_MAX 500			// �V���{���ʂ̃I�u�W�F�N�g��	500�p��
#define OBJ_BIN_BACK 700			// �r��(700-703)
#define OBJ_BIN_SMOKE 750			// �r���X���[�N
#define OBJ_TIMER 1030				// �^�C�}�[
#define OBJ_RESULTBUBBLE 1800		// ���U���g�o�u��(�`2300)
#define OBJ_BIN_FIN 2350			// ���U���g��ʎ��̃r��
#define OBJ_SCORE 2400				// �X�R�A
#define OBJ_RESULTBORD 2430			// ���U���g�{�[�h
#define OBJ_SMOKE 2450				// �X���[�N
#define OBJ_PINKBUTTON 2480			// �s���N�^�C�g���{�^��
#define OBJ_GIRL 2600				// ���̎q�̃I�u�W�F�N�g�ԍ�
#define OBJ_GIRLWIND 2610			// ���̎q�̓o��
#define OBJ_STAR 2650				// ��
#define OBJ_LOADBUBBLES 3000		// �V�[���؂�ւ��o�u��
#define OBJ_LOADBUBBLES_MAX 379		// �V�[���؂�ւ��o�u��

// �^�C�g���֘A
#define BMP_TITLEBUTTON 7			// �X�^�[�g�{�^��ID�ԍ�
#define BMP_ID_PINKBUTTON 14		// �^�C�g���o�b�N�{�^��ID�ԍ�
#define TITLEBUTTONX 248			// �^�C�g���{�^������
#define TITLEBUTTONY 250			// �^�C�g���{�^���c��

// ���̎q
#define BMP_ID_GIRL_BLOW 0			// �����o���A�j���[�V����ID�ԍ�
#define BMP_ID_GIRL_STANDBY 6		// �X�^���o�C�A�j���[�V����ID�ԍ�
#define GIRL_SIZE_W 200				// ���̎q�T�C�Y����
#define GIRL_SIZE_H 200				// ���̎q�T�C�Y�c��
#define GIRL_INIT_POSIX WINDOW_W/2			// ���̎q�����|�W�V����X���W(620)
#define GIRL_INIT_POSIY WINDOW_H/2			// ���̎q�����|�W�V����Y���W(610)
#define GIRL_OFFSETX 100
#define GIRL_OFFSETY 100
#define GIRL_WIND_W 266
#define GIRL_WIND_H 200

// �o�u��
#define BMP_ID_BUBBLE 1				// �o�u��ID�ԍ�(���V���{����)
#define BUBBLES 0					// �V���{���ʃX�v���C�g�ԍ�		0�`499	WndProc.cpp
#define MAXBUBBLES 500				// �V���{���ʕ\����				500��	OBJ�ԍ���ID�ԍ�
#define BUBBLE_INIT_POSIX 45		// �V���{���ʂ̏���X���W
#define BUBBLE_INIT_POSIY -26		// �V���{���ʂ̏���Y���W
#define BUBBLE_OFFSET 40			// �V���{���ʃI�t�Z�b�g
#define BUBBLE_SIZE 80				// �V���{���ʂ̃T�C�Y
#define BUBBLE_COUNTER 30			// ��ʏ�MAX�o�u����
#define BLUE 0
#define ORANGE 1
#define PERPLE 2
#define PINK 3

// �~�j�o�u��
#define MAXMINIBUBBLES 4			// �~�j�V���{���ʕ\����
#define MINIBUBBLE_YPOSI 40			// �~�j�V���{����Y���W

// �r��
#define BIN_ID 8					// �r��ID�ԍ�
#define BIN_SIZE 100				// �r���T�C�Y
#define BIN_MAX 4					// �r���{��

// �X�R�A
#define SCORE_ID 9					// �X�R�AID�ԍ�
#define SCORESIZEX 630				// �X�R�A�T�C�Y����
#define SCORESIZEY 58				// �X�R�A�T�C�Y�c��

// �^�C�}�[
#define TIMER_ID 10					// �^�C�}�[ID�ԍ�
#define TIMER_SIZEX 130				// �^�C�}�[�T�C�Y����
#define TIMER_SIZEY 370				// �^�C�}�[�T�C�Y�c��
#define TIME 60						// �Q�[������
#define LOADTIME 10					// ���[�h����

// �^�C�g��
#define TITLE_ID 11					// �^�C�g��ID�ԍ�
#define TITLE_SIZE 500				// �^�C�g���T�C�Y

// ���U���g
#define RESULT_ID 12				// ���U���gID�ԍ�
#define RESULT_SIZEX 231			// ���U���g�T�C�Y����
#define RESULT_SIZEY 89				// ���U���g�T�C�Y�c��

// �X���[�N
#define SMOKE_ID 13					// �X���[�NID�ԍ�
#define SMOKE_SIZE 150				// �X���[�N�؂蔲���T�C�Y�c��
#define SMOKE_SIZEX 269				// �X���[�N�T�C�Y����
#define SMOKE_SIZEY 900				// �X���[�N���摜�c��

// �r���X���[�N
#define BIN_SMOKE_ID 16
#define BIN_SMOKE_SIZE 120

// �X�^�[
#define STAR_ID 15
#define STAR_INITPOSI_X WINDOW_W/2
#define STAR_INITPOSI_Y WINDOW_H/2
#define STAR_SIZE_X 96
#define STAR_SIZE_Y 103

// �������X�s�[�h
#define ALPHA_SPD 5

// �����o���o�u���A�j���[�V����
#define BUBBLE_INITVERO_MAXX 10.5	// �����o��X������	7.5
#define BUBBLE_INITVERO_MINX 5.3	// �����o��Y������
#define BUBBLE_INITVERO_Y 5.0		// �o�u���㏸�X�s�[�h

// �A�j���[�V�������[�h
#define ANIM_MODE_STOP 0			// �A�j���[�V�������[�v�I��
#define ANIM_MODE_NEXT 1			// ���̃A�j���[�V�����R�}�ֈړ�
#define ANIM_MODE_LOOP 2			// �A�j���[�V�������[�v

// �X�v���C�g���[�h
#define SPR_SCALE 0					// �g��k�����[�h
#define SPR_ALPHA 1					// �����x���[�h

// �A�j���[�V�����̏��
#define ANIM_STATE_STOP 0			// �A�j���[�V�������Î~���Ă����Ԃ̎�
#define ANIM_STATE_PLAY 1			// �A�j���[�V�����������Ă����Ԃ̎�
#define ANIM_PATTERN_BLOW 5			// ���̎q���V���{���ʂ𐁂��Ă���A�j���[�V�����p�^�[����
#define ANIM_PATTERN_STANDBY 8		// ���̎q���X�^���o�C��Ԃł���A�j���[�V�����p�^�[����
#define ANIM_PATTERN_FLOAT 8		// �V���{���ʕ��V�A�j���[�V�����p�^�[����
#define ANIM_PATTERN_SMOKE 6		// �X���[�N�A�j���[�V�����p�^�[����
#define ANIM_PATTERN_STAR 4			// �X�^�[�A�j���[�V�����p�^�[��
#define ANIM_PATTERN_HAJIKE 4		// �e���A�j���[�V�����p�^�[��

/* -----------------------------------------------------------------------------------------
|
|       �\����
|
|		���ӁF�\���̂�include�����O�ɋL�q����K�v������
|
+ --------------------------------------------------------------------------------------- */
struct AnimationData {
	int bmpNo;			// --- �r�b�g�}�b�v�摜�ԍ�
	int holdTime;		// --- �ێ�����
	RECT cutRect;		// --- �؂���Z�`
	int animMode;		// --- �A�j���[�V�������[�h
};

/* -----------------------------------------------------------------------------------------
|
|       ���ʃw�b�_�[
|
+ --------------------------------------------------------------------------------------- */
#include "SceneLoop.h"		// --- �V�[��
#include "DrawLoop.h"		// --- �`��
#include "TimeProc.h"		// --- �^�C���v���V�[�W��
#include "ConsoleWindow.h"	// --- �R���\�[���E�B���h�E
#include "BackGround.h"
#include "BitmapData.h"
#include "Animation.h"		// ���� :: Girl�N���X���Ŏg�p���邽�߁AGirl.h�����O��include����K�v������
#include "CharaBase.h"
#include "Girl.h"
#include "Sprite.h"
#include "LoadScene.h"
#include "BubbleBase.h"
#include "BubbleMove.h"
#include "MiniBubbles.h"
#include "Bin.h"
#include "Score.h"
#include "TitleButton.h"
#include "Title.h"
#include "TitleBubble.h"
#include "Result.h"
#include "ResultBord.h"
#include "ResultBubble.h"
#include "Smoke.h"
#include "ResultBigBubble.h"
#include "TitleBackButton.h"
#include "AllInit.h"
#include "Star.h"

/* -----------------------------------------------------------------------------------------
|
|       �^�錾
|
+ --------------------------------------------------------------------------------------- */
// �V�[���̖��O
enum SceneName {
	eSceneBlank = -1 ,	// �ŏ���1��
	eSceneTitle ,		// �^�C�g��
	eSceneLoad ,		// ���[�h���
	eScenePlay,			// �Q�[�����
	eSceneFin ,			// �Q�[���I�����
} ;

/* -----------------------------------------------------------------------------------------
|
|       �O���[�o���֐��@�v���g�^�C�v�錾
|
+ --------------------------------------------------------------------------------------- */
int SceneLoop( ) ;
int DrawLoop( ) ;

/* -----------------------------------------------------------------------------------------
|
|       �O���Q�Ɛ錾
|
+ --------------------------------------------------------------------------------------- */

// --- �R���\�[���E�B���h�E
//extern ConsoleWindow g_cWin;

// --- �E�B���h�E�Ȃǂ̃^�C�g��
extern TCHAR g_szAppTitle[ ];
extern TCHAR g_szWndClass[ ];

// --- �C���X�^���X�n���h��
extern HINSTANCE g_hInstance;

// --- �E�C���h�E�n���h��
extern HWND g_hWindow;	

// �o�b�N�o�b�t�@
extern HDC g_hBackBuf ;

// ���p�̃f�o�C�X�R���e�L�X�g
extern HDC	g_hWorkBuf ;

// --- �V�[���ԍ�
extern int g_sceneNo ;

extern int scene_Tim;

extern int clickcheck;

extern BOOL reSpawnFlg;

extern BOOL clTrigger;

extern BOOL geneTimFlg[];

extern int anmflg[];

extern int blBblFlg;

extern int totalCatchBbl;

extern int bubbleNum;

extern BOOL destroyFlg;

extern int bblColor[];

extern POINT clickDownPt;

extern BitmapData g_bDataBGTable[];
extern BitmapData g_bDataSprTable[BMP_DATA_SPR_MAX];

extern BackGround g_BG[OBJ_BG_MAX];

extern Sprite g_sprite[];

extern Girl girl;

extern LoadScene* ptrLoadScene[];

extern LoadScene loadScene[];

extern BubbleBase* ptrBubblesarray[];

extern BubbleMove bubbleSet[];

extern MiniBubbles miniBubbles[];

extern AnimationData girlAnmBlow[];

extern AnimationData girlAnmStandby[];

extern AnimationData bubbleAnim[];

extern AnimationData hajikeAnim[];

extern Bin* ptrBinarray[];

extern Bin bin[];

extern Score* ptrScore;

extern Score score;

extern TimeProc* ptrTimeProc;

extern TimeProc timeproc;

extern TitleButton titleButton;

extern Title title;

extern AnimationData titleAnm[];

extern TitleBubble* ptrTitleBubble[];

extern TitleBubble titleBubble[];

extern AnimationData titleBblAnim[];

extern Result* result[];

extern ResultBord resultBord;

extern ResultBubble resultBubble[];

extern Smoke smoke;

extern AnimationData smokeLoopAnim[];

extern AnimationData smokeStopAnim[];

extern AnimationData binSmokeAnim[];

extern ResultBigBubble bigBubble;

extern TitleBackButton titleBackButton;

extern AllInit allInit;

extern Star star;

extern AnimationData starAnim[];



