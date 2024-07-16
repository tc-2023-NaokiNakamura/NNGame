#pragma once

class LoadScene {
	public:
		LoadScene();
		~LoadScene();
		void StaticInit();
		void init();
		int MovingUp();
		double getYp() { return m_yp; };
		int UseFlg() { return m_useflg; };
		int action();
		Animation m_anim;

	private:
		double m_xp;
		double m_yp;
		int m_usebmp;
		int m_sprNo;
		int m_bubbleNo;
		double m_yspd;
		int m_useflg;
		static double m_px;
		static double m_py;
		static int m_sprNoFlg[OBJ_LOADBUBBLES_MAX];
		static int m_bubbleCnt;
};
