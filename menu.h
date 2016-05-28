#ifndef MENU_H
#define MENU_H

#include "state.h"
#include "play.h"

class Menu: public State{

    QCursor *cursor;
    int button;
    bool mouse;
    void checkButton(GameWidget *);
    Menu();
    ~Menu();
public:
    void paint(QPaintEvent*,GameWidget *,QPainter* ,QTimer*);
    void mouse_click(GameWidget* ,QMouseEvent*);
    void key_press(GameWidget*,QKeyEvent*){}
    void key_release(GameWidget*,QKeyEvent*){}
    static State *instance(){
            return new Menu();
    }
};

#endif // MENU_H
