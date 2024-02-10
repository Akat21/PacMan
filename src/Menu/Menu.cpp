#include "Menu.h"
#include "../Engine/TextureManager.h"

//Private Functions
void Menu::initVariables(sf::RenderTarget* target){
    /*
        @return void

        Inits starting variables
    */

    this->startGame = false;
    this->loadGame = false;
    this->choice = 1;
    this->isFile = false;
    this->difficultyChoice = 1;
    this->difficultyMenu = false;
    this->diff = EASY;

    this->background = sf::Sprite(TextureManager::getTexture("Textures/bg-1.png"));
    
    std::vector <sf::Texture*> textures;
    textures.push_back(&TextureManager::getTexture("Textures/bg-1.png"));
    textures.push_back(&TextureManager::getTexture("Textures/bg-2.png"));
    textures.push_back(&TextureManager::getTexture("Textures/bg-3.png"));
    textures.push_back(&TextureManager::getTexture("Textures/bg-4.png"));
    textures.push_back(&TextureManager::getTexture("Textures/bg-5.png"));
    textures.push_back(&TextureManager::getTexture("Textures/bg-6.png"));
    textures.push_back(&TextureManager::getTexture("Textures/bg-7.png"));
    textures.push_back(&TextureManager::getTexture("Textures/bg-8.png"));
    textures.push_back(&TextureManager::getTexture("Textures/bg-9.png"));
    textures.push_back(&TextureManager::getTexture("Textures/bg-10.png"));
    textures.push_back(&TextureManager::getTexture("Textures/bg-11.png"));
    textures.push_back(&TextureManager::getTexture("Textures/bg-12.png"));
    textures.push_back(&TextureManager::getTexture("Textures/bg-13.png"));
    textures.push_back(&TextureManager::getTexture("Textures/bg-14.png"));
    textures.push_back(&TextureManager::getTexture("Textures/bg-15.png"));
    textures.push_back(&TextureManager::getTexture("Textures/bg-16.png"));


    this->animation = new Animator<sf::Sprite>(textures, sf::seconds(0.04), this->background, target);
}

void Menu::initFont(){
    /*
        @return void

        Inits the font
    */

    if (!this->font.loadFromFile("Fonts/advanced_pixel-7.ttf")){
        std::cout << "ERROR::MAINMENUSTATE::COULD NOT LOAD FONT" << std::endl;
    }
}

void Menu::initText(){
    /*
        @return void

        Inits the text objects, assign font, size, position, color and string
    */

    //Init start text
    this->startText.setFont(this->font);
    this->startText.setCharacterSize(60);
    this->startText.setPosition(40.f, 400.f);
    this->startText.setFillColor(sf::Color::White);
    this->startText.setString("NEW GAME");

    //Init load text
    this->loadText.setFont(this->font);
    this->loadText.setCharacterSize(60);
    this->loadText.setPosition(40.f, 500.f);
    this->loadText.setFillColor(sf::Color::White);
    this->loadText.setString("LOAD");

    //Init difficulty text
    this->difficultyText.setFont(this->font);
    this->difficultyText.setCharacterSize(60);
    this->difficultyText.setPosition(40.f, 600.f);
    this->difficultyText.setFillColor(sf::Color::White);
    this->difficultyText.setString("EASY");

    //Init exit text
    this->exitText.setFont(this->font);
    this->exitText.setCharacterSize(60);
    this->exitText.setPosition(40.f, 700.f);
    this->exitText.setFillColor(sf::Color::White);
    this->exitText.setString("EXIT");

    //Init easy text
    this->easyText.setFont(this->font);
    this->easyText.setCharacterSize(60);
    this->easyText.setPosition(40.f, 400.f);
    this->easyText.setFillColor(sf::Color::White);
    this->easyText.setString("EASY");

    //Init medium text
    this->mediumText.setFont(this->font);
    this->mediumText.setCharacterSize(60);
    this->mediumText.setPosition(40.f, 500.f);
    this->mediumText.setFillColor(sf::Color::White);
    this->mediumText.setString("MEDIUM");

    //Init hard text
    this->hardText.setFont(this->font);
    this->hardText.setCharacterSize(60);
    this->hardText.setPosition(40.f, 600.f);
    this->hardText.setFillColor(sf::Color::White);
    this->hardText.setString("HARD");
}

void Menu::checkFile(){
    /*
        @return void

        Checks if the file exists and set isFile to true if it does
    */
    std::ifstream inFile;
    if (std::ifstream inFile("src/save.txt"); inFile) {
        this->isFile = true;
    }
}

//Constructors and Destructors
Menu::Menu(sf::RenderTarget* target){
    this->initVariables(target);
    this->initFont();
    this->initText();
}

Menu::~Menu(){

}

//Getters and Setters
bool Menu::getStartGame() const{
    return this->startGame;
}

void Menu::setStartGame(bool startGame){
    this->startGame = startGame;
}

bool Menu::getLoadGame() const{
    return this->loadGame;
}

void Menu::setLoadGame(bool loadGame){
    this->loadGame = loadGame;
}

difficulty Menu::getDifficultyLevel() const{
    return this->diff;
}

