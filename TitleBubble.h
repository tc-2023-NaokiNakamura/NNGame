/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: TitleBubble.h
	NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------

	�^�C�g���o�u���N���X

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

class TitleBubble {
	public:
		TitleBubble();
		~TitleBubble();
		void StaticInit();
		void init();
		void moving();
		int action();
		Animation m_anim;
	private:
		double m_xp;			// X���W
		double m_yp;			// Y���W
		int m_usebmp;			// BMP�ԍ�
		int m_sprNo;			// �I�u�W�F�N�g�ԍ�
		int m_geneTim;			// �����^�C�}�[
		int m_useflg;			// �\���t���O
		double m_xspd;			// X�X�s�[�h
		double m_yspd;			// Y�X�s�[�h
		double m_xpChange;		// X���W�z�u
		static int m_timer;		// �����^�C�}�[�Z�b�g
		static double m_xg;		// �����l
		static int m_posChange;	// X���W�z�u
		static int sprNo;		// �X�v���C�g�ԍ��X�V
};

