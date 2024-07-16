/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: Star.h
	NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------

	スタークラスの宣言部

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

class Star {
	public:
		Star();
		~Star();
		void init();
		void setUseFlg() { m_useflg = 0; };
		int getUseFlg() { return m_useflg; };
		int action();
		Animation m_anim;
	private:
		double m_xp;
		double m_yp;
		int m_usebmp;
		int m_useflg;
		double m_scaleX;
		double m_scaleY;
};

