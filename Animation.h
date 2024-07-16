
/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: Animation.h
    NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------
       
    �A�j���[�V�����𐧌䂷��N���X�Ɠn���ׂ��f�[�^�\���̂̐錾

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */


// --- �N���X�̐錾
class Animation
{
	public :
		Animation( ) ;
		~Animation( ) ;

		int setAnimData( AnimationData *argp_animData ) ;	// --- �Z�b�g
		int playAnim( ) ;									// --- �Đ�
		int getAnimState( ) ;								// --- ���̎擾
		AnimationData* getNowAnim( ) ;						// --- ���݃f�[�^�̎擾

	private :
		AnimationData *mp_animData ;		// --- �n���ꂽ�f�[�^
		AnimationData m_nowAnimData ;		// --- ���݂̃f�[�^
		int m_animState ;					// --- ���݂̏�
		int m_animCnt ;						// --- ���ڂ̃A�j���[�V�������̃J�E���^
} ;


