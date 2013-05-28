#ifndef INVENTAIRE_H
#define INVENTAIRE_H

#include "Objet.h"
#include "Position.h"

#define TAILLE_INVENTAIRE 6
class Inventaire{
public:
Inventaire();
int getTaille();
Objet getObjet(int position);
bool est_plein();
int getPremier_vide();
void ajouter_objet(Objet objet);
void supprimer_objet(int position);
void affichage(Position pos,int ecran,int nSprite);
private:
Objet inventaire[TAILLE_INVENTAIRE];
};
#endif
