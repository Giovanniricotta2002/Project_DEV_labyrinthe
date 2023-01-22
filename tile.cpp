#include <SFML/Graphics.hpp>

#include "MapTile.cpp"
#include "GTile.cpp"

int main() {
    float windowHeight = 400;
    float windowWidth = 400;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "test");
    
    MapTile gameWorld = MapTile();
    



    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for (int i = 0; i < gameWorld.gridLenght; i++){
            for (int j = 0; j < gameWorld.gridLenght; j++){
                window.draw(gameWorld.tiles[i][j]->sprite);
            }
            
        }
        
        window.display();
    }

    return 0;
}

