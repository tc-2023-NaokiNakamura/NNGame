#pragma once

/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: Bin.h
	NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------

	�r���N���X

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

class Bin {
	public:
		Bin();
		~Bin();
		void StaticInit();
		void init();
		int BinHitCheck();
		int getBinColorNo() { return m_BinColorNo; };
		double getXp() { return m_xp; };
		double getYp() { return m_yp - 50; };
		void changeObjBin(int objNo) { m_objBin = objNo; };
		void changeBinColor();
		void changeBinPos();
		int action();
		Animation m_anim;
	
	private:
		double m_xp;						// �r����X���W
		double m_yp;						// �r����Y���W
		double m_scaleX = 1;				// �r���̑傫��(X��)
		double m_scaleY = 1;				// �r���̑傫��(Y��)
		double m_BinColor;					// �r���̐F(���W)
		RECT m_hitZone;						// �r���̓����蔻��
		int m_ID;							// �r�����ʎq
		int m_usebmp;						// �g�pBMP
		int m_sprNo;						// �I�u�W�F�N�g�ԍ�
		int m_BinColorNo;					// �r���̐F(���ʎq)
		BOOL m_bblCorrectFlg;				// �V���{���ʂƃr���̐��𔻒�
		BOOL m_bblInOutFlg;					// �V���{���ʂƃr���̓����蔻��
		int m_objBin;						// �I�u�W�F�N�g�z�u�v���C�I���e�B

		// �ÓI�����o�ϐ�
		static int m_IDNo;			// ID�J�E���^
		static double m_moveXp;		// X�|�W�V�����z�u
		static double m_ColorNo;	// �r���̐F(���W)
		static double m_hitZoneXp;	// X���W�q�b�g�]�[��
		static double m_moveFinXp;
};

