
/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: Sprite.h
	NAME	: kz-matsu

+ ------ Explanation of file --------------------------------------------------------------------------
       
	スプライトの描画を行うクラス

		--- 主な使い方 ---
		インスタンス１つで１枚のビットマップを描画する。
		基本的な流れとしてはsetSprite→draw→clearSprite→次フレームとなる。
		個別にセットしたい場合は各メンバへの対応メソッドを使用する。

		例・スプライトクラスの基本的な流れ
		インスタンス.setSprite( 0 , 128 , 96 , 0 , 0 , 64 , 64 ) ;
		インスタンス.draw( ) ;
		インスタンス.clearSprite( ) ;

		例・２倍での表示を行いたい場合
		インスタンス.srtScaleXY( 2.0 , 2.0 ) ;
		
		例・アルファ５０％で表示を行いたい場合
		インスタンス.setAlpha( 128 ) ;

		例・45度回転させたいとき
		インスタンス.setRotate( 45.0f ) ;

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

// --- クラスの宣言
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
		int m_useFlg ;		// --- 使用フラグ
		int m_bmpNo ;		// --- テーブル番号
		int m_x , m_y ;		// --- 描画座標（左上）
		int m_u , m_v ;		// --- 切り出し座標
		int m_w , m_h ;		// --- 切り出し幅高さ
		int m_scaleFlg ;	// --- スケール使用フラグ
		float m_scaleX , m_scaleY ;		// --- 倍率
		int m_alphaFlg ;	// --- 半透明使用フラグ
		int m_alpha ;		// --- 半透明の値
		int m_rotateFlg ;	// --- 回転使用フラグ
		float m_degree ;	// --- 回転の角度（度数法）
} ;







