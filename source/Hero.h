#ifndef HERO_H
#define HERO_H
#include "Combattant.h"
#include "Explorateur.h"
#include "Variables.h"

class Hero: public Combattant, public Explorateur{
public:
Hero(char * nom, char * classe , char * race);
};

extern Hero * hero_principal;

#endif
