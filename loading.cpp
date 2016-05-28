#include "loading.h"

Loading::Loading(){
    checkTime =0;
}
Loading::~Loading(){
}

void Loading::paint(QPaintEvent* , GameWidget* widget, QPainter* painter, QTimer* timer){
    checkTime++;
    if(checkTime==100) setStage(widget,Menu::instance(), "Menu");
    painter->drawPixmap(0,0,1280,720, QPixmap(":/res/Resourses/background.jpg"));
    painter->drawPixmap(280,175,720,370, QPixmap(":/res/Resourses/logo.png"));
    timer->start(20);
}

void Loading::mouse_click(GameWidget*, QMouseEvent*){

}

void Loading::key_press(GameWidget *, QKeyEvent *){
}

void Loading::key_release(GameWidget *, QKeyEvent *){
}
