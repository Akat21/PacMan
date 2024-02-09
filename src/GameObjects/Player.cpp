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

    this->dir = NONE;
    this->preDir = NONE;
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

void Player::checkRectCreate(){
    /*
        @ return void

        Creates a rectangle to check for collision in the direction the player is moving
    */

    if (this->preDir == DOWN){
        this->checkRect.setSize(sf::Vector2f(12.f, 8.f));
        this->checkRect.setPosition(this->shape.getPosition().x + (this->shape.getSize().x - this->checkRect.getSize().x) / 2, this->shape.getPosition().y + this->shape.getSize().y);
        this->checkRect.setFillColor(sf::Color::Red);
    } else if (this->preDir == UP){
        this->checkRect.setSize(sf::Vector2f(12.f, 8.f));
        this->checkRect.setPosition(this->shape.getPosition().x + (this->shape.getSize().x - this->checkRect.getSize().x) / 2, this->shape.getPosition().y - this->checkRect.getSize().y);
        this->checkRect.setFillColor(sf::Color::Red);
    } else if (this->preDir == LEFT){
        this->checkRect.setSize(sf::Vector2f(8.f, 12.f));
        this->checkRect.setPosition(this->shape.getPosition().x - this->checkRect.getSize().x, this->shape.getPosition().y + (this->shape.getSize().y - this->checkRect.getSize().y) / 2);
        this->checkRect.setFillColor(sf::Color::Red);
    } else if (this->preDir == RIGHT){
        this->checkRect.setSize(sf::Vector2f(8.f, 12.f));
        this->checkRect.setPosition(this->shape.getPosition().x + this->shape.getSize().x, this->shape.getPosition().y + (this->shape.getSize().y - this->checkRect.getSize().y) / 2);
        this->checkRect.setFillColor(sf::Color::Red);
    } else {
        this->checkRect.setSize(sf::Vector2f(0.f, 0.f));
    }
}

void Player::updateDirection(std::vector<std::vector<sf::RectangleShape>> map){
    /*
        @ return void

        Updates direction of the player based on the key pressed
    */

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            this->preDir = LEFT; 
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        this->preDir = RIGHT;
    }

    //Y axis direction set
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        this->preDir = UP;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        this->preDir = DOWN;
    }


    this->checkRectCreate();

    bool collision = false;
    for (auto row : map){
        for (auto block : row){
            //Check for collision
            if (this->checkRect.getGlobalBounds().intersects(block.getGlobalBounds())){
                collision = true;
                break;
            }
        }
        if (collision) break;
    }

    if (!collision) {
        this->dir = this->preDir;
    }

}

void Player::updateMovement(std::vector<std::vector<sf::RectangleShape>> map){
    /*
        @ return void

        Updates movement of the player based on the direction
    */

    switch (this->dir){
        case LEFT:
            this->movementSpeed.x = -5.f; //Left
            this->movementSpeed.y = 0.f; //None
            break;
        case RIGHT:
            this->movementSpeed.x = 5.f; //Right
            this->movementSpeed.y = 0.f; //None
            break;
        case UP:
            this->movementSpeed.y = -5.f; //Up
            this->movementSpeed.x = 0.f; //None
            break;
        case DOWN:
            this->movementSpeed.y = 5.f; //Down
            this->movementSpeed.x = 0.f; //None
            break;
        default:
            this->movementSpeed.y = 0.f; //None
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
                    switch (this->dir){
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

void Player::updateTexture(){
    /*
        @ return void

        Updates the texture of the player
    */

    if (this->dir == LEFT)
        shape.setTexture(&TextureManager::getTexture("Textures/rosekane_55.png"));
    else if (this->dir == RIGHT)
        shape.setTexture(&TextureManager::getTexture("Textures/rosekane_71.png"));
    else if (this->dir == DOWN)
        shape.setTexture(&TextureManager::getTexture("Textures/rosekane_85.png"));
    else if (this->dir == UP)
        shape.setTexture(&TextureManager::getTexture("Textures/rosekane_103.png"));
    else if (this->dir == NONE)
        shape.setTexture(&TextureManager::getTexture("Textures/rosekane_85.png"));
}

//Functions
void Player::update(std::vector<std::vector<sf::RectangleShape>> map){
    /*
        @ return void

        Updates the player position
    */
    this->updateDirection(map);
    this->updateMovement(map);
    this->updateCollision(map);
    this->updateTexture();
}

void Player::render(sf::RenderTarget* target){
    /*
        @ return void

        Renders the player
    */

    target->draw(this->shape);
    target->draw(this->checkRect);
}