#include "Menu.h"

//Private Functions
void Menu::initVariables(){
    this->startGame = false;
    this->choice = 1;
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

    //Init exit text
    this->exitText.setFont(this->font);
    this->exitText.setCharacterSize(60);
    this->exitText.setPosition(40.f, 600.f);
    this->exitText.setFillColor(sf::Color::White);
    this->exitText.setString("EXIT");

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

//Functions
void Menu::update(sf::RenderWindow* target){
    while(target->pollEvent(this->ev)){
        switch(this->ev.type){
            case sf::Event::KeyReleased:
              if(this->ev.key.code == sf::Keyboard::Up){
                  if(this->choice == 1){
                      this->choice = 3;
                  }
                  else{
                      this->choice--;
                  }
              }
              if(this->ev.key.code == sf::Keyboard::Down){
                  if(this->choice == 3){
                      this->choice = 1;
                  }
                  else{
                      this->choice++;
                  }
              }
              if(this->ev.key.code == sf::Keyboard::Enter){
                  if(this->choice == 1){
                      this->startGame = true;
                  }
                  if(this->choice == 3){
                      this->startGame = false;
                  }
              }
                break;
            default:
                break;
        }
    }
    
    if (this->choice == 1){
        this->startText.setFillColor(sf::Color::Red);
        this->loadText.setFillColor(sf::Color::White);
        this->exitText.setFillColor(sf::Color::White);
    }
    if (this->choice == 2){
        this->startText.setFillColor(sf::Color::White);
        this->loadText.setFillColor(sf::Color::Red);
        this->exitText.setFillColor(sf::Color::White);
    }
    if (this->choice == 3){
        this->startText.setFillColor(sf::Color::White);
        this->loadText.setFillColor(sf::Color::White);
        this->exitText.setFillColor(sf::Color::Red);
    }
}

void Menu::render(sf::RenderTarget* target){
    target->draw(this->startText);
    target->draw(this->loadText);
    target->draw(this->exitText);
}
