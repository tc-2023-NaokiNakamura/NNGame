/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/*																*/
/*	ウィンドウプロシージャ										*/
/*																*/
/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
#include <windows.h>
#include <stdio.h>	// --- コンソール用
#include <stdlib.h>
#include <string.h>

#include "Common.h"	// --- 全ファイルでの共通ヘッダー

LRESULT CALLBACK WndProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
{
	HDC					hDC;				// ディスプレイデバイスコンテキスト
	PAINTSTRUCT			ps;					// 描画構造体

	static HBITMAP		s_hBackBufBitmap ;	// バックバッファ用ビットマップ
	static BOOL m_clickflg;
	static HWND ConWnd = FindWindow(NULL, TEXT("C:\\school\\C++_5\\NNGame\\Release\\NNGame.exe"));

	// --- メッセージで分岐
	switch ( message )
	{
		/* -------------------------
		|		WM_CREATE
		+ ----------------------- */
		case WM_CREATE:
			printf( "WM_CREATEイベントが発行されました\n" );

			// --- ウィンドウハンドルのコピー
			g_hWindow = hWnd;

			// 裏画面の作成
			hDC = GetDC( hWnd ) ;														// デバイスコンテキストのハンドルの取得
			s_hBackBufBitmap = CreateCompatibleBitmap( hDC , WINDOW_W , WINDOW_H ) ;	// ビットマップの生成
			g_hBackBuf = CreateCompatibleDC( hDC ) ;									// バックバッファ用のDCを取得
			g_hWorkBuf = CreateCompatibleDC( hDC ) ;									// 共用のDCを取得
			SelectObject( g_hBackBuf , s_hBackBufBitmap ) ;								// バックバッファにBMPをセット
			DeleteObject( s_hBackBufBitmap ) ;
			ReleaseDC( hWnd , hDC ) ;													// デバイスコンテキストのハンドルの開放
			
			// 背景画像のロード
			g_bDataBGTable[0].loadData("image/BG_Sky.bmp", WINDOW_W, WINDOW_H);

			// ビットマップ(女の子＆しゃぼん玉)
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

			// マウスクリックフラグ
			m_clickflg = FALSE;

			for (int i = 0; i < OBJ_TITLEBUBBLE_MAX; i++) {
				ptrTitleBubble[i] = &titleBubble[i];
			}

			// スプライトのアドレスをポインタへセット
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

			// --- フレーム単位でタイマーイベントを発生させる
			SetTimer( g_hWindow, 1, GAME_FRAME, NULL );

			break;

		/* -------------------------
		|		WM_TIMER
		+ ----------------------- */
		case WM_TIMER:
			//printf( "WM_TIMERイベントが発行されました\n" );

			// シーンループ
			SceneLoop( ) ;

			// ドローループ
			DrawLoop( ) ;

//			printf("%d\n", totalCatchBbl);

			// --- 再描画の要求
			InvalidateRect( hWnd, NULL, FALSE );
			break;

		/* -------------------------
		|		WM_LBUTTONDOWN
		+ ----------------------- */
		case WM_LBUTTONDOWN:
			// クリック点を取得
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
		|		WM_KEYDOWN			テスト用
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
			//printf( "WM_PAINTイベントが発行されました\n" );
			hDC = BeginPaint( hWnd, &ps );

			BitBlt( hDC , 0 , 0 , WINDOW_W , WINDOW_H , g_hBackBuf , 0 , 0 , SRCCOPY ) ; //裏画面に書き込み

			EndPaint( hWnd, &ps );
			break;

		/* -------------------------
		|		WM_DESTROY
		+ ----------------------- */
		case WM_DESTROY:
			printf("WM_DESTROYイベントが発行されました\n");
			destroyFlg = 1;
/*
			// 背景画像のクリア
			g_bDataBGTable[0].~BitmapData();

			// ビットマップクリア
			for (int i = 0; i <= 15; i++) {
				g_bDataSprTable[i].~BitmapData();
			}

			// スプライトのクリア
			for (int i = 0; i < OBJ_SPR_MAX; i++) {
				g_sprite[i].clearSprite();
			}
*/
			if (timeEndPeriod(1) == TIMERR_NOERROR) {
				printf("TimeProcストップ\n");
			}

			// デバイスコンテキストの破棄
			if (DeleteDC(g_hBackBuf) != 0) {
				printf("g_hBackBufの破棄完了\n");
			}
			if (DeleteDC(g_hWorkBuf) != 0) {
				printf("g_hWorkBufの破棄終了\n");
			}

			// --- タイマーの削除
			if (KillTimer(g_hWindow, 1) != 0) {
				printf("タイマーの削除完了\n");
			}			

			// --- アプリケーション終了を発行
			PostQuitMessage( 0 );
			break;

		/* -------------------------
		|		default文
		+ ----------------------- */
		default:
			return ( DefWindowProc( hWnd, message, wParam, lParam ) );
	}

	return 0;
}
