/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: BubbleMove.cpp
	NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------

	浮遊シャボン玉移動

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

#include <windows.h>
#include <stdio.h>	// --- コンソール用

#include "Common.h"
#include "time.h"
#include<cmath>


/* ---------------------------------------------------- */
/*														*/
/*			--- 静的メンバ変数初期セット ---			*/
/*														*/
/* ---------------------------------------------------- */
// --- 吹き出した際の上昇開始位置
double BubbleMove::m_bubble_init_veloXMax = BUBBLE_INITVERO_MAXX;	// 初期X方向スピードMAX(最速)
double BubbleMove::m_bubble_init_veloXMin = BUBBLE_INITVERO_MINX;	// 初期X方向スピードMIN(最遅)
int BubbleMove::sprcnt = 0;											// スプライト配列要素番号	120～
int BubbleMove::m_bblNo = 0;										// クリックしたシャボン玉の色取得
BOOL BubbleMove::m_clickCheck = 0;									// バブルクリックチェックフラグ
int BubbleMove::m_firstBblNo = -1;
int BubbleMove::m_blackBblHitFlg = 0;
BOOL BubbleMove::bblBlackFlg = 0;
int BubbleMove::geneTime = 0;			// バブル生成タイマー
double BubbleMove::yg = 0.03;			// バブル浮遊時縦揺れ重力値
int BubbleMove::m_befhitBubbleNo = 0;
int BubbleMove::m_bubblecnt = 0;
int BubbleMove::m_timer = 0;

BubbleMove::BubbleMove() {
	init();
}

BubbleMove::~BubbleMove() {
	init();
}

void BubbleMove::StaticInit() {
	// --- 吹き出した際の上昇開始位置
	m_bubble_init_veloXMax = BUBBLE_INITVERO_MAXX;	// 初期X方向スピードMAX(最速)
	m_bubble_init_veloXMin = BUBBLE_INITVERO_MINX;	// 初期X方向スピードMIN(最遅)

	m_befhitBubbleNo = 0;

	sprcnt = 0;											// スプライト配列要素番号	120～
	m_bblNo = 0;										// クリックしたシャボン玉の色取得
	m_clickCheck = 0;									// バブルクリックチェックフラグ
	m_firstBblNo = -1;
	m_blackBblHitFlg = 0;
	bblBlackFlg = 0;
	geneTime = 0;		// バブル生成タイマー
	yg = 0.03;		// バブル浮遊時縦揺れ重力値
	m_bubblecnt = 0;
	m_timer = 0;
}

