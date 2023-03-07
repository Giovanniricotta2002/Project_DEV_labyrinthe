#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::Texture texture;
    if (!texture.loadFromFile("tiles/mur.png")){
        std::cout << "error";
        return 0;
    }

    sf::Sprite mur;
    mur.setTexture(texture);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch ( event.type )
            {
            case sf::Event::Closed:
                window.close();

                break;

            case sf::Event::MouseButtonPressed:
                std::cout << "click de souris" << std::endl;

                switch (event.key.code)
                {
                case sf::Mouse::Left:
                    std::cout << "click de souris droit" << std::endl;
                    break;
                }
            break;

            case sf::Event::MouseButtonReleased:
                std::cout << "fin de click de souris" << std::endl;

                switch (event.key.code)
                {
                case sf::Mouse::Left:
                    std::cout << "fin du click de souris droit" << std::endl;
                    break;
                }
            break;

                case sf::Event::MouseMoved:
                    std::cout << "la souris a ete deplacer" << std::endl;
                    std::cout << "la position Y est "<< event.mouseMove.y << std::endl;
                    std::cout << "la position X est "<< event.mouseMove.x << std::endl;
                    break;
        }
}
        window.clear();
        window.draw(shape);
        window.draw(mur);
        window.display();
    }

    return 0;
}
