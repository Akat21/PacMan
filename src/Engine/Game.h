#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <ctime>
#include <string>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "../Menu/Menu.h"
#include "../GameObjects/Player.h"
#include "../GameObjects/Map.h"
#include "../GameObjects/Enemy.h"
#include "../GameObjects/Coins.h"

/*
    Game engine class
*/

class Game{
    private:
        //Window 
        sf::RenderWindow* window;
        sf::VideoMode videoMode;

        sf::Event ev;

        //Menu
        Menu* menu;

        //Map
        Map map;
        std::vector<std::vector<std::string>> stringMap;
        std::vector<std::vector<sf::RectangleShape>> coinsTiles;

        //Player
        Player *player;
        float playerX;
        float playerY;

        //Enemies
        std::vector<Enemy> enemies;

        //Coins
        std::vector<Coins> coins;
        int points;
        sf::Font font;
        sf::Text score;

        //Pause
        sf::Text helpText;
        sf::RectangleShape helpBox;

        //Game logic
        bool endGame;
        int maxEnemies;
        bool load;

        //Textures
        std::map<std::string, sf::Texture> textures;

        //Mouse positions
        sf::Vector2i mousePosWindow;
        sf::Vector2f mousePosView;

        //Pause
        bool pause;

        //Private Functions
        void initVariables();
        void initFonts();
        void initText();
        void initWindow();
        void initObjects();
        void deleteObjects();

    //Constructors and Destructors
    public:
        Game();
        virtual ~Game();
    
    //Getters and Setters
    const bool isRunning() const;

    //Functions
    void pollEvents();

    void saveGame();
    void loadGame();

    void updateEnemies();
    void updateCollision();
    void updateMousePositions();
    void UpdateGUI();
    void updateDifficulty();
    void update();

    void renderEnemies();
    void renderGUI(sf::RenderTarget* target);
    void render();

};

#endif