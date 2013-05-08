#ifndef PIECE_H
#define PIECE_H

#include "Position.h"
#include "Mob.h"

class Piece{
public:
Piece();
Piece(int x,int y,int lvl);

int getPosX();
int getPosY();
bool getVisite();
Piece * getVoisin(char direction);
int getNbVoisin();
bool passable(char direction);
void setPosX(int x1);
void setPosY(int y1);
void setVisite(bool x);
void setVoisin(char direction,Piece p);
void setVoisin(char direction,Piece * p);

void updateSprite();

int getCoinHG();
int getCoinBG();
int getCoinHD();
int getCoinBD();

Mob * getEnnemi();
bool est_envahie();
//void ajouterMonstre(Mob * monstre);
private:
Position position_piece;
bool visite; // 0 si non visit� - 1 si visit�

//struct Objet items[C_TAILLE_INV];

bool envahie;
Mob * ennemi;
Piece * n;
Piece * e;
Piece * s;
Piece * o;

int coinHG;
int coinBG;
int coinHD;
int coinBD;
};
#endif
