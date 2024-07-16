
/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: TimeProc.h
    NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------

	高精度な時間関係の処理を提供するクラス

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

/* ------------------------------------------------------------ */
/*	タイマープロシージャ クラス									*/
/* ------------------------------------------------------------ */
class TimeProc
{
	public :
		TimeProc( ) ;
		~TimeProc( ) ;

		DWORD getTime( ) ;
		DWORD startTime( ) ;
		DWORD endTime( ) ;
		int theWorld( int arg_theWorldTime ) ;
		int getNo(DWORD);
		void StaticInit();
		void init();
		int action();

	private :
		DWORD m_sTime , m_eTime , m_pTime , m_lTime ;
		int m_sprNo[11];		// オブジェクト表示番号
		int m_usebmp;			// 使用ビットマップ
		double m_xp[3];			// X座標	
		double m_yp[3];			// Y座標
		double m_up[11];		// U座標(画像内横)
		double m_vp[11];		// V座標(画像内縦)
		double m_cutSize[11];	// 切り抜きサイズ
		int m_timNo[11];		// タイマー秒数ID番号
		static int tensPlace;	// 10の位
		static int onesPlace;	// 1の位
		static double xp;		// X座標ズラし更新
} ;

