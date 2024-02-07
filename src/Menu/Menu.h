#ifndef Menu_H
#define Menu_H

#include <iostream>
#include <fstream>

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

        bool isFile;
        bool loadGame;

        //Private Functions
        void initVariables();
        void initFont();
        void initText();
        void checkFile();


    public:
        //Setters and Getters
        bool getStartGame() const;
        bool getLoadGame() const;
        difficulty getDifficultyLevel() const;

        //Constructors and Destructors
        Menu();
        virtual ~Menu();

        //Functions
        void update(sf::RenderWindow* target);
        void render(sf::RenderTarget* target);
};

#endif