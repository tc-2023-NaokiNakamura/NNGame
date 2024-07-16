
/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: Sprite.cpp
	NAME	: kz-matsu

+ ------ Explanation of file --------------------------------------------------------------------------
       
	Sprite�N���X�̎�����

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

#include <windows.h>
#include <stdio.h>
#include <math.h>

#include "Common.h"

// --- �R���X�g���N�^
Sprite::Sprite( )
{
	// �Ƃ肠����������
	clearSprite( ) ;
}

// --- �f�X�g���N�^
Sprite::~Sprite( )
{
}

// --- �X�v���C�g�̃Z�b�g
int Sprite::setSprite( int arg_bmpNo , int arg_x , int arg_y , int arg_u , int arg_v , int arg_w , int arg_h,  double arg_scaleX = 1, double arg_scaleY = 1, int arg_argflg = 0, int arg_alpha = 1 )
{
	// --- �S�Ă̏����Z�b�g
	switch (arg_argflg)
	{
		case 0:
			setScaleFlg(true);
			break;
		case 1:
			setAlphaFlg(true);
			break;
	}
	m_scaleX = (float)arg_scaleX;
	m_scaleY = (float)arg_scaleY;
	m_alpha = arg_alpha;
	setFlg( true ) ;
	selectBmp( arg_bmpNo ) ;
	setPos( arg_x, arg_y ) ;
	setUV( arg_u, arg_v ) ;
	setWH( arg_w, arg_h ) ;

	return( false ) ;
}

// --- �X�v���C�g�̃N���A
int Sprite::clearSprite( )
{
	// --- �Ƃ肠����������
	setFlg( false ) ;
	selectBmp( 0 ) ;
	setPos( 0, 0 ) ;
	setUV( 0, 0 ) ;
	setWH( 0, 0 ) ;
	setScaleFlg( false ) ;
	setAlphaFlg( false ) ;
	setRotateFlg( false ) ;

	return( false ) ;
}

// --- �g�p�t���O�̃Z�b�g
int Sprite::setFlg( int arg_flg )
{
	m_useFlg = arg_flg ;

	return( false ) ;
}

// --- �`�悵�����w�i�̔ԍ����Z�b�g
int Sprite::selectBmp( int arg_bmpNo )
{
	m_bmpNo = arg_bmpNo ;

	return( false ) ;
}

// --- �`����W�i����j
int Sprite::setPos( int arg_x , int arg_y )
{
	m_x = arg_x ;
	m_y = arg_y ;

	return( false ) ;
}

// --- �؂�o�����W
int Sprite::setUV( int arg_u , int arg_v )
{
	m_u = arg_u ;
	m_v = arg_v ;

	return( false ) ;
}

// --- �؂�o�����̍���
int Sprite::setWH( int arg_w , int arg_h )
{
	m_w = arg_w ;
	m_h = arg_h ;

	return( false ) ;
}

// --- �X�P�[���t���O�̃Z�b�g
int Sprite::setScaleFlg( int arg_scaleFlg )
{
	m_scaleFlg = arg_scaleFlg ;
	return( m_scaleFlg ) ;
}

// --- �X�P�[���i�g�嗦�j
int Sprite::setScaleXY( float arg_scaleX , float arg_scaleY )
{
	setScaleFlg( true ) ;
	m_scaleX = arg_scaleX ;
	m_scaleY = arg_scaleY ;
	return( false ) ;
}

// --- �������̃t���O�̃Z�b�g
int Sprite::setAlphaFlg( int arg_alphaFlg )
{
	m_alphaFlg = arg_alphaFlg ;

	return( false ) ;
}

// --- �������̒l���Z�b�g
int Sprite::setAlpha( int arg_alpha )
{
	setAlphaFlg( true ) ;
	m_alpha = arg_alpha ;

	return( false ) ;
}

// --- ��]�̃t���O���Z�b�g
int Sprite::setRotateFlg( int arg_rotateFlg )
{
	m_rotateFlg = arg_rotateFlg ;

	return( false ) ;
}

// --- ��]�p�x���Z�b�g
int Sprite::setRotate( float arg_degree )
{
	setRotateFlg( true ) ;
	m_degree = arg_degree ;

	return( false ) ;
}

