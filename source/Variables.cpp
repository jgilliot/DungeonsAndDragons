#ifndef SPRITE_CPP
#define SPRITE_CPP
#define DEFINE_GLOBALS

#include "Variables.h"

Sprite icones_race[3];
Sprite icones_classe[3];
Sprite icones_mob[4];
Sprite icones_arme[1];
char * noms_mob[5];

// objets

char ** descriptions;

void init_variables(){

// ICONES

//races
icones_race[0] = *(new Sprite(0,0,*new Taille(64,64))); //orc
icones_race[1] = *(new Sprite(0,1,*new Taille(64,64))); // humain
icones_race[2] = *(new Sprite(0,2,*new Taille(64,64))); // elfe

//classes
icones_classe[0] = *(new Sprite(4,0,*new Taille(64,64))); //guerrier
icones_classe[1] = *(new Sprite(4,1,*new Taille(64,64))); //archer
icones_classe[2] = *(new Sprite(4,2,*new Taille(64,64))); //mage

//mobs
icones_mob[0] = *(new Sprite(1,2,*new Taille(64,64))); //squelette
icones_mob[1] = *(new Sprite(1,1,*new Taille(64,64))); //araignee
icones_mob[2] = *(new Sprite(1,0,*new Taille(64,64))); //gobelin
icones_mob[3] = *(new Sprite(1,0,*new Taille(64,64))); //dragon

//objets
icones_arme[0] = *(new Sprite(5,0,*new Taille(32,32))); // epee1

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
descriptions[6] = "LES SQUELETTES SONT D'EXCELLENTS COMBATTANTS.";
descriptions[7] = "LES ARAIGNEES ONT UN POISON TRES PUISSANT.";
descriptions[8] = "LES GOBELINS SONT TRES HABILES.";
descriptions[9] = "LE DRAGON EST UN MONSTRE TRES TRES PUISSANT.";

// NOMS DE MOB
noms_mob[0] = "LEORIC";
noms_mob[1] = "GOBGOB";
noms_mob[2] = "ARAC";
noms_mob[3] = "RAFIEL";
noms_mob[4] = "GRIOL";

// OBJETS

//armes

}

#endif
