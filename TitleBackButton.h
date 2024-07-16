/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: TitleBackButton.h
	NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------

	�^�C�g���o�b�N�{�^���N���X

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

class TitleBackButton : public Result {
	public:
		TitleBackButton();
		void init();
		void clickCheck();
		void setAlphaOnFLg() { m_alphaOnFlg = 1; };
		int getClickCheckOnFlg() { return m_clickCheckOnFlg; };
		int getFlashFlg() { return m_flashFlg; };
		void TitleButtonFlash();
		int action() override;
	private:
		int m_spdTim;			// �㉺���V�X�s�[�h
		int m_alpha;			// �����x
		int m_alphaOnFlg;		// ���������[�h�t���O
		int m_clickCheckOnFlg;	// �N���b�N�`�F�b�N�t���O
		int m_flashFlg;			// �t���b�V���t���O
		int m_flashTim;			// �t���b�V���^�C�}�[
};

