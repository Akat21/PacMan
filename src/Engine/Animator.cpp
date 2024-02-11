#include "Animator.h"

Animator<sf::RectangleShape>::Animator(std::vector<sf::Texture*> textures, sf::Time frameDuration, sf::RectangleShape shape){
    this->textures = textures;
    this->uvRect = shape;

    this->frameDuration = frameDuration;
    this->animationTimer = sf::Time::Zero;
    this->currentFrame = 0;
    this->frameClock.restart();
}

Animator<sf::RectangleShape>::~Animator() noexcept {

}

sf::RectangleShape Animator<sf::RectangleShape>::update(){
    this->animationTimer += this->frameClock.getElapsedTime();
    this->frameClock.restart();

    if (this->animationTimer >= this->frameDuration){
        this->animationTimer = sf::Time::Zero;
        this->currentFrame++;
        if (this->currentFrame > this->textures.size() - 1){
            this->currentFrame = 0;
        }
    }
    
    this->uvRect.setTexture(this->textures[this->currentFrame]);

    return this->uvRect;
}

Animator<sf::Sprite>::Animator(std::vector<sf::Texture*> textures, sf::Time frameDuration, sf::Sprite shape, sf::RenderTarget* target){
    this->textures = textures;
    this->uvRect = shape;
    this->target = target;

    this->frameDuration = frameDuration;
    this->animationTimer = sf::Time::Zero;
    this->currentFrame = 0;
    this->frameClock.restart();
}

Animator<sf::Sprite>::~Animator() noexcept {

}


sf::Sprite Animator<sf::Sprite>::update(){
    this->animationTimer += this->frameClock.getElapsedTime();
    this->frameClock.restart();

    if (this->animationTimer >= this->frameDuration){
        this->animationTimer = sf::Time::Zero;
        this->currentFrame++;
        if (this->currentFrame > this->textures.size() - 1){
            this->currentFrame = 0;
        }
    }


    this->uvRect.setTexture(*this->textures[this->currentFrame]);

    return this->uvRect;
}