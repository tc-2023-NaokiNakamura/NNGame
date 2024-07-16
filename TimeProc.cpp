
/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: TimeProc.cpp
	NAME	: kz-matsuzawa

+ ------ Explanation of file --------------------------------------------------------------------------
       
    TimeProc�N���X�̎�����

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

#include <windows.h>
#include <stdio.h>

#include "Common.h"

int TimeProc::tensPlace = 6;
int TimeProc::onesPlace = 0;
double TimeProc::xp = 0;

/* ------------------------------------------------------------ */
/*	�R���X�g���N�^												*/
/* ------------------------------------------------------------ */
TimeProc::TimeProc( )
{
	init();
}

/* ------------------------------------------------------------ */
/*	�f�X�g���N�^												*/
/* ------------------------------------------------------------ */
TimeProc::~TimeProc( )
{
//	if (timeEndPeriod(1) == TIMERR_NOCANDO) {
//		printf("timeeeeee\n");
//	}
	if (destroyFlg != 1) {
		timeEndPeriod(1);
		init();
	}
}

void TimeProc::StaticInit() {
	tensPlace = 6;
	onesPlace = 0;
	xp = 0;
}

void TimeProc::init() {
	m_sTime = 0;
	m_eTime = 0;
	m_pTime = 0;
	m_lTime = 60;
	m_usebmp = TIMER_ID;
	// 2���̃I�u�W�F�N�g�z�u
	for (int i = 0; i < 2; i++) {
		m_xp[i] = 202.5 + xp;
		m_yp[i] = 38;
		xp += 44;
		m_sprNo[i] = i;
	}
	// 0�`9�̉摜�؂蔲�����Z�b�g
	for (int i = 0; i < 10; i++) {
		switch (i)
		{
			case 0:
				m_up[i] = 0;
				m_vp[i] = 38;
				m_timNo[i] = i;
				break;
			case 1:
				m_up[i] = 0;
				m_vp[i] = 105;
				m_timNo[i] = i;
				break;
			case 2:
				m_up[i] = 0;
				m_vp[i] = 171;
				m_timNo[i] = i;
				break;
			case 3:
				m_up[i] = 0;
				m_vp[i] = 238;
				m_timNo[i] = i;
				break;
			case 4:
				m_up[i] = 0;
				m_vp[i] = 304;
				m_timNo[i] = i;
				break;
			case 5:
				m_up[i] = TIMER_SIZEX / 2;
				m_vp[i] = 38;
				m_timNo[i] = i;
				break;
			case 6:
				m_up[i] = (double)((TIMER_SIZEX / 2) - 3);
				m_vp[i] = 105;
				m_timNo[i] = i;
				break;
			case 7:
				m_up[i] = (double)((TIMER_SIZEX / 2) - 2);
				m_vp[i] = 171;
				m_timNo[i] = i;
				break;
			case 8:
				m_up[i] = (double)((TIMER_SIZEX / 2) - 2);
				m_vp[i] = 238;
				m_timNo[i] = i;
				break;
			case 9:
				m_up[i] = (double)((TIMER_SIZEX / 2) - 4);
				m_vp[i] = 304;
				m_timNo[i] = i;
				break;
		}
	}

	// TIME�̕����z�u
	m_xp[2] = 65;
	m_yp[2] = 48;
	m_up[10] = 0;
	m_vp[10] = 0;
	m_sprNo[10] = 2;

	// �؂蔲���T�C�Y�Z�b�g
	for (int i = 0; i < 10; i++) {
		m_cutSize[i] = TIMER_SIZEX / 2;
	}
	m_cutSize[10] = (double)TIMER_SIZEX;
	m_timNo[10] = 10;

	if (timeBeginPeriod(1) == TIMERR_NOERROR) {
		printf("Start\n");
	}

}

/* ------------------------------------------------------------ */
/*	���݂̎��Ԃ��擾����										*/
/* ------------------------------------------------------------ */
DWORD TimeProc::getTime( )
{
	return ( (timeGetTime( ) - m_sTime) / 1000 ) ;
}

/* ------------------------------------------------------------ */
/*	���Ԃ̑�����J�n����										*/
/* ------------------------------------------------------------ */
DWORD TimeProc::startTime( )
{
	m_sTime = timeGetTime( ) ;

	return ( m_sTime ) ;
}

/* ------------------------------------------------------------ */
/*	������I�����A�o�ߎ��Ԃ�Ԃ�								*/
/* ------------------------------------------------------------ */
DWORD TimeProc::endTime( )
{
	m_eTime = timeGetTime( ) ;
	m_pTime = m_eTime - m_sTime ;

	return ( m_pTime ) ;
}

/* ------------------------------------------------------------ */
/*	��������莞�Ԏ~�߂�										*/
/* ------------------------------------------------------------ */
int TimeProc::theWorld( int arg_theWorldTime )
{
	Sleep( arg_theWorldTime ) ;

	return ( true ) ;
}

int TimeProc::getNo(DWORD cnt) {
	// 10�̈�
	switch (cnt / 10)
	{
		case 0:
			tensPlace = 0;
			break;
		case 1:
			tensPlace = 1;
			break;
		case 2:
			tensPlace = 2;
			break;
		case 3:
			tensPlace = 3;
			break;
		case 4:
			tensPlace = 4;
			break;
		case 5:
			tensPlace = 5;
			break;
	}

	// 1�̈�
	switch (cnt % 10)
	{
		case 0:
			onesPlace = 0;
			break;
		case 1:
			onesPlace = 1;
			break;
		case 2:
			onesPlace = 2;
			break;
		case 3:
			onesPlace = 3;
			break;
		case 4:
			onesPlace = 4;
			break;
		case 5:
			onesPlace = 5;
			break;
		case 6:
			onesPlace = 6;
			break;
		case 7:
			onesPlace = 7;
			break;
		case 8:
			onesPlace = 8;
			break;
		case 9:
			onesPlace = 9;
			break;
	}

	return (false);
}

int TimeProc::action() {
	getNo(TIME - getTime());

	// 10�̈ʕ`��
	g_sprite[m_sprNo[0] + OBJ_TIMER].setSprite
	(
		m_usebmp,
		(int)m_xp[0] - 65,
		(int)m_yp[0] - 19,
		(int)m_up[m_timNo[tensPlace]],		// ���݂̉摜���W���擾���č��E��RECT�\���̍��W���X�V
		(int)m_vp[tensPlace],
		(int)57.0,
		(int)65.5,
		0.8,
		0.8,
		SPR_SCALE,
		1
	);
	// 1�̈ʕ`��
	g_sprite[m_sprNo[1] + OBJ_TIMER].setSprite
	(
		m_usebmp,
		(int)m_xp[1] - 65,
		(int)m_yp[1] - 19,
		(int)m_up[m_timNo[onesPlace]],		// ���݂̉摜���W���擾���č��E��RECT�\���̍��W���X�V
		(int)m_vp[onesPlace],
		(int)57.0,
		(int)65.5,
		0.8,
		0.8,
		SPR_SCALE,
		1
	);
	// TIME�`��
	g_sprite[m_sprNo[10] + OBJ_TIMER].setSprite
	(
		m_usebmp,
		(int)m_xp[2] - 65,
		(int)m_yp[2] - 19,
		(int)m_up[m_timNo[10]],		// ���݂̉摜���W���擾���č��E��RECT�\���̍��W���X�V
		(int)m_vp[10],
		(int)m_cutSize[m_timNo[10]],
		38,
		1,
		1,
		SPR_SCALE,
		1
	);
	return (false);
}

