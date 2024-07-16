/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: Result.h
	NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------

	リザルトクラス

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

class Result {
	public:
		int getUseFlg() { return m_useflg; };
		virtual int action() = 0;
	protected:
		double m_xp;		// X座標
		double m_yp;		// Y座標
		int m_usebmp;		// BMP番号
		int m_sprNo;		// オブジェクト番号
		int m_useflg;		// 表示フラグ	0 : 非表示	1 : 表示
		double m_xspd;		// Xスピード
		double m_yspd;		// Yスピード
		double m_scale;		// 拡縮値
};

