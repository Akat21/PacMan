#include "Enemy.h"

//Private Functions
void Enemy::initVariables(){
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

    sf::Color color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1);
    this->shape.setFillColor(color);
}

void Enemy::randomDirection(){
    /*
        @ return void

        Randomizes the direction of the enemy
    */
   
    int random;
    if (this->dir == NONE) random = rand() % 4 + 1;
    if (this->dir == LEFT || this->dir == RIGHT) random = rand() % 2 + 3;
    if (this->dir == UP || this->dir == DOWN) random = rand() % 2 + 1;

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

Direction Enemy::getDir() const{
    return this->dir;
}

void Enemy::setShape(sf::RectangleShape shape){
    this->shape = shape;
}

//Constructors and Destructors
Enemy::Enemy(){
    this->initVariables();
    this->initShape();
}

Enemy::~Enemy(){

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

void Enemy::update(){
    this->updateMovement();
}

void Enemy::render(sf::RenderTarget* target){
    //Draws the enemy
    target->draw(this->shape);
}