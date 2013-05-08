#include "Piece.h"
using namespace std;

Piece::Piece(){
Position position_piece= *(new Position());

visite=false;

ennemi=NULL;
envahie=false;

n=NULL;
e=NULL;
s=NULL;
o=NULL;
}

Piece::Piece(int x,int y,int lvl){
position_piece = *(new Position(x,y));
visite=false;
envahie=false;
ennemi=NULL;
int alea = PA_RandMax(10);

envahie = false;
if(alea==1){
    ennemi=(new Mob(lvl)); // LABYRINTHE . LVL (niveau de mobs)
    envahie=true;
}

n=NULL;
e=NULL;
s=NULL;
o=NULL;
}

int Piece::getPosX(){return this->position_piece.getX();}
int Piece::getPosY(){return this->position_piece.getY();}
bool Piece::getVisite(){return this->visite;}
bool Piece::est_envahie(){return envahie;}
Piece * Piece::getVoisin(char direction){
switch(direction){
	case 'n':
		return this->n;
		break;
	case 'e':
		return this->e;
		break;
	case 's':
		return this->s;
		break;
	case 'o':
		return this->o;
		break;
	default:
		return NULL;
		break;
	}
}

bool Piece::passable(char direction){
switch(direction){
	case 'n':
		if(this->n==NULL)
			return false;
		break;
	case 'e':
		if(this->e==NULL)
			return false;
		break;
	case 's':
		if(this->s==NULL)
			return false;
		break;
	case 'o':
		if(this->o==NULL)
			return false;
		break;
	default:
		return false;
		break;
	}
	return true;
}
int Piece::getNbVoisin(){
int nb=4;
if(this->getVoisin('n')==NULL)
	nb--;
if(this->getVoisin('e')==NULL)
	nb--;
if(this->getVoisin('s')==NULL)
	nb--;
if(this->getVoisin('o')==NULL)
	nb--;
return nb;
}

void Piece::setPosX(int x1){
this->position_piece.setX(x1);
}

void Piece::setPosY(int y1){
this->position_piece.setY(y1);
}

void Piece::setVoisin(char direction,Piece p){
switch(direction){
	case 'n':
		this->n=&p;
		break;
	case 'e':
		this->e=&p;
		break;
	case 's':
		this->s=&p;
		break;
	case 'o':
		this->o=&p;
		break;
	}
}

void Piece::setVoisin(char direction,Piece * p){
switch(direction){
	case 'n':
		this->n=p;
		p->s=this;
		break;
	case 'e':
		this->e=p;
		p->o=this;
		break;
	case 's':
		this->s=p;
		p->n=this;
		break;
	case 'o':
		this->o=p;
		p->e=this;
		break;
	}
}

void Piece::setVisite(bool x){
this->visite=x;
}

void Piece::updateSprite(){
int nbPortes = this->getNbVoisin();
switch(nbPortes){
		case 4:
			coinHG=2;
			coinHD=3;
			coinBG=4;
			coinBD=5;
			break;
		case 3:
			if(this->getVoisin('n')==NULL){
				coinHG=8;
				coinHD=8;
				coinBG=4;
				coinBD=5;
			}
			else if(this->getVoisin('e')==NULL){
				coinHG=2;
				coinHD=7;
				coinBG=4;
				coinBD=7;
			}
			else if(this->getVoisin('s')==NULL){
				coinHG=2;
				coinHD=3;
				coinBG=9;
				coinBD=9;
			}
			else if(this->getVoisin('o')==NULL){
				coinHG=6;
				coinHD=3;
				coinBG=6;
				coinBD=5;
			}
			break;
		case 2:
			if(this->getVoisin('n')==NULL && this->getVoisin('s')==NULL){
				coinHG=8;
				coinHD=8;
				coinBG=9;
				coinBD=9;
			}
			else if(this->getVoisin('e')==NULL && this->getVoisin('o')==NULL){
				coinHG=6;
				coinHD=7;
				coinBG=6;
				coinBD=7;
			}
			else{
				if(this->getVoisin('n')==NULL){
					if(this->getVoisin('e')==NULL){
						coinHG=8;
						coinHD=11;
						coinBG=4;
						coinBD=7;
					}
					else{
						coinHG=10;
						coinHD=8;
						coinBG=6;
						coinBD=5;
					}
				}
				else {
					if(this->getVoisin('e')==NULL){
						coinHG=2;
						coinHD=7;
						coinBG=9;
						coinBD=13;
					}
					else{
						coinHG=6;
						coinHD=3;
						coinBG=12;
						coinBD=9;
					}
				}
			}
		break;
		case 1:
			if(this->getVoisin('n')!=NULL){
				coinHG=6;
				coinHD=7;
				coinBG=12;
				coinBD=13;
			}
			else if(this->getVoisin('e')!=NULL){
				coinHG=10;
				coinHD=8;
				coinBG=12;
				coinBD=9;
			}
			else if(this->getVoisin('s')!=NULL){
				coinHG=10;
				coinHD=11;
				coinBG=6;
				coinBD=7;
			}
			else if(this->getVoisin('o')!=NULL){
				coinHG=8;
				coinHD=11;
				coinBG=9;
				coinBD=13;
			}
		break;
		}
}


int Piece::getCoinHG(){return this->coinHG;}
int Piece::getCoinHD(){return this->coinHD;}
int Piece::getCoinBG(){return this->coinBG;}
int Piece::getCoinBD(){return this->coinBD;}

Mob * Piece::getEnnemi(){return this->ennemi;}
