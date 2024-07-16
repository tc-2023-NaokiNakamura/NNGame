
/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: Sprite.h
	NAME	: kz-matsu

+ ------ Explanation of file --------------------------------------------------------------------------
       
	�X�v���C�g�̕`����s���N���X

		--- ��Ȏg���� ---
		�C���X�^���X�P�łP���̃r�b�g�}�b�v��`�悷��B
		��{�I�ȗ���Ƃ��Ă�setSprite��draw��clearSprite�����t���[���ƂȂ�B
		�ʂɃZ�b�g�������ꍇ�͊e�����o�ւ̑Ή����\�b�h���g�p����B

		��E�X�v���C�g�N���X�̊�{�I�ȗ���
		�C���X�^���X.setSprite( 0 , 128 , 96 , 0 , 0 , 64 , 64 ) ;
		�C���X�^���X.draw( ) ;
		�C���X�^���X.clearSprite( ) ;

		��E�Q�{�ł̕\�����s�������ꍇ
		�C���X�^���X.srtScaleXY( 2.0 , 2.0 ) ;
		
		��E�A���t�@�T�O���ŕ\�����s�������ꍇ
		�C���X�^���X.setAlpha( 128 ) ;

		��E45�x��]���������Ƃ�
		�C���X�^���X.setRotate( 45.0f ) ;

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

// --- �N���X�̐錾
class Sprite
{
	public :
		Sprite( ) ;
		~Sprite( ) ;
		int setSprite( int arg_bmpNo , int arg_x , int arg_y , int arg_u , int arg_v , int arg_w , int arg_h, double, double, int, int ) ;
		int clearSprite( ) ;
		int setFlg( int arg_flg ) ;
		int selectBmp( int arg_bmpNo ) ;
		int setPos( int arg_x , int arg_y ) ;
		int setUV( int arg_u , int arg_v ) ;
		int setWH( int arg_w , int arg_h ) ;
		int setScaleFlg( int arg_scaleFlg ) ;
		int setScaleXY( float arg_scaleX , float arg_scaleY ) ;
		int setAlphaFlg( int arg_alphaFlg ) ;
		int setAlpha( int arg_alpha ) ;
		int setRotateFlg( int arg_rotateFlg ) ;
		int setRotate( float arg_degree ) ;
		int draw( ) ;
	private :
		int m_useFlg ;		// --- �g�p�t���O
		int m_bmpNo ;		// --- �e�[�u���ԍ�
		int m_x , m_y ;		// --- �`����W�i����j
		int m_u , m_v ;		// --- �؂�o�����W
		int m_w , m_h ;		// --- �؂�o��������
		int m_scaleFlg ;	// --- �X�P�[���g�p�t���O
		float m_scaleX , m_scaleY ;		// --- �{��
		int m_alphaFlg ;	// --- �������g�p�t���O
		int m_alpha ;		// --- �������̒l
		int m_rotateFlg ;	// --- ��]�g�p�t���O
		float m_degree ;	// --- ��]�̊p�x�i�x���@�j
} ;







