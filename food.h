#ifndef FOOD_H
#define FOOD_H

#include "gamewidget.h"

class Food
{
public:
    Food();
    void paint(QPainter*);
    void newFood();
    int x();
    int y();
private:
    int posX, posY;
};

#endif // FOOD_H
