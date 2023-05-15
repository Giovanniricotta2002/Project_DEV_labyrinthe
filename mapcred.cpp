#include <SFML/Graphics.hpp>
#include <fstream>
#include "Menu.hpp"

int main()
{
   // Créez une fenêtre SFML
sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");

// Chargez une texture pour le sprite
sf::Texture texture;
sf::Texture texture1;

const sf::Texture* texture3;

texture.setSmooth(true);
texture1.setSmooth(true);


if (!texture.loadFromFile("tiles/mur.png")){ return -1; }
if (!texture1.loadFromFile("tiles/herbe.png")){ return -1; }

// Créez un sprite à partir de la texture
sf::Sprite sprite(texture);
sf::Sprite sprite2(texture1);

// Définissez la position du sprite
sprite.setPosition(100.f, 100.f);

// Boucle principale de l'application
while (window.isOpen())
{
    // Gérez les événements de la fenêtre
    sf::Event event;
    while (window.pollEvent(event))
    {
        // Si l'événement est un mouvement de souris
        //std::cout << &texture2 << std::endl;
        if (event.type == sf::Event::MouseButtonPressed)
        {
            // Récupérez la position de la souris
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

            // Récupérez la zone englobante du sprite
            sf::FloatRect spriteBounds = sprite.getGlobalBounds();
            if (spriteBounds.contains(mousePosition.x, mousePosition.y)) {

                // std::cout << "La souris est sur le sprite !" << std::endl;
               
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    std::cout << texture3 << std::endl;
                    sprite.setTexture(*texture3);
                }
                if (sf::Mouse::isButtonPressed(sf::Mouse::Right)){
                    /*std::cout << &texture2 << std::endl;
                    std::cout << sprite.getTexture() << std::endl;*/
                }
            }


            sf::FloatRect spriteBounds2 = sprite2.getGlobalBounds();
            if (spriteBounds2.contains(mousePosition.x, mousePosition.y)) {
                // std::cout << "La souris est sur le sprite !" << std::endl;
                //texture2 = *sprite2.getTexture();
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    texture3 = sprite2.getTexture();
                    std::cout << "Adresse memoire de la texture spirte2: " << texture3 << std::endl;
                    
                }
                if (sf::Mouse::isButtonPressed(sf::Mouse::Right)){
                    
                }
            }

        }

        // Si l'événement est une fermeture de fenêtre
        if (event.type == sf::Event::Closed)
        {
            // Fermez la fenêtre
            window.close();
        }
    }

    // Affichez le sprite dans la fenêtre
    window.clear();
    window.draw(sprite);
    window.draw(sprite2);
    window.display();
}



    return 0;
}

