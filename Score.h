/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: Score.h
	NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------

	�X�R�A�N���X

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
		double m_xp[13];			// ��ʏ�|�W�V����X
		double m_yp[2];				// ��ʏ�|�W�V����Y
		double m_up[11];			// �摜���W��U
		double m_vp[2];				// �摜���W�cV
		double m_cutSize[10];		// �؂蔲���T�C�Y
		int m_digid[5];				// ���ԍ�
		int m_sprNo[12];			// ��ʕ\���ԍ�
		int m_usebmp = SCORE_ID;	// �g�pBMP
		int scoreNo[10];			// ���l�؂蔲���ʒu
		int m_useflg[10];			// �g�p�t���O
		static int m_alpha[2];		// �����x
		static int totalScore;		// ���v�X�R�A
		static int finFlg;			// ���U���g��ʃt���O
		static int m_sprFlg;		// �X�v���C�g���[�h�t���O	0 : �g�k���[�h	1 : �����x���[�h
		static BOOL m_alphaOnFlg;	// �������t���O
		static double xp;			// X���W�X�V
		static int m_MaxScore;		// MAX�X�R�A
};

