#include "Main.h"
#include "Background.h"
#include "Variables.h"
#include "Position.h"
#include <PA9.h>
#include <arm9/PA_API.h>
#include "Hero.h"
#include "Mob.h"


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

reset_all();
PA_WaitForVBL();
Hero * j = hero_principal; //cast en Hero !
Labyrinthe * essai = new Labyrinthe(16,12);
j->entrer_labyrinthe(*essai);

Position * pMinimap = new Position(0,0);
Position * pJoueur = new Position(0,0);
essai->affiche_minimap(0,*pMinimap,*pJoueur);

PA_OutputText(1,2,2,"entree: %d - %d  ",essai->getEntree()->getPosX(),essai->getEntree()->getPosY());
PA_OutputText(1,2,3,"sortie: %d - %d  ",essai->getSortie()->getPosX(),essai->getSortie()->getPosY());

while(1)
{
PA_OutputText(1,2,4,"position: %d - %d  ",j->getPosX(),j->getPosY());
essai->affiche_minimap(0,*pMinimap,*pJoueur);
j->affiche_sur_minimap();
if(Pad.Newpress.Up)
	j->se_deplace(essai->getNiveau(),'n');
if(Pad.Newpress.Down)
	j->se_deplace(essai->getNiveau(),'s');
if(Pad.Newpress.Left)
	j->se_deplace(essai->getNiveau(),'o');
if(Pad.Newpress.Right)
	j->se_deplace(essai->getNiveau(),'e');//*/
PA_WaitForVBL();
}

/*Mob * squelette = new Mob("Leoric","Squelette","Guerrier",1);
Mob * gobelin = new Mob("GobGob","Gobelin","Archer",2);
Mob * araignee = new Mob("Aracnei","Araignee","Mage",3);

j->combattre(*squelette);
j->combattre(*gobelin);
j->combattre(*araignee);*/



//j->combattre(*m);
while(1){
	PA_WaitForVBL();
}
}
