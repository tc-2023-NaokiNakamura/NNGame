
/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: TimeProc.h
    NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------

	�����x�Ȏ��Ԋ֌W�̏�����񋟂���N���X

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

/* ------------------------------------------------------------ */
/*	�^�C�}�[�v���V�[�W�� �N���X									*/
/* ------------------------------------------------------------ */
class TimeProc
{
	public :
		TimeProc( ) ;
		~TimeProc( ) ;

		DWORD getTime( ) ;
		DWORD startTime( ) ;
		DWORD endTime( ) ;
		int theWorld( int arg_theWorldTime ) ;
		int getNo(DWORD);
		void StaticInit();
		void init();
		int action();

	private :
		DWORD m_sTime , m_eTime , m_pTime , m_lTime ;
		int m_sprNo[11];		// �I�u�W�F�N�g�\���ԍ�
		int m_usebmp;			// �g�p�r�b�g�}�b�v
		double m_xp[3];			// X���W	
		double m_yp[3];			// Y���W
		double m_up[11];		// U���W(�摜����)
		double m_vp[11];		// V���W(�摜���c)
		double m_cutSize[11];	// �؂蔲���T�C�Y
		int m_timNo[11];		// �^�C�}�[�b��ID�ԍ�
		static int tensPlace;	// 10�̈�
		static int onesPlace;	// 1�̈�
		static double xp;		// X���W�Y�����X�V
} ;

