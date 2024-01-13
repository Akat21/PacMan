#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "Player.h"

class Enemy{
    private:
        //Enemy Shape
        sf::RectangleShape shape;
        Direction dir;
        sf::Vector2f movementSpeed;

        //Private Functions
        void randomDirection();
        void initVariables();
        void initShape();

    public:
        //Getters and Setters
        sf::RectangleShape getShape() const;
        
        //Constructors and Destructors
        Enemy();
        virtual ~Enemy();
        
        //Functions
        void update();
        void updateMovement();  
        void updateCollision(std::vector<std::vector<sf::RectangleShape>> collisionTiles);
        void render(sf::RenderTarget* target);
};

#endif