#include "CreationPersonnage.h"
#include "Utils.h"
#include <PA9.h>

using namespace std;

//#######################################################################################

// 								CREATION PERSONNAGE

//#######################################################################################

void creation_hero() {
    reset_all();
    char * nomClasse;
    int race = choix_race();
    int classe = choix_classe();
    char * nom = choix_nom();

    reset_all();

    switch (classe) {
        case 0: nomClasse = "Guerrier";
            break;
        case 1: nomClasse = "Archer";
            break;
        case 2: nomClasse = "Mage";
            break;
        default: nomClasse = "Default";
    }

    switch (race) {
        case 0: hero_principal = new Hero(nom, nomClasse, "Orc");
            break;
        case 1: hero_principal = new Hero(nom, nomClasse, "Humain");
            break;
        case 2: hero_principal = new Hero(nom, nomClasse, "Elfe");
            break;
        default: hero_principal = new Hero(nom, "Default", "Paysan");
    }

    //return j;
}

char * choix_nom() {

    reset_all();

    PA_InitKeyboard(2); // Load the keyboard on background 2...
    PA_KeyboardIn(25, 50);

    int nletter = 0; // Next letter to right. 0 since no letters are there yet
    char letter = 0; // New letter to write.
    char * text = (char*) malloc(15 * sizeof (char)); // This will be our text.

    PA_OutputText(1, 0, 2, "SAISISSEZ VOTRE NOM:");

    // Infinite loop to keep the program running
    while (1) {

        letter = PA_CheckKeyboard();

        if (letter > 31) { // there is a new letter
            text[nletter] = letter;
            nletter++;
        } else if ((letter == PA_BACKSPACE) && nletter) { // Backspace pressed
            nletter--;
            text[nletter] = ' '; // Erase the last letter
        } else if (letter == '\n') { // Enter pressed
            PA_KeyboardOut();
            return text;
            //text[nletter] = letter;
            //nletter++;
        }

        PA_OutputSimpleText(1, 13, 6, text); // Write the text
        PA_WaitForVBL();
    }
}

int choix_classe() {

    reset_all();

    Position * p = new Position(16, 64);
    icones_classe[0].affichage(0, 0, *p); // guerrier
    p->setPos(96, 64);
    icones_classe[1].affichage(0, 1, *p); // archer
    p->setPos(176, 64);
    icones_classe[2].affichage(0, 2, *p); // mage
    p->setPos(10, 10);
    
    int sprite_touche = -1;
    int sprite_deja_touche = -1;

    while (1) {
        sprite_deja_touche = sprite_touche;
        sprite_touche = Sprite::Sprite_touche(0, 3);

        PA_ClearTextBg(1);
        switch (sprite_touche) {
            case 0:
                PA_OutputText(1, 10, 2, "GUERRIER:");
                break;
            case 1:
                PA_OutputText(1, 10, 2, "ARCHER:");
                break;
            case 2:
                PA_OutputText(1, 10, 2, "MAGE:");
        }
        icones_classe[sprite_touche].affichage(1, 0, *p);
        PA_BoxText(1, 3, 12, 29, 23, descriptions[sprite_touche + 3], 256);
        if (sprite_deja_touche == sprite_touche)
            return sprite_touche; // Sortie de boucle car on a choisi une classe
        PA_WaitForVBL();
    }
}

int choix_race() {

    reset_all();

    Position * p = new Position(16, 64);
    icones_race[0].affichage(0, 0, *p);
    p->setPos(96, 64);
    icones_race[1].affichage(0, 1, *p);
    p->setPos(176, 64);
    icones_race[2].affichage(0, 2, *p);
    p->setPos(10, 10);

    int sprite_touche = -1;
    int sprite_deja_touche = -1;
    while (1) {
        sprite_deja_touche = sprite_touche;
        sprite_touche = Sprite::Sprite_touche(0, 3);

        PA_ClearTextBg(1);
        switch (sprite_touche) {
            case 0:
                PA_OutputText(1, 10, 2, "ORC:");
                break;
            case 1:
                PA_OutputText(1, 10, 2, "HUMAIN:");
                break;
            case 2:
                PA_OutputText(1, 10, 2, "ELFE:");
        }
        icones_race[sprite_touche].affichage(1, 0, *p);
        PA_BoxText(1, 3, 12, 29, 23, descriptions[sprite_touche], 256);
        if (sprite_deja_touche == sprite_touche)
            return sprite_touche; // Sortie de boucle car on a choisi une race
        PA_WaitForVBL();
    }
}
