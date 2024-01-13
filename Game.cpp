#include "Game.h"


//Constructors and Destructors
Game::Game(){
    this->initVariables();
    this->initWindow();
    this->initFonts();
    this->initText();
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
    this->coinsTiles = static_cast<std::vector<std::vector<sf::RectangleShape>>>(this->map.getCoinsTiles());
}

void Game::initWindow(){
    //Set window resolution
    this->videoMode.width = 800;
    this->videoMode.height = 800;

    //Create window
    this->window = new sf::RenderWindow(this->videoMode, "Pac Man", sf::Style::Titlebar | sf::Style::Close);

    //Set FPS limit
    this->window->setFramerateLimit(60);
}

void Game::initFonts(){
    if(!this->font.loadFromFile("Fonts/advanced_pixel-7.ttf")){
        std::cout << "ERROR::GAME::INITFONTS::Failed to load font" << std::endl;
    }
}

void Game::initText(){
    this->text.setFont(this->font);
    this->text.setCharacterSize(50);
    this->text.setPosition(40.f, 400.f);
    this->text.setFillColor(sf::Color::White);
    this->text.setString("Points: 0");
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

    //Coins spawning
    for(size_t i = 0; i < this->coinsTiles.size(); i++){
        for(size_t j = 0; j < this->coinsTiles[i].size(); j++){
            this->coins.push_back(Coins(this->coinsTiles[i][j].getPosition().x, this->coinsTiles[i][j].getPosition().y));
            coinsTiles[i].erase(coinsTiles[i].begin() + j);
        }
    }

    //Update all enemies
    for (auto &e : this->enemies){
        e.update();
        e.updateCollision(this->map.getCollisionTiles());
    }
}

void Game::updateCollision(){
    /*
        @return void

        Checks for collision between the player and the enemies
    */

    for (auto &e : this->enemies){
        if (this->player.getShape().getGlobalBounds().intersects(e.getShape().getGlobalBounds())){
            this->endGame = true;
        }
    }

    for (auto &c : this->coins){
        if (this->player.getShape().getGlobalBounds().intersects(c.getShape().getGlobalBounds())){
            this->points += 10;
            c.setCollected(true);
        }
    }
    
}

void Game::UpdateGUI(){
    /*
        @return void

        Updates the GUI
    */

    std::stringstream ss;

    ss << "Points: " << this->points;

    this->text.setString(ss.str());
}

void Game::update(){
    /*
        @return void

        Updates the game logic
    */

   if(this->menu.getStartGame() == false){
        this->menu.update(this->window); //Update menu
    } else {
        if(this->endGame == true){
            this->window->close();
        }

        this->pollEvents();
        this->updateMousePositions();

        this->player.update(this->window);
        this->player.updateCollision(this->map.getCollisionTiles());

        for(auto &c : this->coins){
            c.update();
        }
        
        this->updateCollision();

        this->updateEnemies();

        this->UpdateGUI();
    }

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

    //Rendering all the coins
    for(auto c : this->coins){
        c.render(this->window);
    }
}

void Game::renderGUI(sf::RenderTarget* target){
    /*
        @return void

        Renders the GUI
    */

    target->draw(this->text);
}

void Game::render(){
    /*
        @return void

        Clear old frames, renders the new ones and displays them
    */
   
    this->window->clear(sf::Color::Black); //Clear old frame

    //Render menu and game 
    if (this->menu.getStartGame() == false){
        //Render menu 
        this->menu.render(this->window);
    }
    else if (this->menu.getStartGame() == true){
        //Render game objects
        this->map.render(this->window);
        this->player.render(this->window);
        this->renderEnemies();

        //Render GUI
        this->renderGUI(this->window);
    }

    this->window->display(); //Display new frame

}