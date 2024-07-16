/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: Bin.cpp
	NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------

	�r��

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */
#include <windows.h>
#include <stdio.h>	// --- �R���\�[���p

#include "Common.h"

#define BIN_MOVE_X 180

/* ---------------------------------------------------- */
/*														*/
/*			--- �ÓI�����o�ϐ������Z�b�g ---			*/
/*														*/
/* ---------------------------------------------------- */
int Bin::m_IDNo = 0;			// ID�J�E���^
double Bin::m_moveXp = 130;		// �r����X���W�|�W�V�����ړ�
double Bin::m_ColorNo = 0;		// �r���̐F��ύX
double Bin::m_hitZoneXp = 0;	// �����蔻���X�|�W�V�����ړ�
double Bin::m_moveFinXp = 100;	// ���U���g��ʎ��r����X���W�|�W�V�����ړ�


Bin::Bin() {
	init();
}

Bin::~Bin() {
	if (destroyFlg != 1)
		init();
}

void Bin::StaticInit() {
	m_IDNo = 0;			// ID�J�E���^
	m_moveXp = 130;		// �r����X���W�|�W�V�����ړ�
	m_ColorNo = 0;		// �r���̐F��ύX
	m_hitZoneXp = 0;	// �����蔻���X�|�W�V�����ړ�
	m_moveFinXp = 100;
}

void Bin::init() {
	m_ID = m_IDNo;
	m_sprNo = m_IDNo;
	// �r��ID���ƂɃZ�b�g
	if (m_ID == m_IDNo) {
		m_xp = m_moveXp;
		m_yp = 700;
		m_hitZone.left = 50 + (long)m_hitZoneXp;
		m_hitZone.right = 150 + (long)m_hitZoneXp;
		m_hitZone.top = 660;
		m_hitZone.bottom = 740;
	}

	m_usebmp = BIN_ID;

	m_BinColor = m_ColorNo;

	m_bblCorrectFlg = 0;
	m_bblInOutFlg = 0;
	m_objBin = OBJ_BIN_FORWORD;

	// �r���̐F�Z�b�g
	switch ((int)m_BinColor)
	{
		case 0:
			m_BinColorNo = 2;
			break;
		case 100:
			m_BinColorNo = 3;
			break;
		case 200:
			m_BinColorNo = 4;
			break;
		case 300:
			m_BinColorNo = 5;
			break;
	}

	m_IDNo++;
	m_moveXp += BIN_MOVE_X;
	m_hitZoneXp += BIN_MOVE_X;
	m_ColorNo += BIN_SIZE;

	// �X���[�N�A�j���[�V����
	for (int i = 0; i < ANIM_PATTERN_SMOKE; i++) {
		binSmokeAnim[i].bmpNo = BIN_SMOKE_ID;
		binSmokeAnim[i].holdTime = 5;
		binSmokeAnim[i].cutRect.left = 0;
		binSmokeAnim[i].cutRect.right = BIN_SMOKE_SIZE;
		binSmokeAnim[i].cutRect.top = i * BIN_SMOKE_SIZE;
		binSmokeAnim[i].cutRect.bottom = (i+1) * BIN_SMOKE_SIZE;
		binSmokeAnim[i].animMode = ANIM_MODE_NEXT;
		if (i == 5) {
			binSmokeAnim[i].animMode = ANIM_MODE_STOP;
		}
	}
}


/* -------------------------------------------- */
/*												*/
/*			--- �r���̐F���`�F���W ---			*/
/*												*/
/* -------------------------------------------- */
void Bin::changeBinColor() {
	int cnt = 0;
	m_anim.setAnimData(binSmokeAnim);		// �A�j���[�V�����Z�b�g
	while (1) {
		m_BinColor = (double)(rand() % 4) * BIN_SIZE;
		switch ((int)m_BinColor)
		{
			case 0:
				m_BinColorNo = 2;
				break;
			case 100:
				m_BinColorNo = 3;
				break;
			case 200:
				m_BinColorNo = 4;
				break;
			case 300:
				m_BinColorNo = 5;
				break;
		}
		// �r���̐F�����Ȃ��悤�ɂ��鏈��
		for (int i = 0; i < (BIN_MAX - 1); i++) {
			if (i == m_ID) {
				continue;
			}
			if (ptrBinarray[i]->getBinColorNo() != m_BinColorNo) {
				cnt++;
			}
		}
		if (cnt >= 2) {
			break;
		}
		cnt = 0;
	}
}


/* -------------------------------------------------------- */
/*															*/
/*			--- �o�u���ƃr���̃q�b�g�`�F�b�N ---			*/
/*															*/
/* -------------------------------------------------------- */
int Bin::BinHitCheck() {
	int id = -1;

	for (int i = 0; i < MAXBUBBLES; i++) {
		// �o�u�����\������Ă��鎞
		if (ptrBubblesarray[i]->getUseFlg() == 1) {
			// Y���W�̓����蔻��
			if ((m_hitZone.top <= ptrBubblesarray[i]->getYp()) && (m_hitZone.bottom >= ptrBubblesarray[i]->getYp())) {
				// X���W�̓����蔻��
				if ((m_hitZone.left <= ptrBubblesarray[i]->getXp()) && (m_hitZone.right >= ptrBubblesarray[i]->getXp())) {
					id = m_ID;	// �ǂ̃r���ɓ��������̂��r���̎��ʎq��Ԃ�
				}
			}
		}
	}
	return id;
}


void Bin::changeBinPos() {
	m_BinColor = (double)m_ID * BIN_SIZE;
	m_xp = m_moveFinXp;
	m_objBin = OBJ_BIN_FIN;
	m_moveFinXp += 120;
}


int Bin::action() {
	// --- �r���`��
	g_sprite[m_sprNo + m_objBin].setSprite
	(
		m_usebmp,
		(int)m_xp - 50,
		(int)m_yp - 50,
		0,		// ���݂̉摜���W���擾���č��E��RECT�\���̍��W���X�V
		(int)m_BinColor,
		BIN_SIZE,
		BIN_SIZE,
		1,
		1,
		SPR_SCALE,
		1
	);

	if (m_anim.getAnimState() != ANIM_MODE_STOP) {
		m_anim.playAnim();
		// --- �X���[�N�`��
		g_sprite[m_sprNo + OBJ_BIN_SMOKE].setSprite
		(
			BIN_SMOKE_ID,
			(int)m_xp - 50,
			(int)m_yp - 50,
			0,		// ���݂̉摜���W���擾���č��E��RECT�\���̍��W���X�V
			m_anim.getNowAnim()->cutRect.top,
			BIN_SIZE,
			BIN_SIZE,
			1,
			1,
			SPR_SCALE,
			1
		);
	}
	return (false);
}



