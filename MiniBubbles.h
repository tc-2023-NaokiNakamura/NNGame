#pragma once

class MiniBubbles {
	public:
		MiniBubbles();
		~MiniBubbles();
		void StaticInit();
		void init();
		int action();
	private:
		double m_bubbleInitPosiX;	// ��ʏ�ɂ���ڂ�ʂ�10�z�u���鏉���l
		double m_bubbleInitPosiY;	// ��ʏ�ɂ���ڂ�ʂ�10�z�u���鏉���l
		double m_bScaleX;
		double m_bScaleY;
		int m_bmptim;
		static int m_bubblecnt;
		int m_bmpcnt;
		int m_sprcnt;
};



