#pragma once


class ConsoleWindow {
	public:
		// --- コンストラクタ
		~ConsoleWindow();	
		// --- デストラクタ
		ConsoleWindow();
	private:
		FILE* m_fIn, * m_fOut;
};

