#include "gamewidget.h"
#include "loading.h"
#include "game.h"

#include <QPainter>
#include <iostream>

GameWidget::GameWidget(QWidget *parent): QWidget(parent){
    setFixedSize(1280,720);
    stage = Loading::instance();
    timer = new QTimer(this);
    timer->stop();
    connect(GameWidget::timer, SIGNAL(timeout()), this, SLOT(update()));
}
GameWidget::~GameWidget(){
    delete timer;
}
void GameWidget::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    stage->paint(event, this, &painter, timer);
}
void GameWidget::mousePressEvent(QMouseEvent *event){
  stage->mouse_click(this,event);
}
void GameWidget::keyPressEvent(QKeyEvent *event){
   stage->key_press(this,event);
}

void GameWidget::keyReleaseEvent(QKeyEvent *event){
  stage->key_release(this,event);
}
