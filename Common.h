
/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: Common.h
	NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------
       
	全てのファイルで共通のヘッダーファイル

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

/* -----------------------------------------------------------------------------------------
|
|       DEFINE宣言
|
+ --------------------------------------------------------------------------------------- */

#define GAME_FPS	60					// --- １秒間で６０回の画面更新
#define GAME_FRAME	( 1000 / GAME_FPS )	// --- 1000ミリ秒をFPSで除算で１フレームのスピードを求める

#define BMP_DATA_SPR_MAX	100		// スプライト最大登録可能枚数
#define BMP_DATA_BG_MAX		3		// --- 背景最大登録可能枚数

// ウィンドウサイズ
#define WINDOW_W 700				// ウインドウサイズ　算出
#define WINDOW_H 800				// ウインドウサイズ　算出

// オブジェクト番号
#define OBJ_BG_MAX 3
#define OBJ_SPR_MAX 4000			// オブジェクト数(スプライト表示可能数)
#define OBJ_TITLEBUBBLE 10			// タイトルバブル
#define OBJ_TITLEBUBBLE_MAX 20		// タイトルのシャボン玉を30個用意
#define OBJ_TITLE 35				// タイトル
#define OBJ_TITLE_BUTTON 40			// タイトルボタンのオブジェクト番号
#define OBJ_MINIBUBBLES 70			// ミニシャボン玉表示オブジェクト番号	70-73
#define OBJ_BIN_FORWORD 100			// ビン(100-103)
#define OBJ_BUBBLES 120				// (120-620)
#define OBJ_BUBBLE_MAX 500			// シャボン玉のオブジェクト数	500個用意
#define OBJ_BIN_BACK 700			// ビン(700-703)
#define OBJ_BIN_SMOKE 750			// ビンスモーク
#define OBJ_TIMER 1030				// タイマー
#define OBJ_RESULTBUBBLE 1800		// リザルトバブル(～2300)
#define OBJ_BIN_FIN 2350			// リザルト画面時のビン
#define OBJ_SCORE 2400				// スコア
#define OBJ_RESULTBORD 2430			// リザルトボード
#define OBJ_SMOKE 2450				// スモーク
#define OBJ_PINKBUTTON 2480			// ピンクタイトルボタン
#define OBJ_GIRL 2600				// 女の子のオブジェクト番号
#define OBJ_GIRLWIND 2610			// 女の子の登場
#define OBJ_STAR 2650				// 星
#define OBJ_LOADBUBBLES 3000		// シーン切り替えバブル
#define OBJ_LOADBUBBLES_MAX 379		// シーン切り替えバブル

// タイトル関連
#define BMP_TITLEBUTTON 7			// スタートボタンID番号
#define BMP_ID_PINKBUTTON 14		// タイトルバックボタンID番号
#define TITLEBUTTONX 248			// タイトルボタン横幅
#define TITLEBUTTONY 250			// タイトルボタン縦幅

// 女の子
#define BMP_ID_GIRL_BLOW 0			// 吹き出しアニメーションID番号
#define BMP_ID_GIRL_STANDBY 6		// スタンバイアニメーションID番号
#define GIRL_SIZE_W 200				// 女の子サイズ横幅
#define GIRL_SIZE_H 200				// 女の子サイズ縦幅
#define GIRL_INIT_POSIX WINDOW_W/2			// 女の子初期ポジションX座標(620)
#define GIRL_INIT_POSIY WINDOW_H/2			// 女の子初期ポジションY座標(610)
#define GIRL_OFFSETX 100
#define GIRL_OFFSETY 100
#define GIRL_WIND_W 266
#define GIRL_WIND_H 200

// バブル
#define BMP_ID_BUBBLE 1				// バブルID番号(黒シャボン玉)
#define BUBBLES 0					// シャボン玉スプライト番号		0～499	WndProc.cpp
#define MAXBUBBLES 500				// シャボン玉表示数				500個	OBJ番号兼ID番号
#define BUBBLE_INIT_POSIX 45		// シャボン玉の初期X座標
#define BUBBLE_INIT_POSIY -26		// シャボン玉の初期Y座標
#define BUBBLE_OFFSET 40			// シャボン玉オフセット
#define BUBBLE_SIZE 80				// シャボン玉のサイズ
#define BUBBLE_COUNTER 30			// 画面上MAXバブル数
#define BLUE 0
#define ORANGE 1
#define PERPLE 2
#define PINK 3

// ミニバブル
#define MAXMINIBUBBLES 4			// ミニシャボン玉表示数
#define MINIBUBBLE_YPOSI 40			// ミニシャボン玉Y座標

// ビン
#define BIN_ID 8					// ビンID番号
#define BIN_SIZE 100				// ビンサイズ
#define BIN_MAX 4					// ビン本数

// スコア
#define SCORE_ID 9					// スコアID番号
#define SCORESIZEX 630				// スコアサイズ横幅
#define SCORESIZEY 58				// スコアサイズ縦幅

