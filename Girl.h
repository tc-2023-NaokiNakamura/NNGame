/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: Girl.h
	NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------

	�v���C���[�N���X�̐錾��

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

enum GirlActionName
{
	GirlBlank = -1,
	GirlSet,			// �o��V�[��
	GirlAction,			// �Q�[�����
	GirlFin				// ���U���g���
};

// --- �N���X�̐錾
class Girl : public CharaBase
{
	public:
		Girl();
		void init();
		long getXposi() { return m_positionG.x + 300; };
		long getYposi() { return m_positionG.y + BUBBLE_INIT_POSIY; };
		void homing();
		int action() override;		// --- �A�N�V����
		Animation m_anim;
};



