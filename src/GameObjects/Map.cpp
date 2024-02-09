#include "Map.h"
#include "../Engine/TextureManager.h"

//Constructors and Destructors
Map::Map(){
    this->initVariables();
    this->initMap();
    this->createTiles();
}

Map::~Map(){

}

//Getters and Setters
std::vector<std::vector<sf::RectangleShape>> Map::getCollisionTiles() const{
    return this->collisionTiles;
}

std::vector<std::vector<sf::RectangleShape>> Map::getCoinsTiles() const{
    return this->coinsTiles;
}

void Map::setCollisionTiles(std::vector<std::vector<sf::RectangleShape>> collisionTiles){
    this->collisionTiles = collisionTiles;
}

//Private Functions
void Map::initVariables(){
    /*
        @return void

        Initializes the starting variables
    */

    this->map.clear();
    this->tilesMap.clear();
    this->collisionTiles.clear();
}

void Map::initMap(){
    /*
        @return void

        Loads map from file and stores it in a 2D vector
    */

    //Load map from file
    std::ifstream inFile;
    inFile.open("src/map.txt");
    
    //Check if there is no error
    if(inFile.fail()){
        std::cerr << "Error loading map file" << std::endl;
        exit(1);
    }

    //Read map file, then store it in a 2D vector
    std::string line;
    while(std::getline(inFile, line)){
        std::vector<int> row;
        for(size_t i = 0; i < line.length(); i++){
            char c = line[i];
            int n = static_cast<int>(c);
            row.push_back(n);
        }
        this->map.push_back(row);
    }

    //Close file
    inFile.close();
}

//Functions
void Map::update(){

}

void Map::createTiles(){
    /*
        @return void

        Creates tiles based on map and stores them in a 2D vector
    */

    //Create tile object
    sf::RectangleShape tile;
    tile.setSize(sf::Vector2f(20.f, 20.f));
    tile.setFillColor(sf::Color::Black);

    //Create tilesRow and collisionRow
    std::vector<sf::RectangleShape> tilesRow;
    std::vector<sf::RectangleShape> collisionRow;
    std::vector<sf::RectangleShape> coinsRow;

    //Fill tilesMap with tiles based on map
    for(size_t y = 0; y < this->map.size(); y++){
        for(size_t x = 0; x < this->map[y].size(); x++){

            //Check if the tile is a wall or floor tile (66 = B)
            if(this->map[y][x] >= 65 && this->map[y][x] <= 80 && this->map[y][x] != 67){

                //Set correct texture
                if (this->map[y][x] == 66){
                    tile.setFillColor(sf::Color::Green); 
                    tile.setTexture(&TextureManager::getTexture("Textures/rosekane_196.png"));
                } else if(this->map[y][x] == 65){
                    tile.setFillColor(sf::Color::Blue); 
                    tile.setTexture(&TextureManager::getTexture("Textures/rosekane_227.png"));
                } else if(this->map[y][x] == 68){
                    tile.setFillColor(sf::Color::Blue); 
                    tile.setTexture(&TextureManager::getTexture("Textures/rosekane_176.png"));
                } else if(this->map[y][x] == 69){
                    tile.setFillColor(sf::Color::Blue); 
                    tile.setTexture(&TextureManager::getTexture("Textures/rosekane_228.png"));
                } else if(this->map[y][x] == 70){
                    tile.setFillColor(sf::Color::Blue); 
                    tile.setTexture(&TextureManager::getTexture("Textures/rosekane_212.png"));
                } else if(this->map[y][x] == 71){
                    tile.setFillColor(sf::Color::Blue); 
                    tile.setTexture(&TextureManager::getTexture("Textures/rosekane_178.png"));
                } else if(this->map[y][x] == 72){
                    tile.setFillColor(sf::Color::Blue); 
                    tile.setTexture(&TextureManager::getTexture("Textures/rosekane_210.png"));
                } else if(this->map[y][x] == 73){
                    tile.setFillColor(sf::Color::Blue); 
                    tile.setTexture(&TextureManager::getTexture("Textures/rosekane_231.png"));
                } else if(this->map[y][x] == 74){
                    tile.setFillColor(sf::Color::Blue); 
                    tile.setTexture(&TextureManager::getTexture("Textures/rosekane_193.png"));
                } else if(this->map[y][x] == 75){
                    tile.setFillColor(sf::Color::Blue); 
                    tile.setTexture(&TextureManager::getTexture("Textures/rosekane_213.png"));
                } else if(this->map[y][x] == 76){
                    tile.setFillColor(sf::Color::Blue); 
                    tile.setTexture(&TextureManager::getTexture("Textures/rosekane_177.png"));
                } else if(this->map[y][x] == 77){
                    tile.setFillColor(sf::Color::Blue); 
                    tile.setTexture(&TextureManager::getTexture("Textures/rosekane_195.png"));
                } else if(this->map[y][x] == 78){
                    tile.setFillColor(sf::Color::Blue); 
                    tile.setTexture(&TextureManager::getTexture("Textures/rosekane_230.png"));
                } else if(this->map[y][x] == 79){
                    tile.setFillColor(sf::Color::Blue); 
                    tile.setTexture(&TextureManager::getTexture("Textures/rosekane_211.png"));
                } else if(this->map[y][x] == 80){
                    tile.setFillColor(sf::Color::Blue); 
                    tile.setTexture(&TextureManager::getTexture("Textures/rosekane_229.png"));
                }

                //Set position of tile and push it to collisionRow
                tile.setPosition(x * 20.f, y * 20.f);
                collisionRow.push_back(tile);

            } else if(this->map[y][x] == 67){

                //Set position of tile and push it to coinsRow
                tile.setFillColor(sf::Color::Black);
                tile.setPosition(x * 20.f, y * 20.f);
                coinsRow.push_back(tile);

            } else{
                tile.setFillColor(sf::Color::Black); //Floor
                tile.setPosition(x * 20.f, y * 20.f);
            }

            //Push tile to tilesRow
            tilesRow.push_back(tile);
        }

        //Push tilesRow to tilesMap then clear tilesRow
        this->tilesMap.push_back(tilesRow);
        tilesRow.clear();

        //Push collisionRow to collisionTiles then clear collisionRow
        this->collisionTiles.push_back(collisionRow);   
        this->coinsTiles.push_back(coinsRow);
        collisionRow.clear();
        coinsRow.clear();
    }
}

void Map::render(sf::RenderTarget* target){
    /*
        @return void

        Renders the map
    */

    for(auto row : this->tilesMap){
        for(auto block : row){
            target->draw(block);
        }
    }
}
