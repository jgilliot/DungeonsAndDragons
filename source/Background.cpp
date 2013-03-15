#ifndef BACKGROUND_CPP
#define BACKGROUND_CPP

#include "gfx/all_gfx.h"
#include <PA9.h>
#include "Background.h"

PAGfx_struct backgrounds[2]={(PAGfx_struct)bg_blanc,(PAGfx_struct)bg_cells};

Background::Background(){
id=0;
layer=-1;
screen=-1;
affiche=false;
}

Background::Background(int id){
this->id=id;
layer=-1;
screen=-1;
affiche=false;
}

int Background::getId(){return this->id;}
int Background::getLayer(){return this->layer;}
int Background::getScreen(){return this->screen;}
bool Background::getAffiche(){return this->affiche;}

void Background::setId(int id){this->id=id;}
void Background::setLayer(int layer){this->layer = layer;}
void Background::setScreen(int screen){this->screen = screen;}
void Background::setAffiche(bool affiche){this->affiche = affiche;}

void Background::affichage(int screen,int layer){
this->layer = layer;
this->screen = screen;
affiche = true;
PA_EasyBgLoad(screen,layer,bg_blanc);
}

// FAIRE UN STATIC RESET : reset(int screen) !!!

#endif
