#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Map{
    private:
        //Map init
        std::vector<std::vector<int>> map;
        std::vector<std::vector<sf::RectangleShape>> tilesMap;
        std::vector<std::vector<sf::RectangleShape>> collisionTiles;

        //Private Functions
        void initVariables();
        void initMap();

    public:
        //Constructors and Destructors
        Map();
        virtual ~Map();

        //Getters and Setters
        std::vector<std::vector<sf::RectangleShape>> getCollisionTiles() const;

        //Functions
        void createTiles();
        void update();
        void render(sf::RenderTarget* target);
};

#endif
