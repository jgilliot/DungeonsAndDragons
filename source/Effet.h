#ifndef EFFET_H
#define EFFET_H

class Effet{
public:
Effet();
Effet(char * nom,bool self,int tours,int pvMax,int pv,int mana,int manaMax,int force,int habilete,int intelligence,int endurance, int chance);

char * getNom();
bool getSelf();
int getNb_tours();
int getBonus_pvMax();
int getBonus_pv();
int getBonus_mana();
int getBonus_manaMax();
int getBonus_force();
int getBonus_habilete();
int getBonus_intelligence();
int getBonus_endurance();
int getBonus_chance();

private:
char * nom;
bool self;
int bonus_pvMax;
int bonus_pv;
int bonus_mana;
int bonus_manaMax;
int bonus_force;
int bonus_habilete;
int bonus_intelligence;
int bonus_endurance;
int bonus_chance;
int nb_tours;
// mettre un nombre de tours pour les effets.
};
#endif
