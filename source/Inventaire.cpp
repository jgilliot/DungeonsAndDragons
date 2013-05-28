#include "Inventaire.h"
#include <String.h>

Inventaire::Inventaire(){
	int i=0;
	for(i = 0;i<this->getTaille();i++){
		this->inventaire[i]=*(new Objet());
	}
};

int Inventaire::getTaille(){
	return TAILLE_INVENTAIRE;
}

Objet Inventaire::getObjet(int position){
	return this->inventaire[position];
}

bool Inventaire::est_plein(){
	int i=0;
	Objet * vide= new Objet();
	for(i = 0;i<this->getTaille();i++){
		if(strcmp(this->inventaire[i].getNom(),vide->getNom())==0)
			return false;
	}
	return true;
}

int Inventaire::getPremier_vide(){
	int i=0;
	Objet * vide= new Objet();
	for(i = 0;i<this->getTaille();i++){
		if(strcmp(this->inventaire[i].getNom(),vide->getNom())==0)
			return i;
	}
	return -1;
}
void Inventaire::ajouter_objet(Objet objet){
	if (this->est_plein()==false){
		this->inventaire[this->getPremier_vide()] = objet;
	}
	else{
		// faire fonction si inventaire plein
	}
}

void Inventaire::supprimer_objet(int position){
	if (position<this->getTaille()){
		this->inventaire[position]=*(new Objet());
	}
}

void Inventaire::affichage(Position pos,int ecran,int nSprite){
	int i=0;
        int n=nSprite;
	for(i=0;i<this->getTaille()/2;i++){
		this->inventaire[i].get_icone()->affichage(ecran,n+i,pos);
		pos.setX(pos.getX()+32);
	}
        pos.setY(pos.getY()+32);
        pos.setX(pos.getX()-32);
        for(i=this->getTaille()/2;i<this->getTaille();i++){
            this->inventaire[i].get_icone()->affichage(ecran,n+i,pos);
            pos.setX(pos.getX()-32);
        }
}
