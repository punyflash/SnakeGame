#ifndef TABLE_H
#define TABLE_H

#include "state.h"
#include "menu.h"
#include <vector>

class Table : public State{
    Table();
public:
    void paint(QPaintEvent*,GameWidget *,QPainter* ,QTimer*);
    void mouse_click(GameWidget* ,QMouseEvent*){}
    void key_press(GameWidget*,QKeyEvent*);
    void key_release(GameWidget*,QKeyEvent*){}
    static State *instance(){
            return new Table();
    }
private:
    void sort(int, int);
    struct line{
        QString name;
        int score;
    };
    std::vector<line> rTable;
};

#endif // TABLE_H
