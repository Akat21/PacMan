#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <ctime>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "Player.h"
#include "Map.h"
#include "Enemy.h"

/*
    Game engine class
*/

class Game{
    private:
        //Window 
        sf::RenderWindow* window;
        sf::VideoMode videoMode;

        sf::Event ev;

        //Map
        Map map;

        //Player
        Player player;

        //Enemies
        std::vector<Enemy> enemies;

        //Game logic
        bool endGame;
        int points;
        int maxEnemies;

        //Mouse positions
        sf::Vector2i mousePosWindow;
        sf::Vector2f mousePosView;

        //Private Functions
        void initVariables();
        void initWindow();

    //Constructors and Destructors
    public:
        Game();
        virtual ~Game();
    
    //Getters and Setters
    const bool isRunning() const;

    //Functions
    void pollEvents();

    void updateEnemies();
    void updateCollision();
    void updateMousePositions();
    void update();

    void renderEnemies();
    void render();

};

#endif