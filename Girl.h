/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: Girl.h
	NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------

	プレイヤークラスの宣言部

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

enum GirlActionName
{
	GirlBlank = -1,
	GirlSet,			// 登場シーン
	GirlAction,			// ゲーム画面
	GirlFin				// リザルト画面
};

// --- クラスの宣言
class Girl : public CharaBase
{
	public:
		Girl();
		void init();
		long getXposi() { return m_positionG.x + 300; };
		long getYposi() { return m_positionG.y + BUBBLE_INIT_POSIY; };
		void homing();
		int action() override;		// --- アクション
		Animation m_anim;
};



