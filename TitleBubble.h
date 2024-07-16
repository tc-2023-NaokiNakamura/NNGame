/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: TitleBubble.h
	NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------

	タイトルバブルクラス

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

class TitleBubble {
	public:
		TitleBubble();
		~TitleBubble();
		void StaticInit();
		void init();
		void moving();
		int action();
		Animation m_anim;
	private:
		double m_xp;			// X座標
		double m_yp;			// Y座標
		int m_usebmp;			// BMP番号
		int m_sprNo;			// オブジェクト番号
		int m_geneTim;			// 生成タイマー
		int m_useflg;			// 表示フラグ
		double m_xspd;			// Xスピード
		double m_yspd;			// Yスピード
		double m_xpChange;		// X座標配置
		static int m_timer;		// 生成タイマーセット
		static double m_xg;		// 減速値
		static int m_posChange;	// X座標配置
		static int sprNo;		// スプライト番号更新
};

