#include "Labyrinthe.h"

//#include <stdlib.h>
#include <PA9.h>
#include "gfx/all_gfx.h"
using namespace std;

#define LARGEUR_LABYRINTHE 16
#define HAUTEUR_LABYRINTHE 12


Labyrinthe::Labyrinthe(){
hauteur = HAUTEUR_LABYRINTHE;
largeur = LARGEUR_LABYRINTHE;

niveau = (Piece **) malloc (sizeof(Piece*)*largeur);
for (int i=0;i<largeur;i++)
		niveau[i]=(Piece *)malloc (sizeof(Piece)*hauteur);

for(int i =0;i<largeur;i++)
	for (int j=0;j<hauteur;j++)
		niveau[i][j]=*(new Piece(i,j));

// on choisit une entrée et une sortie au hasard		
int randX = PA_RandMinMax(0,largeur-1);
int randY = PA_RandMinMax(0,hauteur-1);
entree=&niveau[randX][randY];
randX = PA_RandMinMax(0,largeur-1);
randY = PA_RandMinMax(0,hauteur-1);
sortie=&niveau[randX][randY];

this->modeler();
}

Labyrinthe::Labyrinthe(int larg, int haut){
hauteur=haut;
largeur=larg;

niveau = (Piece **) malloc (sizeof(Piece*)*larg);
for (int i=0;i<larg;i++)
		niveau[i]=(Piece *)malloc (sizeof(Piece)*haut);

for(int i =0;i<larg;i++)
	for (int j=0;j<haut;j++)
		niveau[i][j]=*(new Piece(i,j));

// on choisit une entrée et une sortie au hasard 
int randX = PA_RandMinMax(0,largeur-1);
int randY = PA_RandMinMax(0,hauteur-1);
entree=&niveau[randX][randY];
randX = PA_RandMinMax(0,largeur-1);
randY = PA_RandMinMax(0,hauteur-1);
sortie=&niveau[randX][randY];


this->modeler();
}

int Labyrinthe::getLargeur(){return this->largeur;}
int Labyrinthe::getHauteur(){return this->hauteur;}
Piece * Labyrinthe::getEntree(){return this->entree;}
Piece * Labyrinthe::getSortie(){return this->sortie;}
Piece ** Labyrinthe::getNiveau(){return this->niveau;}

void Labyrinthe::creer_chemin(int i,int j,char vient_de){
// DEBUT FONCTION

	this->niveau[i][j].setVisite(true);

	int xdroite=i+1;
	int xgauche=i-1;
	int yhaut=j-1;
	int ybas=j+1;

// ON FAIT ATTENTION A NE PAS SORTIR DU LABYRINTHE
	if(xdroite==this->getLargeur())
		xdroite=this->getLargeur()-1;
	if(xgauche<0)
		xgauche=0;
	if(yhaut<0)
		yhaut=0;
	if(ybas==this->getHauteur())
		ybas=this->getHauteur()-1;

// ON FAIT LA LIAISON AVEC LA CASE D'OU ON VIENT
switch(vient_de){
	case 'n':
		this->niveau[i][j].setVoisin('n',this->niveau[i][yhaut]);
		break;
	case 'e':
		this->niveau[i][j].setVoisin('e',this->niveau[xdroite][j]);
		break;
	case 's':
		this->niveau[i][j].setVoisin('s',this->niveau[i][ybas]);
		break;
	case 'o':
		this->niveau[i][j].setVoisin('o',this->niveau[xgauche][j]);
		break;
}
	
//TANT QUE LA CASE N'A PAS TOUS SES VOISINS
while(this->niveau[xdroite][j].getVisite()!=true || this->niveau[xgauche][j].getVisite()!=true || this->niveau[i][yhaut].getVisite()!=true || this->niveau[i][ybas].getVisite()!=true)
{
	int porte=PA_RandMax(3);
	// ON OUVRE UNE PORTE AU HASARD
	//PA_OutputText(1,i,j,"%d",porte);	
	switch(porte){
		case 0:
			if(this->niveau[i][yhaut].getVisite()!=true)
			{
				this->niveau[i][j].setVoisin('n',this->niveau[i][yhaut]);
				creer_chemin(i,yhaut,'s');
			}
			// fonction case nord
			break;
		case 1:
			if(this->niveau[xdroite][j].getVisite()!=true)
			{
				this->niveau[i][j].setVoisin('e',this->niveau[xdroite][j]);
				creer_chemin(xdroite,j,'o');
			}
			// fonction case est
			break;
		case 2:
			if(this->niveau[i][ybas].getVisite()!=true)
			{
				this->niveau[i][j].setVoisin('s',this->niveau[i][ybas]);
				creer_chemin(i,ybas,'n');
			}
			// fonction case sud
			break;
		case 3:
			if(this->niveau[xgauche][j].getVisite()!=true)
			{
				this->niveau[i][j].setVoisin('o',this->niveau[xgauche][j]);
				creer_chemin(xgauche,j,'e');
			}
			// fonction case ouest
			break;
	}
}
}

