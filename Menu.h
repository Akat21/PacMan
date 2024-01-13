#ifndef Menu_H
#define Menu_H

#include <iostream>

#include <SFML/Graphics.hpp>

class Menu{
    private:
        //Menu init
        sf::Font font;
        sf::Text startText;
        sf::Text loadText;
        sf::Text exitText;

        sf::Event ev;

        //Game logic
        bool startGame;
        int choice;

        //Private Functions
        void initVariables();
        void initFont();
        void initText();


    public:
        //Setters and Getters
        bool getStartGame() const;

        //Constructors and Destructors
        Menu();
        virtual ~Menu();

        //Getters and Setters

        //Functions
        void update(sf::RenderWindow* target);
        void render(sf::RenderTarget* target);
};

#endif