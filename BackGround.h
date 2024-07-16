
/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: BackGround.h
	NAME	: kz-matsu

+ ------ Explanation of file --------------------------------------------------------------------------
       
	背景面の描画を行うクラス

		--- 主な使い方 ---
		インスタンス１つで１枚のビットマップを描画する。
		SelectBmpに背景用ビットマップテーブル内の描画したい番号で渡すことで、(０番目と決めておくとよい)
		描画にはDrawメソッドをフレームごとに呼び出すこと。

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

// --- クラスの宣言
class BackGround
{
	public :
		BackGround( ) ;
		~BackGround( ) ;

		int selectBmp( int arg_bmpNo ) ;
		int setPosition( int arg_x , int arg_y ) ;
		int getBmpNo( ) ;
		int draw( ) ;

		int getm_x(){
			return m_x ;
		}
		void setm_x(int addnumber){
			m_x = addnumber ;
		}
		void addm_x(int addnumber){
			m_x += addnumber ;
		}

	private :
		int m_bmpNo ;
		int m_x ;
		int m_y ;
} ;







