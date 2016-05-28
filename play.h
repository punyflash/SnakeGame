#ifndef PLAY_H
#define PLAY_H

#include "menu.h"
#include "state.h"
#include "table.h"
#include "snake.h"
#include "food.h"
#include <QtGui>
#include <QtCore>


class Play: public State{
     Play();
     ~Play();
public:
    void paint(QPaintEvent*,GameWidget *,QPainter* ,QTimer*);
    void mouse_click(GameWidget* ,QMouseEvent*){}
    void key_press(GameWidget*,QKeyEvent*);
    void key_release(GameWidget*,QKeyEvent*){}
    static State *instance(){
            return new Play();
    }
private:
    bool isDirChanged;
    bool isGameEnd;
    int score;
    QString name;
    Snake snake;
    Food food;
};

#endif // PLAY_H
