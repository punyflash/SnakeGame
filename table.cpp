#include "table.h"
#include <iostream>

Table::Table()
{
    QFile read("./records.txt");
    if (read.open(QIODevice::ReadOnly))
    {
        line readed;
        QString str, temp;
        QStringList lst;

        while(!read.atEnd()){
            str = read.readLine();
            lst = str.split(" ");

            readed.name = lst.at(0);
            temp = lst.at(1);
            readed.score = temp.toInt();

            rTable.push_back(readed);
        }
        read.close();
        std::cout << rTable.size() << std::endl;
        if(!rTable.empty()) sort(0,rTable.size()-1);
    }
}

void Table::paint(QPaintEvent *, GameWidget*, QPainter *painter, QTimer*){
    painter->drawPixmap(0,0,1280,720, QPixmap(":/res/Resourses/background.jpg"));
    painter->drawPixmap(250,40,780,600, QPixmap(":/res/Resourses/gamefield.png"));
    QFont font; font.setPixelSize(40); font.setBold(true); painter->setFont(font);
    painter->setPen(QColor(255,255,255));
    painter->drawText(250,40,780,100,Qt::AlignCenter,"Best scores:");
    font.setPixelSize(23); painter->setFont(font);
    if (!rTable.empty()) for(unsigned int i=0; i<=rTable.size()-1 && i<10; i++){
        painter->drawText(265,140+50*i,720,50,Qt::AlignLeft,QString::number(i+1));
        painter->drawText(300,140+50*i,710,50,Qt::AlignLeft,rTable.at(i).name);
        painter->drawText(270,140+50*i,740,50,Qt::AlignRight,QString::number(rTable.at(i).score));
    }
    painter->setPen(QColor(0,0,0)); font.setPixelSize(16); painter->setFont(font);
    painter->drawText(250,660,780,20,Qt::AlignCenter,"Press any key to back in menu");
}

void Table::key_press(GameWidget* widget, QKeyEvent*){
    setStage(widget,Menu::instance(), "Menu");
}

void Table::sort(int from, int to){
    for (int i = from; i < to; i++) {
        for (int j = from; j < to; j++) {
            if (rTable.at(j).score < rTable.at(j+1).score) {
                 line b = rTable.at(j);
                 rTable.at(j) = rTable.at(j+1);
                 rTable.at(j+1) = b;
            }
        }
    }
}

