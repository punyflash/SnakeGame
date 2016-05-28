#include "menu.h"

Menu::Menu(){
    button=0;
}

Menu::~Menu(){
    delete cursor;
}

void Menu::paint(QPaintEvent *, GameWidget *widget, QPainter *painter, QTimer *timer){
    painter->drawPixmap(0,0,1280,720, QPixmap(":/res/Resourses/background.jpg"));

    painter->drawPixmap(390,200,QPixmap(":/res/Resourses/start_s1"));
    painter->drawPixmap(390,310,QPixmap(":/res/Resourses/records_s1"));
    painter->drawPixmap(390,420,QPixmap(":/res/Resourses/exit_s1"));

    checkButton(widget);

    switch(button){
        case 1: painter->drawPixmap(390,200,QPixmap(":/res/Resourses/start_s2")); break;
        case 2: painter->drawPixmap(390,310,QPixmap(":/res/Resourses/records_s2")); break;
        case 3: painter->drawPixmap(390,420,QPixmap(":/res/Resourses/exit_s2")); break;
    default:break;
}
    timer->start(10);
}


void Menu::checkButton(GameWidget *widget){

    QPoint position = widget->mapFromGlobal(cursor->pos());
    if(position.ry() > 210 && position.ry() < 310 && position.rx() > 390 &&  position.rx()<890){
        button = 1; mouse = true;
    }
    else if(position.ry() > 310 && position.ry() < 410 && position.rx()>390 &&  position.rx()<890){
         button = 2;mouse = true;
    }
    else if(position.ry() > 410 && position.ry() < 510 && position.rx()>390 &&  position.rx()<890){
         button = 3;mouse = true;
    }
    else {
        mouse ? button = 0:mouse = false;
    }
}


void Menu::mouse_click(GameWidget *widget, QMouseEvent *){
    if(Qt::LeftButton){
        switch(button){
            case 1: setStage(widget,Play::instance(), "Play"); break;
            case 2: setStage(widget,Table::instance(), "Table"); break;
            case 3: widget->close(); break;
        }
    }
}


