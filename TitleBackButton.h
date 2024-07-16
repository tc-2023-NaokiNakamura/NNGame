/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: TitleBackButton.h
	NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------

	タイトルバックボタンクラス

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

class TitleBackButton : public Result {
	public:
		TitleBackButton();
		void init();
		void clickCheck();
		void setAlphaOnFLg() { m_alphaOnFlg = 1; };
		int getClickCheckOnFlg() { return m_clickCheckOnFlg; };
		int getFlashFlg() { return m_flashFlg; };
		void TitleButtonFlash();
		int action() override;
	private:
		int m_spdTim;			// 上下浮遊スピード
		int m_alpha;			// 透明度
		int m_alphaOnFlg;		// 透明化モードフラグ
		int m_clickCheckOnFlg;	// クリックチェックフラグ
		int m_flashFlg;			// フラッシュフラグ
		int m_flashTim;			// フラッシュタイマー
};

