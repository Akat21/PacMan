#include "Coins.h"
#include "../Engine/TextureManager.h"

//Constructors and Destructors
Coins::Coins(float x, float y){
    //Coins position
    this->shape.setPosition(x, y);

    //Inits
    this->initVariables();
    this->initShape();

    //Animation
    std::vector <sf::Texture*> textures;
    textures.push_back(&TextureManager::getTexture("Textures/rosekane_0.png"));
    textures.push_back(&TextureManager::getTexture("Textures/rosekane_1.png"));
    textures.push_back(&TextureManager::getTexture("Textures/rosekane_2.png"));
    textures.push_back(&TextureManager::getTexture("Textures/rosekane_3.png"));
    textures.push_back(&TextureManager::getTexture("Textures/rosekane_4.png"));
    textures.push_back(&TextureManager::getTexture("Textures/rosekane_5.png"));
    textures.push_back(&TextureManager::getTexture("Textures/rosekane_6.png"));
    textures.push_back(&TextureManager::getTexture("Textures/rosekane_7.png"));

    this->animation = new Animator<sf::RectangleShape>(textures, sf::seconds(0.1), this->shape);
}

Coins::~Coins(){

}

//Private Functions
void Coins::initVariables(){
    /*
        @ return void

        Initializes the starting variables
    */
    this->collected = false;
}

void Coins::initShape(){
    /*
        @ return void

        Initializes the shape of the coin
    */
    
    this->shape.setFillColor(sf::Color::Yellow);
    this->shape.setSize(sf::Vector2f(20.f, 20.f));
    // this->shape.setTexture(&TextureManager::getTexture("Textures/rosekane_0.png"));
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
void Coins::updateTextures(){
    /*
        @ return void

        Updates the coin texture
    */

    if (!this->collected){
        this->shape.setTexture(&TextureManager::getTexture("Textures/rosekane_0.png"));
    }
}

void Coins::update(){
    /*
        @ return void

        Updates the coin position
    */
    this->shape = this->animation->update();
    if (this->collected){
        this->shape.setPosition(-100.f, -100.f);
    }
}

void Coins::render(sf::RenderTarget* target){
    /*
        @ return void

        Renders the coin to the screen
    */

    target->draw(this->shape);
}

