
/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: DrawLoop.cpp
    NAME	: kz-matsu

+ ------ Explanation of file --------------------------------------------------------------------------
       
    描画を行う

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

#include <windows.h>
#include <stdio.h>

#include "Common.h"

// --- 転送処理を行う
int DrawLoop( )
{
    g_BG->draw();
 
    // スプライト128枚の描画(キャラなど)
    for (int i = 0; i < OBJ_SPR_MAX; i++) {
        g_sprite[i].draw();
    }
    // スプライト128枚の初期化
    for (int i = 0; i < OBJ_SPR_MAX; i++) {
        g_sprite[i].clearSprite();
    }
    return( false ) ;
}




