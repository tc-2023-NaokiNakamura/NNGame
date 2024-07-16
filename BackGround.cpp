
/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: BackGround.cpp
	NAME	: kz-matsu

+ ------ Explanation of file --------------------------------------------------------------------------
       
	BackGroundクラスの実装部

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

#include <windows.h>
#include <stdio.h>

#include "Common.h"

// --- コンストラクタ
BackGround::BackGround( )
{
	m_bmpNo = 0 ;
	m_x = 0 ;
	m_y = 0 ;
}

// --- デストラクタ
BackGround::~BackGround( )
{
}

// --- 描画したい背景の番号をセット
int BackGround::selectBmp( int arg_bmpNo )
{
	m_bmpNo = arg_bmpNo ;

	return( true ) ;
}

// --- 描画したい位置をセット
int BackGround::setPosition( int arg_x , int arg_y )
{
	m_x = arg_x ;
	m_y = arg_y ;

	return( true ) ;
}

// --- 描画する背景の番号をゲット
int BackGround::getBmpNo( )
{
	return( m_bmpNo ) ;
}

// --- 背景描画
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


