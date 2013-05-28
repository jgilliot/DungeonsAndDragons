#include "Objet.h"
#include "Variables.h"

Objet::Objet(char * nom, char * classe, char * type, int lvl_min, int prix, bool consommable, Sprite * icone) {

    this->nom = nom;
    this->classe = classe;
    this->type = type;
    this->lvl_min = lvl_min;
    this->valeur = prix;

    this->icone = icone;
    this->consommable = consommable;
};

Objet::Objet(char * nom, char * classe, char * type, int lvl_min, int prix, bool consommable, Effet effet, Sprite * icone) {

    this->nom = nom;
    this->classe = classe;
    this->type = type;
    this->lvl_min = lvl_min;
    this->valeur = prix;

    this->effet = effet;
    this->icone = icone;
    this->consommable = consommable;
};

Objet::Objet() {
    this->nom = "rien";
    this->classe = "aucune";
    this->type = "vide";
    this->lvl_min = 0;
    this->valeur = 0;

    this->icone = &icones_arme[0];
    this->consommable = false;
};

char * Objet::getNom() {
    return this->nom;
}

char * Objet::getClasse() {
    return this->classe;
}

char * Objet::getType() {
    return this->type;
}

int Objet::getLvl_minimum() {
    return lvl_min;
}

int Objet::getValeur() {
    return this->valeur;
}

bool Objet::est_consommable() {
    return this->consommable;
}

Sprite * Objet::get_icone() {
    return this->icone;
}
