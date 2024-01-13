#include "Enemy.h"

//Private Functions
void Enemy::initVariables(){
    
}

void Enemy::initShape(){
    /*
        @ return void

        Initializes the shape of the enemy
    */

    this->shape.setFillColor(sf::Color::Red);
    this->shape.setSize(sf::Vector2f(50.f, 50.f));
    this->shape.setPosition(240.f, 200.f);
}

//Constructors and Destructors
Enemy::Enemy(){
    this->initVariables();
    this->initShape();
}

Enemy::~Enemy(){

}

//Functions
void Enemy::update(){
    
}

void Enemy::render(sf::RenderTarget* target){
    //Draws the enemy
    target->draw(this->shape);
}