#include "Game.h"


//Constructors and Destructors
Game::Game(){
    this->initVariables();
    this->initWindow();
}

Game::~Game(){
    delete this->window;
}


//Private Functions
void Game::initVariables(){
    this->window = nullptr;

    //Game logic
    this->endGame = false;
    this->points = 0;
    this->maxEnemies = 5;
}

void Game::initWindow(){
    //Set window resolution
    this->videoMode.width = 800;
    this->videoMode.height = 600;

    //Create window
    this->window = new sf::RenderWindow(this->videoMode, "Pac Man", sf::Style::Titlebar | sf::Style::Close);

    //Set FPS limit
    this->window->setFramerateLimit(60);
}

//Getters and Setters
const bool Game::isRunning() const{
    return this->window->isOpen();
}


//Functions
void Game::pollEvents(){
    /*
        @return void

        Polls SFML events
    */

    //Event polling
    while(this->window->pollEvent(this->ev)){
        switch(this->ev.type){
            
            //Close window by pressing X
            case sf::Event::Closed:
                this->window->close();
                break;

            //Close window by pressing ESC
            case sf::Event::KeyPressed:
                if(this->ev.key.code == sf::Keyboard::Escape)
                    this->window->close();
                break;
        }
    }
}

void Game::updateMousePositions(){
    /*
        @return void

        Updates the mouse positions
    */

    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Game::updateEnemies(){
    /*
        @return void

        Spawn enemies when the enemies amount on screen is smaller than the maxEnemies
    */ 

    //Enemy spawning
    if(this->enemies.size() < this->maxEnemies){
        this->enemies.push_back(Enemy());
    }
}

void Game::updateCollision(){
    /*
        @return void

        Checks for collision between the player and the enemies
    */

    
}

void Game::update(){
    /*
        @return void

        Updates the game logic
    */

    this->pollEvents();
    this->updateMousePositions();

    this->player.update(this->window);
    this->player.updateCollision(this->map.getCollisionTiles());

    // this->updateCollision();

    this->updateEnemies();

}

void Game::renderEnemies(){
    /*
        @return void

        Renders the enemies
    */

    //Rendering all the enemies
    for (auto e : this->enemies){
        e.render(this->window);
    }
}

void Game::render(){
    /*
        @return void

        Clear old frames, renders the new ones and displays them
    */
   
    this->window->clear(sf::Color::Black); //Clear old frame

    //Render game objects
    this->map.render(this->window);
    this->player.render(this->window);
    this->renderEnemies();

    this->window->display(); //Display new frame
}