#include "Game.h"


//Constructors and Destructors
Game::Game(){
    this->initVariables();
    this->initWindow();
    this->initFonts();
    this->initText();
    this->player = new Player(this->playerX, this->playerY);
}

Game::~Game(){
    delete this->window;
}

//Private Functions
void Game::initVariables(){
    /*
        @return void

        Initializes the starting variables
    */

    this->window = nullptr;

    //Game logic
    this->playerX = 20.f;
    this->playerY = 20.f;
    this->pause = false;
    this->endGame = false;
    this->load = false;
    this->points = 0;
    this->stringMap = static_cast<std::vector<std::vector<std::string>>>(this->map.getMapString());
    this->coinsTiles = static_cast<std::vector<std::vector<sf::RectangleShape>>>(this->map.getCoinsTiles());
    this->menu = new Menu(this->window);
}

void Game::initWindow(){
    /*
        @return void

        Initializes the window
    */

    //Set window resolution
    this->videoMode.width = 780;
    this->videoMode.height = 800;

    //Create window
    this->window = new sf::RenderWindow(this->videoMode, "Pac Man", sf::Style::Titlebar | sf::Style::Close);

    //Pause box
    this->helpBox.setSize(sf::Vector2f(400.f, 400.f));
    this->helpBox.setFillColor(sf::Color(0, 0, 0, 150));
    this->helpBox.setPosition(200.f, 210.f);

    //Set FPS limit
    this->window->setFramerateLimit(60);
}

void Game::initFonts(){
    /*
        @return void

        Initializes the fonts
    */

    if(!this->font.loadFromFile("Fonts/advanced_pixel-7.ttf")){
        std::cout << "ERROR::GAME::INITFONTS::Failed to load font" << std::endl;
    }
}

void Game::initText(){
    /*
        @return void

        Initializes the text
    */

    //Init score text
    this->score.setFont(this->font);
    this->score.setCharacterSize(50);
    this->score.setPosition(40.f, 400.f);
    this->score.setFillColor(sf::Color::White);
    this->score.setString("Points: 0");

    //Init help text
    this->helpText.setFont(this->font);
    this->helpText.setCharacterSize(60);
    this->helpText.setPosition(205.f, 180.f);
    this->helpText.setFillColor(sf::Color::White);
    this->helpText.setString("Press F1 to unpause\n\nCollect Coins to \nget points\nAvoid the ghosts\n\nPress ESC to exit");
}

void Game::initObjects(){
    /*
        @return void

        Initializes the game objects
    */

    this->player = new Player(this->playerX, this->playerY);

    //Enemy spawning
    for (int i = 0; i < this->maxEnemies; i++) this->enemies.push_back(Enemy());
    
    //Coins spawning
    for(size_t i = 0; i < this->coinsTiles.size(); i++){
        for(size_t j = 0; j < this->coinsTiles[i].size(); j++){
            this->coins.push_back(Coins(this->coinsTiles[i][j].getPosition().x, this->coinsTiles[i][j].getPosition().y));
        }
    }

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
                if(this->ev.key.code == sf::Keyboard::Escape){
                    this->saveGame();
                    this->deleteObjects();
                }
                if(this->ev.key.code == sf::Keyboard::F1)
                    this->pause = !this->pause;
                break;
        }
    }
}

void Game::deleteObjects(){
    /*
        @return void

        Deletes the game objects
    */

    this->menu->setStartGame(false);
    this->menu->setLoadGame(false);

    this->pause = false;

    this->enemies.clear();

    this->coins.clear();

    this->points = 0;

    this->stringMap = static_cast<std::vector<std::vector<std::string>>>(this->map.getMapString());
    this->coinsTiles = static_cast<std::vector<std::vector<sf::RectangleShape>>>(this->map.getCoinsTiles());

    this->playerX = 20.f;
    this->playerY = 20.f;
}

void Game::saveGame(){
    /*
        @return void

        Saves the game
    */

    std::ofstream ofs("src/save.txt", std::ios::trunc);

    ofs << this->points << " " << this->player->getShape().getPosition().x << " " << this->player->getShape().getPosition().y << std::endl;
    for (auto &row : this->stringMap){
        for (auto &col : row){
            ofs << col;
        }
        ofs << std::endl;
    }
    ofs.close();
}