// タイマー
#define TIMER_ID 10					// タイマーID番号
#define TIMER_SIZEX 130				// タイマーサイズ横幅
#define TIMER_SIZEY 370				// タイマーサイズ縦幅
#define TIME 60						// ゲーム時間
#define LOADTIME 10					// ロード時間

// タイトル
#define TITLE_ID 11					// タイトルID番号
#define TITLE_SIZE 500				// タイトルサイズ

// リザルト
#define RESULT_ID 12				// リザルトID番号
#define RESULT_SIZEX 231			// リザルトサイズ横幅
#define RESULT_SIZEY 89				// リザルトサイズ縦幅

// スモーク
#define SMOKE_ID 13					// スモークID番号
#define SMOKE_SIZE 150				// スモーク切り抜きサイズ縦幅
#define SMOKE_SIZEX 269				// スモークサイズ横幅
#define SMOKE_SIZEY 900				// スモーク元画像縦幅

// ビンスモーク
#define BIN_SMOKE_ID 16
#define BIN_SMOKE_SIZE 120

// スター
#define STAR_ID 15
#define STAR_INITPOSI_X WINDOW_W/2
#define STAR_INITPOSI_Y WINDOW_H/2
#define STAR_SIZE_X 96
#define STAR_SIZE_Y 103

// 透明化スピード
#define ALPHA_SPD 5

// 吹き出しバブルアニメーション
#define BUBBLE_INITVERO_MAXX 10.5	// 吹き出しX軸初速	7.5
#define BUBBLE_INITVERO_MINX 5.3	// 吹き出しY軸初速
#define BUBBLE_INITVERO_Y 5.0		// バブル上昇スピード

// アニメーションモード
#define ANIM_MODE_STOP 0			// アニメーションループ終了
#define ANIM_MODE_NEXT 1			// 次のアニメーションコマへ移動
#define ANIM_MODE_LOOP 2			// アニメーションループ

// スプライトモード
#define SPR_SCALE 0					// 拡大縮小モード
#define SPR_ALPHA 1					// 透明度モード

// アニメーションの状態
#define ANIM_STATE_STOP 0			// アニメーションが静止している状態の時
#define ANIM_STATE_PLAY 1			// アニメーションが動いている状態の時
#define ANIM_PATTERN_BLOW 5			// 女の子がシャボン玉を吹いているアニメーションパターン数
#define ANIM_PATTERN_STANDBY 8		// 女の子がスタンバイ状態であるアニメーションパターン数
#define ANIM_PATTERN_FLOAT 8		// シャボン玉浮遊アニメーションパターン数
#define ANIM_PATTERN_SMOKE 6		// スモークアニメーションパターン数
#define ANIM_PATTERN_STAR 4			// スターアニメーションパターン
#define ANIM_PATTERN_HAJIKE 4		// 弾けアニメーションパターン

/* -----------------------------------------------------------------------------------------
|
|       構造体
|
|		注意：構造体はincludeよりも前に記述する必要がある
|
+ --------------------------------------------------------------------------------------- */
struct AnimationData {
	int bmpNo;			// --- ビットマップ画像番号
	int holdTime;		// --- 保持時間
	RECT cutRect;		// --- 切り取り短形
	int animMode;		// --- アニメーションモード
};

/* -----------------------------------------------------------------------------------------
|
|       共通ヘッダー
|
+ --------------------------------------------------------------------------------------- */
#include "SceneLoop.h"		// --- シーン
#include "DrawLoop.h"		// --- 描画
#include "TimeProc.h"		// --- タイムプロシージャ
#include "ConsoleWindow.h"	// --- コンソールウィンドウ
#include "BackGround.h"
#include "BitmapData.h"
#include "Animation.h"		// 注意 :: Girlクラス内で使用するため、Girl.hよりも前でincludeする必要がある
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
|       型宣言
|
+ --------------------------------------------------------------------------------------- */
// シーンの名前
enum SceneName {
	eSceneBlank = -1 ,	// 最初の1回
	eSceneTitle ,		// タイトル
	eSceneLoad ,		// ロード画面
	eScenePlay,			// ゲーム画面
	eSceneFin ,			// ゲーム終了画面
} ;

/* -----------------------------------------------------------------------------------------
|
|       グローバル関数　プロトタイプ宣言
|
+ --------------------------------------------------------------------------------------- */
int SceneLoop( ) ;
int DrawLoop( ) ;

/* -----------------------------------------------------------------------------------------
|
|       外部参照宣言
|
+ --------------------------------------------------------------------------------------- */

// --- コンソールウィンドウ
//extern ConsoleWindow g_cWin;

// --- ウィンドウなどのタイトル
extern TCHAR g_szAppTitle[ ];
extern TCHAR g_szWndClass[ ];

// --- インスタンスハンドル
extern HINSTANCE g_hInstance;

// --- ウインドウハンドル
extern HWND g_hWindow;	

// バックバッファ
extern HDC g_hBackBuf ;

// 共用のデバイスコンテキスト
extern HDC	g_hWorkBuf ;

// --- シーン番号
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