void Labyrinthe::modeler(){

	// on crée les couloirs principaux !
	this->creer_chemin(0,0,'e');
	this->niveau[1][0].setVoisin('o',this->niveau[0][0]);
	
	// on casse encore quelques murs !
	for(int i=0;i<(this->getLargeur()*this->getHauteur()/2);i++){
		
		// on choisit une salle au hasard 
		int salleX = PA_RandMinMax(1,this->getLargeur()-2);
		int salleY = PA_RandMinMax(1,this->getHauteur()-2);
		
		// on choisit un mur au hasard
		int porte = PA_RandMax(3);

		int xdroite=salleX+1;
		int xgauche=salleX-1;
		int yhaut=salleY-1;
		int ybas=salleY+1;
			
		// et on crée un lien !
		switch(porte){
		case 0:
			this->niveau[salleX][salleY].setVoisin('n',this->niveau[salleX][yhaut]);
			this->niveau[salleX][yhaut].setVoisin('s',this->niveau[salleX][salleY]);
			break;
		case 1:
			this->niveau[salleX][salleY].setVoisin('e',this->niveau[xdroite][salleY]);
			this->niveau[xdroite][salleY].setVoisin('o',this->niveau[salleX][salleY]);
			break;
		case 2:
			this->niveau[salleX][salleY].setVoisin('o',this->niveau[xgauche][salleY]);
			this->niveau[xgauche][salleY].setVoisin('e',this->niveau[salleX][salleY]);
			break;
		case 3:
			this->niveau[salleX][salleY].setVoisin('s',this->niveau[salleX][ybas]);
			this->niveau[salleX][ybas].setVoisin('n',this->niveau[salleX][salleY]);
			break;
		}
	}
	
	for(int i =0;i<largeur;i++)
		for (int j=0;j<hauteur;j++){
			niveau[i][j].setVisite(false);
			niveau[i][j].updateSprite();
			}
}
	
	// on ajoute des ennemis !


void Labyrinthe::affiche_minimap(int screen ,Position pCarte,Position pJoueur){
Position * tmp = new Position(0,0);

PA_LoadTiledBg(0,0,bg_cells);
		for (int x=0 ; x<32; x+=1)
			for(int y=0 ; y<24; y+=1)
				PA_SetMapTileAll(0,0,x,y,0);
			
	for (int i=0;i<this->getLargeur();i++){
		for (int j=0;j<this->getHauteur();j++){
			tmp->setX(i*2);
			tmp->setY(j*2);
			if(this->niveau[i][j].getVisite()==true){
				PA_SetMapTileAll(0,0,tmp->getX(),tmp->getY(),bg_cells_Map[this->niveau[i][j].getCoinHG()]);
				PA_SetMapTileAll(0,0,tmp->getX()+1,tmp->getY(),bg_cells_Map[this->niveau[i][j].getCoinHD()]);
				PA_SetMapTileAll(0,0,tmp->getX(),tmp->getY()+1,bg_cells_Map[this->niveau[i][j].getCoinBG()]);
				PA_SetMapTileAll(0,0,tmp->getX()+1,tmp->getY()+1,bg_cells_Map[this->niveau[i][j].getCoinBD()]);
			}
		}
	}
}
