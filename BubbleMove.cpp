/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: BubbleMove.cpp
	NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------

	���V�V���{���ʈړ�

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

#include <windows.h>
#include <stdio.h>	// --- �R���\�[���p

#include "Common.h"
#include "time.h"
#include<cmath>


/* ---------------------------------------------------- */
/*														*/
/*			--- �ÓI�����o�ϐ������Z�b�g ---			*/
/*														*/
/* ---------------------------------------------------- */
// --- �����o�����ۂ̏㏸�J�n�ʒu
double BubbleMove::m_bubble_init_veloXMax = BUBBLE_INITVERO_MAXX;	// ����X�����X�s�[�hMAX(�ő�)
double BubbleMove::m_bubble_init_veloXMin = BUBBLE_INITVERO_MINX;	// ����X�����X�s�[�hMIN(�Œx)
int BubbleMove::sprcnt = 0;											// �X�v���C�g�z��v�f�ԍ�	120�`
int BubbleMove::m_bblNo = 0;										// �N���b�N�����V���{���ʂ̐F�擾
BOOL BubbleMove::m_clickCheck = 0;									// �o�u���N���b�N�`�F�b�N�t���O
int BubbleMove::m_firstBblNo = -1;
int BubbleMove::m_blackBblHitFlg = 0;
BOOL BubbleMove::bblBlackFlg = 0;
int BubbleMove::geneTime = 0;			// �o�u�������^�C�}�[
double BubbleMove::yg = 0.03;			// �o�u�����V���c�h��d�͒l
int BubbleMove::m_befhitBubbleNo = 0;
int BubbleMove::m_bubblecnt = 0;
int BubbleMove::m_timer = 0;

BubbleMove::BubbleMove() {
	init();
}

BubbleMove::~BubbleMove() {
	init();
}

void BubbleMove::StaticInit() {
	// --- �����o�����ۂ̏㏸�J�n�ʒu
	m_bubble_init_veloXMax = BUBBLE_INITVERO_MAXX;	// ����X�����X�s�[�hMAX(�ő�)
	m_bubble_init_veloXMin = BUBBLE_INITVERO_MINX;	// ����X�����X�s�[�hMIN(�Œx)

	m_befhitBubbleNo = 0;

	sprcnt = 0;											// �X�v���C�g�z��v�f�ԍ�	120�`
	m_bblNo = 0;										// �N���b�N�����V���{���ʂ̐F�擾
	m_clickCheck = 0;									// �o�u���N���b�N�`�F�b�N�t���O
	m_firstBblNo = -1;
	m_blackBblHitFlg = 0;
	bblBlackFlg = 0;
	geneTime = 0;		// �o�u�������^�C�}�[
	yg = 0.03;		// �o�u�����V���c�h��d�͒l
	m_bubblecnt = 0;
	m_timer = 0;
}

void BubbleMove::init() {
	// �o�u��ID		0�`
	m_bubbleID = sprcnt;		// test
	// �X�v���C�g�ԍ�����
	m_sprNo = MAXBUBBLES - sprcnt;
	sprcnt++;
	m_flg = 0;					// �t���O	->	0 : ��\��	1 : �\��
	m_bubbleMode = bMBlank;		// �o�u�����[�h�ŏ��̈��
	m_lostFlg = 0;
	m_UpSpd = -20;
	m_separateFlg = 0;
	m_hitbubbleNo = 0;
	m_moveCheck = 0;
	m_hitBinID = 0;
	m_bblHitFlg = 0;

	// �o�u�������o���A�j���[�V����
	for (int i = 0; i < ANIM_PATTERN_FLOAT; i++) {
		bubbleAnim[i].holdTime = 8;
		bubbleAnim[i].cutRect.left = i * BUBBLE_SIZE;
		bubbleAnim[i].cutRect.right = (i + 1) * BUBBLE_SIZE;
		bubbleAnim[i].cutRect.top = 0;
		bubbleAnim[i].cutRect.bottom = BUBBLE_SIZE;
		bubbleAnim[i].animMode = ANIM_MODE_NEXT;
		if (i == 7) {
			bubbleAnim[i].animMode = ANIM_MODE_LOOP;
		}
	}
	m_anim.setAnimData(bubbleAnim);


	// �e���A�j���[�V����
	for (int i = 0; i < ANIM_PATTERN_HAJIKE; i++) {
		hajikeAnim[i].holdTime = 4;
		hajikeAnim[i].cutRect.left = i * BUBBLE_SIZE;
		hajikeAnim[i].cutRect.right = (i + 1) * BUBBLE_SIZE;
		hajikeAnim[i].cutRect.top = BUBBLE_SIZE;
		hajikeAnim[i].cutRect.bottom = BUBBLE_SIZE*2;
		hajikeAnim[i].animMode = ANIM_MODE_NEXT;
		if (i == 3) {
			hajikeAnim[i].animMode = ANIM_MODE_STOP;
		}
	}

	m_xp = (double)girl.getXposi();
	m_yp = (double)girl.getYposi();
	m_xgTunk = 0.1;
	m_timY = 20;
	m_bScaleX = 0;
	m_bScaleY = 0;

	m_hitbubbleID = 0;

	m_geneFlg = 0;
	// �����^�C�}�[�Z�b�g
	m_geneTim = 0;
	// ���V���c�h��l�Z�b�g
	m_ygTunk = yg;
	yg += 0.02;
	if (yg >= 0.07)
		yg = 0.03;

	m_yg = BUBBLE_INITVERO_Y;

	m_xspdTunk = (double)(rand() % 5) + 3;
	m_xspdTunk /= 10;
	m_xspd = (double)(rand() % 4) + 4;
	m_xspd /= 10;
	m_yspdTunk = (double)(rand() % 3) + 4;
	m_yspdTunk /= 10;
	m_yspd /= 10;
	m_g = (double)(rand() % 6) + 10.0;
	m_g = 20.0;			// �㏸�X�s�[�h
	m_g /= 10;
//	m_g = 0.0;			// �㏸�X�s�[�h

	// �V���{���ʂ�BMP�Z�b�g
	m_usebmp = (rand() % 5) + BMP_ID_BUBBLE;

	// ���ꂼ��̏������Z�b�g
	m_xg = (double)(rand() % (int)(m_bubble_init_veloXMax - m_bubble_init_veloXMin + 1) + m_bubble_init_veloXMin);
	m_blowTim = (rand() % 15) + 45;
}


/* -------------------------------------------- */
/*												*/
/*			--- �o�u���X�P�[���g�� ---			*/
/*												*/
/* -------------------------------------------- */
void BubbleMove::addScale() {
	if (m_geneFlg == 1) {
		// ���K�T�C�Y�ɂȂ�܂ŃX�P�[�������X�Ɋg��
		if (m_bScaleX < 1.0) {
			m_bScaleX += 0.025;
			m_bScaleY += 0.025;
		}
	}
}

/* -------------------------------------------------------- */
/*															*/
/*				--- �����V���{���ʐ��J�E���^�[ ---			*/
/*															*/
/* -------------------------------------------------------- */
void BubbleMove::BubbleGenerator() {
	bubbleSet[m_bubbleID].setUseFlg();
	// �o�u����ʏ�Max������ : 30��
	m_geneTim = geneTime;
	geneTime += 100;
	m_yp = (double)girl.getYposi();
	m_bubblecnt++;
}


/*
void BubbleMove::test() {
	if (m_geneTim >= 0) {
		m_geneTim = -1;
		m_yp = (double)girl.getYposi();
	}
};
*/

/* -------------------------------------------- */
/*												*/
/*			--- �V���{���ʕ������ ---			*/
/*												*/
/* -------------------------------------------- */
int BubbleMove::separating(double scale = 60) {
	static double xLength, yLength, Length;

	for (int i = 0; i < MAXBUBBLES + 2; i++) {
		xLength = bubbleSet[i].getXp() - m_xp;
		yLength = bubbleSet[i].getYp() - m_yp;
		Length = std::hypot(xLength, yLength);
		if (Length < scale) {		// 75
			if (bubbleSet[i].getID() > m_bubbleID) {
				m_separateFlg = 1;
				bubbleSet[i].setsepaFlg();
				return i;
			}
		}
		else {
			m_separateFlg = 0;
			bubbleSet[i].releasesepaFlg();
		}
	}
	return -1;
}


/* -------------------------------------------- */
/*												*/
/*			--- �V���{���ʕ��V��� ---			*/
/*												*/
/* -------------------------------------------- */
void BubbleMove::floating() {
	double pi = 3.14;
	static double x, y, z, c;
	m_timY--;
	m_xspd = 0.0;

	// ��������
	m_hitbubbleNo = separating();
	if (bubbleSet[m_hitbubbleNo].getUseFlg() == 1) {
		if (m_separateFlg == 1) {
			x = bubbleSet[m_hitbubbleNo].getXp() - m_xp;
			y = bubbleSet[m_hitbubbleNo].getYp() - m_yp;
			z = atan2(y, x);
			c = z / (pi / 180);
			m_xspd = -cos(c * (pi / 180)) * 4;		// 4
			m_yspd = -sin(c * (pi / 180)) * 2;		// 2
		}
	}

	// �㉺���V�ړ�
//	m_xp += m_xspd;
	m_yspd += m_yg;
	m_yp += m_yspd;
	m_yp -= m_g;
	if (m_timY <= 0) {
		m_yg *= -1;
		m_timY = 20;
		m_yspd = 0;
	}

	// --- ����ɂ��ǂ蒅������\���t���O�����낵�č폜
	if (m_yp < -50) {
//		m_flg = 0;
//		m_bubbleCounter--;
		m_bubbleMode = bMDestroy;
	}
}


/* ---------------------------------------------------------------------------- */
/*																				*/
/*			--- �}�E�X�ƃo�u���̓����蔻��(�N���b�N�q�b�g�`�F�b�N) ---			*/
/*																				*/
/* ---------------------------------------------------------------------------- */
void BubbleMove::clickHitCheck() {
	int mx_pt = (int)getMXposi();	// �}�E�X��X���W���擾
	int my_pt = (int)getMYposi();	// �}�E�X��Y���W���擾

	// �}�E�X�ƃo�u���̋������擾
	m_xLength = mx_pt - m_xp;
	m_yLength = my_pt - m_yp;

	// �}�C�i�X���v���X�ɂ��鏈��
	m_xLength = abs(m_xLength);
	m_yLength = abs(m_yLength);

	// ��ʂɕ\������Ă��鎞
	if (m_flg != 0) {
		if (m_geneFlg == 1) {
			// ��x�N���b�N������s���ăN���b�N����Ă��邱�Ƃ��m�F�ł��Ă���΃X���[
			if (clTrigger == FALSE) {
				// �V���{���ʂ̒��S�_�ƃ}�E�X�N���b�N�ʒu�̋������擾
				m_Length = std::hypot(m_xLength, m_yLength);
				// ������35�����ł���Γ����蔻��
				if (m_Length < 35) {
					m_bubbleMode = bMClick;		// ���[�h���N���b�N���ꂽ����ɐ؂�ւ�
					clTrigger = TRUE;			// �P�o�u�����N���b�N���ꂽ���߁A�P�N���b�N�P�o�u���̃R���W������������邽�߂Ƀg���K�[�𗧂Ă�
					m_bblNo = m_usebmp;			// �ŏ��ɃN���b�N�����V���{���ʂ̐F���i�[
					m_hitbubbleID = m_bubbleID;
					m_befhitBubbleNo = m_bubbleID;
					m_firstBblNo = m_bubbleID;
					m_clickCheck = 1;
				}
			}
		}
	}
}


/* ---------------------------------------------------------------- */
/*																	*/
/*			--- ���F�V���{���ʃh���b�O���q�b�g�`�F�b�N ---			*/
/*																	*/
/* ---------------------------------------------------------------- */
void BubbleMove::dragHitCheck() {
	int mx_pt = (int)getMXposi();	// �}�E�X��X���W���擾
	int my_pt = (int)getMYposi();	// �}�E�X��Y���W���擾

	// �}�E�X�ƃo�u���̋������擾
	m_xLength = mx_pt - m_xp;
	m_yLength = my_pt - m_yp;

	// �}�C�i�X���v���X�ɂ��鏈��
	m_xLength = abs(m_xLength);
	m_yLength = abs(m_yLength);

	// ��ʂɕ\������Ă��鎞
	if (m_flg != 0) {
		if (m_geneFlg == 1) {
			// �V���{���ʂ̒��S�_�ƃ}�E�X�N���b�N�ʒu�̋������擾
			m_Length = std::hypot(m_xLength, m_yLength);
			// �ŏ��ɃN���b�N�����V���{���ʂƓ��F�̃V���{���ʂ̎�
			if ((m_bblNo == m_usebmp) || (m_usebmp == 1)) {
				// �}�E�X�̍��W�ƃV���{���ʂ̒��S���W�̋�����35�����̎�(�����蔻��)
				if (m_Length < 35) {
					if ((m_usebmp == 1) && (blBblFlg == 0)) {
						m_blackBblHitFlg = 1;
						bblBlackFlg = 1;
					}
					else if ((m_usebmp == 1) && (blBblFlg == 1)) {
						bblBlackFlg = 1;
					}
					m_hitbubbleID = m_befhitBubbleNo;
					m_hitBinID = bubbleSet[m_hitbubbleID].getHitBinID();
					m_befhitBubbleNo = m_bubbleID;
					m_bubbleMode = bMHoming;
					m_bblHitFlg = 1;
				}
			}
		}
	}
}


/* ------------------------------------------------ */
/*													*/
/*			--- �V���{���ʐ����o����� ---			*/
/*													*/
/* ------------------------------------------------ */
void BubbleMove::blowing() {
	double pi = 3.14;
	static double x, y, z, c;
	m_blowTim--;
	// ��������
	m_hitbubbleNo = separating();
	if (bubbleSet[m_hitbubbleNo].getUseFlg() == 1) {
		if (m_separateFlg == 1) {
				x = bubbleSet[m_hitbubbleNo].getXp() - m_xp;
				y = bubbleSet[m_hitbubbleNo].getYp() - m_yp;
				z = atan2(y, x);
				c = z / (pi / 180);
				m_xspd = -cos(c * (pi / 180)) * 4;
				m_yspd = -sin(c * (pi / 180)) * 2;
		}
	}

	// �����o�����[�V����
	if (m_blowTim > 0) {
		m_xg -= 0.05;
		m_xp -= m_xg;
		m_yg -= 0.19;
		m_yp += m_yg;
	}
	else {
		if (m_yg <= m_yspd - 2.3) {
			m_yg += 0.12;
			m_yp += m_yg;
		}
		else {
			m_xg = m_xgTunk;
			m_yg = m_ygTunk;
			m_bubbleMode = bMFloating;
		}
	}
}


/* ---------------------------------------- */
/*											*/
/*			--- �z�[�~���O���� ---			*/
/*											*/
/* ---------------------------------------- */
void BubbleMove::homing() {
	double pi = 3.14;
	static double x, y, z, c;
	double Length = 74;


	x = bubbleSet[m_hitbubbleID].getXp() - m_xp;	// X������
	y = bubbleSet[m_hitbubbleID].getYp() - m_yp;	// Y������
	z = atan2(y, x);								// �p�x
//	c = z / (pi / 180);								// �i�ފp�x
	x = 70 * cos(z);								// �V���{���ʂ̋�����70
	y = 70 * sin(z);

/*
	m_xspd = cos(c * (pi / 180)) * 10;
	m_yspd = sin(c * (pi / 180)) * 10;

	m_xp += m_xspd;
	m_yp += m_yspd;
*/

	m_xp = bubbleSet[m_hitbubbleID].getXp() - x;
	m_yp = bubbleSet[m_hitbubbleID].getYp() - y;
}


/* ------------------------------------ */
/*										*/
/*			--- �z������ ---			*/
/*										*/
/* ------------------------------------ */
void BubbleMove::vacuuming() {
	double pi = 3.14;
	static double x, y, z, c;

	// �}�㏸(���ˏオ��)
	m_UpSpd++;
	m_yp += m_UpSpd;

	// �z�[�~���O����
	x = ptrBinarray[m_hitBinID]->getXp() - m_xp;
	y = ptrBinarray[m_hitBinID]->getYp() - m_yp;
	z = atan2(y, x);
	c = z / (pi / 180);
	m_xspd = cos(c * (pi / 180)) * 7;
	m_yspd = sin(c * (pi / 180)) * 7;
	m_xp += m_xspd;
	m_yp += m_yspd;

	// ���X�ɏk��
	m_bScaleX -= 0.05;
	m_bScaleY -= 0.05;

	// �r���̕\���v���C�I���e�B���グ��
	ptrBinarray[m_hitBinID]->changeObjBin(OBJ_BIN_BACK);


	// �k����������
	if (m_bScaleX < 0) {
		// ���V���{���ʈȊO�̎�
		if (m_usebmp != 1)
			ptrScore->addScore(1);		// 100�|�C���g�ǉ�
		m_bubbleMode = bMDestroy;
		ptrBinarray[m_hitBinID]->changeObjBin(OBJ_BIN_FORWORD);		// �r���̃v���C�I���e�B��������
		ptrBinarray[m_hitBinID]->changeBinColor();					// �r���̐F�������_���ύX
	}
}


/* ----------------------------------------------------	*/
/*														*/
/*				--- ���V����ڂ�ʒe�� ---				*/
/*														*/
/* ---------------------------------------------------- */
void BubbleMove::HajikeBubble() {
	if (m_anim.getAnimState() == ANIM_MODE_STOP) {
//		m_bubbleCounter--;
//		m_flg = 0;
		m_bubbleMode = bMDestroy;
	}
}


/* ----------------------------------------------------	*/
/*														*/
/*				--- ���V����ڂ�ʈړ� ---				*/
/*														*/
/* ---------------------------------------------------- */
int BubbleMove::action() {
	double pi = 3.14;
	static double x, y, z, c;
	int sprNo = 0;

	addScale();		// �o�u���g��
	if (clTrigger == FALSE) {
		m_clickCheck = 0;
		m_blackBblHitFlg = 0;
		bblBlackFlg = 0;
	}
	
	if (m_timer > m_geneTim) {
		m_geneFlg = 1;
	}

	if (reSpawnFlg == 1) {
		m_timer++;
	}
	
	switch (m_bubbleMode)
	{
		case bMBlank:		// �ŏ��̂P��
			m_bubbleMode++;
			break;
		case bMBlow:		// �V���{���ʐ����o�����[�h
			if (m_geneFlg == 1) {
				blowing();
			}

			if (m_blackBblHitFlg == 0) {
				// �V���{���ʂ̘A��
				if (clTrigger != FALSE)
					dragHitCheck();
			}

			// ���N���b�N�������ݎ�
			if (GetKeyState(VK_LBUTTON) < -1) {
				// �}�C�o�u���|�W�V�������ړ����������߂ɉ����Ȃ��ӏ����N���b�N�������̂́A
				// ���̃}�E�X���W���擾���ĕ��V�o�u�������̍��W�֐G�ꂽ�ۂɃN���b�N����ƂȂ��Ă��܂��̂�h���N���b�N�^�C�}�[
				if (m_clickCheck == 0) {
					if (m_usebmp != 1) {
						clickHitCheck();	// �N���b�N���胁�\�b�h
					}
				}
			}

			reSpawnFlg = TRUE;		// testOK
			break;
		case bMFloating:			// �V���{���ʕ��V���[�h(�q�b�g�`�F�b�N)
			reSpawnFlg = FALSE;
			floating();
			if (m_blackBblHitFlg == 0) {
				if (clTrigger != FALSE)
					dragHitCheck();
			}

			// ���N���b�N�������ݎ�
			if (GetKeyState(VK_LBUTTON) < -1) {
				if (m_clickCheck == 0) {
					if (m_usebmp != 1){
						clickHitCheck();	// �N���b�N���胁�\�b�h
					}
					// �N���b�N���Ă���o�u������ԑO��
					if (m_sprNo > bubbleSet[m_befhitBubbleNo].getSprNo()) {
						sprNo = m_sprNo;
						m_sprNo = bubbleSet[m_befhitBubbleNo].getSprNo();
						bubbleSet[m_befhitBubbleNo].setSprNo(sprNo);
					}
				}
			}
			break;
		case bMClick:		// �N���b�N���胂�[�h(�N���b�N�����V���{���ʂ̏��)		1�ڂ̃V���{����
/*
			// ��������
			m_hitbubbleNo = separating();
			if (bubbleSet[m_hitbubbleNo].getUseFlg() == 1) {
				if (m_separateFlg == 1) {
					x = bubbleSet[m_hitbubbleNo].getXp() - m_xp;
					y = bubbleSet[m_hitbubbleNo].getYp() - m_yp;
					z = atan2(y, x);
					c = z / (pi / 180);
					m_xspd = -cos(c * (pi / 180)) * 4;		// 4
					m_yspd = -sin(c * (pi / 180)) * 2;		// 2
				}
			}
*/

			m_xp = getMXposi();		// �N���b�N�����V���{���ʂ�xp���}�E�X��X���W��
			m_yp = getMYposi();		// �N���b�N�����V���{���ʂ�yp���}�E�X��Y���W��

			for (int i = 0; i < (BIN_MAX-1); i++) {
				// �r���Ƃ̏Փ˔���
				if (ptrBinarray[i]->BinHitCheck() != -1) {
					// �r���ƃo�u���̐F����
					if (ptrBinarray[i]->getBinColorNo() == m_usebmp) {
						m_hitBinID = i;
						m_bblHitFlg = 1;
						bubbleSet[m_befhitBubbleNo].bblHitFlg();
					}
				}
			}

			// �r���͈͓̔��Ń����[�X�������ȊO�́A��x�r���̃q�b�g�`�F�b�N�͈͓��Ƀo�u�����G��Ă��Ă��펞�͈͓����m�F����
			if (ptrBinarray[m_hitBinID]->BinHitCheck() == -1) {
				m_bblHitFlg = 0;
			}

			// ���V���{���ʂɓ���������
			if (bblBlackFlg == 1) {
//				m_flg = 0;		// �V���{���ʍ폜
				m_bubbleMode = bMHajike;
				m_anim.setAnimData(hajikeAnim);
			}

			if (clTrigger == 0) {					// �N���b�N���Ă��Ȃ���
				if (m_bblHitFlg == 1) {				// �r���ƏՓ˂��Ă��锻��̎�
					m_bubbleMode = bMVacuum;
					totalCatchBbl++;
					switch (m_usebmp)
					{
					case 2:
						bblColor[BLUE]++;
						resultBubble[totalCatchBbl - 1].setUseBmp(m_usebmp);
						break;
					case 3:
						bblColor[ORANGE]++;
						resultBubble[totalCatchBbl - 1].setUseBmp(m_usebmp);
						break;
					case 4:
						bblColor[PERPLE]++;
						resultBubble[totalCatchBbl - 1].setUseBmp(m_usebmp);
						break;
					case 5:
						bblColor[PINK]++;
						resultBubble[totalCatchBbl - 1].setUseBmp(m_usebmp);
						break;
					}
				}
				else {								// �r���ƏՓ˂��Ă��Ȃ���
					m_bubbleMode = bMFloating;
					m_xspdTunk /= 10;
					m_xspd = m_xspdTunk;		
					m_yspdTunk /= 10;
					m_yg = m_ygTunk;
					m_yspd = m_yspdTunk;
					m_bblHitFlg = 0;
//					totalCatchBbl--;
				}
			}
			break;
		case bMHoming:		// �t���Ă����V���{���ʂ̏��				2�ڈȍ~�̃V���{����
			if (clTrigger == 1){		// ���N���b�N�������Ă��鎞
				if (m_HitFlg != 1) {	// �ڐG��ԂłȂ���
					homing();
				}
			}

			if (clTrigger == 0) {				// �����[�X������
				if (bubbleSet[m_firstBblNo].getbblHitFlg() != 1) {		// �o�u���ƃr������Փˎ�
					m_bblHitFlg = 0;
				}
				if (m_bblHitFlg == 1) {									// �o�u���ƃr�����Փˎ�
					m_bubbleMode = bMVacuum;
					m_hitBinID = bubbleSet[m_firstBblNo].getHitBinID();
					totalCatchBbl++;
					switch (m_usebmp)
					{
					case 2:
						bblColor[BLUE]++;
						resultBubble[totalCatchBbl - 1].setUseBmp(m_usebmp);
						break;
					case 3:
						bblColor[ORANGE]++;
						resultBubble[totalCatchBbl - 1].setUseBmp(m_usebmp);
						break;
					case 4:
						bblColor[PERPLE]++;
						resultBubble[totalCatchBbl - 1].setUseBmp(m_usebmp);
						break;
					case 5:
						bblColor[PINK]++;
						resultBubble[totalCatchBbl - 1].setUseBmp(m_usebmp);
						break;
					}
				}
				else {
					m_bubbleMode = bMFloating;	// ���V��Ԃփ��[�h��߂�
//					totalCatchBbl--;
				}
				m_xspdTunk /= 10;
				m_xspd = m_xspdTunk;
				m_yspdTunk /= 10;
				m_yspd = m_yspdTunk;
				m_yg = m_ygTunk;
			}
			if (bblBlackFlg == 1) {
				m_bubbleMode = bMHajike;
				m_anim.setAnimData(hajikeAnim);
			}
			break;
		case bMVacuum:							// �z�����[�h
			vacuuming();
			break;
		case bMHajike:
			HajikeBubble();
			break;
		case bMDestroy:
			m_bubblecnt--;
			m_flg = 0;
			setLostFlg();
			break;
	}

	m_anim.playAnim();		// �A�j���[�V����
	// �����t���O�������Ă��鎞
	if (m_geneFlg == 1) {
		// --- �`��
		g_sprite[m_sprNo + OBJ_BUBBLES].setSprite
		(
			m_usebmp,
			(int)m_xp - (int)(m_bScaleX * 40),
			(int)m_yp - (int)(m_bScaleY * 40),
			m_anim.getNowAnim()->cutRect.left,		// ���݂̉摜���W���擾���č��E��RECT�\���̍��W���X�V
			m_anim.getNowAnim()->cutRect.top,
			BUBBLE_SIZE,
			BUBBLE_SIZE,
			m_bScaleX,
			m_bScaleY,
			SPR_SCALE,
			1
		);
	}
	return (false);
}


