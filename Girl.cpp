
/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: Girl.cpp
	NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------

	ガールクラスの実装部

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

#include <windows.h>
#include <stdio.h>
#include <math.h>

#include "Common.h"

Girl::Girl(){
	init();
}


void Girl::init() {
	m_positionG.x = GIRL_INIT_POSIX;
	m_positionG.y = GIRL_INIT_POSIY;
	m_speed = -1.0;				// 上下移動スピード
	m_moveCount = 20;
	anmflg[0] = 0;
	anmflg[1] = 0;
	m_scale = 0.1;
	m_maxxp = 500;
	m_xpsd = 10;
	m_turn = 0;
	m_girlActMode = -1;	// 女の子アクションモード
	m_windFlg = 0;

	// バブル吹き出しアニメーション
	for (int i = 0; i < ANIM_PATTERN_BLOW; i++) {
		girlAnmBlow[i].bmpNo = BMP_ID_GIRL_BLOW;
		girlAnmBlow[i].holdTime = 8;
		girlAnmBlow[i].cutRect.left = i * GIRL_SIZE_W;
		girlAnmBlow[i].cutRect.right = (i + 1) * GIRL_SIZE_W;
		girlAnmBlow[i].cutRect.top = 0;
		girlAnmBlow[i].cutRect.bottom = GIRL_SIZE_H;
		girlAnmBlow[i].animMode = ANIM_MODE_NEXT;
		if (i == 2) {
			girlAnmBlow[i].holdTime = 16;
		}
		if (i == 3) {
			girlAnmBlow[i].animMode = ANIM_MODE_STOP;
		}
	}

	// スタンバイ状態アニメーション
	for (int i = 0; i < ANIM_PATTERN_STANDBY; i++) {
		girlAnmStandby[i].bmpNo = BMP_ID_GIRL_STANDBY;
		girlAnmStandby[i].holdTime = 8;
		girlAnmStandby[i].cutRect.left = i * GIRL_SIZE_W;
		girlAnmStandby[i].cutRect.right = (i + 1) * GIRL_SIZE_W;
		girlAnmStandby[i].cutRect.top = 0;
		girlAnmStandby[i].cutRect.bottom = GIRL_SIZE_H;
		girlAnmStandby[i].animMode = ANIM_MODE_NEXT;
		if (i == 7) {
			girlAnmStandby[i].animMode = ANIM_MODE_LOOP;
		}
	}
	m_anim.setAnimData(girlAnmStandby);		// スタンバイアニメーション
}


/* ----------------------------------------	*/
/*											*/
/*			--- 女の子最終セット ---		*/
/*											*/
/* ---------------------------------------- */
void Girl::homing() {
	double pi = 3.14;
	double xspd, yspd;
	static double x, y, z, c;
	double Length = 74;


	x = 620 - (double)m_positionG.x;	// X軸距離
	y = 610 - (double)m_positionG.y;	// Y軸距離
	z = atan2(y, x);								// 角度
	c = z / (pi / 180);								// 進む角度

	xspd = cos(c * (pi / 180)) * 5;
	yspd = sin(c * (pi / 180)) * 5;

	m_positionG.x += (long)xspd;
	m_positionG.y += (long)yspd;

	if ((m_positionG.x <= 620) && (m_positionG.y >= 610)) {
		m_girlActMode = GirlAction;
		g_sceneNo = eScenePlay;
	}
}


