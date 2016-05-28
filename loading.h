#ifndef LOADING_H
#define LOADING_H

#include "state.h"
#include "gamewidget.h"
#include "menu.h"

class Loading :public State{

    Loading();
    ~Loading();
    int checkTime;
public:
    void paint(QPaintEvent*,GameWidget *,QPainter* ,QTimer*);
    void mouse_click(GameWidget* ,QMouseEvent*);
    void key_press(GameWidget*,QKeyEvent*);
    void key_release(GameWidget*,QKeyEvent*);
    static State *instance(){
        return new Loading();
    }
};

#endif // LOADING_H
