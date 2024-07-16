/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: Score.h
	NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------

	スコアクラス

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

class Score {
	public:
		Score();
		~Score();
		void StaticInit();
		void init();
		void addScore(int);
		void setOnAlphaFlg() { m_alphaOnFlg = 1; };
		int getAlphaFlg() { return m_alpha[1]; };
		int getUseFlg(int);
		int action();
	private:
		double m_xp[13];			// 画面上ポジションX
		double m_yp[2];				// 画面上ポジションY
		double m_up[11];			// 画像座標横U
		double m_vp[2];				// 画像座標縦V
		double m_cutSize[10];		// 切り抜きサイズ
		int m_digid[5];				// 桁番号
		int m_sprNo[12];			// 画面表示番号
		int m_usebmp = SCORE_ID;	// 使用BMP
		int scoreNo[10];			// 数値切り抜き位置
		int m_useflg[10];			// 使用フラグ
		static int m_alpha[2];		// 透明度
		static int totalScore;		// 合計スコア
		static int finFlg;			// リザルト画面フラグ
		static int m_sprFlg;		// スプライトモードフラグ	0 : 拡縮モード	1 : 透明度モード
		static BOOL m_alphaOnFlg;	// 透明化フラグ
		static double xp;			// X座標更新
		static int m_MaxScore;		// MAXスコア
};