void Game::loadGame(){
    /*
        @return void

        Loads the game
    */

    std::ifstream ifs("src/save.txt");

    if(ifs.is_open()){

        std::string firstLine;
        if (std::getline(ifs, firstLine)) {
            std::istringstream iss(firstLine);
            if (!(iss >> this->points >> this->playerX >> this->playerY)) {
                std::cerr << "Error parsing line: " << firstLine << std::endl;
            }
        } else {
            std::cerr << "File is empty" << std::endl;
        }

        // Read map data
        this->stringMap.clear(); // Clear existing data

        std::string line;

        // Read the file line by line
        while (std::getline(ifs, line)) {
            std::vector<std::string> row;
            for (char c : line) {
                row.push_back(std::string(1, c)); // Convert char to string and push into row
            }
            stringMap.push_back(row);
        }

        this->coinsTiles.clear();
        sf::RectangleShape tile;
        tile.setSize(sf::Vector2f(20.f, 20.f));
        tile.setFillColor(sf::Color::Yellow);

        std::vector<sf::RectangleShape> coinsRow;

        for(size_t y = 0; y < this->stringMap.size(); y++){
            for(size_t x = 0; x < this->stringMap[y].size(); x++){
                if (this->stringMap[y][x] == "C"){
                    tile.setFillColor(sf::Color::Black);
                    tile.setPosition(x * 20.f, y * 20.f);
                    coinsRow.push_back(tile);
                }
            }
            this->coinsTiles.push_back(coinsRow);
            coinsRow.clear();
        }

        this->initObjects();

    }

    ifs.close();
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

    //Update enemies
    for (auto &e : this->enemies){
        e.update(this->map.getCollisionTiles());
    }

    //Update coins
    for(auto &c : this->coins){
        c.update();
    }
}

void Game::updateCollision(){
    /*
        @return void

        Checks for collision between the player and the enemies
    */

    for (auto &e : this->enemies){
        if (this->player->getShape().getGlobalBounds().intersects(e.getShape().getGlobalBounds())){
            this->endGame = true;
        }
    }

    for (auto &c : this->coins){
        if (this->player->getShape().getGlobalBounds().intersects(c.getShape().getGlobalBounds())){
            this->stringMap[static_cast<int>(c.getShape().getPosition().y / 20)][static_cast<int>(c.getShape().getPosition().x / 20)] = ' ';
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

    this->score.setString(ss.str());
}

void Game::updateDifficulty(){
    /*
        @return void

        Updates the difficulty of the game
    */

    if (this->menu->getDifficultyLevel() == EASY){
        this->maxEnemies = 5;
    }
    else if (this->menu->getDifficultyLevel() == MEDIUM){
        this->maxEnemies = 10;
    }
    else if (this->menu->getDifficultyLevel() == HARD){
        this->maxEnemies = 15;
    }
}

void Game::update(){
    /*
        @return void

        Updates the game logic
    */
   if(this->menu->getStartGame() == false){
        this->menu->update(this->window); //Update menu
        this->updateDifficulty();
        this->load = false;
    } else {
 
        //Load game
        if (this->load == false){
            if (this->menu->getLoadGame()) this->loadGame();
            else this->initObjects();
            this->load = true;
        }
        //Poll events
        this->pollEvents();

        //Game update
        if (this->pause == false){
            if(this->endGame == true){
                sf::Text endText;
                endText.setFont(this->font);
                endText.setCharacterSize(100);

                sf::Vector2u windowSize = this->window->getSize();
                endText.setPosition((windowSize.x - 350.f) / 2, (windowSize.y - 150.f) / 2);

                endText.setFillColor(sf::Color::White);
                endText.setString("Game Over\n");

                sf::RectangleShape endBox;
                endBox.setSize(sf::Vector2f(600.f, 200.f));
                endBox.setFillColor(sf::Color(0, 0, 0, 200));
                endBox.setPosition((windowSize.x - 600.f) / 2, (windowSize.y - 200.f) / 2);

                this->window->draw(endBox);
                this->window->draw(endText);
                this->window->display();

                sf::sleep(sf::milliseconds(2000));
                this->deleteObjects();
                this->endGame = false;
            }

            this->updateMousePositions();

            this->updateDifficulty();
            
            this->updateCollision();

            this->player->update(this->map.getCollisionTiles());

            this->updateEnemies();

            this->UpdateGUI();
        }
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

    target->draw(this->score);
    if (this->pause == true){
        target->draw(this->helpText);
    }
}

void Game::render(){
    /*
        @return void

        Clear old frames, renders the new ones and displays them
    */
   
    this->window->clear(sf::Color::Black); //Clear old frame

    //Render menu and game 
    if (this->menu->getStartGame() == false){
        //Render menu 
        this->menu->render(this->window);
    }
    else if (this->menu->getStartGame() == true){
        //Render game objects
        this->map.render(this->window);
        this->player->render(this->window);
        this->renderEnemies();

        //Render pause
        if (this->pause == true) this->window->draw(this->helpBox);

        //Render GUI
        this->renderGUI(this->window);
    }

    this->window->display(); //Display new frame

}