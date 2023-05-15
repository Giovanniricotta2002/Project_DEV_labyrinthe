#include <SFML/Graphics.hpp>
#include <iostream>


int main(){
    // Créez une fenêtre SFML
    sf::RenderWindow window(sf::VideoMode(800, 600), "Labyrinthe Menu");

    // sf::Texture textureBtnPlay;
    // sf::Texture textureBtnEdit;
    // sf::Texture textureBtnCreate;

    // sf::Texture texturePlay;
    // sf::Texture textureEdit;
    // sf::Texture textureCreate;

    // sf::Texture textureTitle;

    // textureBtnPlay.setSmooth(true);
    // textureBtnEdit.setSmooth(true);
    // textureBtnCreate.setSmooth(true);

    // texturePlay.setSmooth(true);
    // textureEdit.setSmooth(true);
    // textureCreate.setSmooth(true);

    // textureTitle.setSmooth(true);

    // if (!textureBtnPlay.loadFromFile("tiles/bouton/bouton_play.png")) { return -1; }
    // if (!textureBtnEdit.loadFromFile("tiles/bouton/bouton_edit.png")) { return -1; }
    // if (!textureBtnCreate.loadFromFile("tiles/bouton/bouton_create.png")) { return -1; }

    // if (!texturePlay.loadFromFile("tiles/menu/play.png")) { return -1; }
    // if (!textureEdit.loadFromFile("tiles/menu/edit.png")) { return -1; }
    // if (!textureCreate.loadFromFile("tiles/menu/create.png")) { return -1; }

    // if (!textureTitle.loadFromFile("tiles/LABYRINTH.png")) { return -1; }

    // sf::Sprite SpriteBtnPlay(textureBtnPlay);
    // sf::Sprite SpriteBtnEdit(textureBtnEdit);
    // sf::Sprite SpriteBtnCreate(textureBtnCreate);

    // sf::Sprite SpritePlay(texturePlay);
    // sf::Sprite SpriteEdit(textureEdit);
    // sf::Sprite SpriteCreate(textureCreate);

    // sf::Sprite SpriteTitle(textureTitle);

   


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
                }
                sf::FloatRect spriteBoundsEdit = SpriteEdit.getGlobalBounds();
                if (spriteBoundsEdit.contains(mousePosition.x, mousePosition.y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    std::cout << "Edit" << std::endl;
                }
                sf::FloatRect spriteBoundsCreate = SpriteCreate.getGlobalBounds();
                if (spriteBoundsCreate.contains(mousePosition.x, mousePosition.y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    std::cout << "Create" << std::endl;
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

        // window.draw(SpriteBtnPlay);
        // window.draw(SpriteBtnEdit);
        // window.draw(SpriteBtnCreate);

        window.draw(SpritePlay);
        window.draw(SpriteEdit);
        window.draw(SpriteCreate);

        window.draw(SpriteTitle);

        window.display();
    }

    return 0;
}
