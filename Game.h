#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <ctime>
#include <string>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "Player.h"
#include "Map.h"
#include "Enemy.h"
#include "Coins.h"

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
        std::vector<std::vector<sf::RectangleShape>> coinsTiles;

        //Player
        Player player;

        //Enemies
        std::vector<Enemy> enemies;

        //Coins
        std::vector<Coins> coins;
        int points;
        sf::Font font;
        sf::Text text;

        //Game logic
        bool endGame;
        int maxEnemies;

        //Mouse positions
        sf::Vector2i mousePosWindow;
        sf::Vector2f mousePosView;

        //Private Functions
        void initVariables();
        void initFonts();
        void initText();
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
    void UpdateGUI();
    void update();

    void renderEnemies();
    void renderGUI(sf::RenderTarget* target);
    void render();

};

#endif