
/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: BitmapData.h
	NAME	: kz-matsu

+ ------ Explanation of file --------------------------------------------------------------------------
       
	ビットマップを読み込みデータを保持するクラス
	
		--- 主な使い方 ---
		1つのインスタンスで1枚のビットマップデータを保持することができる。
		つまり16枚のビットマップを読み込みたい場合はインスタンスが16個必要である。
		また使いまわしを考え、明示的な解放と多重読み込み時の暗黙の解放をサポートしている。

		例１・コンストラクタでビットマップを読み込む
		BitmapData bmp1( 読み込みたいファイルのパス , 幅 , 高さ ) ;

		例２・コンストラクタを使わない場合
		BitmapData bmp1 ;
		bmp1.LoadData( 読み込みたいファイルのパス , 幅 , 高さ ) ;

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

// クラスの宣言
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






