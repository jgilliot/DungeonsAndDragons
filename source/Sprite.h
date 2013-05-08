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
static int Sprite_touche(int sprite1,int sprite2);
static int Sprite_double_touche(int sprite1,int sprite2);

private:

int id; // num�ro de ligne
int type; // Palette commune pour les m�me types : icone/objets/sorts/carte/effets attaque 
		  // num�ro colonne sprite + case palettes.
bool affiche; // vrai si affich�
int screen; // numero ecran
int nSprite; // numero du Sprite
Position * p; // position ou le sprite est affich�
Taille taille;
};

#endif