// --- BMP�̕`��
int Sprite::draw( )
{
	HDC hDC ;
	static HDC				s_tRBWorkHDC ;
	static HBITMAP			s_tRBWorkBmp ;
	static BLENDFUNCTION	s_blendFunc = { AC_SRC_OVER , 0 , 255 , 0 } ;
	float radian , x , y ;
	POINT rotatePoint[ 3 ] ;
	int i ;

	// --- �g�p����Ă�����
	if ( m_useFlg == ( int )true )
	{
		if ( m_rotateFlg == ( int )true )		// --- ��]�@�\ON
		{
			// --- �p�x�����W�A���ɕϊ�
			radian = m_degree * 3.14f / 180.0f ;

			// --- ���㒸�_����]�ϊ�
			rotatePoint[ 0 ].x = -( m_w / 2 ) ;
			rotatePoint[ 0 ].y = -( m_h / 2 ) ;
			x = ( float )rotatePoint[ 0 ].x ;
			y = ( float )rotatePoint[ 0 ].y ;
			rotatePoint[ 0 ].x = ( int )( x * cos( radian ) - y * sin( radian ) ) ;
			rotatePoint[ 0 ].y = ( int )( x * sin( radian ) + y * cos( radian ) ) ;

			// --- �E�㒸�_����]�ϊ�
			rotatePoint[ 1 ].x = ( m_w / 2 ) ;
			rotatePoint[ 1 ].y = -( m_h / 2 ) ;
			x = ( float )rotatePoint[ 1 ].x ;
			y = ( float )rotatePoint[ 1 ].y ;
			rotatePoint[ 1 ].x = ( int )( x * cos( radian ) - y * sin( radian ) ) ;
			rotatePoint[ 1 ].y = ( int )( x * sin( radian ) + y * cos( radian ) ) ;

			// --- �������_����]�ϊ�
			rotatePoint[ 2 ].x = -( m_w / 2 ) ;
			rotatePoint[ 2 ].y = ( m_h / 2 ) ;
			x = ( float )rotatePoint[ 2 ].x ;
			y = ( float )rotatePoint[ 2 ].y ;
			rotatePoint[ 2 ].x = ( int )( x * cos( radian ) - y * sin( radian ) ) ;
			rotatePoint[ 2 ].y = ( int )( x * sin( radian ) + y * cos( radian ) ) ;

			// --- ���s�ړ��Œ��S�ʒu��߂�
			for ( i = 0 ; i < 3 ; i++ )
			{
				rotatePoint[ i ].x += ( m_w / 2 ) ;
				rotatePoint[ i ].y += ( m_h / 2 ) ;
			}

			// --- �r�b�g�}�b�v��I��
			SelectObject( g_hWorkBuf , g_bDataSprTable[ m_bmpNo ].getBmpData( ) ) ;

			// --- ��Ɨp�f�o�C�X�R���e�L�X�g�̐���
			hDC = GetDC( g_hWindow ) ;
			s_tRBWorkHDC = CreateCompatibleDC( hDC ) ;
			s_tRBWorkBmp = CreateCompatibleBitmap( hDC , m_w , m_h ) ;
			SelectObject( s_tRBWorkHDC , s_tRBWorkBmp ) ;
			ReleaseDC( g_hWindow , hDC ) ;

			// --- ��Ɨp�f�o�C�X�R���e�L�X�g���J���[�L�[�œh��Ԃ�
			RECT fillBox ;
			fillBox.left	= 0 ;
			fillBox.top		= 0 ;
			fillBox.right	= m_w ;
			fillBox.bottom	= m_h ;
			HBRUSH hBrush ;
			hBrush = CreateSolidBrush( RGB( 0 , 255 , 0 ) ) ;
			FillRect( s_tRBWorkHDC , &fillBox , hBrush ) ;
			DeleteObject( hBrush ) ;

			// --- ��Ɨp�ɓ]��
			PlgBlt( s_tRBWorkHDC , rotatePoint , g_hWorkBuf , m_u , m_v , m_w , m_h , NULL , 0 , 0 ) ;

			// --- �o�b�N�o�b�t�@�ɓ]��
			TransparentBlt
			(
				g_hBackBuf,
				m_x, m_y,
				m_w, m_h,
				s_tRBWorkHDC,
				m_u, m_v,
				m_w, m_h,
				RGB( 0, 255, 0 )
			) ;

			
			/*
			if ( m_scaleFlg == ( int )true )
			{
				// --- �o�b�N�o�b�t�@�ɓ]��
				TransparentBlt
				(
					g_hBackBuf,
					m_x, m_y,
					( int )( m_w * m_scaleX ), ( int )( m_h * m_scaleY ),
					s_tRBWorkHDC,
					m_u, m_v,
					m_w, m_h,
					RGB( 0, 255, 0 )
				) ;
			}
			else
			{
				// --- �o�b�N�o�b�t�@�ɓ]��
				TransparentBlt
				(
					g_hBackBuf,
					m_x, m_y,
					m_w, m_h,
					s_tRBWorkHDC,
					m_u, m_v,
					m_w, m_h,
					RGB( 0, 255, 0 )
				) ;
			}
*/
			// --- DC�ƃr�b�g�}�b�v�̈�̉��
			DeleteDC( s_tRBWorkHDC ) ;
			DeleteObject( s_tRBWorkBmp ) ;
		}
		else if ( m_alphaFlg == ( int )true )		// --- �������@�\ON
		{
			SelectObject( g_hWorkBuf , g_bDataSprTable[ m_bmpNo ].getBmpData( ) ) ;

			// --- ��Ɨp�f�o�C�X�R���e�L�X�g�̐���
			hDC = GetDC( g_hWindow ) ;
			s_tRBWorkHDC = CreateCompatibleDC( hDC ) ;
			s_tRBWorkBmp = CreateCompatibleBitmap( hDC , m_w , m_h ) ;
			SelectObject( s_tRBWorkHDC , s_tRBWorkBmp ) ;
			DeleteObject( s_tRBWorkBmp ) ;
			ReleaseDC( g_hWindow , hDC ) ;

			// --- �X�v���C�g�̕`��ꏊ���o�b�N�o�b�t�@����؂���
			BitBlt( s_tRBWorkHDC , 0 , 0 , m_w , m_h , g_hBackBuf , m_x , m_y , SRCCOPY ) ;

			// --- �؂�����DC�ɕ`�悵�����摜�𒣂�t����i��ɔ킹��r�b�g�}�b�v����������j
			TransparentBlt( s_tRBWorkHDC , 0 , 0 , m_w , m_h , g_hWorkBuf , m_u , m_v , m_w , m_h , RGB( 0,0,0 ) ) ;

			// --- �A���t�@�u�����h�i�����������j
			s_blendFunc.SourceConstantAlpha = m_alpha ;
			AlphaBlend( g_hBackBuf , m_x , m_y , m_w , m_h , s_tRBWorkHDC , 0 , 0 , m_w , m_h , s_blendFunc ) ;

			// --- DC�ƃr�b�g�}�b�v�̈�̉��
			DeleteDC( s_tRBWorkHDC ) ;
		}
		else if ( m_scaleFlg == ( int )true )		// --- �g��@�\ON
		{
			SelectObject( g_hWorkBuf , g_bDataSprTable[ m_bmpNo ].getBmpData( ) ) ;
			TransparentBlt(
				g_hBackBuf ,
				m_x, m_y,
				( int )( m_w * m_scaleX ) , ( int )( m_h * m_scaleY ) ,
				g_hWorkBuf ,
				m_u, m_v,
				m_w , m_h ,
				RGB( 0 , 0 , 0 )			// RGB( 0 , 255 , 0 )
			) ;
		}
		else		// --- �ʏ�`��
		{
			SelectObject( g_hWorkBuf , g_bDataSprTable[ m_bmpNo ].getBmpData( ) ) ;
			TransparentBlt(
				g_hBackBuf ,
				m_x , m_y ,
				m_w , m_h ,
				g_hWorkBuf ,
				m_u , m_v ,
				m_w , m_h ,
				RGB( 0 , 0 , 0 )		// RGB( 0 , 255 , 0 )
			) ;
		}
	}
	return( false ) ;
}


