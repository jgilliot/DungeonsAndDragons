#ifndef VARIABLES_H
#define VARIABLES_H

#include "Combattant.h"
#include "Explorateur.h"
#include "Objet.h"

extern Sprite icones_race[3];
extern Sprite icones_classe[3];
extern Sprite icones_mob[4];
extern Sprite icones_arme[1];
extern Sprite icones_ui[5];

extern char * noms_mob[5];

//extern Mob mobs[4];
extern char ** descriptions;
void init_variables();

#endif
