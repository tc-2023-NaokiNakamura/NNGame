/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: ResultBord.h
	NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------

	リザルトボードクラス

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

class ResultBord : public Result {
	public:
		ResultBord();
		~ResultBord();
		void init();
		void setOnAlphaFlg() { m_alphaOnFlg = 1; };
		int getAlphaFlg() { return m_alpha; };
		int action() override;
	private:
		int m_alpha;
		BOOL m_alphaOnFlg;
};

