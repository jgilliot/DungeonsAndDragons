#ifndef TAILLE_H
#define TAILLE_H

class Taille{
public:
Taille();
Taille(int h,int l);

int getHauteur();
int getLargeur();

void setHauteur(int h);
void setLargeur(int l);

int * tailleToInt();
private:
int hauteur;
int largeur;
};

#endif
