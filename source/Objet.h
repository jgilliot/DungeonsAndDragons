#ifndef OBJET_H
#define OBJET_H

#include "Sprite.h"
#include "Effet.h"

class Objet {
public:
    Objet();
    Objet(char * nom, char * classe, char * type, int lvl_min, int prix, bool consommable,Sprite * icone);
    Objet(char * nom, char * classe, char * type, int lvl_min, int prix, bool consommable,Effet effet, Sprite * icone);
    Effet getEffet();
    char * getClasse();
    char * getNom();
    char * getType();
    int getLvl_minimum();
    int getValeur();

    bool est_consommable();
    Sprite * get_icone();
private:
    char * nom;
    char * classe;
    char * type;
    Effet effet;
    Sprite * icone;

    int valeur;
    bool consommable;
    int lvl_min;
};
#endif