void BubbleMove::init() {
	// バブルID		0～
	m_bubbleID = sprcnt;		// test
	// スプライト番号を代入
	m_sprNo = MAXBUBBLES - sprcnt;
	sprcnt++;
	m_flg = 0;					// フラグ	->	0 : 非表示	1 : 表示
	m_bubbleMode = bMBlank;		// バブルモード最初の一回
	m_lostFlg = 0;
	m_UpSpd = -20;
	m_separateFlg = 0;
	m_hitbubbleNo = 0;
	m_moveCheck = 0;
	m_hitBinID = 0;
	m_bblHitFlg = 0;

	// バブル吹き出しアニメーション
	for (int i = 0; i < ANIM_PATTERN_FLOAT; i++) {
		bubbleAnim[i].holdTime = 8;
		bubbleAnim[i].cutRect.left = i * BUBBLE_SIZE;
		bubbleAnim[i].cutRect.right = (i + 1) * BUBBLE_SIZE;
		bubbleAnim[i].cutRect.top = 0;
		bubbleAnim[i].cutRect.bottom = BUBBLE_SIZE;
		bubbleAnim[i].animMode = ANIM_MODE_NEXT;
		if (i == 7) {
			bubbleAnim[i].animMode = ANIM_MODE_LOOP;
		}
	}
	m_anim.setAnimData(bubbleAnim);


	// 弾けアニメーション
	for (int i = 0; i < ANIM_PATTERN_HAJIKE; i++) {
		hajikeAnim[i].holdTime = 4;
		hajikeAnim[i].cutRect.left = i * BUBBLE_SIZE;
		hajikeAnim[i].cutRect.right = (i + 1) * BUBBLE_SIZE;
		hajikeAnim[i].cutRect.top = BUBBLE_SIZE;
		hajikeAnim[i].cutRect.bottom = BUBBLE_SIZE*2;
		hajikeAnim[i].animMode = ANIM_MODE_NEXT;
		if (i == 3) {
			hajikeAnim[i].animMode = ANIM_MODE_STOP;
		}
	}

	m_xp = (double)girl.getXposi();
	m_yp = (double)girl.getYposi();
	m_xgTunk = 0.1;
	m_timY = 20;
	m_bScaleX = 0;
	m_bScaleY = 0;

	m_hitbubbleID = 0;

	m_geneFlg = 0;
	// 生成タイマーセット
	m_geneTim = 0;
	// 浮遊時縦揺れ値セット
	m_ygTunk = yg;
	yg += 0.02;
	if (yg >= 0.07)
		yg = 0.03;

	m_yg = BUBBLE_INITVERO_Y;

	m_xspdTunk = (double)(rand() % 5) + 3;
	m_xspdTunk /= 10;
	m_xspd = (double)(rand() % 4) + 4;
	m_xspd /= 10;
	m_yspdTunk = (double)(rand() % 3) + 4;
	m_yspdTunk /= 10;
	m_yspd /= 10;
	m_g = (double)(rand() % 6) + 10.0;
	m_g = 20.0;			// 上昇スピード
	m_g /= 10;
//	m_g = 0.0;			// 上昇スピード

	// シャボン玉のBMPセット
	m_usebmp = (rand() % 5) + BMP_ID_BUBBLE;

	// それぞれの初速をセット
	m_xg = (double)(rand() % (int)(m_bubble_init_veloXMax - m_bubble_init_veloXMin + 1) + m_bubble_init_veloXMin);
	m_blowTim = (rand() % 15) + 45;
}


/* -------------------------------------------- */
/*												*/
/*			--- バブルスケール拡大 ---			*/
/*												*/
/* -------------------------------------------- */
void BubbleMove::addScale() {
	if (m_geneFlg == 1) {
		// 正規サイズになるまでスケールを徐々に拡大
		if (m_bScaleX < 1.0) {
			m_bScaleX += 0.025;
			m_bScaleY += 0.025;
		}
	}
}

/* -------------------------------------------------------- */
/*															*/
/*				--- 生成シャボン玉数カウンター ---			*/
/*															*/
/* -------------------------------------------------------- */
void BubbleMove::BubbleGenerator() {
	bubbleSet[m_bubbleID].setUseFlg();
	// バブル画面上Max生成数 : 30個
	m_geneTim = geneTime;
	geneTime += 100;
	m_yp = (double)girl.getYposi();
	m_bubblecnt++;
}


/*
void BubbleMove::test() {
	if (m_geneTim >= 0) {
		m_geneTim = -1;
		m_yp = (double)girl.getYposi();
	}
};
*/

/* -------------------------------------------- */
/*												*/
/*			--- シャボン玉分離状態 ---			*/
/*												*/
/* -------------------------------------------- */
int BubbleMove::separating(double scale = 60) {
	static double xLength, yLength, Length;

	for (int i = 0; i < MAXBUBBLES + 2; i++) {
		xLength = bubbleSet[i].getXp() - m_xp;
		yLength = bubbleSet[i].getYp() - m_yp;
		Length = std::hypot(xLength, yLength);
		if (Length < scale) {		// 75
			if (bubbleSet[i].getID() > m_bubbleID) {
				m_separateFlg = 1;
				bubbleSet[i].setsepaFlg();
				return i;
			}
		}
		else {
			m_separateFlg = 0;
			bubbleSet[i].releasesepaFlg();
		}
	}
	return -1;
}


