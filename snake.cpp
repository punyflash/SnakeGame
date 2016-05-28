#include "snake.h"
#include <iostream>

Snake::Snake(){
    growing = 3;
    speed = 100;
    moveDirection = Stop;

    head.rx()=13; head.ry()=10;
    tail.push_back(QPointF(13,10));
    tail.push_back(QPointF(13,11));
    tail.push_back(QPointF(13,12));
}

void Snake::paint(QPainter *painter){
    for(auto i=tail.begin(); i!=tail.end(); i++)
        painter->drawPixmap(250+30*(*i).x(),40+30*(*i).y(),30,30,QPixmap(":/res/Resourses/snakepiece.png"));
}

void Snake::grow(){
    QPointF newPiece = (*(tail.end()-1));
    move();
    tail.push_back(newPiece);
    ++growing;
    speed+=5;
}

void Snake::move(){
    int x, y, xs, ys;
    switch(moveDirection){
    case MoveUp: x=0; y=-1; break;
    case MoveDown: x=0; y=1; break;
    case MoveLeft: x=-1; y=0; break;
    case MoveRight: x=1; y=0; break;
    default: x=0; y=0; break;
    }
    if(moveDirection!=Stop){
        xs=head.x(); ys=head.y();
        head.rx()+=x; head.ry()+=y;
        (*tail.begin()).rx()+=x; (*tail.begin()).ry()+=y;
        auto i = tail.begin(); ++i;
        while(i!=tail.end()){
            x=(*i).x(); y=(*i).y();
            (*i).rx()=xs; (*i).ry()=ys;
            xs=x; ys=y;
            ++i;
        }
    }
}

bool Snake::isDead(){
    if(head.x()<0 || head.x()>25 || head.y()<0 || head.y()>19) return true;
    for(auto i=tail.begin()+1; i!=tail.end(); ++i){
        if((*i).x()==head.x() && (*i).y()==head.y()) return true;
    }
    return false;
}

const QPointF Snake::getHeadPos(){
    return head;
}

int Snake::getSpeed(){
    return speed;
}

int Snake::getLength(){
    return growing;
}

void Snake::setMoveDir(Direction dir){
    switch(dir){
    case MoveUp:
        if(moveDirection!=MoveUp && moveDirection!=MoveDown) moveDirection=MoveUp;
        break;
    case MoveDown:
        if(moveDirection!=MoveUp && moveDirection!=MoveDown && moveDirection!=Stop) moveDirection=MoveDown;
        break;
    case MoveLeft:
        if(moveDirection!=MoveLeft && moveDirection!=MoveRight) moveDirection=MoveLeft;
        break;
    case MoveRight:
        if(moveDirection!=MoveLeft && moveDirection!=MoveRight) moveDirection=MoveRight;
        break;
    default:break;
    }
}
