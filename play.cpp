#include "play.h"

Play::Play()
{
    score=0;
    isGameEnd=false;
    isDirChanged=false;
}
Play::~Play(){

}

void Play::paint(QPaintEvent *, GameWidget *, QPainter *painter, QTimer *timer){
    isDirChanged=false;
    painter->drawPixmap(0,0,1280,720, QPixmap(":/res/Resourses/background.jpg"));
    painter->drawPixmap(250,40,780,600, QPixmap(":/res/Resourses/gamefield.png"));
    painter->setPen(QColor(0,0,0));
    QFont font; font.setPixelSize(23);
    font.setBold(true);
    painter->setFont(font);
    painter->drawText(250,660,100,20,Qt::AlignCenter,"Score:");
    painter->drawText(350,660,100,20,Qt::AlignCenter,QString::number(score));

    if(!isGameEnd){
        food.paint(painter);
        snake.paint(painter);
        if(snake.getHeadPos()==QPointF(food.x(),food.y())){
            food.newFood();
            snake.grow();
            score+=10*snake.getLength();
        }
        else snake.move();
        if(snake.isDead()) {
            isGameEnd=true;
        }
    }
    else{
        painter->setPen(QColor(255,255,255));
        painter->drawText(250,40,780,100,Qt::AlignCenter,"Enter your name and press Enter:");
        font.setPixelSize(40); painter->setFont(font);
        painter->drawText(250,200,780,100,Qt::AlignCenter,name);
    }
    timer->start(20000/snake.getSpeed());
}

void Play::key_press(GameWidget* widget, QKeyEvent *event){
    if(!isGameEnd) {
    if(!isDirChanged) {
        switch(event->key()){
        case Qt::Key_Right: snake.setMoveDir(MoveRight); break;
        case Qt::Key_Left: snake.setMoveDir(MoveLeft); break;
        case Qt::Key_Down: snake.setMoveDir(MoveDown); break;
        case Qt::Key_Up: snake.setMoveDir(MoveUp); break;
        case Qt::Key_D: snake.setMoveDir(MoveRight); break;
        case Qt::Key_A: snake.setMoveDir(MoveLeft); break;
        case Qt::Key_S: snake.setMoveDir(MoveDown); break;
        case Qt::Key_W: snake.setMoveDir(MoveUp); break;
        default: break;
        } isDirChanged=true;
    }
    }
    else {
        switch(event->key()){
        case Qt::Key_Backspace: name.chop(1); break;
        case Qt::Key_Return: {
            QFile mFile("./records.txt");
            QTextStream out(&mFile);
            if(mFile.open(QIODevice::WriteOnly | QIODevice::Append)) {
                out << name << " " << score << "\r\n";
                mFile.close();
            }
            setStage(widget,Table::instance(), "Table");
        } break;
        default:
            QString input;
            input.append(QKeySequence(event->key()).toString());
            if(name.length()<10 && input.length()==1) name.append(QKeySequence(event->key()).toString());
            break;
        }
    }
}
