/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: BubbleMove.h
	NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------

	���V�V���{���ʃN���X

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

// �o�u���̃��[�h
enum BubbleMode
{
	bMBlank = -1,		// �ŏ��̂P��
	bMBlow,				// �o�u�������o�����[�h
	bMFloating,			// �o�u�������ʒu�Z�b�g���[�h(���V���)
	bMClick,			// �o�u���N���b�N����
	bMHoming,			// �V���{���ʃz�[�~���O���[�h
	bMVacuum,			// �o�u���z�����
	bMHajike,			// �e�����
	bMDestroy			// ����
};

class BubbleMove : public BubbleBase {
	public:
		BubbleMove();
		~BubbleMove();
		void StaticInit();
		void init();
		void floating();
		void blowing();
		int separating(double);
		void homing();
		int action();
		void setsepaFlg() { m_separateFlg = 1; };
		void releasesepaFlg() { m_separateFlg = 0; };
		void clickHitCheck();
		void dragHitCheck();
		void addScale();
		void vacuuming();
		void bblHitFlg() { m_bblHitFlg = 1; };
		int getbblHitFlg() { return m_bblHitFlg; };
		int getHitBinID() { return m_hitBinID; };
		int getBubbleMode() { return m_bubbleMode; };
		int getSprNo() { return m_sprNo; };
		void setSprNo(int sprNo) { m_sprNo = sprNo; };
		void HajikeBubble();
		void BubbleGenerator();
		void setUseFlg() { m_flg = 1; };
		int getBubbleCnt() { return m_bubblecnt; };

//		void test();
		Animation m_anim;

	protected:
		double m_xg;				// ���E�ړ��d��
		double m_xgTunk;			// Y�����d�͂𗭂߂Ă���
		double m_yg;				// �㉺�ړ��d��
		double m_ygTunk;			// Y�����d�͂𗭂߂Ă���
		int m_usebmp;				// BMP�ԍ�
		int m_timY;					// �㉺�ړ�
		int m_geneTim;				// �o�u�����������^�C�}�[
		int m_blowTim;				// �o�u�������o�����ړ��^�C��
		double m_g;					// �o�u���㏸�X�s�[�h
		BOOL m_geneFlg;				// �o�u���`��t���O
		int m_separateFlg;		// �����������s�t���O		0 : �d�Ȃ��Ă��Ȃ�	1 : �d�Ȃ��Ă���
		int m_hitbubbleNo;		// �Փ˂����V���{���ʂ�ID�ԍ��擾
		BOOL m_moveCheck;		// X���W�������z�u�����ꍇ�̃t���O
		double m_UpSpd;		// �z�������ˏオ��X�s�[�h
		int m_hitBinID;			// �r�������蔻��r�����ʎq
		BOOL m_bblHitFlg;		// �o�u���ƃr���̏Փ˔���t���O

		// --- �ÓI�����o�ϐ�
		static double m_bubble_init_veloXMax;	// ����X�����X�s�[�hMAX(�ő�)
		static double m_bubble_init_veloXMin;	// ����X�����X�s�[�hMIN(�Œx)
		static BOOL m_clickCheck;				// �o�u���N���b�N�`�F�b�N�t���O		0 : ��N���b�N��	1 : �o�u���N���b�N��
		static int sprcnt;						// �X�v���C�g�z��v�f�ԍ�	120�`
		static int m_bblNo;						// �N���b�N�����V���{���ʂ̐F�擾
		static int m_firstBblNo;				// �ŏ��Ɏ擾�����V���{���ʂ�ID�ԍ�
		static int m_blackBblHitFlg;			// ����ȏ�V���{���ʂ��W�߂邱�Ƃ��ł��Ȃ�
		static BOOL bblBlackFlg;				// ���V���{���ʎ擾�t���O
		static int geneTime;					// �o�u�������^�C�}�[�Z�b�g�p
		static double yg;						// �o�u�����V���c�h��d�͒l
		static int m_befhitBubbleNo;			// 1�O�̏Փ˃V���{����ID�ԍ�
		static int m_bubblecnt;					// ��ʏ�\���V���{���ʐ�
		static int m_timer;
};



