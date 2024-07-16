/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: BubbleBase.h
	NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------

	シャボン玉ベースクラス

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

class BubbleBase {
	public:
		virtual int action() = 0;
		virtual int getUseFlg();
		double getMXposi();
		double getMYposi();
		double getXp() { return m_xp; };
		double getYp() { return m_yp; };
		double getXspd() { return m_xspd; };
		double getYspd() { return m_yspd; };
		void stopXspd() { m_xspd = 0; };
		void stopYspd() { m_yspd = 0; };
		int getID() { return m_bubbleID; };
		virtual void BubbleGenerator() = 0;
		virtual int getBubbleCnt() = 0;
		void setLostFlg() { m_lostFlg = 1; };
		int getLostFlg() { return m_lostFlg; };

	protected:
		double m_xp;			// バブルX座標
		double m_yp;			// バブルY座標
		double m_Mbxp;			// マイバブルXポジション
		double m_Mbyp;			// マイバブルYポジション
		double m_xspd;			// 左右移動スピード
		double m_yspd;			// 上下移動スピード
		double m_xspdTunk;		// 左右移動スピード
		double m_yspdTunk;		// 上下移動スピード
		int m_flg;				// 表示フラグ管理
		BOOL m_HitFlg = FALSE;	// ヒットチェックフラグ		0 : 当たっていない	1 : 当たった
		int m_bubbleID;			// 表示バブルID
		int m_sprNo;			// スプライト番号(表示プライオリティ)
		int m_bubbleMode;		// バブル状態管理
		int m_hitbubbleID;		// 衝突したバブルのID番号
		double m_xLength;		// 三平方の定理(X座標長さ)
		double m_yLength;		// 三平方の定理(Y座標長さ)
		double m_Length;		// マウスと円の中心の長さ
		double m_bScaleX;		// バブルの大きさ拡縮(X方向)
		double m_bScaleY;		// バブルの大きさ拡縮(Y方向)
		int m_XposiCheckTim;	// マウスポインタのXポジション取得タイマー
		double m_beforepx;		// 前回のマウスクリックX座標格納
		int m_lostFlg;
};



