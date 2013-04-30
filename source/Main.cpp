#include "Main.h"
#include "Background.h"
#include "Variables.h"
#include "Position.h"
#include <PA9.h>
#include <arm9/PA_API.h>
#include "Hero.h"
#include "Mob.h"
#include "Effet.h"
#include "Objet.h"


//using namespace std;

int main(int argc, char ** argv){

PA_Init();
PA_InitVBL();
PAPI_Init(0); // Init the API on the bottom screen
PA_InitText(1,0);
PA_InitText(0,0);


//Labyrinthe * l = new Labyrinthe();

init_variables(); // initialisation des variables globales

//display_menu();

Effet * soin = new Effet("Heal",0,50,0,0,0,0,0,0,0);
Sprite * sprite1 = new Sprite(5,0,*(new Taille(32,32)));
Objet * epee1 = new Objet("Epee 1","Guerrier","Arme",0,15,false,sprite1);
epee1->get_icone()->affichage(0,0,*(new Position(10,10)));

//j->combattre(*m);
while(1){
	PA_WaitForVBL();
}
}
