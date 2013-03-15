#ifndef BACKGROUND_H
#define BACKGROUND_H

using namespace std;

class Background{
public:
Background();
Background(int id);

int getId();
int getLayer();
int getScreen();
bool getAffiche();

void setId(int id);
void setLayer(int layer);
void setScreen(int screen);
void setAffiche(bool affiche);

void affichage(int screen,int layer);

private:
int id;
int layer;
int screen;
bool affiche;
};

#endif
