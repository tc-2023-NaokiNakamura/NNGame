#pragma once

/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: CharaBase.h
	NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------

	キャラベースクラスの宣言部

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

class CharaBase {
	public:
		virtual int action() = 0;
	protected:
		POINT m_positionG;		// グローバル座標(X,Y)
		double m_speed;			// 移動スピード
		double m_xpsd;
		double m_scale;			// 拡縮
		double m_maxxp;
		int m_turn;
		int m_moveCount;		// 移動カウント
		int m_girlActMode = -1;	// 女の子アクションモード
		int m_windFlg;
};

