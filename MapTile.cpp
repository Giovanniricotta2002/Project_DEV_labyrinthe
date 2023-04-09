#include "MapTile.h"
#include <iostream>



MapTile::MapTile(){
    gridLenght = 5;
    setUpInitialState();
}

void MapTile::setUpInitialState(){
    exitPos = sf::Vector2i(1,0);
    botPos = sf::Vector2i(gridLenght-1, gridLenght-1);
    setUpEnemyPositions();
    setUpTiles();
}

void MapTile::setUpEnemyPositions(){
    enemyPositions.clear();
    enemyPositions.push_back(sf::Vector2i(0,2));
    enemyPositions.push_back(sf::Vector2i(6,0));
    enemyPositions.push_back(sf::Vector2i(2,7));
}

void MapTile::setUpTiles(){
    tiles.clear();
    std::vector<GTile *> firstRow;
    int j = 0;
    for (int i = 0; i < gridLenght; i++){
        firstRow.push_back(new GTile("tiles/mur.png",j,0,false,false));
        j = j +50;
    }

    /*firstRow.push_back(new GTile("tiles/mur.png",0,0,false,false));
    firstRow.push_back(new GTile("tiles/mur.png",50,0,false,false));
    firstRow.push_back(new GTile("tiles/mur.png",100,0,false,false));
    firstRow.push_back(new GTile("tiles/mur.png",150,0,false,false));
    firstRow.push_back(new GTile("tiles/mur.png",200,0,false,false));*/
    /*firstRow.push_back(new GTile("tiles/mur.png",250,0,false,false));
    firstRow.push_back(new GTile("tiles/ennemi.png",300,0,true,false));
    firstRow.push_back(new GTile("tiles/mur.png",350,0,false,false));*/
    tiles.push_back(firstRow);

    std::vector<GTile *> secondRow;
    secondRow.push_back(new GTile("tiles/mur.png",0,50,false,false));
    secondRow.push_back(new GTile("tiles/mur.png",50,50,false,false));
    secondRow.push_back(new GTile("tiles/herbe.png",100,50,true,false));
    secondRow.push_back(new GTile("tiles/mur.png",150,50,false,false));
    secondRow.push_back(new GTile("tiles/mur.png",200,50,false,false));
    /*secondRow.push_back(new GTile("tiles/herbe.png",250,50,true,false));
    secondRow.push_back(new GTile("tiles/herbe.png",300,50,true,false));
    secondRow.push_back(new GTile("tiles/herbe.png",350,50,true,false));*/
    tiles.push_back(secondRow);

    std::vector<GTile *> thirdRow;
    thirdRow.push_back(new GTile("tiles/mur.png",0,100,false,false));
    thirdRow.push_back(new GTile("tiles/herbe.png",50,100,true,false));
    thirdRow.push_back(new GTile("tiles/herbe.png",100,100,true,false));
    thirdRow.push_back(new GTile("tiles/herbe.png",150,100,true,false));
    thirdRow.push_back(new GTile("tiles/mur.png",200,100,false,false));
    /*thirdRow.push_back(new GTile("tiles/herbe.png",250,100,true,false));
    thirdRow.push_back(new GTile("tiles/herbe.png",300,100,true,false));
    thirdRow.push_back(new GTile("tiles/herbe.png",350,100,true,false));*/
    tiles.push_back(thirdRow);

    std::vector<GTile *> fourthRow;
    fourthRow.push_back(new GTile("tiles/mur.png",0,150,false,false));
    fourthRow.push_back(new GTile("tiles/start.png",50,150,true,false));
    fourthRow.push_back(new GTile("tiles/mur.png",100,150,false,false));
    fourthRow.push_back(new GTile("tiles/fin.png",150,150,true,false));
    fourthRow.push_back(new GTile("tiles/mur.png",200,150,false,false));
    /*fourthRow.push_back(new GTile("tiles/herbe.png",250,150,true,false));
    fourthRow.push_back(new GTile("tiles/herbe.png",300,150,true,false));
    fourthRow.push_back(new GTile("tiles/herbe.png",350,150,true,false));*/
    tiles.push_back(fourthRow);

    std::vector<GTile *> fifthRow;
    fifthRow.push_back(new GTile("tiles/mur.png",0,200,false,false));
    fifthRow.push_back(new GTile("tiles/mur.png",50,200,false,false));
    fifthRow.push_back(new GTile("tiles/mur.png",100,200,false,false));
    fifthRow.push_back(new GTile("tiles/mur.png",150,200,false,false));
    fifthRow.push_back(new GTile("tiles/mur.png",200,200,false,false));
    /*fifthRow.push_back(new GTile("tiles/herbe.png",250,200,true,false));
    fifthRow.push_back(new GTile("tiles/herbe.png",300,200,true,false));
    fifthRow.push_back(new GTile("tiles/herbe.png",350,200,true,false));*/
    tiles.push_back(fifthRow);

    /*std::vector<GTile *> sixthRow;
    sixthRow.push_back(new GTile("tiles/mur.png",0,250,false,false));
    sixthRow.push_back(new GTile("tiles/herbe.png",50,250,true,false));
    sixthRow.push_back(new GTile("tiles/herbe.png",100,250,true,false));
    sixthRow.push_back(new GTile("tiles/herbe.png",150,250,true,false));
    sixthRow.push_back(new GTile("tiles/herbe.png",200,250,true,false));
    sixthRow.push_back(new GTile("tiles/herbe.png",250,250,true,false));
    sixthRow.push_back(new GTile("tiles/herbe.png",300,250,true,false));
    sixthRow.push_back(new GTile("tiles/herbe.png",350,250,true,false));
    tiles.push_back(sixthRow);

    std::vector<GTile *> seventhRow;
    seventhRow.push_back(new GTile("tiles/mur.png",0,300,false,false));
    seventhRow.push_back(new GTile("tiles/herbe.png",50,300,true,false));
    seventhRow.push_back(new GTile("tiles/herbe.png",100,300,true,false));
    seventhRow.push_back(new GTile("tiles/herbe.png",150,300,true,false));
    seventhRow.push_back(new GTile("tiles/herbe.png",200,300,true,false));
    seventhRow.push_back(new GTile("tiles/herbe.png",250,300,true,false));
    seventhRow.push_back(new GTile("tiles/herbe.png",300,300,true,false));
    seventhRow.push_back(new GTile("tiles/herbe.png",350,300,true,false));
    tiles.push_back(seventhRow);

    std::vector<GTile *> eighthRow;
    eighthRow.push_back(new GTile("tiles/mur.png",0,350,false,false));
    eighthRow.push_back(new GTile("tiles/herbe.png",50,350,true,false));
    eighthRow.push_back(new GTile("tiles/herbe.png",100,350,true,false));
    eighthRow.push_back(new GTile("tiles/herbe.png",150,350,true,false));
    eighthRow.push_back(new GTile("tiles/herbe.png",200,350,true,false));
    eighthRow.push_back(new GTile("tiles/herbe.png",250,350,true,false));
    eighthRow.push_back(new GTile("tiles/herbe.png",300,350,true,false));
    eighthRow.push_back(new GTile("tiles/joueur.png",350,350,true,false));
    tiles.push_back(eighthRow);*/


}
