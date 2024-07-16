/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: TitleButton.h
	NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------

	タイトルボタンクラス

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

#include <Windows.h>

class TitleButton {
	public:
		TitleButton();
		~TitleButton();
		void init();
		int ClickHitCheck();
		int StartButtonFlash();
		int getFlashFlg() { return m_flashFlg; };
		int action();
	private:
		double m_xp;
		double m_yp;
		double m_yspd;
		int m_usebmp;
		int m_spdTim;
		int m_flashTim;
		int m_flashFlg;
		int m_useflg;
};


