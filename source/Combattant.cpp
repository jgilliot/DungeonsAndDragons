#include "Combattant.h"
#include "Variables.h"
#include "Sprite.h"
#include "Utils.h"
#include "gfx/all_gfx.h"
#include <PA9.h>

using namespace std;

int Combattant::getForceBase() {
    return this->forceBase;
}

int Combattant::getHabileteBase() {
    return this->habileteBase;
}

int Combattant::getIntelligenceBase() {
    return this->intelligenceBase;
}

int Combattant::getEnduranceBase() {
    return this->enduranceBase;
}

int Combattant::getChanceBase() {
    return this->chanceBase;
}

int Combattant::getVie() {
    return this->vie;
}

int Combattant::getForce() {
    return this->force;
}

int Combattant::getHabilete() {
    return this->habilete;
}

int Combattant::getIntelligence() {
    return this->intelligence;
}

int Combattant::getEndurance() {
    return this->endurance;
}

int Combattant::getChance() {
    return this->chance;
}

int Combattant::getLvl() {
    return this->lvl;
}

char * Combattant::getClasse() {
    return this->classe;
}

void Combattant::setClasse(char * classe) {
    this->classe = classe;
}

int Combattant::getDefense() {
    return (this->force / 2);
}

int Combattant::getArmure(int lvl) {
    return int(this->lvl / lvl);
}

int Combattant::getDegats() {
    if (strcmp(this->getClasse(), "Guerrier") == 0)
        return (int) (this->getForce());
    if (strcmp(this->getClasse(), "Mage") == 0)
        return (int) (this->getIntelligence());
    if (strcmp(this->getClasse(), "Archer") == 0)
        return (int) (this->getHabilete());
    return 0;
}

int Combattant::getResistance() {
    return int(this->intelligence / 2);
}

int Combattant::getVieMax() {
    return int(this->endurance * 4 * (this->lvl + 1));
}

int Combattant::getCritique(int lvl) {
    return int((this->chance * 5) / (lvl * 2));
}

void Combattant::setForceBase(int For) {
    this->forceBase = For;
}

void Combattant::setHabileteBase(int hab) {
    this->habileteBase = hab;
}

void Combattant::setIntelligenceBase(int Int) {
    this->intelligenceBase = Int;
}

void Combattant::setEnduranceBase(int end) {
    this->enduranceBase = end;
}

void Combattant::setChanceBase(int luck) {
    this->chanceBase = luck;
}

void Combattant::setForce(int For) {
    this->force = For;
}

void Combattant::setHabilete(int hab) {
    this->habilete = hab;
}

void Combattant::setIntelligence(int Int) {
    this->intelligence = Int;
}

void Combattant::setEndurance(int end) {
    this->endurance = end;
}

void Combattant::setChance(int luck) {
    this->chance = luck;
}

void Combattant::setVie(int pv) {
    this->vie = pv;
}

void Combattant::setGold(int G) {
    this->gold = G;
}

void Combattant::setXP(int xp) {
    this->xp = xp;
}

void Combattant::setLvl(int lvl) {
    this->lvl = lvl;
}

void Combattant::addVie(int vie) {
    this->vie += vie;
}

void Combattant::addForce(int For) {
    this->force += For;
}

void Combattant::addHabilete(int hab) {
    this->habilete += hab;
}

void Combattant::addIntelligence(int Int) {
    this->intelligence += Int;
}

void Combattant::addEndurance(int end) {
    this->endurance += end;
}

void Combattant::addChance(int luck) {
    this->chance += luck;
}

void Combattant::addGold(int G) {
    this->gold += G;
}

void Combattant::addXP(int xp) {
    this->xp += xp;
}

void Combattant::addLvl(int lvl) {
    this->lvl += lvl;
}

Combattant::Combattant() {
    this->setNom("Player");
    this->setRace("Defaut");
    this->setClasse("Paysan");

    this->setForceBase(0);
    this->setHabileteBase(0);
    this->setIntelligenceBase(0);
    this->setEnduranceBase(0);
    this->setChanceBase(0);

    this->setVie(this->getVieMax());
    this->setForce(this->getForceBase());
    this->setHabilete(this->getHabileteBase());
    this->setIntelligence(this->getIntelligenceBase());
    this->setEndurance(this->getEnduranceBase());
    this->setChance(this->getChanceBase());

    this->setLvl(1);
    this->setXP(0);
}

