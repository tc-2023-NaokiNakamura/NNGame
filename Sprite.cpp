
/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: Sprite.cpp
	NAME	: kz-matsu

+ ------ Explanation of file --------------------------------------------------------------------------
       
	Spriteクラスの実装部

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

#include <windows.h>
#include <stdio.h>
#include <math.h>

#include "Common.h"

// --- コンストラクタ
Sprite::Sprite( )
{
	// とりあえず初期化
	clearSprite( ) ;
}

// --- デストラクタ
Sprite::~Sprite( )
{
}

// --- スプライトのセット
int Sprite::setSprite( int arg_bmpNo , int arg_x , int arg_y , int arg_u , int arg_v , int arg_w , int arg_h,  double arg_scaleX = 1, double arg_scaleY = 1, int arg_argflg = 0, int arg_alpha = 1 )
{
	// --- 全ての情報をセット
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

// --- スプライトのクリア
int Sprite::clearSprite( )
{
	// --- とりあえず初期化
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

// --- 使用フラグのセット
int Sprite::setFlg( int arg_flg )
{
	m_useFlg = arg_flg ;

	return( false ) ;
}

// --- 描画したい背景の番号をセット
int Sprite::selectBmp( int arg_bmpNo )
{
	m_bmpNo = arg_bmpNo ;

	return( false ) ;
}

// --- 描画座標（左上）
int Sprite::setPos( int arg_x , int arg_y )
{
	m_x = arg_x ;
	m_y = arg_y ;

	return( false ) ;
}

// --- 切り出し座標
int Sprite::setUV( int arg_u , int arg_v )
{
	m_u = arg_u ;
	m_v = arg_v ;

	return( false ) ;
}

// --- 切り出し幅の高さ
int Sprite::setWH( int arg_w , int arg_h )
{
	m_w = arg_w ;
	m_h = arg_h ;

	return( false ) ;
}

// --- スケールフラグのセット
int Sprite::setScaleFlg( int arg_scaleFlg )
{
	m_scaleFlg = arg_scaleFlg ;
	return( m_scaleFlg ) ;
}

// --- スケール（拡大率）
int Sprite::setScaleXY( float arg_scaleX , float arg_scaleY )
{
	setScaleFlg( true ) ;
	m_scaleX = arg_scaleX ;
	m_scaleY = arg_scaleY ;
	return( false ) ;
}

// --- 半透明のフラグのセット
int Sprite::setAlphaFlg( int arg_alphaFlg )
{
	m_alphaFlg = arg_alphaFlg ;

	return( false ) ;
}

// --- 半透明の値をセット
int Sprite::setAlpha( int arg_alpha )
{
	setAlphaFlg( true ) ;
	m_alpha = arg_alpha ;

	return( false ) ;
}

// --- 回転のフラグをセット
int Sprite::setRotateFlg( int arg_rotateFlg )
{
	m_rotateFlg = arg_rotateFlg ;

	return( false ) ;
}

// --- 回転角度をセット
int Sprite::setRotate( float arg_degree )
{
	setRotateFlg( true ) ;
	m_degree = arg_degree ;

	return( false ) ;
}

// --- BMPの描画
int Sprite::draw( )
{
	HDC hDC ;
	static HDC				s_tRBWorkHDC ;
	static HBITMAP			s_tRBWorkBmp ;
	static BLENDFUNCTION	s_blendFunc = { AC_SRC_OVER , 0 , 255 , 0 } ;
	float radian , x , y ;
	POINT rotatePoint[ 3 ] ;
	int i ;

	// --- 使用されていたら
	if ( m_useFlg == ( int )true )
	{
		if ( m_rotateFlg == ( int )true )		// --- 回転機能ON
		{
			// --- 角度をラジアンに変換
			radian = m_degree * 3.14f / 180.0f ;

			// --- 左上頂点を回転変換
			rotatePoint[ 0 ].x = -( m_w / 2 ) ;
			rotatePoint[ 0 ].y = -( m_h / 2 ) ;
			x = ( float )rotatePoint[ 0 ].x ;
			y = ( float )rotatePoint[ 0 ].y ;
			rotatePoint[ 0 ].x = ( int )( x * cos( radian ) - y * sin( radian ) ) ;
			rotatePoint[ 0 ].y = ( int )( x * sin( radian ) + y * cos( radian ) ) ;

			// --- 右上頂点を回転変換
			rotatePoint[ 1 ].x = ( m_w / 2 ) ;
			rotatePoint[ 1 ].y = -( m_h / 2 ) ;
			x = ( float )rotatePoint[ 1 ].x ;
			y = ( float )rotatePoint[ 1 ].y ;
			rotatePoint[ 1 ].x = ( int )( x * cos( radian ) - y * sin( radian ) ) ;
			rotatePoint[ 1 ].y = ( int )( x * sin( radian ) + y * cos( radian ) ) ;

			// --- 左下頂点を回転変換
			rotatePoint[ 2 ].x = -( m_w / 2 ) ;
			rotatePoint[ 2 ].y = ( m_h / 2 ) ;
			x = ( float )rotatePoint[ 2 ].x ;
			y = ( float )rotatePoint[ 2 ].y ;
			rotatePoint[ 2 ].x = ( int )( x * cos( radian ) - y * sin( radian ) ) ;
			rotatePoint[ 2 ].y = ( int )( x * sin( radian ) + y * cos( radian ) ) ;

			// --- 平行移動で中心位置を戻す
			for ( i = 0 ; i < 3 ; i++ )
			{
				rotatePoint[ i ].x += ( m_w / 2 ) ;
				rotatePoint[ i ].y += ( m_h / 2 ) ;
			}

			// --- ビットマップを選択
			SelectObject( g_hWorkBuf , g_bDataSprTable[ m_bmpNo ].getBmpData( ) ) ;

			// --- 作業用デバイスコンテキストの生成
			hDC = GetDC( g_hWindow ) ;
			s_tRBWorkHDC = CreateCompatibleDC( hDC ) ;
			s_tRBWorkBmp = CreateCompatibleBitmap( hDC , m_w , m_h ) ;
			SelectObject( s_tRBWorkHDC , s_tRBWorkBmp ) ;
			ReleaseDC( g_hWindow , hDC ) ;

			// --- 作業用デバイスコンテキストをカラーキーで塗りつぶす
			RECT fillBox ;
			fillBox.left	= 0 ;
			fillBox.top		= 0 ;
			fillBox.right	= m_w ;
			fillBox.bottom	= m_h ;
			HBRUSH hBrush ;
			hBrush = CreateSolidBrush( RGB( 0 , 255 , 0 ) ) ;
			FillRect( s_tRBWorkHDC , &fillBox , hBrush ) ;
			DeleteObject( hBrush ) ;

			// --- 作業用に転送
			PlgBlt( s_tRBWorkHDC , rotatePoint , g_hWorkBuf , m_u , m_v , m_w , m_h , NULL , 0 , 0 ) ;

			// --- バックバッファに転送
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
				// --- バックバッファに転送
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
				// --- バックバッファに転送
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
			// --- DCとビットマップ領域の解放
			DeleteDC( s_tRBWorkHDC ) ;
			DeleteObject( s_tRBWorkBmp ) ;
		}
		else if ( m_alphaFlg == ( int )true )		// --- 半透明機能ON
		{
			SelectObject( g_hWorkBuf , g_bDataSprTable[ m_bmpNo ].getBmpData( ) ) ;

			// --- 作業用デバイスコンテキストの生成
			hDC = GetDC( g_hWindow ) ;
			s_tRBWorkHDC = CreateCompatibleDC( hDC ) ;
			s_tRBWorkBmp = CreateCompatibleBitmap( hDC , m_w , m_h ) ;
			SelectObject( s_tRBWorkHDC , s_tRBWorkBmp ) ;
			DeleteObject( s_tRBWorkBmp ) ;
			ReleaseDC( g_hWindow , hDC ) ;

			// --- スプライトの描画場所をバックバッファから切り取る
			BitBlt( s_tRBWorkHDC , 0 , 0 , m_w , m_h , g_hBackBuf , m_x , m_y , SRCCOPY ) ;

			// --- 切り取ったDCに描画したい画像を張り付ける（上に被せるビットマップが完成する）
			TransparentBlt( s_tRBWorkHDC , 0 , 0 , m_w , m_h , g_hWorkBuf , m_u , m_v , m_w , m_h , RGB( 0,0,0 ) ) ;

			// --- アルファブレンド（半透明処理）
			s_blendFunc.SourceConstantAlpha = m_alpha ;
			AlphaBlend( g_hBackBuf , m_x , m_y , m_w , m_h , s_tRBWorkHDC , 0 , 0 , m_w , m_h , s_blendFunc ) ;

			// --- DCとビットマップ領域の解放
			DeleteDC( s_tRBWorkHDC ) ;
		}
		else if ( m_scaleFlg == ( int )true )		// --- 拡大機能ON
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
		else		// --- 通常描画
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


