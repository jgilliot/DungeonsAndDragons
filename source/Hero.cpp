#include "Hero.h"
#include <string.h>

Hero * hero_principal; // Variable globale 

Hero::Hero(char * nom, char * classe, char * race) {
    this->setNom(nom);
    this->setClasse(classe);
    this->setLvl(1);
    this->setXP(0);

    if (strcmp(race, "Orc") == 0) {
        this->setRace("Orc");
        this->setForceBase(150);
        this->setHabileteBase(50);
        this->setIntelligenceBase(20);
        this->setEnduranceBase(50);
        this->setChanceBase(0);
        this->setIcone(&icones_race[0]);
    } else if (strcmp(race, "Elfe") == 0) {
        this->setRace("Elfe");
        this->setForceBase(10);
        this->setHabileteBase(150);
        this->setIntelligenceBase(10);
        this->setEnduranceBase(30);
        this->setChanceBase(50);
        this->setIcone(&icones_race[2]);
    } else {
        this->setRace("Humain");
        this->setForceBase(30);
        this->setHabileteBase(10);
        this->setIntelligenceBase(150);
        this->setEnduranceBase(40);
        this->setChanceBase(10);
        this->setIcone(&icones_race[1]);
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

void Hero::presentation() {
    Joueur::presentation();
    PA_OutputText(1, 10, 5, "Classe : %s", this->getClasse());
    PA_OutputText(1, 1, 10, "Force : %d", this->getForce());
    PA_OutputText(1, 1, 12, "Habilete : %d", this->getHabilete());
    PA_OutputText(1, 1, 11, "Intelligence : %d", this->getIntelligence());
    PA_OutputText(1, 1, 13, "Endurance : %d", this->getEndurance());
    PA_OutputText(1, 1, 14, "Chance : %d", this->getChance());
}