Combattant::Combattant(char * nomP, char * raceP, char * classeP, int forceBaseP, int habileteBaseP, int intelligenceBaseP, int enduranceBaseP, int chanceBaseP, Sprite * sP) {
    this->setNom(nomP);
    this->setRace(raceP);
    this->setClasse(classeP);

    this->setForceBase(forceBaseP);
    this->setHabileteBase(habileteBaseP);
    this->setIntelligenceBase(intelligenceBaseP);
    this->setEnduranceBase(enduranceBaseP);
    this->setChanceBase(chanceBaseP);

    this->setIcone(sP);

    this->setVie(this->getVieMax());
    this->setForce(this->getForceBase());
    this->setHabilete(this->getHabileteBase());
    this->setIntelligence(this->getIntelligenceBase());
    this->setEndurance(this->getEnduranceBase());
    this->setChance(this->getChanceBase());

    this->setLvl(1);
    this->setXP(0);
}

int Combattant::subit(int degats, char * classe) {
    int degatsRecus = 0;
    int esquive = 0;
    if (strcmp(classe, "Mage") == 0)
        degatsRecus = degats - (this->getResistance());
    if (strcmp(classe, "Guerrier") == 0)
        degatsRecus = degats - (this->getDefense());
    if (strcmp(classe, "Archer") == 0)
        degatsRecus = degats - (this->getHabilete() / 2);

    /*	if(strcmp(this->getClasse(),"Mage")==0)
            {
	
            } */
    if (strcmp(this->getClasse(), "Archer") == 0 && strcmp(classe, "Mage") != 0) {
        esquive = PA_RandMinMax(1, 450);
        if (esquive<this->getHabilete())
            degatsRecus = 0; // esquive
    }
    if (strcmp(this->getClasse(), "Guerrier") == 0 && strcmp(classe, "Mage") != 0) {
        esquive = PA_RandMinMax(1, 600);
        if (esquive<this->getForce())
            degatsRecus = 0; //parade
    }

    if (degatsRecus < 0)
        degatsRecus = 1;
    this->setVie((int) (this->getVie() - degatsRecus));
    return degatsRecus;
}

void Combattant::attaque(Combattant * ennemi) {
    int degats = this->getDegats();
    int chance = PA_RandMinMax(1, 200);
    PA_OutputText(0, 20, 3, "%s                ", this->getNom());
    PA_OutputText(0, 14, 8, "                    ");
    if (chance<this->getChance()) {
        degats = degats * 2;
        PA_OutputText(0, 13, 8, "Coup Critique ! x2");
    }
    int inflige = ennemi->subit(degats, this->getClasse());
    //PA_OutputText(0,13,9,"degats: %d   ",degats);
    PA_OutputText(0, 15, 7, "Degats : %d   ", inflige);
    PA_OutputText(0, 15, 11, "        ");
    if (inflige == 0) {
        if (strcmp(ennemi->getClasse(), "Guerrier") == 0) {
            PA_OutputText(0, 15, 11, "Parade !");
        }
        if (strcmp(ennemi->getClasse(), "Archer") == 0) {
            PA_OutputText(0, 15, 11, "Esquive !");
        }
    }

}

void Combattant::sort(Effet * sort, Combattant * ennemi) {
    Combattant * j;
    j = this;
    if (sort->getSelf() != true) {
        j = ennemi;
    }
    j->addVie(sort->getBonus_pv());
    j->addForce(sort->getBonus_force());
    j->addHabilete(sort->getBonus_habilete());
    j->addIntelligence(sort->getBonus_intelligence());
    j->addEndurance(sort->getBonus_endurance());
    j->addChance(sort->getBonus_chance());
}
// faire fonction coup critique qui renvoie bool�en (50% max)

bool Combattant::est_mort() {
    if (this->getVie() <= 0)
        return true;
    return false;
}

