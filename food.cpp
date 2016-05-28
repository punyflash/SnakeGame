#include "food.h"
#include <cstdlib>
#include <ctime>

Food::Food()
{
    srand(time(nullptr));
    posX=rand()%26;
    posY=rand()%20;
}

void Food::newFood(){
    srand(time(nullptr));
    posX=rand()%26;
    posY=rand()%20;
}

void Food::paint(QPainter *painter){
    painter->drawPixmap(250+30*x(),40+30*y(),30,30,QPixmap(":/res/Resourses/food.png"));
}

int Food::x(){
    return posX;
}

int Food::y(){
    return posY;
}
