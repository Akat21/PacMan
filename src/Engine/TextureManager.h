#ifndef TextureManager_H
#define TextureManager_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class TextureManager {
private:
    //Variables
    static std::map<std::string, sf::Texture> textures;

public:
    //Functions
    static sf::Texture& getTexture(const std::string& filename);
};

#endif