void Combattant::combattre(Combattant ennemi) {
    reset_all();
    Position * p1 = new Position(30, 15);
    Position * p2 = new Position(160, 15);


    // UTILISER LA CLASSE BACKGROUND ?
    PA_EasyBgLoad(1, 1, bg_combat_top);
    PA_EasyBgLoad(0, 1, bg_combat_bot);

    Sprite * bouton_attaque = &icones_ui[0];
    Sprite * bouton_objet = &icones_ui[1];
    Sprite * bouton_sort = &icones_ui[2];
    Sprite * bouton_passer = &icones_ui[3];
    Sprite * bouton_fuite = &icones_ui[4];

    bouton_attaque->affichage(0, 0, *(new Position(20, 20)));
    bouton_sort->affichage(0, 1, *(new Position(20, 60)));
    bouton_objet->affichage(0, 2, *(new Position(20, 100)));
    bouton_passer->affichage(0, 3, *(new Position(115, 140)));
    bouton_fuite->affichage(0, 4, *(new Position(185, 140)));
    //s->affichage(0,0,*(new Position(20,60)));

    this->getIcone()->affichage(1, 0, *p1);
    PA_OutputText(1, 4, 10, "%s", this->getRace());
    PA_OutputText(1, 4, 11, "%s", this->getClasse());
    PA_OutputText(1, 4, 12, "%03d/%03d", this->getVie(), this->getVieMax());
    PA_OutputText(1, 4, 14, "F:%d", this->getForce()); // faire une icone dans variables ! class Stats , static icone_Force , static ...
    PA_OutputText(1, 4, 15, "H:%d", this->getHabilete());
    PA_OutputText(1, 4, 16, "I:%d", this->getIntelligence());
    PA_OutputText(1, 4, 18, "Lvl:%d", this->getLvl());

    ennemi.getIcone()->affichage(1, 1, *p2);
    PA_OutputText(1, 20, 10, "%s", ennemi.getRace());
    PA_OutputText(1, 20, 11, "%s", ennemi.getClasse());
    PA_OutputText(1, 20, 12, "%03d/%03d", ennemi.getVie(), ennemi.getVieMax());
    PA_OutputText(1, 20, 14, "F:%d", ennemi.getForce());
    PA_OutputText(1, 20, 15, "H:%d", ennemi.getHabilete());
    PA_OutputText(1, 20, 16, "I:%d", ennemi.getIntelligence());
    PA_OutputText(1, 20, 18, "Lvl:%d", ennemi.getLvl());

    int tour = 1;
    int temps_tour = 2;

    int sprite_touche = -1;

    while (1) {
        if (temps_tour != 0) {
            sprite_touche = -1;
            PA_OutputText(0,0,0,"%d",tour);
            sprite_touche = Sprite::Sprite_touche(0, 4);
            
            switch (sprite_touche) {
                case 0:
                    this->attaque(&ennemi);
                    break;
                case 1:
                    //fonction sort
                    break;
                case 2:
                    this->inventaire.affichage(*new Position(115, 20), 0, 10);
                    break;
                case 3:
                    temps_tour = 0;
                    break;
                case 4:
                    // fonction fuite (chance de quitter combat)
                    break;
            }
            sleep(temps_tour);
            ennemi.attaque(this);
        } else {
            this->attaque(&ennemi);
            ennemi.attaque(this);
        }
        PA_OutputText(1, 4, 12, "%03d/%03d", this->getVie(), this->getVieMax());
        PA_OutputText(1, 20, 12, "%03d/%03d", ennemi.getVie(), ennemi.getVieMax());

        tour++;
        if (ennemi.est_mort()) {
            //fonction continuer (+ loot)
            PA_OutputText(0, 10, 3, "Bien joue");
            this->loot();
            reset_all();
            break;
        }
        if (this->est_mort()) {
            //fonction game over
            PA_OutputText(0, 10, 3, "Game Over.");
            reset_all();
            break;
        }
    }
}

void Combattant::loot() {
    Objet * potion = new Objet("potion", "guerrier", "potion", 0, 50, true, NULL);
    this->inventaire.ajouter_objet(*potion);
}
