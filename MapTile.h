#include <SFML/Graphics.hpp>
#include <vector>

#include "GTile.h"

#ifndef MAPTILE_H
#define MAPTILE_H


class MapTile {
    sf::Vector2i exitPos;
    sf::Vector2i botPos;
    std::vector<sf::Vector2i> enemyPositions;
    void setUpInitialState();
    void setUpEnemyPositions();
    void setUpTiles();
    private:
    public:
        std::vector<std::vector<GTile *>> tiles;
        int gridLenght;
        MapTile();
        
};

#endif