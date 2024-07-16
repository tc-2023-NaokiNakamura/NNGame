/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: BubbleMove.h
	NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------

	浮遊シャボン玉クラス

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

// バブルのモード
enum BubbleMode
{
	bMBlank = -1,		// 最初の１回
	bMBlow,				// バブル吹き出しモード
	bMFloating,			// バブル初期位置セットモード(浮遊状態)
	bMClick,			// バブルクリック判定
	bMHoming,			// シャボン玉ホーミングモード
	bMVacuum,			// バブル吸引状態
	bMHajike,			// 弾け状態
	bMDestroy			// 消滅
};

class BubbleMove : public BubbleBase {
	public:
		BubbleMove();
		~BubbleMove();
		void StaticInit();
		void init();
		void floating();
		void blowing();
		int separating(double);
		void homing();
		int action();
		void setsepaFlg() { m_separateFlg = 1; };
		void releasesepaFlg() { m_separateFlg = 0; };
		void clickHitCheck();
		void dragHitCheck();
		void addScale();
		void vacuuming();
		void bblHitFlg() { m_bblHitFlg = 1; };
		int getbblHitFlg() { return m_bblHitFlg; };
		int getHitBinID() { return m_hitBinID; };
		int getBubbleMode() { return m_bubbleMode; };
		int getSprNo() { return m_sprNo; };
		void setSprNo(int sprNo) { m_sprNo = sprNo; };
		void HajikeBubble();
		void BubbleGenerator();
		void setUseFlg() { m_flg = 1; };
		int getBubbleCnt() { return m_bubblecnt; };

//		void test();
		Animation m_anim;

	protected:
		double m_xg;				// 左右移動重力
		double m_xgTunk;			// Y方向重力を溜めておく
		double m_yg;				// 上下移動重力
		double m_ygTunk;			// Y方向重力を溜めておく
		int m_usebmp;				// BMP番号
		int m_timY;					// 上下移動
		int m_geneTim;				// バブル初期発生タイマー
		int m_blowTim;				// バブル吹き出し横移動タイム
		double m_g;					// バブル上昇スピード
		BOOL m_geneFlg;				// バブル描画フラグ
		int m_separateFlg;		// 分離処理実行フラグ		0 : 重なっていない	1 : 重なっている
		int m_hitbubbleNo;		// 衝突したシャボン玉のID番号取得
		BOOL m_moveCheck;		// X座標が初期配置した場合のフラグ
		double m_UpSpd;		// 吸収時跳ね上がりスピード
		int m_hitBinID;			// ビン当たり判定ビン識別子
		BOOL m_bblHitFlg;		// バブルとビンの衝突判定フラグ

		// --- 静的メンバ変数
		static double m_bubble_init_veloXMax;	// 初期X方向スピードMAX(最速)
		static double m_bubble_init_veloXMin;	// 初期X方向スピードMIN(最遅)
		static BOOL m_clickCheck;				// バブルクリックチェックフラグ		0 : 非クリック時	1 : バブルクリック時
		static int sprcnt;						// スプライト配列要素番号	120～
		static int m_bblNo;						// クリックしたシャボン玉の色取得
		static int m_firstBblNo;				// 最初に取得したシャボン玉のID番号
		static int m_blackBblHitFlg;			// これ以上シャボン玉を集めることができない
		static BOOL bblBlackFlg;				// 黒シャボン玉取得フラグ
		static int geneTime;					// バブル生成タイマーセット用
		static double yg;						// バブル浮遊時縦揺れ重力値
		static int m_befhitBubbleNo;			// 1つ前の衝突シャボン玉ID番号
		static int m_bubblecnt;					// 画面上表示シャボン玉数
		static int m_timer;
};



