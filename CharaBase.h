#pragma once

/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: CharaBase.h
	NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------

	�L�����x�[�X�N���X�̐錾��

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

class CharaBase {
	public:
		virtual int action() = 0;
	protected:
		POINT m_positionG;		// �O���[�o�����W(X,Y)
		double m_speed;			// �ړ��X�s�[�h
		double m_xpsd;
		double m_scale;			// �g�k
		double m_maxxp;
		int m_turn;
		int m_moveCount;		// �ړ��J�E���g
		int m_girlActMode = -1;	// ���̎q�A�N�V�������[�h
		int m_windFlg;
};

