#ifndef LABYRINTHE_H
#define LABYRINTHE_H
#include "Piece.h"
#include "Utils.h"

class Piece;

class Labyrinthe{
public:
Labyrinthe();
Labyrinthe(int larg, int haut);
int getLargeur();
int getHauteur();

Piece * getEntree();
Piece * getSortie();
Piece ** getNiveau();

void creer_chemin(int i,int j,char vient_de);
void affiche_minimap(int screen,Position pCarte,Position pJoueur);
void modeler();
private:
int largeur;
int hauteur;

Piece ** niveau;
Piece * entree;
Piece * sortie;
};

#endif