/* -------------------------------------------- */
/*												*/
/*			--- シャボン玉浮遊状態 ---			*/
/*												*/
/* -------------------------------------------- */
void BubbleMove::floating() {
	double pi = 3.14;
	static double x, y, z, c;
	m_timY--;
	m_xspd = 0.0;

	// 分離処理
	m_hitbubbleNo = separating();
	if (bubbleSet[m_hitbubbleNo].getUseFlg() == 1) {
		if (m_separateFlg == 1) {
			x = bubbleSet[m_hitbubbleNo].getXp() - m_xp;
			y = bubbleSet[m_hitbubbleNo].getYp() - m_yp;
			z = atan2(y, x);
			c = z / (pi / 180);
			m_xspd = -cos(c * (pi / 180)) * 4;		// 4
			m_yspd = -sin(c * (pi / 180)) * 2;		// 2
		}
	}

	// 上下浮遊移動
//	m_xp += m_xspd;
	m_yspd += m_yg;
	m_yp += m_yspd;
	m_yp -= m_g;
	if (m_timY <= 0) {
		m_yg *= -1;
		m_timY = 20;
		m_yspd = 0;
	}

	// --- 上限にたどり着いたら表示フラグを下ろして削除
	if (m_yp < -50) {
//		m_flg = 0;
//		m_bubbleCounter--;
		m_bubbleMode = bMDestroy;
	}
}


/* ---------------------------------------------------------------------------- */
/*																				*/
/*			--- マウスとバブルの当たり判定(クリックヒットチェック) ---			*/
/*																				*/
/* ---------------------------------------------------------------------------- */
void BubbleMove::clickHitCheck() {
	int mx_pt = (int)getMXposi();	// マウスのX座標を取得
	int my_pt = (int)getMYposi();	// マウスのY座標を取得

	// マウスとバブルの距離を取得
	m_xLength = mx_pt - m_xp;
	m_yLength = my_pt - m_yp;

	// マイナスをプラスにする処理
	m_xLength = abs(m_xLength);
	m_yLength = abs(m_yLength);

	// 画面に表示されている時
	if (m_flg != 0) {
		if (m_geneFlg == 1) {
			// 一度クリック判定を行ってクリックされていることが確認できていればスルー
			if (clTrigger == FALSE) {
				// シャボン玉の中心点とマウスクリック位置の距離を取得
				m_Length = std::hypot(m_xLength, m_yLength);
				// 距離が35未満であれば当たり判定
				if (m_Length < 35) {
					m_bubbleMode = bMClick;		// モードをクリックされた判定に切り替え
					clTrigger = TRUE;			// １つバブルがクリックされたため、１クリック１バブルのコリジョン判定をするためにトリガーを立てる
					m_bblNo = m_usebmp;			// 最初にクリックしたシャボン玉の色を格納
					m_hitbubbleID = m_bubbleID;
					m_befhitBubbleNo = m_bubbleID;
					m_firstBblNo = m_bubbleID;
					m_clickCheck = 1;
				}
			}
		}
	}
}


/* ---------------------------------------------------------------- */
/*																	*/
/*			--- 同色シャボン玉ドラッグ中ヒットチェック ---			*/
/*																	*/
/* ---------------------------------------------------------------- */
void BubbleMove::dragHitCheck() {
	int mx_pt = (int)getMXposi();	// マウスのX座標を取得
	int my_pt = (int)getMYposi();	// マウスのY座標を取得

	// マウスとバブルの距離を取得
	m_xLength = mx_pt - m_xp;
	m_yLength = my_pt - m_yp;

	// マイナスをプラスにする処理
	m_xLength = abs(m_xLength);
	m_yLength = abs(m_yLength);

	// 画面に表示されている時
	if (m_flg != 0) {
		if (m_geneFlg == 1) {
			// シャボン玉の中心点とマウスクリック位置の距離を取得
			m_Length = std::hypot(m_xLength, m_yLength);
			// 最初にクリックしたシャボン玉と同色のシャボン玉の時
			if ((m_bblNo == m_usebmp) || (m_usebmp == 1)) {
				// マウスの座標とシャボン玉の中心座標の距離が35未満の時(当たり判定)
				if (m_Length < 35) {
					if ((m_usebmp == 1) && (blBblFlg == 0)) {
						m_blackBblHitFlg = 1;
						bblBlackFlg = 1;
					}
					else if ((m_usebmp == 1) && (blBblFlg == 1)) {
						bblBlackFlg = 1;
					}
					m_hitbubbleID = m_befhitBubbleNo;
					m_hitBinID = bubbleSet[m_hitbubbleID].getHitBinID();
					m_befhitBubbleNo = m_bubbleID;
					m_bubbleMode = bMHoming;
					m_bblHitFlg = 1;
				}
			}
		}
	}
}


