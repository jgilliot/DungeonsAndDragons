class Objet{
public:
virtual char * getClasse() =0;
virtual char * getCaracteristique()=0;

char * getNom();
char * getType();
int getLvlMinimum();
int getValeur();

void setNom(char * nom);
void setType(char * type);
void setLvlMinimum(int lvl);
void setValeur(int valeur);

private:
char * nom;
char * type;
int lvlminimum;
int valeur;
};
