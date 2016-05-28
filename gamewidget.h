#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <QtGui>
#include <math.h>

class State;
class GameWidget : public QWidget
{
    Q_OBJECT
    friend class State;
    QTimer *timer;
    void setStage(State* s){
        stage = s;
    }
public:
    explicit GameWidget(QWidget *parent = 0);
    ~GameWidget();

protected:
    State *stage;
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);
};

#endif // GAMEWIDGET_H
