#include "TextureManager.h"

std::map<std::string, sf::Texture> TextureManager::textures;

sf::Texture& TextureManager::getTexture(const std::string& filename) {
    /*
        @return sf::Texture&

        Loads and returns a texture from the given file
    */

    if (!textures.count(filename)) {
        textures[filename].loadFromFile(filename);
    }
    
    return textures[filename];
}