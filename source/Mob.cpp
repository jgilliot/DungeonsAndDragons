#include "Mob.h"

Mob::Mob(char * nom, char * race, char * classe, int lvl){
this->setNom(nom);
this->setClasse(classe);
this->setLvl(lvl);
this->setXP(30*lvl);

if(strcmp(race,"Araignee")==0){
	this->setRace("Araignee");
	this->setForceBase(100+3*lvl);
	this->setHabileteBase(50+lvl);
	this->setIntelligenceBase(0+lvl);
	this->setEnduranceBase(50+2*lvl);
	this->setChanceBase(0+lvl);
	this->setIcone(&icones_mob[1]);
	}
else if(strcmp(race,"Gobelin")==0){
	this->setRace("Gobelin");
	this->setForceBase(5+2*lvl);
	this->setHabileteBase(50+5*lvl);
	this->setIntelligenceBase(10+lvl);
	this->setEnduranceBase(20+2*lvl);
	this->setChanceBase(30+4*lvl);
	this->setIcone(&icones_mob[2]);
}
else{
	this->setRace("Squelette");
	this->setForceBase(30+3*lvl);
	this->setHabileteBase(10+lvl);
	this->setIntelligenceBase(150+4*lvl);
	this->setEnduranceBase(40+2*lvl);
	this->setChanceBase(10);
	this->setIcone(&icones_mob[0]);
	}

if(strcmp(classe,"Archer")==0){
	this->addHabilete(50);
}
else if(strcmp(classe,"Mage")==0){
	this->addIntelligence(50);
}
else{ // Guerrier
	this->addForce(50);
}

this->setForce(this->getForceBase());
this->setHabilete(this->getHabileteBase());
this->setIntelligence(this->getIntelligenceBase());
this->setEndurance(this->getEnduranceBase());
this->setChance(this->getChanceBase());
this->setVie(this->getVieMax());
};
