#include "Mob.h"
#include "Utils.h"
#include <PA9.h>

Mob::Mob(){
    Combattant::Combattant();
}

Mob::Mob(int lvl) {
    int alea;
    alea = PA_RandMax(4);
    char * nom = noms_mob[alea];
    alea = PA_RandMax(2);
    char * race = "Default";
    switch (alea) {
        case 0:
            race = "Squelette";
            break;
        case 1:
            race = "Gobelin";
            break;
        case 2:
            race = "Araignee";
            break;
    }
    alea = PA_RandMax(2);
    char * classe = "Default";
    switch (alea) {
        case 0:
            classe = "Guerrier";
            break;
        case 1:
            classe = "Archer";
            break;
        case 2:
            classe = "Mage";
            break;
    }
     this->setNom(nom);
    this->setClasse(classe);
    this->setLvl(lvl);
    this->setXP(30 * lvl);

    if (strcmp(race, "Squelette") == 0) {
        this->setRace("Squelette");
        this->setForceBase(50 + 3 * lvl);
        this->setHabileteBase(15 + lvl);
        this->setIntelligenceBase(0 + lvl);
        this->setEnduranceBase(20 + 2 * lvl);
        this->setChanceBase(0 + lvl);
        this->setIcone(&icones_mob[0]);
    } else if (strcmp(race, "Gobelin") == 0) {
        this->setRace("Gobelin");
        this->setForceBase(5 + 2 * lvl);
        this->setHabileteBase(50 + 5 * lvl);
        this->setIntelligenceBase(10 + lvl);
        this->setEnduranceBase(20 + 2 * lvl);
        this->setChanceBase(30 + 4 * lvl);
        this->setIcone(&icones_mob[2]);
    } else {
        this->setRace("Araignee");
        this->setForceBase(15 + 3 * lvl);
        this->setHabileteBase(10 + lvl);
        this->setIntelligenceBase(20 + 4 * lvl);
        this->setEnduranceBase(10 + 2 * lvl);
        this->setChanceBase(10);
        this->setIcone(&icones_mob[1]);
    }

    if (strcmp(classe, "Archer") == 0) {
        this->addHabilete(50);
    } else if (strcmp(classe, "Mage") == 0) {
        this->addIntelligence(50);
    } else { // Guerrier
        this->addForce(50);
    }

    this->setForce(this->getForceBase());
    this->setHabilete(this->getHabileteBase());
    this->setIntelligence(this->getIntelligenceBase());
    this->setEndurance(this->getEnduranceBase());
    this->setChance(this->getChanceBase());
    this->setVie(this->getVieMax());
};

Mob::Mob(char * nom, char * race, char * classe, int lvl) {
    this->setNom(nom);
    this->setClasse(classe);
    this->setLvl(lvl);
    this->setXP(30 * lvl);

    if (strcmp(race, "Squelette") == 0) {
        this->setRace("Squelette");
        this->setForceBase(50 + 3 * lvl);
        this->setHabileteBase(15 + lvl);
        this->setIntelligenceBase(0 + lvl);
        this->setEnduranceBase(20 + 2 * lvl);
        this->setChanceBase(0 + lvl);
        this->setIcone(&icones_mob[0]);
    } else if (strcmp(race, "Gobelin") == 0) {
        this->setRace("Gobelin");
        this->setForceBase(5 + 2 * lvl);
        this->setHabileteBase(50 + 5 * lvl);
        this->setIntelligenceBase(10 + lvl);
        this->setEnduranceBase(20 + 2 * lvl);
        this->setChanceBase(30 + 4 * lvl);
        this->setIcone(&icones_mob[2]);
    } else {
        this->setRace("Araignee");
        this->setForceBase(15 + 3 * lvl);
        this->setHabileteBase(10 + lvl);
        this->setIntelligenceBase(20 + 4 * lvl);
        this->setEnduranceBase(10 + 2 * lvl);
        this->setChanceBase(10);
        this->setIcone(&icones_mob[1]);
    }

    if (strcmp(classe, "Archer") == 0) {
        this->addHabilete(50);
    } else if (strcmp(classe, "Mage") == 0) {
        this->addIntelligence(50);
    } else { // Guerrier
        this->addForce(50);
    }

    this->setForce(this->getForceBase());
    this->setHabilete(this->getHabileteBase());
    this->setIntelligence(this->getIntelligenceBase());
    this->setEndurance(this->getEnduranceBase());
    this->setChance(this->getChanceBase());
    this->setVie(this->getVieMax());
};
