#include "Joueur.h"
using namespace std;

char * Joueur::getNom(){return this->nom;}
char * Joueur::getRace(){return this->race;}

Sprite * Joueur::getIcone(){return this->icone;}

void Joueur::setNom(char * nom){this->nom=nom;}
void Joueur::setRace(char * race){this->race=race;}
void Joueur::setIcone(Sprite * sprite){this->icone=sprite;}

// NOM + RACE + CLASSE /! 

void Joueur::presentation(){
Position * p = new Position(10,10);
this->getIcone()->affichage(1,0,*p);
PA_OutputText(1,10,2,"Nom : %s",this->getNom());
PA_OutputText(1,10,4,"Race : %s",this->getRace());
}

Joueur::Joueur(){
this->setNom("Player");
this->setRace("Default");
}

Joueur::Joueur(char * nomP, char * raceP,Sprite * sP){
this->setNom(nomP);
this->setRace(raceP);
this->setIcone(sP);
}
