/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: ResultBigBubble.h
	NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------

	���U���g�r�b�O�o�u���N���X

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

class ResultBigBubble : public Result {
	public:
		ResultBigBubble();
		void init();
		void addScale();
		int action() override;
		Animation m_anim;
};

