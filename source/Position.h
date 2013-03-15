#ifndef POSITION_H
#define POSITION_H

class Position{
public:
Position();
Position(int x1 , int y1);

int getX();
int getY();

void setX(int x1);
void setY(int y1);
void setPos(int x1 , int y1);
private:
int x;
int y;
};
#endif
