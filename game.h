#ifndef GAME_H
#define GAME_H

#include "gamewidget.h"
#include "QFile"

class Game{
public:
     static Game& Instance(){
         static Game theSingleInstance;
         return theSingleInstance;
     }
     void run();
     static void addState(std::string stateOptions);
private:
     GameWidget *widget;
     Game();
     ~Game();
     Game(const Game&);
     Game& operator=(const Game&);
};

#endif // GAME_H
