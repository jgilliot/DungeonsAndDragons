#ifndef SPRITE_CPP
#define SPRITE_CPP
#define DEFINE_GLOBALS
#include "Variables.h"

Sprite icones[10];
char ** descriptions;

void init_variables(){

// ICONES

//races
icones[0] = *(new Sprite(0,0,*new Taille(64,64))); //orc
icones[1] = *(new Sprite(0,1,*new Taille(64,64))); // humain
icones[2] = *(new Sprite(0,2,*new Taille(64,64))); // elfe

//classes
icones[3] = *(new Sprite(4,0,*new Taille(64,64))); //guerrier
icones[4] = *(new Sprite(4,1,*new Taille(64,64))); //archer
icones[5] = *(new Sprite(4,2,*new Taille(64,64))); //mage

//mobs
icones[6] = *(new Sprite(1,2,*new Taille(64,64))); //squelette
icones[7] = *(new Sprite(1,1,*new Taille(64,64))); //araignee
icones[8] = *(new Sprite(1,0,*new Taille(64,64))); //gobelin
icones[9] = *(new Sprite(1,0,*new Taille(64,64))); //dragon

// DESCRIPTIONS 

descriptions = (char **)malloc ( sizeof(char *)  *  10);
    for (int i = 0 ; i < 10 ; i++){
        descriptions[i] = (char *)malloc (sizeof(char) * 256);
    }
// races
descriptions[0] = "LES ORCS SONT CONNUS POUR LEUR FORCE MONSTRUEUSE ET LEUR PEAU SI RESISTANTE QU'ELLE PEUT BLOQUER DES FLECHES. ILS SONT D'EXCELLENTS COMBATTANTS MAIS SONT TRES FAIBLES CONTRE LES MAGES.";
descriptions[1] = "LES HUMAINS SONT CONNUS POUR EXCELLER EN TOUT.";
descriptions[2] = "LES ELFES SONT DOUES POUR LA MAGIE ET ONT UNE AFFINITE POUR LES ARMES A DISTANCE.";
// classes
descriptions[3] = "LES GUERRIERS SONT ROBUSTES.";
descriptions[4] = "LES ARCHERS ESQUIVENT.";
descriptions[5] = "LES MAGES FONT MAL ET ON NE PEUT LES ESQUIVER.";
// mobs
descriptions[6] = "LES SQUELETTES ";
descriptions[7] = "LES ARAIGNEES ";
descriptions[8] = "LES GOBELINS ";
descriptions[9] = "LE DRAGON EST ";
}

#endif
