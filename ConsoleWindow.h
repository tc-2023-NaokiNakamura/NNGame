#pragma once


class ConsoleWindow {
	public:
		// --- �R���X�g���N�^
		~ConsoleWindow();	
		// --- �f�X�g���N�^
		ConsoleWindow();
	private:
		FILE* m_fIn, * m_fOut;
};

