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
        sf::RectangleShape checkRect;

        //Movement
        Direction dir;
        Direction dirX;
        Direction dirY;
        Direction preDir;
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
        void checkRectCreate();
        void update(std::vector<std::vector<sf::RectangleShape>> map);
        void updateTexture();
        void updateDirection(std::vector<std::vector<sf::RectangleShape>> map);
        void updateMovement(std::vector<std::vector<sf::RectangleShape>> map);
        void updateCollision(std::vector<std::vector<sf::RectangleShape>> collisionTiles);
        void render(sf::RenderTarget* target);
};

#endif
