#ifndef Menu_H
#define Menu_H

#include <iostream>
#include <fstream>

#include "../Engine/Animator.h"
#include <SFML/Graphics.hpp>

enum difficulty {EASY, MEDIUM, HARD};

class Menu{
    private:
        //Menu init
        sf::Font font;
        sf::Text startText;
        sf::Text loadText;
        sf::Text difficultyText;
        sf::Text exitText;

        //Difficulty Menu init
        sf::Text easyText;
        sf::Text mediumText;
        sf::Text hardText;

        //Window
        sf::Event ev;

        //Game logic
        bool startGame;

        bool difficultyMenu;
        int choice;
        int difficultyChoice;
        difficulty diff;

        //Background Animation
        Animator<sf::Sprite> *animation;
        sf::Sprite background;

        bool isFile;
        bool loadGame;

        //Private Functions
        void initVariables(sf::RenderTarget* target);
        void initFont();
        void initText();
        void checkFile();


    public:
        //Setters and Getters
        bool getStartGame() const;
        void setStartGame(bool startGame);
        bool getLoadGame() const;
        void setLoadGame(bool loadGame);
        difficulty getDifficultyLevel() const;

        //Constructors and Destructors
        Menu(sf::RenderTarget* target);
        virtual ~Menu();

        //Functions
        void update(sf::RenderWindow* target);
        void renderBackground(sf::RenderTarget* target);
        void render(sf::RenderTarget* target);
};

#endif