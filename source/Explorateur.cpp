#include "Explorateur.h"

Explorateur::Explorateur(){
icone_map=new Sprite(3,0,*(new Taille(8,8)));
}

Position Explorateur::getPos(){return this->posMap;}
int Explorateur::getPosX(){return this->posMap.getX();}
int Explorateur::getPosY(){return this->posMap.getY();}

void Explorateur::setPosX(int x){this->posMap.setX(x);}
void Explorateur::setPosY(int y){this->posMap.setY(y);}
void Explorateur::setPos(Position p){this->posMap=p;}

void Explorateur::se_deplace(Piece ** labyrinthe,char direction){
	
	if(labyrinthe[this->getPosX()][this->getPosY()].passable(direction)){
		Position * p= NULL;
		switch(direction){
			case 'n':
				p = new Position(this->getPosX(),this->getPosY()-1);
				break;
			case 'e':
				p = new Position(this->getPosX()+1,this->getPosY());
				break;
			case 's':
				p = new Position(this->getPosX(),this->getPosY()+1);
				break;
			case 'o':
				p = new Position(this->getPosX()-1,this->getPosY());
				break;
			default:
				break;
		}
		this->setPos(*p);
		labyrinthe[p->getX()][p->getY()].setVisite(true);
	}
}

void Explorateur::affiche_sur_minimap(){
	static bool est_affiche=false;
	if(est_affiche==false){
		this->icone_map->affichage(0,0,*(new Position(this->getPosX()*16+4,this->getPosY()*16+4)));
		est_affiche=true;
		}
	this->icone_map->bouger(*(new Position(this->getPosX()*16+4,this->getPosY()*16+4)));
}

void Explorateur::entrer_labyrinthe(Labyrinthe labyrinthe){
	this->setPos(*(new Position(labyrinthe.getEntree()->getPosX(),labyrinthe.getEntree()->getPosY())));
	labyrinthe.getEntree()->setVisite(true);
}

