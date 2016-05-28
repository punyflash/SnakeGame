#ifndef STATE_H
#define STATE_H

#include "gamewidget.h"
#include "game.h"
#include <QObject>
#include <QtDebug>

class State: public QObject{
    Q_OBJECT
    public:
        virtual void paint(QPaintEvent *event,GameWidget *widget,QPainter* ,QTimer* timer ) = 0;
        virtual void mouse_click(GameWidget *,QMouseEvent*) = 0;
        virtual void key_press(GameWidget*,QKeyEvent*) =0;
        virtual void key_release(GameWidget*,QKeyEvent*) =0;
    protected:
        void setStage(GameWidget *widget, State *stage, std::string stateName){
            Game::addState(stateName);
            widget->setStage(stage);
        }
};

#endif // STATE_H