/* ------------------------------------------------ */
/*													*/
/*			--- シャボン玉吹き出し状態 ---			*/
/*													*/
/* ------------------------------------------------ */
void BubbleMove::blowing() {
	double pi = 3.14;
	static double x, y, z, c;
	m_blowTim--;
	// 分離処理
	m_hitbubbleNo = separating();
	if (bubbleSet[m_hitbubbleNo].getUseFlg() == 1) {
		if (m_separateFlg == 1) {
				x = bubbleSet[m_hitbubbleNo].getXp() - m_xp;
				y = bubbleSet[m_hitbubbleNo].getYp() - m_yp;
				z = atan2(y, x);
				c = z / (pi / 180);
				m_xspd = -cos(c * (pi / 180)) * 4;
				m_yspd = -sin(c * (pi / 180)) * 2;
		}
	}

	// 吹き出しモーション
	if (m_blowTim > 0) {
		m_xg -= 0.05;
		m_xp -= m_xg;
		m_yg -= 0.19;
		m_yp += m_yg;
	}
	else {
		if (m_yg <= m_yspd - 2.3) {
			m_yg += 0.12;
			m_yp += m_yg;
		}
		else {
			m_xg = m_xgTunk;
			m_yg = m_ygTunk;
			m_bubbleMode = bMFloating;
		}
	}
}


/* ---------------------------------------- */
/*											*/
/*			--- ホーミング処理 ---			*/
/*											*/
/* ---------------------------------------- */
void BubbleMove::homing() {
	double pi = 3.14;
	static double x, y, z, c;
	double Length = 74;


	x = bubbleSet[m_hitbubbleID].getXp() - m_xp;	// X軸距離
	y = bubbleSet[m_hitbubbleID].getYp() - m_yp;	// Y軸距離
	z = atan2(y, x);								// 角度
//	c = z / (pi / 180);								// 進む角度
	x = 70 * cos(z);								// シャボン玉の距離感70
	y = 70 * sin(z);

/*
	m_xspd = cos(c * (pi / 180)) * 10;
	m_yspd = sin(c * (pi / 180)) * 10;

	m_xp += m_xspd;
	m_yp += m_yspd;
*/

	m_xp = bubbleSet[m_hitbubbleID].getXp() - x;
	m_yp = bubbleSet[m_hitbubbleID].getYp() - y;
}


/* ------------------------------------ */
/*										*/
/*			--- 吸収処理 ---			*/
/*										*/
/* ------------------------------------ */
void BubbleMove::vacuuming() {
	double pi = 3.14;
	static double x, y, z, c;

	// 急上昇(跳ね上がり)
	m_UpSpd++;
	m_yp += m_UpSpd;

	// ホーミング処理
	x = ptrBinarray[m_hitBinID]->getXp() - m_xp;
	y = ptrBinarray[m_hitBinID]->getYp() - m_yp;
	z = atan2(y, x);
	c = z / (pi / 180);
	m_xspd = cos(c * (pi / 180)) * 7;
	m_yspd = sin(c * (pi / 180)) * 7;
	m_xp += m_xspd;
	m_yp += m_yspd;

	// 徐々に縮小
	m_bScaleX -= 0.05;
	m_bScaleY -= 0.05;

	// ビンの表示プライオリティを上げる
	ptrBinarray[m_hitBinID]->changeObjBin(OBJ_BIN_BACK);


	// 縮小化完遂時
	if (m_bScaleX < 0) {
		// 黒シャボン玉以外の時
		if (m_usebmp != 1)
			ptrScore->addScore(1);		// 100ポイント追加
		m_bubbleMode = bMDestroy;
		ptrBinarray[m_hitBinID]->changeObjBin(OBJ_BIN_FORWORD);		// ビンのプライオリティを下げる
		ptrBinarray[m_hitBinID]->changeBinColor();					// ビンの色をランダム変更
	}
}


/* ----------------------------------------------------	*/
/*														*/
/*				--- 浮遊しゃぼん玉弾け ---				*/
/*														*/
/* ---------------------------------------------------- */
void BubbleMove::HajikeBubble() {
	if (m_anim.getAnimState() == ANIM_MODE_STOP) {
//		m_bubbleCounter--;
//		m_flg = 0;
		m_bubbleMode = bMDestroy;
	}
}


