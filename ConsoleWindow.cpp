#include <windows.h>
#include <stdio.h>			// --- コンソール
#include "ConsoleWindow.h"

// コンストラクタ
ConsoleWindow::ConsoleWindow() {
	AllocConsole();
	freopen_s(&m_fIn, "CON", "r", stdin);
	freopen_s(&m_fOut, "CON", "w", stdout);
	printf("It succeeded in starting of a console screen.\nA standard input/output can be used.\n\n");
}

ConsoleWindow::~ConsoleWindow() {
	fclose(m_fIn);
	fclose(m_fOut);
	FreeConsole();
}


