#include <windows.h>
#include <stdio.h>

#include "Common.h"


/* ---------------------------------------------------- */
/*														*/
/*			--- �ÓI�����o�ϐ������Z�b�g ---			*/
/*														*/
/* ---------------------------------------------------- */
double LoadScene::m_px = 0;
double LoadScene::m_py = WINDOW_H;
int LoadScene::m_sprNoFlg[OBJ_LOADBUBBLES_MAX] = { 0 };
int LoadScene::m_bubbleCnt = 0;


// �C���X�g���N�^
LoadScene::LoadScene() {
	init();
}

// �f�X�g���N�^
LoadScene::~LoadScene() {
	if (destroyFlg != 1)
		init();
}

void LoadScene::StaticInit() {
	m_px = 0;
	m_py = WINDOW_H;
	for (int i = 0; i < OBJ_LOADBUBBLES_MAX; i++) {
		m_sprNoFlg[i] = 0;
	}
	m_bubbleCnt = 0;
}

// �����Z�b�g
void LoadScene::init() {
	m_useflg = 1;
	m_bubbleNo = m_bubbleCnt;
	m_bubbleCnt++;
	m_xp = m_px;
	m_px += 40;
	m_yp = m_py;
	if (m_xp >= WINDOW_W) {
		m_px = 0;
		m_py += 40;
	}
	m_usebmp = (rand() % 4) + 2;
	m_yspd = 15.0;
	while (1) {
		m_sprNo = rand() % OBJ_LOADBUBBLES_MAX;
		if (m_sprNoFlg[m_sprNo] == 0) {
			m_sprNoFlg[m_sprNo] = 1;
			break;
		}
	}

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
}


int LoadScene::MovingUp() {
	m_yp -= m_yspd;
	if (m_yp < -50)
		m_useflg = 0;

	return (false);
}


int LoadScene::action() {
	MovingUp();
	m_anim.playAnim();		// �A�j���[�V����
	g_sprite[m_sprNo + OBJ_LOADBUBBLES].setSprite
	(
		m_usebmp,
		(int)m_xp - 40,
		(int)m_yp - 40,
		m_anim.getNowAnim()->cutRect.left,		// ���݂̉摜���W���擾���č��E��RECT�\���̍��W���X�V
		0,
		BUBBLE_SIZE,
		BUBBLE_SIZE,
		1,
		1,
		SPR_SCALE,
		1
	);


	return (false);
}

