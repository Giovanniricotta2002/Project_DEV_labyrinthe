#include "Menu.hpp"


Menu::Menu(float width, float height) {

    sf::Texture texture[max_number_of_items];
    std::string texturenamefile[3] = {"tiles/bouton/bouton_play.png", "tiles/bouton/bouton_choixDeMap.png", "tiles/bouton/bouton_edit.png"};
    for (int i = 0; i < max_number_of_items; i++) {
        if (!texture[i].loadFromFile(texturenamefile[i]))
        {
            std::cout << "Error while loading texture" << std::endl;
            //system("pause");
        }
    }

    for (int i = 0; i < max_number_of_items; i++) {
        sprite[i].setTexture(texture[i]);
    }



//tiles\bouton\bouton_play.png
//tiles\bouton\bouton_choixDeMap.png
//tiles\bouton\bouton_edit.png



}


Menu::~Menu() {}



void Menu::draw(sf::RenderWindow & window){
    for(int i = 0; i < max_number_of_items; i++) {
        window.draw(sprite[i]);
    }

}




