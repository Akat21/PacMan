#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Enemy{
    private:
        //Enemy Shape
        sf::RectangleShape shape;

        //Private Functions
        void initVariables();
        void initShape();

    public:
        //Constructors and Destructors
        Enemy();
        virtual ~Enemy();
        
        //Functions
        void update();
        void render(sf::RenderTarget* target);
};

#endif