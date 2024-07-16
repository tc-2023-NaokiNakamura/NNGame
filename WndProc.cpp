/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/*																*/
/*	�E�B���h�E�v���V�[�W��										*/
/*																*/
/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
#include <windows.h>
#include <stdio.h>	// --- �R���\�[���p
#include <stdlib.h>
#include <string.h>

#include "Common.h"	// --- �S�t�@�C���ł̋��ʃw�b�_�[

LRESULT CALLBACK WndProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
{
	HDC					hDC;				// �f�B�X�v���C�f�o�C�X�R���e�L�X�g
	PAINTSTRUCT			ps;					// �`��\����

	static HBITMAP		s_hBackBufBitmap ;	// �o�b�N�o�b�t�@�p�r�b�g�}�b�v
	static BOOL m_clickflg;
	static HWND ConWnd = FindWindow(NULL, TEXT("C:\\school\\C++_5\\NNGame\\Release\\NNGame.exe"));

	// --- ���b�Z�[�W�ŕ���
	switch ( message )
	{
		/* -------------------------
		|		WM_CREATE
		+ ----------------------- */
		case WM_CREATE:
			printf( "WM_CREATE�C�x���g�����s����܂���\n" );

			// --- �E�B���h�E�n���h���̃R�s�[
			g_hWindow = hWnd;

			// ����ʂ̍쐬
			hDC = GetDC( hWnd ) ;														// �f�o�C�X�R���e�L�X�g�̃n���h���̎擾
			s_hBackBufBitmap = CreateCompatibleBitmap( hDC , WINDOW_W , WINDOW_H ) ;	// �r�b�g�}�b�v�̐���
			g_hBackBuf = CreateCompatibleDC( hDC ) ;									// �o�b�N�o�b�t�@�p��DC���擾
			g_hWorkBuf = CreateCompatibleDC( hDC ) ;									// ���p��DC���擾
			SelectObject( g_hBackBuf , s_hBackBufBitmap ) ;								// �o�b�N�o�b�t�@��BMP���Z�b�g
			DeleteObject( s_hBackBufBitmap ) ;
			ReleaseDC( hWnd , hDC ) ;													// �f�o�C�X�R���e�L�X�g�̃n���h���̊J��
			
			// �w�i�摜�̃��[�h
			g_bDataBGTable[0].loadData("image/BG_Sky.bmp", WINDOW_W, WINDOW_H);

			// �r�b�g�}�b�v(���̎q������ڂ��)
			g_bDataSprTable[0].loadData("image/girl_huku.bmp", GIRL_SIZE_W, GIRL_SIZE_H);
			g_bDataSprTable[1].loadData("image/BlackBubble.bmp", BUBBLE_SIZE, BUBBLE_SIZE);
			g_bDataSprTable[2].loadData("image/BlueBubble.bmp", BUBBLE_SIZE, BUBBLE_SIZE);
			g_bDataSprTable[3].loadData("image/OrangeBubble.bmp", BUBBLE_SIZE, BUBBLE_SIZE);
			g_bDataSprTable[4].loadData("image/PerpleBubble.bmp", BUBBLE_SIZE, BUBBLE_SIZE);
			g_bDataSprTable[5].loadData("image/PinkBubble.bmp", BUBBLE_SIZE, BUBBLE_SIZE);
			g_bDataSprTable[6].loadData("image/girl_seisi.bmp", GIRL_SIZE_W, GIRL_SIZE_H);
			g_bDataSprTable[7].loadData("image/StartButton1.bmp", BUBBLE_SIZE, BUBBLE_SIZE);
			g_bDataSprTable[8].loadData("image/BinTest.bmp", BIN_SIZE, BIN_SIZE);
			g_bDataSprTable[9].loadData("image/score.bmp", BIN_SIZE, BIN_SIZE);
			g_bDataSprTable[10].loadData("image/time.bmp", TIMER_SIZEX, TIMER_SIZEY);
			g_bDataSprTable[11].loadData("image/Title.bmp", TITLE_SIZE, TITLE_SIZE);
			g_bDataSprTable[12].loadData("image/Result.bmp", RESULT_SIZEX, RESULT_SIZEY);
			g_bDataSprTable[13].loadData("image/Smoke.bmp", SMOKE_SIZEX, SMOKE_SIZEY);
			g_bDataSprTable[14].loadData("image/TitleButton.bmp", SMOKE_SIZEX, SMOKE_SIZEY);
			g_bDataSprTable[15].loadData("image/Star.bmp", SMOKE_SIZEX, SMOKE_SIZEY);
			g_bDataSprTable[16].loadData("image/Smoke2.bmp", BIN_SMOKE_SIZE, BIN_SMOKE_SIZE);

			// �}�E�X�N���b�N�t���O
			m_clickflg = FALSE;

			for (int i = 0; i < OBJ_TITLEBUBBLE_MAX; i++) {
				ptrTitleBubble[i] = &titleBubble[i];
			}

			// �X�v���C�g�̃A�h���X���|�C���^�փZ�b�g
			for (int i = BUBBLES; i < MAXBUBBLES; i++) {
				ptrBubblesarray[i] = &bubbleSet[i];
			}

			for (int i = 0; i < BIN_MAX; i++) {
				ptrBinarray[i] = &bin[i];
			}

			ptrScore = &score;

			ptrTimeProc = &timeproc;

			result[0] = &resultBord;

			for (int i = 0; i < OBJ_LOADBUBBLES_MAX; i++) {
				ptrLoadScene[i] = &loadScene[i];
			}

			// --- �t���[���P�ʂŃ^�C�}�[�C�x���g�𔭐�������
			SetTimer( g_hWindow, 1, GAME_FRAME, NULL );

			break;

		/* -------------------------
		|		WM_TIMER
		+ ----------------------- */
		case WM_TIMER:
			//printf( "WM_TIMER�C�x���g�����s����܂���\n" );

			// �V�[�����[�v
			SceneLoop( ) ;

			// �h���[���[�v
			DrawLoop( ) ;

//			printf("%d\n", totalCatchBbl);

			// --- �ĕ`��̗v��
			InvalidateRect( hWnd, NULL, FALSE );
			break;

		/* -------------------------
		|		WM_LBUTTONDOWN
		+ ----------------------- */
		case WM_LBUTTONDOWN:
			// �N���b�N�_���擾
			clickDownPt.x = LOWORD( lParam ) ;
			clickDownPt.y = HIWORD( lParam ) ;

			titleButton.ClickHitCheck();
			if (titleBackButton.getClickCheckOnFlg() == 1) {
				titleBackButton.clickCheck();
			}

//			printf("333");

			m_clickflg = TRUE;
			break ;

		/* -------------------------
		|		WM_LBUTTONUP
		+ ----------------------- */
		case WM_LBUTTONUP:
			m_clickflg = FALSE;
			clTrigger = FALSE;
			break ;

		/* -------------------------
		|		WM_RBUTTONDOWN
		+ ----------------------- */
		case WM_RBUTTONDOWN:
			break ;

		/* -------------------------
		|		WM_MOUSEMOVE
		+ ----------------------- */
		case WM_MOUSEMOVE:
			if (m_clickflg == TRUE) {
				clickDownPt.x = LOWORD(lParam);
				clickDownPt.y = HIWORD(lParam);
			}
			break ;

		/* -------------------------
		|		WM_KEYDOWN			�e�X�g�p
		+ ----------------------- */
		case WM_KEYDOWN:
			if ((wParam == VK_RETURN) && (geneTimFlg[0] == 0)) {
				geneTimFlg[0] = 1;
//				bubbleSet[cnt].test();
//				reSpawnFlg = TRUE;
			}
			else if (wParam == VK_SPACE) {
				if (blBblFlg == 0)
					blBblFlg = 1;
				else
					blBblFlg = 0;
			}
			else {
				geneTimFlg[0] = 0;
				wParam = 0;
			}
			break ;

		/* -------------------------
		|		WM_PAINT
		+ ----------------------- */
		case WM_PAINT:
			//printf( "WM_PAINT�C�x���g�����s����܂���\n" );
			hDC = BeginPaint( hWnd, &ps );

			BitBlt( hDC , 0 , 0 , WINDOW_W , WINDOW_H , g_hBackBuf , 0 , 0 , SRCCOPY ) ; //����ʂɏ�������

			EndPaint( hWnd, &ps );
			break;

		/* -------------------------
		|		WM_DESTROY
		+ ----------------------- */
		case WM_DESTROY:
			printf("WM_DESTROY�C�x���g�����s����܂���\n");
			destroyFlg = 1;
/*
			// �w�i�摜�̃N���A
			g_bDataBGTable[0].~BitmapData();

			// �r�b�g�}�b�v�N���A
			for (int i = 0; i <= 15; i++) {
				g_bDataSprTable[i].~BitmapData();
			}

			// �X�v���C�g�̃N���A
			for (int i = 0; i < OBJ_SPR_MAX; i++) {
				g_sprite[i].clearSprite();
			}
*/
			if (timeEndPeriod(1) == TIMERR_NOERROR) {
				printf("TimeProc�X�g�b�v\n");
			}

			// �f�o�C�X�R���e�L�X�g�̔j��
			if (DeleteDC(g_hBackBuf) != 0) {
				printf("g_hBackBuf�̔j������\n");
			}
			if (DeleteDC(g_hWorkBuf) != 0) {
				printf("g_hWorkBuf�̔j���I��\n");
			}

			// --- �^�C�}�[�̍폜
			if (KillTimer(g_hWindow, 1) != 0) {
				printf("�^�C�}�[�̍폜����\n");
			}			

			// --- �A�v���P�[�V�����I���𔭍s
			PostQuitMessage( 0 );
			break;

		/* -------------------------
		|		default��
		+ ----------------------- */
		default:
			return ( DefWindowProc( hWnd, message, wParam, lParam ) );
	}

	return 0;
}
