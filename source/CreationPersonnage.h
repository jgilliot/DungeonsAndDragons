#ifndef CREATIONPERSO_H
#define CREATIONPERSO_H
#include "Variables.h"
#include "Hero.h"

void affiche_menu();
void start_game();

// Creation du personnage
Hero * creation_hero();
char * choix_nom();
int choix_classe();
int choix_race();
#endif
