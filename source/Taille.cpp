#include "Taille.h"
#include <malloc.h>

Taille::Taille(){
hauteur=0;
largeur=0;
}

Taille::Taille(int h,int l){
hauteur=h;
largeur=l;
}

int Taille::getHauteur(){return this->hauteur;}
int Taille::getLargeur(){return this->largeur;}

void Taille::setHauteur(int h){this->hauteur=h;}
void Taille::setLargeur(int l){this->largeur=l;}

int * Taille::tailleToInt(){
int * tmp= (int*)malloc(2*sizeof(int));
if(this->largeur==this->hauteur){
	tmp[0]=0;
	if(this->largeur==8){
		tmp[1]=0;
		}
	else if(this->largeur==16){
		tmp[1]=1;
		}
	else if(this->largeur==32){
		tmp[1]=2;
		}
	else if(this->largeur==64){
		tmp[1]=3;
	}
}
else if(this->largeur>this->hauteur){
	tmp[0]=1;
	if(this->largeur==16 && this->hauteur==8){
		tmp[1]=0;
		}
	else if(this->largeur==32 && this->hauteur==8){
		tmp[1]=1;
		}
	else if(this->largeur==32 && this->hauteur==16){
		tmp[1]=2;
		}
	else if(this->largeur==64 && this->hauteur==32){
		tmp[1]=3;
		}
}
else {
tmp[0]=2;
	if(this->hauteur==16){
		tmp[1]=0;
		}
	else if(this->largeur==8 && this->hauteur==32){
		tmp[1]=1;
		}
	else if(this->largeur==16 && this->hauteur==32){
		tmp[1]=2;
		}
	else if(this->hauteur==64){
		tmp[1]=3;
	}
}
return tmp;
}
