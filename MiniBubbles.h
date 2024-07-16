#pragma once

class MiniBubbles {
	public:
		MiniBubbles();
		~MiniBubbles();
		void StaticInit();
		void init();
		int action();
	private:
		double m_bubbleInitPosiX;	// 画面上にしゃぼん玉を10個配置する初期値
		double m_bubbleInitPosiY;	// 画面上にしゃぼん玉を10個配置する初期値
		double m_bScaleX;
		double m_bScaleY;
		int m_bmptim;
		static int m_bubblecnt;
		int m_bmpcnt;
		int m_sprcnt;
};



