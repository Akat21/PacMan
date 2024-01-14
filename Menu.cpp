#include "Menu.h"

//Private Functions
void Menu::initVariables(){
    this->startGame = false;
    this->choice = 1;
    this->difficultyChoice = 1;
    this->difficultyMenu = false;
    this->diff = EASY;
}

void Menu::initFont(){
    if (!this->font.loadFromFile("Fonts/advanced_pixel-7.ttf")){
        std::cout << "ERROR::MAINMENUSTATE::COULD NOT LOAD FONT" << std::endl;
    }
}

void Menu::initText(){
    //Init start text
    this->startText.setFont(this->font);
    this->startText.setCharacterSize(60);
    this->startText.setPosition(40.f, 400.f);
    this->startText.setFillColor(sf::Color::White);
    this->startText.setString("START");

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

//Constructors and Destructors
Menu::Menu(){
    this->initVariables();
    this->initFont();
    this->initText();
}

Menu::~Menu(){

}

//Getters and Setters
bool Menu::getStartGame() const{
    return this->startGame;
}

difficulty Menu::getDifficultyLevel() const{
    return this->diff;
}

//Functions
void Menu::update(sf::RenderWindow* target){
    while(target->pollEvent(this->ev)){
        switch(this->ev.type){
            case sf::Event::KeyReleased:
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

                    //Choose difficulty
                    if(this->difficultyMenu == true){
                        if(this->difficultyChoice == 1){
                            this->difficultyChoice = 3;
                        }
                        else{
                            this->difficultyChoice--;
                        }
                    }
                }
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
                if(this->ev.key.code == sf::Keyboard::Enter){
                    //Choose menu option
                    if (difficultyMenu == false){
                        if(this->choice == 1){
                            this->startGame = true;
                        }
                        if(this->choice == 3){
                            this->difficultyMenu = true;
                        }
                        if(this->choice == 4){
                            target->close();
                        }
                    }

                    //Choose difficulty
                    else if(this->difficultyMenu == true){
                        if(this->difficultyChoice == 1){
                            this->diff = EASY;
                            this->difficultyText.setString("EASY");
                            this->difficultyMenu = false;  
                        }
                        if(this->difficultyChoice == 2){
                            this->diff = MEDIUM;
                            this->difficultyText.setString("MEDIUM");
                            this->difficultyMenu = false;  
                        }
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
    
    //Menu
    if (this->choice == 1){
        this->startText.setFillColor(sf::Color::Red);
        this->loadText.setFillColor(sf::Color::White);
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
        this->loadText.setFillColor(sf::Color::White);
        this->difficultyText.setFillColor(sf::Color::Red);
        this->exitText.setFillColor(sf::Color::White);
    }
    if  (this->choice == 4){
        this->startText.setFillColor(sf::Color::White);
        this->loadText.setFillColor(sf::Color::White);
        this->difficultyText.setFillColor(sf::Color::White);
        this->exitText.setFillColor(sf::Color::Red);
    }

    //Difficulty menu
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

void Menu::render(sf::RenderTarget* target){
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
