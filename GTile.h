#include <SFML/Graphics.hpp>

#ifndef GTILE_H
#define GTILE_H

class GTile {
    private:
        /* data */
    public:
        bool isPassable;
        bool isExit;
        sf::Vector2f pos;
        sf::Texture texture;
        sf::Sprite sprite;
        bool setUpSprite(std::string);   


        GTile(std::string, float, float, bool, bool);
};

#endif