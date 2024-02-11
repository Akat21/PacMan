#include "Enemy.h"
#include "../Engine/TextureManager.h"

//Constructors and Destructors
Enemy::Enemy(){
    this->initVariables();
    this->initShape();
}

Enemy::~Enemy(){

}

//Private Functions
void Enemy::initVariables(){
    /*
        @ return void

        Initializes the starting variables
    */

    this->dir = NONE;
    randomDirection();
}

void Enemy::initShape(){
    /*
        @ return void

        Initializes the shape of the enemy
    */

    this->shape.setFillColor(sf::Color::Red);
    this->shape.setSize(sf::Vector2f(18.f, 18.f));
    this->shape.setPosition(400.f, 330.f);

    //Randomizes the color of the enemy
    sf::Color color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1);
    this->shape.setFillColor(color);
}

void Enemy::randomDirection(){
    /*
        @ return void

        Randomizes the direction of the enemy
    */
   
    //Randomize direction after collision
    int random;
    if (this->dir == NONE) random = rand() % 4 + 1;
    if (this->dir == LEFT || this->dir == RIGHT) random = rand() % 2 + 3;
    if (this->dir == UP || this->dir == DOWN) random = rand() % 2 + 1;

    //Set enemy move direction
    switch(random){
        case 1:
            this->dir = LEFT;
            break;
        case 2:
            this->dir = RIGHT;
            break;
        case 3:
            this->dir = UP;
            break;
        case 4:
            this->dir = DOWN;
            break;
        default:
            this->dir = NONE;
            break;
    }
}

//Getters and Setters
sf::RectangleShape Enemy::getShape() const{
    return this->shape;
}

//Functions
void Enemy::updateMovement(){
    /*
        @ return void

        Updates the movement of the enemy
    */

    switch(this->dir){
        case LEFT:
            this->movementSpeed.x = -3.f;
            this->movementSpeed.y = 0.f;
            break;
        case RIGHT:
            this->movementSpeed.x = 3.f;
            this->movementSpeed.y = 0.f;
            break;
        case UP:
            this->movementSpeed.x = 0.f;
            this->movementSpeed.y = -3.f;
            break;
        case DOWN:
            this->movementSpeed.x = 0.f;
            this->movementSpeed.y = 3.f;
            break;
        default:
            this->movementSpeed.x = 0.f;
            this->movementSpeed.y = 0.f;
            break;
    }

    this->shape.move(this->movementSpeed);
}

void Enemy::updateCollision(std::vector<std::vector<sf::RectangleShape>> collisionTiles){
    /*
        @ return void

        Updates the collision of the enemy
    */

    //Collision
    for(size_t i = 0; i < collisionTiles.size(); i++){
        for(size_t j = 0; j < collisionTiles[i].size(); j++){
            if (collisionTiles[i][j].getGlobalBounds().intersects(this->shape.getGlobalBounds())){
                switch(this->dir){
                    case LEFT:
                        this->shape.move(3.f, 0.f);
                        break;
                    case RIGHT:
                        this->shape.move(-3.f, 0.f);
                        break;
                    case UP:
                        this->shape.move(0.f, 3.f);
                        break;
                    case DOWN:
                        this->shape.move(0.f, -3.f);
                        break;
                    default:
                        break;
                }
                this->randomDirection();
            }
        }
    }
}

void Enemy::updateTextures(){
    /*
        @ return void

        Updates the textures of the enemy
    */

    if (this->dir == LEFT)
        this->shape.setTexture(&TextureManager::getTexture("Textures/rosekane_21.png"));
    else if (this->dir == RIGHT)
        this->shape.setTexture(&TextureManager::getTexture("Textures/rosekane_22.png"));
    else if (this->dir == DOWN)
        this->shape.setTexture(&TextureManager::getTexture("Textures/rosekane_23.png"));
    else if (this->dir == UP)
        this->shape.setTexture(&TextureManager::getTexture("Textures/rosekane_24.png"));

}

void Enemy::update(std::vector<std::vector<sf::RectangleShape>> collisionTiles){
    /*
        @ return void

        Updates the enemy
    */

    this->updateMovement();
    this->updateCollision(collisionTiles);
    this->updateTextures();
}

void Enemy::render(sf::RenderTarget* target){
    /*
        @ return void

        Renders the enemy
    */

    target->draw(this->shape);
}