//Functions
void Menu::update(sf::RenderWindow* target){
    /*
        @return void

        Listens for events and updates the menu based on the events (key presses)
    */


    this->checkFile();
    if (this->animation != nullptr) this->background = this->animation->update();

    //Event polling
    while(target->pollEvent(this->ev)){
        switch(this->ev.type){

            //check if window is closed
            case sf::Event::Closed:
                target->close();
                break;

            //check if key is released
            case sf::Event::KeyReleased:
                
                //Up Key Handling
                if(this->ev.key.code == sf::Keyboard::Up){

                    //Choose menu option
                    if (difficultyMenu == false){
                        if(this->choice == 1){
                            this->choice = 4;
                        }
                        else{
                            this->choice--;
                        }
                    }

                    //Choose difficulty option
                    if(this->difficultyMenu == true){
                        if(this->difficultyChoice == 1){
                            this->difficultyChoice = 3;
                        }
                        else{
                            this->difficultyChoice--;
                        }
                    }

                }

                //Down Key Handling
                if(this->ev.key.code == sf::Keyboard::Down){

                    //Choose menu option
                    if (difficultyMenu == false){
                        if (this->choice == 4){
                            this->choice = 1;
                        }
                        else {
                            this->choice++;
                        }
                    }

                    //Choose difficulty
                    if(this->difficultyMenu == true){
                        if(this->difficultyChoice == 3){
                            this->difficultyChoice = 1;
                        }
                        else{
                            this->difficultyChoice++;
                        }
                    }
                }

                //Enter Key Handling
                if(this->ev.key.code == sf::Keyboard::Enter){
                    
                    //Handle menu choices
                    if (difficultyMenu == false){

                        //Start game choice handling
                        if(this->choice == 1){
                            this->startGame = true;
                        }

                        //Load game choice handling
                        if(this->choice == 2){
                            if(this->isFile == true){
                                this->loadGame = true;
                                this->startGame = true;
                            }
                        }

                        //Difficulty choice handling
                        if(this->choice == 3){
                            this->difficultyMenu = true;
                        }

                        //Exit choice handling
                        if(this->choice == 4){
                            target->close();
                        }
                    }

                    //Handle difficulty menu choices 
                    else if(this->difficultyMenu == true){

                        //Set difficuly to Easy
                        if(this->difficultyChoice == 1){
                            this->diff = EASY;
                            this->difficultyText.setString("EASY");
                            this->difficultyMenu = false;  
                        }

                        //Set difficuly to Medium
                        if(this->difficultyChoice == 2){
                            this->diff = MEDIUM;
                            this->difficultyText.setString("MEDIUM");
                            this->difficultyMenu = false;  
                        }

                        //Set difficuly to Hard
                        if(this->difficultyChoice == 3){
                            this->diff = HARD;
                            this->difficultyText.setString("HARD");
                            this->difficultyMenu = false;  
                        }
                    }
                }
                break;
            default:
                break;
        }
    }
    
    //Menu text color change (highlighting the chosen option)
    if (this->choice == 1){
        this->startText.setFillColor(sf::Color::Red);
        if(this->isFile) this->loadText.setFillColor(sf::Color::White); else this->loadText.setFillColor(sf::Color(150, 150, 150));
        this->difficultyText.setFillColor(sf::Color::White);
        this->exitText.setFillColor(sf::Color::White);
    }
    if (this->choice == 2){
        this->startText.setFillColor(sf::Color::White);
        this->loadText.setFillColor(sf::Color::Red);
        this->difficultyText.setFillColor(sf::Color::White);
        this->exitText.setFillColor(sf::Color::White);
    }
    if (this->choice == 3){
        this->startText.setFillColor(sf::Color::White);
        if(this->isFile) this->loadText.setFillColor(sf::Color::White); else this->loadText.setFillColor(sf::Color(150, 150, 150));
        this->difficultyText.setFillColor(sf::Color::Red);
        this->exitText.setFillColor(sf::Color::White);
    }
    if  (this->choice == 4){
        this->startText.setFillColor(sf::Color::White);
        if(this->isFile) this->loadText.setFillColor(sf::Color::White); else this->loadText.setFillColor(sf::Color(150, 150, 150));
        this->difficultyText.setFillColor(sf::Color::White);
        this->exitText.setFillColor(sf::Color::Red);
    }

    //Difficulty text color change (highlighting the chosen option)
    if (this->difficultyChoice == 1){
        this->easyText.setFillColor(sf::Color::Red);
        this->mediumText.setFillColor(sf::Color::White);
        this->hardText.setFillColor(sf::Color::White);
    }
    if (this->difficultyChoice == 2){
        this->easyText.setFillColor(sf::Color::White);
        this->mediumText.setFillColor(sf::Color::Red);
        this->hardText.setFillColor(sf::Color::White);
    }
    if (this->difficultyChoice == 3){
        this->easyText.setFillColor(sf::Color::White);
        this->mediumText.setFillColor(sf::Color::White);
        this->hardText.setFillColor(sf::Color::Red);
    }
}

void Menu::renderBackground(sf::RenderTarget* target){
    /*
        @return void

        Renders the background to the screen
    */

    target->draw(this->background);
}

void Menu::render(sf::RenderTarget* target){
    /*
        @return void

        Renders the menu to the screen
    */

    this->renderBackground(target);

    if (this->difficultyMenu == true){
        target->draw(this->easyText);
        target->draw(this->mediumText);
        target->draw(this->hardText);
    }
    else {
        target->draw(this->startText);
        target->draw(this->loadText);
        target->draw(this->difficultyText);
        target->draw(this->exitText);
    }
}
