#ifndef Coins_H
#define Coins_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Coins{
    private:
        //Coins Shape
        sf::RectangleShape shape;

        bool collected;

        //Private Functions
        void initVariables();
        void initShape();

    public:
        //Getters and Setters
        sf::RectangleShape getShape() const;
        void setCollected(bool collected);
        void setShape(sf::RectangleShape shape);
        
        //Constructors and Destructors
        Coins(float x = 0.f, float y = 0.f);
        virtual ~Coins();
        
        //Functions
        void update();
        void render(sf::RenderTarget* target);
};

#endif