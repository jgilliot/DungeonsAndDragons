#ifndef COMBATTANT_H
#define COMBATTANT_H

#include "Joueur.h"
#include "Effet.h"
#include "Inventaire.h"
#include <math.h>

using namespace std;

class Combattant : public Joueur{
public:

Combattant(char * nomP, char * raceP, char * classeP, int forceBaseP,  int habileteBaseP , int intelligenceBaseP, int enduranceBaseP , int chanceBaseP, Sprite * sP);
Combattant();

char * getClasse();
void setClasse(char * classe);

//variables de base 
int getForceBase();
int getHabileteBase();
int getIntelligenceBase();
int getEnduranceBase();
int getChanceBase();
int getDefenseBase();
int getLvl();

//variables actuelles (objets + buffs/debuffs)
int getVie();
int getForce();
int getHabilete();
int getIntelligence();
int getEndurance();
int getChance();

//stats (sans variables)
int getDefense();
int getArmure(int lvl);
int getDegats();
int getResistance();
int getVieMax();
int getCritique(int lvl);

// variables de base
void setForceBase(int For);
void setHabileteBase(int hab);
void setIntelligenceBase(int Int);
void setEnduranceBase(int end);
void setChanceBase(int luck);

//variables actuelles
void setForce(int For);
void setHabilete(int hab);
void setIntelligence(int Int);
void setEndurance(int end);
void setChance(int luck);
void setVie(int pv);

void setGold(int G);

void setXP(int xp);
void setLvl(int lvl);

// Incr�ment variables
void addVie(int vie);
void addForce(int For);
void addHabilete(int hab);
void addIntelligence(int Int);
void addEndurance(int end);
void addChance(int luck);

void addGold(int G);
void addXP(int xp);
void addLvl(int lvl);

void addObjet(Objet objet);
// pour lvl up > lvl ++ > xp = 0 

// COMBAT

// renvoie les pv de l'adversaire
void attaque(Combattant * ennemi);
int subit(int degats,char * classe);
void sort(Effet * sort, Combattant * ennemi);
bool est_mort();

void combattre(Combattant ennemi);
void loot();

Inventaire inventaire;
private:

char * classe;

int forceBase; 
int habileteBase;
int intelligenceBase;
int enduranceBase;
int chanceBase;

int force; 
int habilete;
int intelligence;
int endurance;
int chance;
int vie;

int lvl;
int xp;

int gold;
};

#endif
