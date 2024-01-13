#include "Player.h"

//Private Functions
void Player::initVariables(){
    
}

void Player::initShape(){
    this->shape.setFillColor(sf::Color::Blue);
    this->shape.setSize(sf::Vector2f(20.f, 20.f));
    this->shape.setPosition(20.f, 20.f);
}

//Constructors and Destructors
Player::Player(float x, float y){
    
    //Movement
    this->shape.setPosition(x, y); //Player position
    this->movementSpeed.x = 0.f; //Player X axis movement speed
    this->movementSpeed.y = 0.f; //Player Y axis movement speed

    //Inits
    this->initVariables();
    this->initShape();
}

Player::~Player(){

}

//Getters and Setters

//Functions
void Player::updateDirection(){
    /*
        @ return void

        Updates direction of the player based on the key pressed
    */

    //X axis direction set
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        this->dir = LEFT;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        this->dir = RIGHT;
    }

    //Y axis direction set
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        this->dir = UP;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        this->dir = DOWN;
    }
}

void Player::updateMovement(){
    /*
        @ return void

        Updates movement of the player based on the direction
    */

    switch (this->dir){
        case LEFT:
            this->movementSpeed.x = -5.f; //Left
            this->movementSpeed.y = 0.f;
            break;
        case RIGHT:
            this->movementSpeed.x = 5.f; //Right
            this->movementSpeed.y = 0.f;
            break;
        case UP:
            this->movementSpeed.y = -5.f; //Up
            this->movementSpeed.x = 0.f;
            break;
        case DOWN:
            this->movementSpeed.y = 5.f; //Down
            this->movementSpeed.x = 0.f;
            break;
        default:
            break;
    }

    //Update position
    this->shape.move(this->movementSpeed);
}

void Player::updateCollision(std::vector<std::vector<sf::RectangleShape>> map){
    /*
        @ return void

        Checks for collision between the player and the surrounding blocks
    */

    for (auto row : map){
        for (auto block : row){
            //Check for collision
            if (this->shape.getGlobalBounds().intersects(block.getGlobalBounds())){
                switch(this->dir){
                    case LEFT:
                        this->shape.move(5.f, 0.f);
                        break;
                    case RIGHT:
                        this->shape.move(-5.f, 0.f);
                        break;
                    case UP:
                        this->shape.move(0.f, 5.f);
                        break;
                    case DOWN:
                        this->shape.move(0.f, -5.f);
                        break;
                    default:
                        break;
                }
            }
        }
    }
}

//Functions
void Player::update(sf::RenderTarget* target){

    //Update position of the player
    this->updateDirection();
    this->updateMovement();
}

void Player::render(sf::RenderTarget* target){

    //Render player
    target->draw(this->shape);
}