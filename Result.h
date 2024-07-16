/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: Result.h
	NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------

	���U���g�N���X

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

class Result {
	public:
		int getUseFlg() { return m_useflg; };
		virtual int action() = 0;
	protected:
		double m_xp;		// X���W
		double m_yp;		// Y���W
		int m_usebmp;		// BMP�ԍ�
		int m_sprNo;		// �I�u�W�F�N�g�ԍ�
		int m_useflg;		// �\���t���O	0 : ��\��	1 : �\��
		double m_xspd;		// X�X�s�[�h
		double m_yspd;		// Y�X�s�[�h
		double m_scale;		// �g�k�l
};

