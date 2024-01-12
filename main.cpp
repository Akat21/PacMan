#include <iostream>

#include <SFML/Graphics.hpp>

int main(){
    //Window Creation
    sf::RenderWindow window(sf::VideoMode(640, 480), "Pac Man", sf::Style::Titlebar | sf::Style::Close);
    sf::Event ev;

    //Game Loop
    while(window.isOpen()){
        
        //Event Polling
        while(window.pollEvent(ev)){
            switch(ev.type){

                //Close Event by clicking the X
                case sf::Event::Closed:
                    window.close();
                    break;

                //Close Event by pressing Escape
                case sf::Event::KeyPressed:
                    if(ev.key.code == sf::Keyboard::Escape){
                        window.close();
                    }
                    break;
            }
        }

        //Update

        //Render
        window.clear(sf::Color::Black); //Clear old frame

        window.display(); //Render new frame
    }

    //End of Application
    return 0;
}