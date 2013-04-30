#include "Variables.h"
#include "Menu.h"
#include <arm9/PA_API.h>
#include <PA9.h>
#include "Utils.h"
#include "CreationPersonnage.h"
#include "Hero.h"
using namespace std;

//############
// MENU
//############

void display_menu(){
reset_all();
// load écran haut + load écran bas
PA_Init8bitBg(0, 3);
	
	PAPI_CreateButton(0, // screen
					  64, // X position
					  20, // Y position
					  128, // X size
					  32, // Y size
					  &start_game, // function to execute on button press
					  "Commencer la partie", // Text displayed on the button
					  1, // Text palette color, we'll put 1
					  1); // Text size (you must enable all text sizes in PA9.h to use this)
	
	while (1){
		PAPI_CheckButton(); // Check the buttons
		PA_WaitForVBL();
	}
}

void start_game(){

reset_all();
// LOAD BG !
creation_hero();
Hero * j=0;
j=hero_principal;
j->presentation();


PA_Init8bitBg(0, 3);
	PAPI_CreateButton(0, // screen
					  64, // X position
					  50, // Y position
					  128, // X size
					  32, // Y size
					  &start_game, // function to execute on button press
					  "Annuler", // Text displayed on the button
					  1, // Text palette color, we'll put 1
					  1); // Text size (you must enable all text sizes in PA9.h to use this)

	PAPI_CreateButton(0, // screen
					  64, // X position
					  85, // Y position
					  128, // X size
					  32, // Y size
					  &start_adventure, // function to execute on button press
					  "Partir a l'aventure", // Text displayed on the button
					  1, // Text palette color, we'll put 1
					  1); // Text size (you must enable all text sizes in PA9.h to use this)
	while (1){
		PAPI_CheckButton(); // Check the buttons
		PA_WaitForVBL();
	}
reset_all();
}

void start_adventure(){
reset_all();
PA_OutputText(1,0,0,"L'aventure commence...");
PA_WaitForVBL();
Hero * j = hero_principal;
PA_OutputText(1,0,0,"Le Hero est bien cree ...");
Labyrinthe * essai = new Labyrinthe(); // 16x12 max
PA_WaitForVBL();
PA_OutputText(1,0,0,"Le Labyrinthe est ok ...");
PA_WaitForVBL();
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

}
