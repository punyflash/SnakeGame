#ifndef SNAKE_H
#define SNAKE_H

#include <QGraphicsItem>
#include "gamewidget.h"
#include <QRectF>

enum Direction {
        Stop,
        MoveLeft,
        MoveRight,
        MoveUp,
        MoveDown
    };

class Snake {
public:
    Snake();
    void paint(QPainter*);
    void grow();
    void move();
    void setMoveDir(Direction);
    bool isDead();
    const QPointF getHeadPos();
    int getSpeed();
    int getLength();
private:
    QPointF head;
    int growing;
    int speed;
    QList<QPointF> tail;
    Direction moveDirection;
};

#endif // SNAKE_H
