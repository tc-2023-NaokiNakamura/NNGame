
/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: DrawLoop.cpp
    NAME	: kz-matsu

+ ------ Explanation of file --------------------------------------------------------------------------
       
    �`����s��

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

#include <windows.h>
#include <stdio.h>

#include "Common.h"

// --- �]���������s��
int DrawLoop( )
{
    g_BG->draw();
 
    // �X�v���C�g128���̕`��(�L�����Ȃ�)
    for (int i = 0; i < OBJ_SPR_MAX; i++) {
        g_sprite[i].draw();
    }
    // �X�v���C�g128���̏�����
    for (int i = 0; i < OBJ_SPR_MAX; i++) {
        g_sprite[i].clearSprite();
    }
    return( false ) ;
}




