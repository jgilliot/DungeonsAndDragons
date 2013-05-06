#ifndef SPRITE_CPP
#define SPRITE_CPP
#define DEFINE_GLOBALS
#include "Sprite.h"

#include "gfx/all_gfx.c"
#include "gfx/all_gfx.h"


using namespace std;

int Sprite::nbSprites=0;

void * palettes[5] = {(void*)icone_Pal,(void*)icone_Pal,(void*)icone_Pal,(void*)ui_Pal,(void*)classe_Pal};
void * joueurs_Sprite[3] = {(void*)icone_orc_Sprite,(void*)icone_humain_Sprite,(void*)icone_elfe_Sprite};
void * mobs_Sprite[3] = {(void*)icone_gobelin_Sprite,(void*)icone_araignee_Sprite,(void*)icone_squelette_Sprite};
void * objets_Sprite[1] = {(void*)icone_epee1_Sprite};
void * classes_Sprite[3] = {(void*)classe_guerrier_Sprite,(void*)classe_archer_Sprite,(void*)classe_mage_Sprite};
void * ui_Sprite[6] = {(void*)joueur_minimap_Sprite,(void*)bouton_attaque_Sprite,(void*)bouton_objet_Sprite,(void*)bouton_sort_Sprite,(void*)bouton_passer_Sprite,(void*)bouton_fuite_Sprite};

Sprite::Sprite(){
id = 0;
type = 0;
taille.setLargeur(0) ; 
taille.setHauteur(0);
screen=-1;
affiche=false;
nSprite=-1;
nbSprites++;
}

Sprite::Sprite(int type,int id,Taille t){
this->id = id;
this->type = type;
taille.setLargeur(t.getLargeur()); taille.setHauteur(t.getHauteur());
screen=-1;
affiche=false;
nSprite=-1;
}

int Sprite::getId(){return this->id;}
int Sprite::getType(){return this->type;}
bool Sprite::getAffiche(){return this->affiche;}
int Sprite::getScreen(){return this->screen;}
int Sprite::getNSprite(){return this->nSprite;}
Position * Sprite::getPosition(){return this->p;}
Taille Sprite::getTaille(){return this->taille;}

void Sprite::setId(int id){this->id=id;}
void Sprite::setType(int typ){this->type=typ;}

void Sprite::affichage(int screen ,int nSprite,Position p){

this->screen=screen;
this->p=&p;
this->nSprite=nSprite;
this->affiche=true;

	PA_LoadSpritePal(screen,nSprite,(void*)palettes[this->type]);
switch(type){
case 0:
	PA_CreateSprite(screen,nSprite,(void*)joueurs_Sprite[this->id],this->taille.tailleToInt()[0],this->taille.tailleToInt()[1],1,0,p.getX(),p.getY());
	break;
case 1:
	PA_CreateSprite(screen,nSprite,(void*)mobs_Sprite[this->id],this->taille.tailleToInt()[0],this->taille.tailleToInt()[1],1,0,p.getX(),p.getY());
	break;
case 3:
	PA_CreateSprite(screen,nSprite,(void*)ui_Sprite[this->id],this->taille.tailleToInt()[0],this->taille.tailleToInt()[1],1,0,p.getX(),p.getY());
	break;
case 4:
	PA_CreateSprite(screen,nSprite,(void*)classes_Sprite[this->id],this->taille.tailleToInt()[0],this->taille.tailleToInt()[1],1,0,p.getX(),p.getY());
	break;
case 5:
	PA_CreateSprite(screen,nSprite,(void*)objets_Sprite[this->id],this->taille.tailleToInt()[0],this->taille.tailleToInt()[1],1,0,p.getX(),p.getY());
}
}

void Sprite::setRotation(int angle){
if(this->affiche==true){
static int x;
x=this->getNSprite();
PA_SetSpriteRotEnable(this->getScreen(),// screen
		      this->getNSprite(),// sprite number
		      x);
			  
PA_SetRotsetNoZoom(this->getScreen(), //screen
			   x, // rotset
			   angle); // angle, from 0 to 511

x++;
}
}

void Sprite::bouger(Position p){
PA_SetSpriteXY(this->getScreen(),this->getNSprite(),p.getX(),p.getY());
}

// FAIRE UN STATIC RESET : reset(screen)
#endif
