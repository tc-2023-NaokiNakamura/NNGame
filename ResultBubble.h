/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: ResultBubble.h
	NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------

	���U���g�o�u���N���X

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
		int geneTim;				// ��������
		static int geneTimSet;		// �����^�C�}�[�X�V
		static int geneTimer;		// �����^�C�}�[
		static int resultBblCnt;	// ���U���g�o�u�������
		static int sprNo;			// �X�v���C�g�ԍ��Z�b�g
};

