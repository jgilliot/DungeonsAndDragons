#ifndef JOUEUR_H
#define JOUEUR_H

#include "Position.h"
#include "Sprite.h"
#include <string>
using namespace std;

class Joueur{
public:

Joueur();
Joueur(char * nomP, char * raceP,Sprite * sP);

char * getNom();
char * getRace();

Sprite * getIcone();

void setNom(char * nom);
void setRace(char * race);

void setIcone(Sprite * sprite);

void presentation();

private:
char * nom;
char * race;
Sprite * icone;
};
#endif
