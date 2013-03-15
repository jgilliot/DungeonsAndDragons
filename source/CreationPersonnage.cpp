#include "CreationPersonnage.h"
#include "Utils.h"
#include <arm9/PA_API.h>
#include <PA9.h>

using namespace std;

//#######################################################################################

// 								CREATION PERSONNAGE

//#######################################################################################

Hero * creation_hero(){
reset_all();
char * nomClasse;
int race = choix_race();
int classe = choix_classe();
char * nom = choix_nom();

reset_all();

Hero * j;

switch(classe){
case 0: nomClasse = "Guerrier"; break;
case 1: nomClasse = "Archer"; break;
case 2: nomClasse = "Mage"; break;
default: nomClasse = "Default";
}

switch(race){
case 0: j = new Hero(nom,nomClasse,"Orc"); break;
case 1: j = new Hero(nom,nomClasse,"Humain"); break;
case 2: j = new Hero(nom,nomClasse,"Elfe"); break;
default: j = new Hero(nom,"Default","Paysan");
}

return j;
}

char * choix_nom(){

reset_all();

PA_InitKeyboard(2); // Load the keyboard on background 2...
PA_KeyboardIn(25, 50); 

int nletter = 0; // Next letter to right. 0 since no letters are there yet
char letter = 0; // New letter to write.
char * text=(char*)malloc(15*sizeof(char));  // This will be our text.

PA_OutputText(1,0,2,"SAISISSEZ VOTRE NOM:");
	
// Infinite loop to keep the program running
while (1)
{
		
	letter = PA_CheckKeyboard();
		
	if (letter > 31) { // there is a new letter
		text[nletter] = letter;
		nletter++;
	}
	else if ((letter == PA_BACKSPACE)&&nletter) { // Backspace pressed
		nletter--;
		text[nletter] = ' '; // Erase the last letter
	}
	else if (letter == '\n'){ // Enter pressed
		PA_KeyboardOut();
		return text;
		//text[nletter] = letter;
		//nletter++;
	}
		
	PA_OutputSimpleText(1, 13, 6, text); // Write the text
	PA_WaitForVBL();
}
}

int choix_classe(){

reset_all();

int spritetouche=-1;
int spritedejatouche=-1;

Taille * t = new Taille(64,64);
Sprite * icone_guerrier = new Sprite(4,0,*t);
Sprite * icone_archer = new Sprite(4,1,*t);
Sprite * icone_mage = new Sprite(4,2,*t);
Position * p = new Position(16,64);
icone_guerrier->affichage(0,0,*p);
p->setPos(96,64);
icone_archer->affichage(0,1,*p);
p->setPos(176,64);
icone_mage->affichage(0,2,*p);

	while(1)
	{	
		for (int i = 0; i < 3; i++) {
			if (PA_SpriteTouched(i) && Stylus.Newpress) 
			{
					spritedejatouche=spritetouche;
					spritetouche=i;
					switch(i){
					case 0:
						PA_ClearTextBg(1);
						PA_OutputText(1,10,2,"GUERRIER:");
						PA_BoxText(1,3,12,29,23,"LES GUERRIERS SONT ROBUSTES.",256);
						break;
					case 1:
						PA_ClearTextBg(1);
						PA_OutputText(1,10,2,"ARCHER:");
						PA_BoxText(1,3,12,29,23,"LES ARCHERS ESQUIVENT.",256);
						break;
					case 2:
						PA_ClearTextBg(1);
						PA_OutputText(1,10,2,"MAGE:");
						PA_BoxText(1,3,12,29,23,"LES MAGES FONT MAL ET ON NE PEUT LES ESQUIVER.",256);
							}			
				if (spritedejatouche==spritetouche)
					return spritetouche; // Sortie de boucle car on a choisi une classe
			}
		}
		PA_WaitForVBL();
	}
}

int choix_race(){

reset_all();

int spritetouche=-1;
int spritedejatouche=-1;

Position * p = new Position(16,64);
icones[0].affichage(0,0,*p);
p->setPos(96,64);
icones[1].affichage(0,1,*p);
p->setPos(176,64);
icones[2].affichage(0,2,*p);
p->setPos(10,10);

	while(1)
	{	
		for (int i = 0; i < 3; i++) {
			if (PA_SpriteTouched(i) && Stylus.Newpress) 
			{
					spritedejatouche=spritetouche;
					spritetouche=i;
					switch(i){
					case 0:
						PA_ClearTextBg(1);
						icones[0].affichage(1,0,*p);
						PA_OutputText(1,10,2,"ORC:");
						PA_BoxText(1,3,12,29,23,descriptions[0],256);
						break;
					case 1:
						PA_ClearTextBg(1);
						icones[1].affichage(1,0,*p);
						PA_OutputText(1,10,2,"HUMAIN:");
						PA_BoxText(1,3,12,29,23,descriptions[1],256);
						break;
					case 2:
						PA_ClearTextBg(1);
						icones[2].affichage(1,0,*p);
						PA_OutputText(1,10,2,"ELFE:");
						PA_BoxText(1,3,12,29,23,descriptions[2],256);
							}			
			if (spritedejatouche==spritetouche)
				return spritetouche; // Sortie de boucle car on a choisi une race
			}
		}
		PA_WaitForVBL();
	}
}
