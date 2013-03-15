#ifndef SPRITE_H
#define SPRITE_H

#include "Position.h"
#include <PA9.h>
#include "Taille.h"


using namespace std;

class Sprite{
public:
Sprite();
Sprite(int type,int id, Taille t);

int getId(); 
int getType();
bool getAffiche();
int getScreen();
int getNSprite();
Position * getPosition();
Taille getTaille();

void setId(int id);
void setType(int typ);

void affichage(int screen,int nSprite,Position p);
void bouger(Position p);
void setRotation(int angle);


static int nbSprites;

private:

int id; // numéro de ligne
int type; // Palette commune pour les même types : icone/objets/sorts/carte/effets attaque 
		  // numéro colonne sprite + case palettes.
bool affiche; // vrai si affiché
int screen; // numero ecran
int nSprite; // numero du Sprite
Position * p; // position ou le sprite est affiché
Taille taille;
};

#endif
