#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

enum Direction {
    LEFT,
    RIGHT,
    UP, 
    DOWN,
    NONE
};

class Player{
    private:
        //Player Shape
        sf::RectangleShape shape;

        //Movement
        std::vector<Direction> dir;
        sf::Vector2f movementSpeed;
        sf::Event ev;

        //Private Functions
        void initVariables();
        void initShape();

    public:

        //Constructors and Destructors
        Player(float x = 0.f, float y = 0.f);
        virtual ~Player();

        //Getters and Setters
        sf::RectangleShape getShape() const;

        //Functions
        void update(sf::RenderWindow* target);
        void updateDirection(sf::RenderWindow* target);
        void updateMovement();
        void updateCollision(std::vector<std::vector<sf::RectangleShape>> collisionTiles);
        void render(sf::RenderTarget* target);
};

#endif
