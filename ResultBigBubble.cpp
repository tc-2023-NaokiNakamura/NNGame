/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: ResultBigBubble.cpp
	NAME	: Naoki_Nakamura

+ ------ Explanation of file --------------------------------------------------------------------------

	���U���g�r�b�O�o�u��

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */
#include <windows.h>
#include <stdio.h>	// --- �R���\�[���p

#include "Common.h"

ResultBigBubble::ResultBigBubble() {
	init();
}

void ResultBigBubble::init() {
	m_xp = WINDOW_W / 2;
	m_yp = 300;
	m_usebmp = (rand() % 4) + 2;
	m_scale = 0;

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

void ResultBigBubble::addScale() {
	// 7�{�܂Ŋg��
	if (m_scale < 7) {
		m_scale += 0.1;
	}
	// 5�{�𒴂�����
	if (m_scale > 5) {
		resultBord.setOnAlphaFlg();			// ���U���g�����\��
		score.setOnAlphaFlg();				// �ŏI�X�R�A�\��
		titleBackButton.setAlphaOnFLg();	// �^�C�g���o�b�N�{�^���\��
	}
}

int ResultBigBubble::action() {
	addScale();
	m_anim.playAnim();		// �A�j���[�V����
	// --- �`��
	g_sprite[m_sprNo + OBJ_RESULTBUBBLE].setSprite
	(
		m_usebmp,
		(int)m_xp - (int)(m_scale * 40),
		(int)m_yp - (int)(m_scale * 40),
		m_anim.getNowAnim()->cutRect.left,		// ���݂̉摜���W���擾���č��E��RECT�\���̍��W���X�V
		0,
		BUBBLE_SIZE,
		BUBBLE_SIZE,
		m_scale,
		m_scale,
		SPR_SCALE,
		1
	);

	return (false);
}

