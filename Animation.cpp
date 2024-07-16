
/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: Animation.cpp
    NAME	: Teacher.K

+ ------ Explanation of file --------------------------------------------------------------------------
       
    Animationクラスの実装部

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

#include <windows.h>
#include <stdio.h>

#include "Common.h"

// --- コンストラクタ
Animation::Animation( )
{
	mp_animData = NULL ;
	memset( &m_nowAnimData, 0, sizeof(AnimationData) ) ;
	m_animState = ANIM_STATE_STOP ;
	m_animCnt = 0 ;
}

// --- デストラクタ
Animation::~Animation( )
{

}

// --- アニメーションデータのセット
int Animation::setAnimData( AnimationData *argp_animData )
{
	mp_animData = argp_animData ;
	m_animCnt = 0 ;
	m_nowAnimData = mp_animData[ m_animCnt ] ;
	m_animState = ANIM_STATE_PLAY ;

	return( false ) ;
}

// --- アニメーションの再生
int Animation::playAnim()
{
	if( m_animState == ANIM_STATE_PLAY ){
		m_nowAnimData.holdTime-- ;									// その絵を何フレーム保持するか(４フレーム)
		if( m_nowAnimData.holdTime <= 0 ){
			if( m_nowAnimData.animMode == ANIM_MODE_STOP ){			// アニメーションの最後の画像
				m_animState = ANIM_STATE_STOP ;
			}
			else if( m_nowAnimData.animMode == ANIM_MODE_NEXT ){	// 次のアニメーションへ
				m_animCnt++ ;
				m_nowAnimData = mp_animData[ m_animCnt ] ;
			}
			else if( m_nowAnimData.animMode == ANIM_MODE_LOOP ){	// アニメーションをループさせる
				m_animCnt = 0 ;
				m_nowAnimData = mp_animData[ m_animCnt ] ;
			}
		}
	}

	return( false ) ;
}

// --- アニメーション情報の取得
int Animation::getAnimState( )
{
	return( m_animState ) ;
}

// --- 現在のアニメーションデータの取得
AnimationData* Animation::getNowAnim( )
{
	return( &m_nowAnimData ) ;
}



