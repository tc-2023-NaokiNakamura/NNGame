
/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: BackGround.h
	NAME	: kz-matsu

+ ------ Explanation of file --------------------------------------------------------------------------
       
	�w�i�ʂ̕`����s���N���X

		--- ��Ȏg���� ---
		�C���X�^���X�P�łP���̃r�b�g�}�b�v��`�悷��B
		SelectBmp�ɔw�i�p�r�b�g�}�b�v�e�[�u�����̕`�悵�����ԍ��œn�����ƂŁA(�O�Ԗڂƌ��߂Ă����Ƃ悢)
		�`��ɂ�Draw���\�b�h���t���[�����ƂɌĂяo�����ƁB

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

// --- �N���X�̐錾
class BackGround
{
	public :
		BackGround( ) ;
		~BackGround( ) ;

		int selectBmp( int arg_bmpNo ) ;
		int setPosition( int arg_x , int arg_y ) ;
		int getBmpNo( ) ;
		int draw( ) ;

		int getm_x(){
			return m_x ;
		}
		void setm_x(int addnumber){
			m_x = addnumber ;
		}
		void addm_x(int addnumber){
			m_x += addnumber ;
		}

	private :
		int m_bmpNo ;
		int m_x ;
		int m_y ;
} ;







