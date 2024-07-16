/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: BubbleBase.h
	NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------

	�V���{���ʃx�[�X�N���X

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

class BubbleBase {
	public:
		virtual int action() = 0;
		virtual int getUseFlg();
		double getMXposi();
		double getMYposi();
		double getXp() { return m_xp; };
		double getYp() { return m_yp; };
		double getXspd() { return m_xspd; };
		double getYspd() { return m_yspd; };
		void stopXspd() { m_xspd = 0; };
		void stopYspd() { m_yspd = 0; };
		int getID() { return m_bubbleID; };
		virtual void BubbleGenerator() = 0;
		virtual int getBubbleCnt() = 0;
		void setLostFlg() { m_lostFlg = 1; };
		int getLostFlg() { return m_lostFlg; };

	protected:
		double m_xp;			// �o�u��X���W
		double m_yp;			// �o�u��Y���W
		double m_Mbxp;			// �}�C�o�u��X�|�W�V����
		double m_Mbyp;			// �}�C�o�u��Y�|�W�V����
		double m_xspd;			// ���E�ړ��X�s�[�h
		double m_yspd;			// �㉺�ړ��X�s�[�h
		double m_xspdTunk;		// ���E�ړ��X�s�[�h
		double m_yspdTunk;		// �㉺�ړ��X�s�[�h
		int m_flg;				// �\���t���O�Ǘ�
		BOOL m_HitFlg = FALSE;	// �q�b�g�`�F�b�N�t���O		0 : �������Ă��Ȃ�	1 : ��������
		int m_bubbleID;			// �\���o�u��ID
		int m_sprNo;			// �X�v���C�g�ԍ�(�\���v���C�I���e�B)
		int m_bubbleMode;		// �o�u����ԊǗ�
		int m_hitbubbleID;		// �Փ˂����o�u����ID�ԍ�
		double m_xLength;		// �O�����̒藝(X���W����)
		double m_yLength;		// �O�����̒藝(Y���W����)
		double m_Length;		// �}�E�X�Ɖ~�̒��S�̒���
		double m_bScaleX;		// �o�u���̑傫���g�k(X����)
		double m_bScaleY;		// �o�u���̑傫���g�k(Y����)
		int m_XposiCheckTim;	// �}�E�X�|�C���^��X�|�W�V�����擾�^�C�}�[
		double m_beforepx;		// �O��̃}�E�X�N���b�NX���W�i�[
		int m_lostFlg;
};



