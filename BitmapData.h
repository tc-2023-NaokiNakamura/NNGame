
/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: BitmapData.h
	NAME	: kz-matsu

+ ------ Explanation of file --------------------------------------------------------------------------
       
	�r�b�g�}�b�v��ǂݍ��݃f�[�^��ێ�����N���X
	
		--- ��Ȏg���� ---
		1�̃C���X�^���X��1���̃r�b�g�}�b�v�f�[�^��ێ����邱�Ƃ��ł���B
		�܂�16���̃r�b�g�}�b�v��ǂݍ��݂����ꍇ�̓C���X�^���X��16�K�v�ł���B
		�܂��g���܂킵���l���A�����I�ȉ���Ƒ��d�ǂݍ��ݎ��̈Öق̉�����T�|�[�g���Ă���B

		��P�E�R���X�g���N�^�Ńr�b�g�}�b�v��ǂݍ���
		BitmapData bmp1( �ǂݍ��݂����t�@�C���̃p�X , �� , ���� ) ;

		��Q�E�R���X�g���N�^���g��Ȃ��ꍇ
		BitmapData bmp1 ;
		bmp1.LoadData( �ǂݍ��݂����t�@�C���̃p�X , �� , ���� ) ;

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

// �N���X�̐錾
class BitmapData
{
	public :
		BitmapData( LPCTSTR arg_pStr , int arg_width , int arg_height ) ;
		BitmapData( ) ;
		~BitmapData( ) ;

		int loadData( LPCTSTR arg_pStr , int arg_width , int arg_height ) ;
		int clearData( ) ;

		HBITMAP getBmpData( ) ;
		int getBmpWidth( ) ;
		int getBmpHeight( ) ;

	private :
		HBITMAP m_hBmp ;
		int m_width ;
		int m_height ;
} ;






