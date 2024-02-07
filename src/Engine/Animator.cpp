#include "Animator.h"

Animator::Animator(std::vector<sf::Texture*> textures, sf::Time frameDuration, sf::RectangleShape shape){
    this->textures = textures;
    this->uvRect = shape;

    this->frameDuration = frameDuration;
    this->animationTimer = sf::Time::Zero;
    this->currentFrame = 0;
    this->frameClock.restart();
}

Animator::~Animator(){

}

sf::RectangleShape Animator::update(){
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