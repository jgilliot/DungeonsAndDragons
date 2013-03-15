#include "Utils.h"
#include <PA9.h>

#include "Sprite.h"
using namespace std;

void reset_all(){
PA_ResetBgSys(); // reset bgs
PA_ResetSpriteSys(); // reset sprites
PA_ClearTextBg(0);
PA_ClearTextBg(1);
PA_InitText(1,0);
PA_InitText(0,0);

Sprite::nbSprites=0;
}

void sleep(int seconds){
for(int i = 0; i < 60*seconds; i++)
	PA_WaitForVBL();
}

void sleep(){
	PA_WaitForVBL();
}
