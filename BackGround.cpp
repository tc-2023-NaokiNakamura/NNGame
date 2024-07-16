
/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: BackGround.cpp
	NAME	: kz-matsu

+ ------ Explanation of file --------------------------------------------------------------------------
       
	BackGround�N���X�̎�����

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

#include <windows.h>
#include <stdio.h>

#include "Common.h"

// --- �R���X�g���N�^
BackGround::BackGround( )
{
	m_bmpNo = 0 ;
	m_x = 0 ;
	m_y = 0 ;
}

// --- �f�X�g���N�^
BackGround::~BackGround( )
{
}

// --- �`�悵�����w�i�̔ԍ����Z�b�g
int BackGround::selectBmp( int arg_bmpNo )
{
	m_bmpNo = arg_bmpNo ;

	return( true ) ;
}

// --- �`�悵�����ʒu���Z�b�g
int BackGround::setPosition( int arg_x , int arg_y )
{
	m_x = arg_x ;
	m_y = arg_y ;

	return( true ) ;
}

// --- �`�悷��w�i�̔ԍ����Q�b�g
int BackGround::getBmpNo( )
{
	return( m_bmpNo ) ;
}

// --- �w�i�`��
int BackGround::draw( )
{
	SelectObject( g_hWorkBuf , g_bDataBGTable[ m_bmpNo ].getBmpData( ) ) ;
	BitBlt
	(
		g_hBackBuf ,
		m_x ,
		m_y ,
		g_bDataBGTable[ m_bmpNo ].getBmpWidth( ) ,
		g_bDataBGTable[ m_bmpNo ].getBmpHeight( ) ,
		g_hWorkBuf ,
		0 ,
		800 ,
		SRCCOPY
	) ;

	return( true ) ;
}


