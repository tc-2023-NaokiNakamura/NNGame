
/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: Animation.h
    NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------
       
    アニメーションを制御するクラスと渡すべきデータ構造体の宣言

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */


// --- クラスの宣言
class Animation
{
	public :
		Animation( ) ;
		~Animation( ) ;

		int setAnimData( AnimationData *argp_animData ) ;	// --- セット
		int playAnim( ) ;									// --- 再生
		int getAnimState( ) ;								// --- 情報の取得
		AnimationData* getNowAnim( ) ;						// --- 現在データの取得

	private :
		AnimationData *mp_animData ;		// --- 渡されたデータ
		AnimationData m_nowAnimData ;		// --- 現在のデータ
		int m_animState ;					// --- 現在の状況
		int m_animCnt ;						// --- 何個目のアニメーションかのカウンタ
} ;