/* ----------------------------------------------------	*/
/*														*/
/*				--- 浮遊しゃぼん玉移動 ---				*/
/*														*/
/* ---------------------------------------------------- */
int BubbleMove::action() {
	double pi = 3.14;
	static double x, y, z, c;
	int sprNo = 0;

	addScale();		// バブル拡大
	if (clTrigger == FALSE) {
		m_clickCheck = 0;
		m_blackBblHitFlg = 0;
		bblBlackFlg = 0;
	}
	
	if (m_timer > m_geneTim) {
		m_geneFlg = 1;
	}

	if (reSpawnFlg == 1) {
		m_timer++;
	}
	
	switch (m_bubbleMode)
	{
		case bMBlank:		// 最初の１回
			m_bubbleMode++;
			break;
		case bMBlow:		// シャボン玉吹き出しモード
			if (m_geneFlg == 1) {
				blowing();
			}

			if (m_blackBblHitFlg == 0) {
				// シャボン玉の連結
				if (clTrigger != FALSE)
					dragHitCheck();
			}

			// 左クリック押し込み時
			if (GetKeyState(VK_LBUTTON) < -1) {
				// マイバブルポジションを移動したいために何もない箇所をクリックしたものの、
				// そのマウス座標を取得して浮遊バブルがその座標へ触れた際にクリック判定となってしまうのを防ぐクリックタイマー
				if (m_clickCheck == 0) {
					if (m_usebmp != 1) {
						clickHitCheck();	// クリック判定メソッド
					}
				}
			}

			reSpawnFlg = TRUE;		// testOK
			break;
		case bMFloating:			// シャボン玉浮遊モード(ヒットチェック)
			reSpawnFlg = FALSE;
			floating();
			if (m_blackBblHitFlg == 0) {
				if (clTrigger != FALSE)
					dragHitCheck();
			}

			// 左クリック押し込み時
			if (GetKeyState(VK_LBUTTON) < -1) {
				if (m_clickCheck == 0) {
					if (m_usebmp != 1){
						clickHitCheck();	// クリック判定メソッド
					}
					// クリックしているバブルが一番前面
					if (m_sprNo > bubbleSet[m_befhitBubbleNo].getSprNo()) {
						sprNo = m_sprNo;
						m_sprNo = bubbleSet[m_befhitBubbleNo].getSprNo();
						bubbleSet[m_befhitBubbleNo].setSprNo(sprNo);
					}
				}
			}
			break;
		case bMClick:		// クリック判定モード(クリックしたシャボン玉の状態)		1個目のシャボン玉
/*
			// 分離処理
			m_hitbubbleNo = separating();
			if (bubbleSet[m_hitbubbleNo].getUseFlg() == 1) {
				if (m_separateFlg == 1) {
					x = bubbleSet[m_hitbubbleNo].getXp() - m_xp;
					y = bubbleSet[m_hitbubbleNo].getYp() - m_yp;
					z = atan2(y, x);
					c = z / (pi / 180);
					m_xspd = -cos(c * (pi / 180)) * 4;		// 4
					m_yspd = -sin(c * (pi / 180)) * 2;		// 2
				}
			}
*/

			m_xp = getMXposi();		// クリックしたシャボン玉のxpをマウスのX座標へ
			m_yp = getMYposi();		// クリックしたシャボン玉のypをマウスのY座標へ

			for (int i = 0; i < (BIN_MAX-1); i++) {
				// ビンとの衝突判定
				if (ptrBinarray[i]->BinHitCheck() != -1) {
					// ビンとバブルの色判定
					if (ptrBinarray[i]->getBinColorNo() == m_usebmp) {
						m_hitBinID = i;
						m_bblHitFlg = 1;
						bubbleSet[m_befhitBubbleNo].bblHitFlg();
					}
				}
			}

			// ビンの範囲内でリリースした時以外は、一度ビンのヒットチェック範囲内にバブルが触れていても常時範囲内か確認する
			if (ptrBinarray[m_hitBinID]->BinHitCheck() == -1) {
				m_bblHitFlg = 0;
			}

			// 黒シャボン玉に当たった時
			if (bblBlackFlg == 1) {
//				m_flg = 0;		// シャボン玉削除
				m_bubbleMode = bMHajike;
				m_anim.setAnimData(hajikeAnim);
			}

			if (clTrigger == 0) {					// クリックしていない時
				if (m_bblHitFlg == 1) {				// ビンと衝突している判定の時
					m_bubbleMode = bMVacuum;
					totalCatchBbl++;
					switch (m_usebmp)
					{
					case 2:
						bblColor[BLUE]++;
						resultBubble[totalCatchBbl - 1].setUseBmp(m_usebmp);
						break;
					case 3:
						bblColor[ORANGE]++;
						resultBubble[totalCatchBbl - 1].setUseBmp(m_usebmp);
						break;
					case 4:
						bblColor[PERPLE]++;
						resultBubble[totalCatchBbl - 1].setUseBmp(m_usebmp);
						break;
					case 5:
						bblColor[PINK]++;
						resultBubble[totalCatchBbl - 1].setUseBmp(m_usebmp);
						break;
					}
				}
				else {								// ビンと衝突していない時
					m_bubbleMode = bMFloating;
					m_xspdTunk /= 10;
					m_xspd = m_xspdTunk;		
					m_yspdTunk /= 10;
					m_yg = m_ygTunk;
					m_yspd = m_yspdTunk;
					m_bblHitFlg = 0;
//					totalCatchBbl--;
				}
			}
			break;
		case bMHoming:		// 付いていくシャボン玉の状態				2個目以降のシャボン玉
			if (clTrigger == 1){		// 左クリックを押している時
				if (m_HitFlg != 1) {	// 接触状態でない時
					homing();
				}
			}

			if (clTrigger == 0) {				// リリースした時
				if (bubbleSet[m_firstBblNo].getbblHitFlg() != 1) {		// バブルとビンが非衝突時
					m_bblHitFlg = 0;
				}
				if (m_bblHitFlg == 1) {									// バブルとビンが衝突時
					m_bubbleMode = bMVacuum;
					m_hitBinID = bubbleSet[m_firstBblNo].getHitBinID();
					totalCatchBbl++;
					switch (m_usebmp)
					{
					case 2:
						bblColor[BLUE]++;
						resultBubble[totalCatchBbl - 1].setUseBmp(m_usebmp);
						break;
					case 3:
						bblColor[ORANGE]++;
						resultBubble[totalCatchBbl - 1].setUseBmp(m_usebmp);
						break;
					case 4:
						bblColor[PERPLE]++;
						resultBubble[totalCatchBbl - 1].setUseBmp(m_usebmp);
						break;
					case 5:
						bblColor[PINK]++;
						resultBubble[totalCatchBbl - 1].setUseBmp(m_usebmp);
						break;
					}
				}
				else {
					m_bubbleMode = bMFloating;	// 浮遊状態へモードを戻す
//					totalCatchBbl--;
				}
				m_xspdTunk /= 10;
				m_xspd = m_xspdTunk;
				m_yspdTunk /= 10;
				m_yspd = m_yspdTunk;
				m_yg = m_ygTunk;
			}
			if (bblBlackFlg == 1) {
				m_bubbleMode = bMHajike;
				m_anim.setAnimData(hajikeAnim);
			}
			break;
		case bMVacuum:							// 吸収モード
			vacuuming();
			break;
		case bMHajike:
			HajikeBubble();
			break;
		case bMDestroy:
			m_bubblecnt--;
			m_flg = 0;
			setLostFlg();
			break;
	}

	m_anim.playAnim();		// アニメーション
	// 生成フラグが立っている時
	if (m_geneFlg == 1) {
		// --- 描画
		g_sprite[m_sprNo + OBJ_BUBBLES].setSprite
		(
			m_usebmp,
			(int)m_xp - (int)(m_bScaleX * 40),
			(int)m_yp - (int)(m_bScaleY * 40),
			m_anim.getNowAnim()->cutRect.left,		// 現在の画像座標を取得して左右のRECT構造体座標を更新
			m_anim.getNowAnim()->cutRect.top,
			BUBBLE_SIZE,
			BUBBLE_SIZE,
			m_bScaleX,
			m_bScaleY,
			SPR_SCALE,
			1
		);
	}
	return (false);
}


