#include "Combattant.h"
using namespace std;

int Combattant::getForceBase(){return this->forceBase;}
int Combattant::getHabileteBase(){return this->habileteBase;}
int Combattant::getIntelligenceBase(){return this->intelligenceBase;}
int Combattant::getEnduranceBase(){return this->enduranceBase;}
int Combattant::getChanceBase(){return this->chanceBase;}

int Combattant::getVie(){return this->vie;}
int Combattant::getForce(){return this->force;}
int Combattant::getHabilete(){return this->habilete;}
int Combattant::getIntelligence(){return this->intelligence;}
int Combattant::getEndurance(){return this->endurance;}
int Combattant::getChance(){return this->chance;}

char * Combattant::getClasse(){return this->classe;}
void Combattant::setClasse(char * classe){this->classe=classe;}

int Combattant::getDefense(){return (this->force/2);}
int Combattant::getArmure(int lvl){return int(this->lvl/lvl);}
int Combattant::getDegats(){
	if (strcmp(this->getClasse(),"Guerrier")==0)
		return (int)(this->getForce());
	if (strcmp(this->getClasse(),"Mage")==0)
		return (int)(this->getIntelligence());
	if (strcmp(this->getClasse(),"Archer")==0)
		return (int)(this->getHabilete());
	return 0;
}
int Combattant::getResistance(){return int(this->intelligence/2);}
int Combattant::getVieMax(){return int(this->endurance * 4 * (this->lvl+1));}
int Combattant::getCritique(int lvl){return int((this->chance * 5) / (lvl * 2));}

void Combattant::setForceBase(int For){this->forceBase=For;}
void Combattant::setHabileteBase(int hab){this->habileteBase=hab;}
void Combattant::setIntelligenceBase(int Int){this->intelligenceBase=Int;}
void Combattant::setEnduranceBase(int end){this->enduranceBase=end;}
void Combattant::setChanceBase(int luck){this->chanceBase=luck;}

void Combattant::setForce(int For){this->force=For;}
void Combattant::setHabilete(int hab){this->habilete=hab;}
void Combattant::setIntelligence(int Int){this->intelligence=Int;}
void Combattant::setEndurance(int end){this->endurance=end;}
void Combattant::setChance(int luck){this->chance=luck;}
void Combattant::setVie(int pv){this->vie=pv;}

void Combattant::setGold(int G){this->gold=G;}
void Combattant::setXP(int xp){this->xp=xp;}
void Combattant::setLvl(int lvl){this->lvl=lvl;}

void Combattant::addForce(int For){this->force+=For;}
void Combattant::addHabilete(int hab){this->habilete+=hab;}
void Combattant::addIntelligence(int Int){this->intelligence+=Int;}
void Combattant::addEndurance(int end){this->endurance+=end;}
void Combattant::addChance(int luck){this->chance+=luck;}

void Combattant::addGold(int G){this->gold+=G;}
void Combattant::addXP(int xp){this->xp+=xp;}
void Combattant::addLvl(int lvl){this->lvl+=lvl;}


Combattant::Combattant(){
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

Combattant::Combattant(char * nomP, char * raceP, char * classeP, int forceBaseP,  int habileteBaseP , int intelligenceBaseP, int enduranceBaseP , int chanceBaseP, Sprite * sP){
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

int Combattant::subit(int degats,char * classe){
	int degatsRecus=0;
	int esquive=0;
	if(strcmp(classe,"Mage")==0)
		degatsRecus= degats - (this->getResistance());
	if(strcmp(classe,"Guerrier")==0)
		degatsRecus= degats - (this->getDefense());
	if(strcmp(classe,"Archer")==0)
		degatsRecus= degats - (this->getHabilete()/2);
		
/*	if(strcmp(this->getClasse(),"Mage")==0)
	{
	
	} */
	if(strcmp(this->getClasse(),"Archer")==0 && strcmp(classe,"Mage")!=0){
		esquive=PA_RandMinMax(1,450);
		if(esquive<this->getHabilete())
			degatsRecus=0; // esquive
		}
	if(strcmp(this->getClasse(),"Guerrier")==0 && strcmp(classe,"Mage")!=0){
		esquive=PA_RandMinMax(1,600);
		if(esquive<this->getForce())
			degatsRecus=0; //parade
		}
	
	if(degatsRecus<0)
		degatsRecus=1;
	this->setVie((int)(this->getVie()-degatsRecus));
	return degatsRecus;
}

void Combattant::attaque(Combattant * ennemi){
	int degats=this->getDegats();
	int chance=PA_RandMinMax(1,200);
	PA_OutputText(0,1,8,"                    ");
	if(chance<this->getChance()){
		degats=degats*2;
		PA_OutputText(0,1,8,"Coup Critique ! x2");
		}
	int inflige=ennemi->subit(degats,this->getClasse());
	PA_OutputText(0,1,9,"degats: %d   ",degats);
	PA_OutputText(0,1,10,"degats infliges : %d   ",inflige);
	PA_OutputText(0,1,11,"        ");
	if(inflige==0){
		if(strcmp(ennemi->getClasse(),"Guerrier")==0){
			PA_OutputText(0,1,11,"Parade");}
		if(strcmp(ennemi->getClasse(),"Archer")==0){
			PA_OutputText(0,1,11,"Esquive");}
	}
	
}

// faire fonction coup critique qui renvoie booléen (50% max)

bool Combattant::est_mort(){
if (this->getVie()<=0)
	return true;
return false;
}

void Combattant::combattre(Combattant ennemi){
	reset_all();
	Position * p1 = new Position(10,10);
	Position * p2 = new Position(182,10);
	
	this->getIcone()->affichage(1,0,*p1);
	PA_OutputText(1,1,10,"%s",this->getRace());
	PA_OutputText(1,1,11,"%s",this->getClasse());
	PA_OutputText(1,1,12,"%03d/%03d",this->getVie(),this->getVieMax());
	PA_OutputText(1,1,14,"F:%d",this->getForce()); // faire une icone dans variables ! class Stats , static icone_Force , static ...
	PA_OutputText(1,1,15,"H:%d",this->getHabilete());
	PA_OutputText(1,1,16,"I:%d",this->getIntelligence());
	
	ennemi.getIcone()->affichage(1,1,*p2);
	PA_OutputText(1,23,10,"%s",ennemi.getRace());
	PA_OutputText(1,23,11,"%s",ennemi.getClasse());
	PA_OutputText(1,23,12,"%03d/%03d",ennemi.getVie(),ennemi.getVieMax());
	PA_OutputText(1,23,14,"F:%d",ennemi.getForce());
	PA_OutputText(1,23,15,"H:%d",ennemi.getHabilete());
	PA_OutputText(1,23,16,"I:%d",ennemi.getIntelligence());
	
	int tour=0;
	Combattant * attaquant;
	Combattant * victime;
	while(1){
		if(tour%2==0){
			attaquant=this;
			victime=&ennemi;
		}
		else{
			victime=this;
			attaquant=&ennemi;
		}
		
		attaquant->attaque(victime);
		
		PA_OutputText(1,23,12,"%03d/%03d",ennemi.getVie(),ennemi.getVieMax());
		PA_OutputText(1,1,12,"%03d/%03d",this->getVie(),this->getVieMax());
		
		if(victime->est_mort())
			break;
		sleep(2);
		tour++;
	}
	
	if(ennemi.est_mort())
	{
		PA_OutputText(0,10,3,"Bien joue");
	}
	else
		PA_OutputText(0,10,3,"Game Over.");
	
}
