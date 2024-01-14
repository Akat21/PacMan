#include "Coins.h"

//Constructors and Destructors
Coins::Coins(float x, float y){
    //Coins position
    this->shape.setPosition(x, y);

    //Inits
    this->initVariables();
    this->initShape();
}

Coins::~Coins(){

}

//Private Functions
void Coins::initVariables(){
    this->collected = false;
}

void Coins::initShape(){
    /*
        @ return void

        Initializes the shape of the enemy
    */
    
    this->shape.setFillColor(sf::Color::Yellow);
    this->shape.setSize(sf::Vector2f(20.f, 20.f));
    // this->shape.setScale(sf::Vector2f(0.5f, 0.5f));
}

//Getters and Setters
sf::RectangleShape Coins::getShape() const{
    return this->shape;
}

void Coins::setCollected(bool collected){
    this->collected = collected;
}

void Coins::setShape(sf::RectangleShape shape){
    this->shape = shape;
}

//Functions
void Coins::update(){
    if (this->collected){
        this->shape.setPosition(-100.f, -100.f);
    }
}

void Coins::render(sf::RenderTarget* target){
    target->draw(this->shape);
}

