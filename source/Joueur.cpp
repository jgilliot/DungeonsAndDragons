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
PA_OutputText(1,10,3,"Race : %s",this->getRace());
//PA_OutputText(1,10,4,"Classe : %s",this->getClasse());
/*PA_OutputText(1,1,10,"Force : %d",this->getForce());
PA_OutputText(1,1,12,"Habilete : %d",this->getHabilete());
PA_OutputText(1,1,11,"Intelligence : %d",this->getIntelligence());
PA_OutputText(1,1,13,"Endurance : %d",this->getEndurance());
PA_OutputText(1,1,14,"Chance : %d",this->getChance());*/
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
