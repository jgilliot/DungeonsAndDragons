#include "Effet.h"

Effet::Effet(){
this->nom = "null";
this->bonus_pvMax = 0;
this->bonus_pv = 0;
this->bonus_mana = 0;
this->bonus_manaMax = 0;
this->bonus_force = 0;
this->bonus_habilete = 0;
this->bonus_intelligence = 0;
this->bonus_endurance = 0;
this->bonus_chance = 0;
}

Effet::Effet(char * nom,int pvMax,int pv,int mana,int manaMax,int force,int habilete,int intelligence,int endurance, int chance){
this->nom = nom;
this->bonus_pvMax = pvMax;
this->bonus_pv = pv;
this->bonus_mana = mana;
this->bonus_manaMax = manaMax;
this->bonus_force = force;
this->bonus_habilete = habilete;
this->bonus_intelligence = intelligence;
this->bonus_endurance = endurance;
this->bonus_chance = chance;
}

int Effet::getBonus_pvMax(){return this->bonus_pvMax;}
int Effet::getBonus_pv(){return this->bonus_pv;}
int Effet::getBonus_mana(){return this->bonus_mana;}
int Effet::getBonus_manaMax(){return this->bonus_manaMax;}
int Effet::getBonus_force(){return this->bonus_force;}
int Effet::getBonus_habilete(){return this->bonus_habilete;}
int Effet::getBonus_intelligence(){return this->bonus_intelligence;}
int Effet::getBonus_endurance(){return this->bonus_endurance;}
int Effet::getBonus_chance(){return this->bonus_chance;}

