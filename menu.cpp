#include <SFML/Graphics.hpp>
#include <iostream>

#include "CreateMap.cpp"
#include "pmap.cpp"


int main(){
    // Créez une fenêtre SFML
    sf::RenderWindow window(sf::VideoMode(800, 600), "Labyrinthe Menu");

    std::vector<std::string> imagePaths = {
        "tiles/bouton/bouton_play.png",
        "tiles/bouton/bouton_edit.png",
        "tiles/bouton/bouton_create.png",
        "tiles/menu/play.png",
        "tiles/menu/edit.png",
        "tiles/menu/create.png",
        "tiles/LABYRINTH.png"
    };

    std::vector<sf::Texture> textures(imagePaths.size());
    for (int i = 0; i < imagePaths.size(); i++) {
        if (!textures[i].loadFromFile(imagePaths[i])) {
            return -1;
        }
    }

    for (auto& texture : textures) { texture.setSmooth(true); }

    // sf::Sprite SpriteBtnPlay(textures[0]);
    // sf::Sprite SpriteBtnEdit(textures[1]);
    // sf::Sprite SpriteBtnCreate(textures[2]);

    sf::Sprite SpritePlay(textures[3]);
    sf::Sprite SpriteEdit(textures[4]);
    sf::Sprite SpriteCreate(textures[5]);

    sf::Sprite SpriteTitle(textures[6]);

    // test(window);
    // SpriteBtnPlay.setPosition(330, 108);
    // SpriteBtnEdit.setPosition(330, 158);
    // SpriteBtnCreate.setPosition(330, 208);

    SpritePlay.setPosition(350, 108);
    SpriteEdit.setPosition(350, 158);
    SpriteCreate.setPosition(350, 208);

    SpriteTitle.setPosition(350, 50);

    // Boucle principale de l'application
    while (window.isOpen()) {
        // Gérez les événements de la fenêtre
        sf::Event event;
        while (window.pollEvent(event)) {


            if (event.type == sf::Event::MouseButtonPressed){
                //background
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                sf::FloatRect spriteBoundsPlay = SpritePlay.getGlobalBounds();
                if (spriteBoundsPlay.contains(mousePosition.x, mousePosition.y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    std::cout << "Play" << std::endl;
                    pmap();
                }
                sf::FloatRect spriteBoundsEdit = SpriteEdit.getGlobalBounds();
                if (spriteBoundsEdit.contains(mousePosition.x, mousePosition.y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    std::cout << "Edit" << std::endl;
                }
                sf::FloatRect spriteBoundsCreate = SpriteCreate.getGlobalBounds();
                if (spriteBoundsCreate.contains(mousePosition.x, mousePosition.y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    std::cout << "Create" << std::endl;
                    cmap();
                }
            }

            // Si l'événement est une fermeture de fenêtre
            if (event.type == sf::Event::Closed) {
                // Fermez la fenêtre
                window.close();
            }
        }

        // Affichez le sprite dans la fenêtre
        window.clear();



        window.draw(SpritePlay);
        window.draw(SpriteEdit);
        window.draw(SpriteCreate);

        window.draw(SpriteTitle);

        window.display();
    }

    return 0;
}
