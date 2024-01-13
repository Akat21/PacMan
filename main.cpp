#include "Game.h"

//"C:\\SFML-2.6.1\\include"
int main(){

    //Init srand
    std::srand(static_cast<unsigned>(time(NULL)));

    //Init Game Engine
    Game game;

    //Game Loop
    while(game.isRunning()){

        //Update
        game.update();

        //Render
        game.render();
    }

    //End of Application
    return 0;
}