int Girl::action() {
	int nowGirlUseBmp = BMP_ID_GIRL_BLOW;	// プログラム起動時は吹き出し画像セット
	int nowGirlWidth = GIRL_SIZE_W;
	int nowGirlHeight = GIRL_SIZE_H;
	int nowWindPos = 0,nowWinddir = 0;
	m_windFlg = 0;

	switch (m_girlActMode) {
		case GirlBlank:
			m_girlActMode = GirlSet;
			for (int i = 0; i < ANIM_PATTERN_STANDBY; i++) {
				girlAnmStandby[i].cutRect.top = GIRL_SIZE_H;
				girlAnmStandby[i].cutRect.bottom = GIRL_SIZE_H*2;
			}
			m_anim.setAnimData(girlAnmStandby);		// スタンバイアニメーション
			break;

		case GirlSet:
			nowGirlUseBmp = BMP_ID_GIRL_STANDBY;
			if (m_turn == 0) {		// 右行く
				m_xpsd -= 0.25;							// koko
				m_positionG.x += (long)m_xpsd;
				if (m_positionG.x > m_maxxp) {
					m_turn = 1;
					m_maxxp = WINDOW_W/2;
					for (int i = 0; i < ANIM_PATTERN_STANDBY; i++) {
						girlAnmStandby[i].cutRect.top = 0;
						girlAnmStandby[i].cutRect.bottom = GIRL_SIZE_H;
					}
					m_anim.setAnimData(girlAnmStandby);		// スタンバイアニメーション
				}
			}
			if (m_turn == 1) {		// 左行く
				m_xpsd -= 0.15;							// koko
				if (m_xpsd > 0) {
					nowWindPos = 50;
					nowWinddir = 0;
					m_windFlg = 1;
				}

				m_positionG.x += (long)m_xpsd;
				
				if (m_positionG.x < m_maxxp) {
					m_turn = 2;
					m_maxxp = (double)(WINDOW_W + 100);
					for (int i = 0; i < ANIM_PATTERN_STANDBY; i++) {
						girlAnmStandby[i].cutRect.top = GIRL_SIZE_H;
						girlAnmStandby[i].cutRect.bottom = GIRL_SIZE_H*2;
					}
					m_anim.setAnimData(girlAnmStandby);		// スタンバイアニメーション
				}
			}
			if (m_turn == 2) {
				m_xpsd += 0.25;					// koko
				if (m_xpsd < 0) {
					nowWindPos = -150;
					nowWinddir = 266;
					m_windFlg = 1;
				}
				m_positionG.x += (long)m_xpsd;
				if (m_positionG.x > m_maxxp) {
					m_turn = 3;
					for (int i = 0; i < ANIM_PATTERN_STANDBY; i++) {
						girlAnmStandby[i].cutRect.top = 0;
						girlAnmStandby[i].cutRect.bottom = GIRL_SIZE_H;
					}
					m_anim.setAnimData(girlAnmStandby);		// スタンバイアニメーション
				}
			}
			if (m_turn == 3)
				homing();

			if (m_scale < 1)
				m_scale += 0.004;
			break;

		case GirlAction:
			// バブルがリスポーンした時
			if (reSpawnFlg == 1) {
				nowGirlUseBmp = BMP_ID_GIRL_BLOW;
				anmflg[1] = 0;
			}
			// スタンバイ状態の時
			if (reSpawnFlg == 0) {
				nowGirlUseBmp = BMP_ID_GIRL_STANDBY;
				anmflg[0] = 0;
			}

			// 毎回初期値へ戻らないように一度入ったらアニメーションが切り変わるまで再度入らないようにフラグ管理
			// 画像番号でアニメーションデータセットを変更
			switch (nowGirlUseBmp) {
				case BMP_ID_GIRL_BLOW:
					if (anmflg[0] == 0) {
						m_anim.setAnimData(girlAnmBlow);		// 吹き出しアニメーション
						anmflg[0] = 1;		// スタンバイアニメーションはLOOPするため、毎度初期セットしないようにトリガーを付ける
					}
					break;
				case BMP_ID_GIRL_STANDBY:
					if (anmflg[1] == 0) {
						m_anim.setAnimData(girlAnmStandby);		// スタンバイアニメーション
						anmflg[1] = 1;		// スタンバイアニメーションはLOOPするため、毎度初期セットしないようにトリガーを付ける
					}
					break;
			}


			// 女の子浮遊モーション(上下移動)
			if (reSpawnFlg == 0) {
				m_moveCount--;
				if (m_moveCount < 0) {
					m_speed *= -1;
					m_moveCount = 20;
				}
				m_positionG.y += (long)m_speed;
			}

			// ゲームモードがリザルト画面の時
			if (g_sceneNo == eSceneFin) {
				m_girlActMode = GirlFin;
				m_anim.setAnimData(girlAnmStandby);		// 吹き出しアニメーション
			}
			break;
		case GirlFin:
/*
			// バブル吹き出し時
			if (reSpawnFlg == 1) {
				nowGirlUseBmp = BMP_ID_GIRL_BLOW;
				anmflg[1] = 0;
			}
			// スタンバイ状態の時
			if (reSpawnFlg == 0) {
				nowGirlUseBmp = BMP_ID_GIRL_STANDBY;
				anmflg[0] = 0;
			}

			switch (nowGirlUseBmp) {
				case BMP_ID_GIRL_BLOW:
					if (anmflg[0] == 0) {
						m_anim.setAnimData(girlAnmBlow);		// 吹き出しアニメーション
						anmflg[0] = 1;		// スタンバイアニメーションはLOOPするため、毎度初期セットしないようにトリガーを付ける
					}
					break;
				case BMP_ID_GIRL_STANDBY:
					if (anmflg[1] == 0) {
						m_anim.setAnimData(girlAnmStandby);		// スタンバイアニメーション
						anmflg[1] = 1;		// スタンバイアニメーションはLOOPするため、毎度初期セットしないようにトリガーを付ける
					}
					break;
			}
*/
			nowGirlUseBmp = BMP_ID_GIRL_STANDBY;

			// 女の子浮遊モーション(上下移動)
//			if (reSpawnFlg == 0) {
				m_moveCount--;
				if (m_moveCount < 0) {
					m_speed *= -1;
					m_moveCount = 20;
				}
				m_positionG.y += (long)m_speed;
//			}
			break;
	}
	m_anim.playAnim();	// アニメーション
	g_sprite[OBJ_GIRL].setSprite
	(
		nowGirlUseBmp,
		m_positionG.x - (int)(m_scale*100),
		m_positionG.y - (int)(m_scale*100),
		m_anim.getNowAnim()->cutRect.left,		// 現在の画像座標を取得して左右のRECT構造体座標を更新
		m_anim.getNowAnim()->cutRect.top,
		nowGirlWidth,
		nowGirlHeight,
		m_scale,
		m_scale,
		SPR_SCALE,
		1
	);

	// 登場時
	if (m_windFlg == 1) {
		g_sprite[OBJ_GIRLWIND].setSprite
		(
			BMP_ID_GIRL_STANDBY,
			m_positionG.x - (int)(m_scale * 100) + nowWindPos,
			m_positionG.y - (int)(m_scale * 100),
			nowWinddir,		// 現在の画像座標を取得して左右のRECT構造体座標を更新
			406,
			GIRL_WIND_W,
			GIRL_WIND_H,
			m_scale,
			m_scale,
			SPR_SCALE,
			1
		);
	}

	return (false);
}



