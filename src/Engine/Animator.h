#ifndef Animator_H
#define Animator_H

#include <vector>
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

template <class T>
class Animator{
private:
    // Timers
    sf::Time frameDuration;
    sf::Time animationTimer;
    sf::Clock frameClock;
    int currentFrame;

    T uvRect;
    std::vector<sf::Texture*> textures;

public:
    Animator(std::vector<sf::Texture*> textures, sf::Time frameDuration, T shape);
    virtual ~Animator();

    T update();
};

template <>
class Animator<sf::RectangleShape>{
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

template <>
class Animator<sf::Sprite>{
    private:
        //Timers
        sf::Time frameDuration;
        sf::Time animationTimer;
        sf::Clock frameClock;
        int currentFrame;

        sf::Sprite uvRect;
        std::vector<sf::Texture*> textures;
        sf::RenderTarget* target;

    public:
        Animator(std::vector <sf::Texture*> textures, sf::Time frameDuration, sf::Sprite shape, sf::RenderTarget* target);
        virtual ~Animator();

        sf::Sprite update();

};

#endif
