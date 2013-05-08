#ifndef MOB_H
#define MOB_H
#include "Combattant.h"
#include "Variables.h"

class Mob : public Combattant {
public:
    Mob();
    Mob(int lvl);
    Mob(char * nom, char * race, char * classe, int lvl);

    // faire fonction pour créer mob aléatoirement.
};

#endif
