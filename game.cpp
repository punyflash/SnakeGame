#include "game.h"

Game::Game(){
    widget=new GameWidget();
}
Game::~Game(){
    delete widget;
}

void Game::run(){
    widget->show();
}

void Game::addState(std::string stateOptions){
    QFile mFile("./logfile.txt");
    QTextStream out(&mFile);
    if (mFile.open(QIODevice::WriteOnly | QIODevice::Append)) {
        out<<QDateTime::currentDateTime().toString("yyyy-MM-d : hh-mm-ss").toStdString().c_str();
        out<<" state name: " << stateOptions.c_str() << "\r\n";
        mFile.close();
    };

}
