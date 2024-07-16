#pragma once

/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: Bin.h
	NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------

	ビンクラス

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

class Bin {
	public:
		Bin();
		~Bin();
		void StaticInit();
		void init();
		int BinHitCheck();
		int getBinColorNo() { return m_BinColorNo; };
		double getXp() { return m_xp; };
		double getYp() { return m_yp - 50; };
		void changeObjBin(int objNo) { m_objBin = objNo; };
		void changeBinColor();
		void changeBinPos();
		int action();
		Animation m_anim;
	
	private:
		double m_xp;						// ビンのX座標
		double m_yp;						// ビンのY座標
		double m_scaleX = 1;				// ビンの大きさ(X軸)
		double m_scaleY = 1;				// ビンの大きさ(Y軸)
		double m_BinColor;					// ビンの色(座標)
		RECT m_hitZone;						// ビンの当たり判定
		int m_ID;							// ビン識別子
		int m_usebmp;						// 使用BMP
		int m_sprNo;						// オブジェクト番号
		int m_BinColorNo;					// ビンの色(識別子)
		BOOL m_bblCorrectFlg;				// シャボン玉とビンの正解判定
		BOOL m_bblInOutFlg;					// シャボン玉とビンの当たり判定
		int m_objBin;						// オブジェクト配置プライオリティ

		// 静的メンバ変数
		static int m_IDNo;			// IDカウンタ
		static double m_moveXp;		// Xポジション配置
		static double m_ColorNo;	// ビンの色(座標)
		static double m_hitZoneXp;	// X座標ヒットゾーン
		static double m_moveFinXp;
};

