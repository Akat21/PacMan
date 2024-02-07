#ifndef Animator_H
#define Animator_H

#include <vector>
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Animator{
    private:
        //Timers
        sf::Time frameDuration;
        sf::Time animationTimer;
        sf::Clock frameClock;
        int currentFrame;

        sf::RectangleShape uvRect;
        std::vector<sf::Texture*> textures;

    public:
        Animator(std::vector <sf::Texture*> textures, sf::Time frameDuration, sf::RectangleShape shape);
        virtual ~Animator();

        sf::RectangleShape update();

};

#endif
