#ifndef EXPLORATEUR_H
#define EXPLORATEUR_H

#include "Position.h"
#include "Labyrinthe.h"

class Labyrinthe;
class Piece;

class Explorateur{
public:
Explorateur();
Position getPos();
int getPosX();
int getPosY();

void setPosX(int x);
void setPosY(int y);
void setPos(Position p);

void se_deplace(Piece ** labyrinthe,char direction);
void affiche_sur_minimap();
void entrer_labyrinthe(Labyrinthe labyrinthe);
private:
Position posMap;
Sprite * icone_map;
};

#endif
