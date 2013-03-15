#include "Position.h"
using namespace std;

Position::Position(){
x=0;
y=0;}

Position::Position(int x1,int y1){
x=x1;
y=y1;
}

int Position::getX(){return this->x;}
int Position::getY(){return this->y;}

void Position::setX(int x1){this->x=x1;}
void Position::setY(int y1){this->y=y1;}
void Position::setPos(int x1,int y1){this->x=x1;this->y=y1;}
