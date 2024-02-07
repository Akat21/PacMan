#include "Player.h"
#include "../Engine/TextureManager.h"

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

//Private Functions
void Player::initVariables(){
    /*
        @ return void

        Initializes the starting variables
    */

    for(size_t i = 0; i < 2; i++) this->dir.push_back(NONE);
}

void Player::initShape(){
    /*
        @ return void

        Initializes the shape of the player
    */

    this->shape.setFillColor(sf::Color::Blue);
    this->shape.setSize(sf::Vector2f(20.f, 20.f));
    this->shape.setPosition(20.f, 20.f);
}

//Getters and Setters
sf::RectangleShape Player::getShape() const{
    return this->shape;
}


//Functions
void Player::updateDirection(){
    /*
        @ return void

        Updates direction of the player based on the key pressed
    */

    //X axis direction set
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        this->dir[0] = static_cast<Direction>(this->dir[1]);
        this->dir[1] = LEFT;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        this->dir[0] = static_cast<Direction>(this->dir[1]);
        this->dir[1] = RIGHT;
    }

    //Y axis direction set
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        this->dir[0] = static_cast<Direction>(this->dir[1]);
        this->dir[1] = UP;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        this->dir[0] = static_cast<Direction>(this->dir[1]);
        this->dir[1] = DOWN;
    }
}

void Player::updateMovement(){
    /*
        @ return void

        Updates movement of the player based on the direction
    */
    switch (this->dir[1]){
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
                switch (this->dir[1]){
                    case LEFT:
                        this->shape.move(5.f, 0.f);
                        this->dir[1] = static_cast<Direction>(this->dir[0]);
                        break;
                    case RIGHT:
                        this->shape.move(-5.f, 0.f);
                        this->dir[1] = static_cast<Direction>(this->dir[0]);
                        break;
                    case UP:
                        this->shape.move(0.f, 5.f);
                        this->dir[1] = static_cast<Direction>(this->dir[0]);
                        break;
                    case DOWN:
                        this->shape.move(0.f, -5.f);
                        this->dir[1] = static_cast<Direction>(this->dir[0]);
                        break;
                    default:
                        break;
                }
            }
        }
    }
}

void Player::updateTexture(){
    /*
        @ return void

        Updates the texture of the player
    */

    if (this->dir[1] == LEFT)
        shape.setTexture(&TextureManager::getTexture("Textures/rosekane_55.png"));
    else if (this->dir[1] == RIGHT)
        shape.setTexture(&TextureManager::getTexture("Textures/rosekane_71.png"));
    else if (this->dir[1] == DOWN)
        shape.setTexture(&TextureManager::getTexture("Textures/rosekane_85.png"));
    else if (this->dir[1] == UP)
        shape.setTexture(&TextureManager::getTexture("Textures/rosekane_103.png"));
    else if (this->dir[1] == NONE)
        shape.setTexture(&TextureManager::getTexture("Textures/rosekane_85.png"));
}

//Functions
void Player::update(std::vector<std::vector<sf::RectangleShape>> map){
    /*
        @ return void

        Updates the player position
    */

    this->updateDirection();
    this->updateMovement();
    this->updateCollision(map);
    this->updateTexture();
}

void Player::render(sf::RenderTarget* target){
    /*
        @ return void

        Renders the player
    */

    target->draw(this->shape);
}