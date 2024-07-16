/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: ResultBubble.h
	NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------

	リザルトバブルクラス

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

class ResultBubble : public Result {
	public:
		ResultBubble();
		~ResultBubble();
		void StaticInit();
		void init();
		void moving();
		void setYPosi();
		void addScale();
		void homing();
		void setPosi();
		void setUseBmp(int bmp) { m_usebmp = bmp; printf("%d\n",bmp); };
		int getResultBblCnt() { return resultBblCnt; };
		int action() override;
		Animation m_anim;
	private:
		int geneTim;				// 生成時間
		static int geneTimSet;		// 生成タイマー更新
		static int geneTimer;		// 生成タイマー
		static int resultBblCnt;	// リザルトバブル回収数
		static int sprNo;			// スプライト番号セット
};

