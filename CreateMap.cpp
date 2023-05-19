#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>

#include "lib/json/single_include/nlohmann/json.hpp"

#include "HTTPlab.hpp"
// #include "HTTPlab.cpp"
using json = nlohmann::json;


struct Node {
    int x;
    int y;
    bool obstacle;
    bool end;
    bool start;

    Node(int _x = 0, int _y = 0, bool _obstacle = false, bool _end = false, bool _start = false): x(_x), y(_y), obstacle(_obstacle), end(_end), start(_start) {}
};




inline int cmap(){

    HTTPlab d("localhost", 3000);

    bool obstacle = false;
    bool end = false;
    bool start = false;
    std::vector<std::vector<Node>> graph;
    std::vector<Node> row1;
    std::vector<Node> row2;
    std::vector<Node> row3;
    std::vector<Node> row4;
    std::vector<Node> row5;

    sf::RenderWindow window(sf::VideoMode(1000, 500), "SFML Window");
    // sf::Texture texture;
    // sf::Texture texture2;
    // sf::Texture texture4;
    // sf::Texture texture5;
    // sf::Texture texture6;
    // sf::Texture texture7;
    // sf::Texture texture8;
    // sf::Texture texture9;

    // sf::Texture texture1;


    // texture.setSmooth(true);
    // texture2.setSmooth(true);
    // texture4.setSmooth(true);
    // texture5.setSmooth(true);
    // texture6.setSmooth(true);
    // texture7.setSmooth(true);
    // texture8.setSmooth(true);
    // texture9.setSmooth(true);

    // texture1.setSmooth(true);

    // if (!texture.loadFromFile("tiles/mur.png")){ return -1; }
    // if (!texture1.loadFromFile("tiles/herbe.png")){ return -1; }
    // if (!texture2.loadFromFile("tiles/fin.png")){ return -1; }
    // if (!texture4.loadFromFile("tiles/piege.png")){ return -1; }
    // if (!texture5.loadFromFile("tiles/mur_cassable.png")){ return -1; }
    // if (!texture6.loadFromFile("tiles/piege_vitesse.png")){ return -1; }
    // if (!texture7.loadFromFile("tiles/interrupteur_tiles/interrupteur16.png")){ return -1; }
    // if (!texture8.loadFromFile("tiles/start.png")){ return -1; }
    // if (!texture9.loadFromFile("tiles/BORDURE.png")){ return -1; }


    std::vector<std::string> imgPaths = {
        "tiles/mur.png",
        "tiles/herbe.png",
        "tiles/fin.png",
        "tiles/piege.png",
        "tiles/mur_cassable.png",
        "tiles/piege_vitesse.png",
        "tiles/interrupteur_tiles/interrupteur16.png",
        "tiles/start.png",
        "tiles/BORDURE.png",
        "tiles/piege.png",
        "tiles/bouton/bouton_save.png",
    };//bouton_save

    std::vector<sf::Texture> textures(imgPaths.size());
    for(int i = 0; i< imgPaths.size(); i++) {
        if(!textures[i].loadFromFile(imgPaths[i])){
            return -1;
        }
    }

    for (auto& texture : textures) { texture.setSmooth(true); }


    const sf::Texture* texture3;




    sf::Sprite toolbox1(textures[0]);
    sf::Sprite toolbox2(textures[1]);
    sf::Sprite toolbox3(textures[2]);
    sf::Sprite toolbox4(textures[3]);
    sf::Sprite toolbox5(textures[4]);
    sf::Sprite toolbox6(textures[5]);
    sf::Sprite toolbox7(textures[6]);
    sf::Sprite toolbox8(textures[7]);

    sf::Sprite background1(textures[1]);
    sf::Sprite background2(textures[1]);
    sf::Sprite background3(textures[1]);
    sf::Sprite background4(textures[1]);
    sf::Sprite background5(textures[1]);
    sf::Sprite background6(textures[1]);
    sf::Sprite background7(textures[1]);
    sf::Sprite background8(textures[1]);
    sf::Sprite background9(textures[1]);
    sf::Sprite background10(textures[1]);
    sf::Sprite background11(textures[1]);
    sf::Sprite background12(textures[1]);
    sf::Sprite background13(textures[1]);
    sf::Sprite background14(textures[1]);
    sf::Sprite background15(textures[1]);
    sf::Sprite background16(textures[1]);
    sf::Sprite background17(textures[1]);
    sf::Sprite background18(textures[1]);
    sf::Sprite background19(textures[1]);
    sf::Sprite background20(textures[1]);
    sf::Sprite background21(textures[1]);
    sf::Sprite background22(textures[1]);
    sf::Sprite background23(textures[1]);
    sf::Sprite background24(textures[1]);
    sf::Sprite background25(textures[1]);

    sf::Sprite sprite_spe(textures[8]);

    sf::Sprite btnSave(textures[9]);

    background1.setPosition(158, 108);
    row1.push_back(Node(0, 0, false, false, false));

    background2.setPosition(216, 108);
    row1.push_back(Node(1, 0, false, false, false));

    background3.setPosition(274, 108);
    row1.push_back(Node(2, 0, false, false, false));

    background4.setPosition(332, 108);
    row1.push_back(Node(3, 0, false, false, false));

    background5.setPosition(390, 108);
    row1.push_back(Node(4, 0, false, false, false));








    background6.setPosition(158, 158);
    row2.push_back(Node(0, 1, false, false, false));

    background7.setPosition(216, 158);
    row2.push_back(Node(1, 1, false, false, false));


    background8.setPosition(274, 158);
    row2.push_back(Node(2, 1, false, false, false));


    background9.setPosition(332, 158);
    row2.push_back(Node(3, 1, false, false, false));


    background10.setPosition(390, 158);
    row2.push_back(Node(4, 1, false, false, false));



    background11.setPosition(158, 216);
    row3.push_back(Node(0, 2, false, false, false));

    background12.setPosition(216, 216);
    row3.push_back(Node(1, 2, false, false, false));

    background13.setPosition(274, 216);
    row3.push_back(Node(2, 2, false, false, false));

    background14.setPosition(332, 216);
    row3.push_back(Node(3, 2, false, false, false));

    background15.setPosition(390, 216);
    row3.push_back(Node(4, 2, false, false, false));


    background16.setPosition(158, 274);
    row4.push_back(Node(0, 3, false, false, false));

    background17.setPosition(216, 274);
    row4.push_back(Node(1, 3, false, false, false));

    background18.setPosition(274, 274);
    row4.push_back(Node(2, 3, false, false, false));

    background19.setPosition(332, 274);
    row4.push_back(Node(3, 3, false, false, false));

    background20.setPosition(390, 274);
    row4.push_back(Node(4, 3, false, false, false));


    background21.setPosition(158, 332);
    row5.push_back(Node(0, 4, false, false, false));

    background22.setPosition(216, 332);
    row5.push_back(Node(1, 4, false, false, false));

    background23.setPosition(274, 332);
    row5.push_back(Node(2, 4, false, false, false));

    background24.setPosition(332, 332);
    row5.push_back(Node(3, 4, false, false, false));

    background25.setPosition(390, 332);
    row5.push_back(Node(4, 4, false, false, false));






    toolbox1.setPosition(700, 58);
    toolbox2.setPosition(758, 58);
    toolbox3.setPosition(816, 58);
    toolbox4.setPosition(874, 58);
    toolbox5.setPosition(932, 58);
    toolbox6.setPosition(700, 116);
    toolbox7.setPosition(758, 116);
    toolbox8.setPosition(816, 116);

    sprite_spe.setPosition(550, 0);

    btnSave.setPosition(158, 400);


    while (window.isOpen()){
        // G�rez les �v�nements de la fen�tre
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::MouseButtonPressed){
                //background
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                sf::FloatRect spriteBounds11 = background1.getGlobalBounds();
                if (spriteBounds11.contains(mousePosition.x, mousePosition.y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    // std::cout << "La souris est sur le sprite !" << std::endl;
                    std::cout << texture3 << std::endl;
                    background1.setTexture(*texture3);
                    // row1.push_back(Node(158, 108, obstacle));
                    row1[0].x = 0;
                    row1[0].obstacle = obstacle;
                    row1[0].end = end;
                    row1[0].start = start;
                }

                sf::FloatRect spriteBounds12 = background2.getGlobalBounds();
                if (spriteBounds12.contains(mousePosition.x, mousePosition.y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    // std::cout << "La souris est sur le sprite !" << std::endl;
                    std::cout << texture3 << std::endl;
                    background2.setTexture(*texture3);
                    // row1.push_back(Node(216, 108, obstacle));
                    row1[1].x = 1;
                    row1[1].obstacle = obstacle;
                    row1[1].end = end;
                    row1[1].start = start;
                }

                sf::FloatRect spriteBounds13 = background3.getGlobalBounds();
                if (spriteBounds13.contains(mousePosition.x, mousePosition.y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    // std::cout << "La souris est sur le sprite !" << std::endl;
                    std::cout << texture3 << std::endl;
                    background3.setTexture(*texture3);
                    // row1.push_back(Node(274, 108, obstacle));
                    row1[2].x = 2;
                    row1[2].obstacle = obstacle;
                    row1[2].end = end;
                    row1[2].start = start;
                }

                sf::FloatRect spriteBounds14 = background4.getGlobalBounds();
                if (spriteBounds14.contains(mousePosition.x, mousePosition.y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    // std::cout << "La souris est sur le sprite !" << std::endl;
                    std::cout << texture3 << std::endl;
                    background4.setTexture(*texture3);
                    // row1.push_back(Node(332, 108, obstacle));
                    row1[3].x = 3;
                    row1[3].obstacle = obstacle;
                    row1[3].end = end;
                    row1[3].start = start;
                }

                sf::FloatRect spriteBounds15 = background5.getGlobalBounds();
                if (spriteBounds15.contains(mousePosition.x, mousePosition.y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    // std::cout << "La souris est sur le sprite !" << std::endl;
                    std::cout << texture3 << std::endl;
                    background5.setTexture(*texture3);
                    // row1.push_back(Node(390, 108, obstacle));
                    row1[4].x = 4;
                    row1[4].obstacle = obstacle;
                    row1[4].end = end;
                    row1[4].start = start;
                }



                sf::FloatRect spriteBounds16 = background6.getGlobalBounds();
                if (spriteBounds16.contains(mousePosition.x, mousePosition.y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    // std::cout << "La souris est sur le sprite !" << std::endl;
                    std::cout << texture3 << std::endl;
                    background6.setTexture(*texture3);
                    // row2.push_back(Node(158, 158, obstacle));
                    row2[0].x = 0;
                    row2[0].obstacle = obstacle;
                    row2[0].end = end;
                    row2[0].start = start;
                    row2[0].start = start;
                    row2[0].start = start;
                }

                sf::FloatRect spriteBounds17 = background7.getGlobalBounds();
                if (spriteBounds17.contains(mousePosition.x, mousePosition.y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    // std::cout << "La souris est sur le sprite !" << std::endl;
                    std::cout << texture3 << std::endl;
                    background7.setTexture(*texture3);
                    // row2.push_back(Node(216, 158, obstacle));
                    row2[1].x = 1;
                    row2[1].obstacle = obstacle;
                    row2[1].end = end;
                    row2[1].start = start;
                    row2[1].start = start;
                    row2[1].start = start;
                }

                sf::FloatRect spriteBounds18 = background8.getGlobalBounds();
                if (spriteBounds18.contains(mousePosition.x, mousePosition.y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    // std::cout << "La souris est sur le sprite !" << std::endl;
                    std::cout << texture3 << std::endl;
                    background8.setTexture(*texture3);
                    // row2.push_back(Node(274, 158, obstacle));
                    row2[2].x = 2;
                    row2[2].obstacle = obstacle;
                    row2[2].end = end;
                    row2[2].start = start;
                    row2[2].start = start;
                    row2[2].start = start;
                }

                sf::FloatRect spriteBounds19 = background9.getGlobalBounds();
                if (spriteBounds19.contains(mousePosition.x, mousePosition.y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    // std::cout << "La souris est sur le sprite !" << std::endl;
                    std::cout << texture3 << std::endl;
                    background9.setTexture(*texture3);
                    // row2.push_back(Node(332, 158, obstacle));
                    row2[3].x = 3;
                    row2[3].obstacle = obstacle;
                    row2[3].end = end;
                    row2[3].start = start;
                    row2[3].start = start;
                    row2[3].start = start;
                }

                sf::FloatRect spriteBounds20 = background10.getGlobalBounds();
                if (spriteBounds20.contains(mousePosition.x, mousePosition.y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    // std::cout << "La souris est sur le sprite !" << std::endl;
                    std::cout << texture3 << std::endl;
                    background10.setTexture(*texture3);
                    // row2.push_back(Node(390, 158, obstacle));
                    row2[4].x = 4;
                    row2[4].obstacle = obstacle;
                    row2[4].end = end;
                    row2[4].start = start;
                    row2[4].start = start;
                    row2[4].start = start;
                }



                sf::FloatRect spriteBounds21 = background11.getGlobalBounds();
                if (spriteBounds21.contains(mousePosition.x, mousePosition.y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    // std::cout << "La souris est sur le sprite !" << std::endl;
                    std::cout << texture3 << std::endl;
                    background11.setTexture(*texture3);
                    // row3.push_back(Node(158, 216, obstacle));
                    row3[0].x = 0;
                    row3[0].obstacle = obstacle;
                    row3[0].end = end;
                    row3[0].start = start;
                    row3[0].start = start;

                }

                sf::FloatRect spriteBounds22 = background12.getGlobalBounds();
                if (spriteBounds22.contains(mousePosition.x, mousePosition.y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    // std::cout << "La souris est sur le sprite !" << std::endl;
                    std::cout << texture3 << std::endl;
                    background12.setTexture(*texture3);
                    // row3.push_back(Node(216, 216, obstacle));
                    row3[1].x = 1;
                    row3[1].obstacle = obstacle;
                    row3[1].end = end;
                    row3[1].start = start;
                    row3[1].start = start;

                }

                sf::FloatRect spriteBounds23 = background13.getGlobalBounds();
                if (spriteBounds23.contains(mousePosition.x, mousePosition.y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    // std::cout << "La souris est sur le sprite !" << std::endl;
                    std::cout << texture3 << std::endl;
                    background13.setTexture(*texture3);
                    // row3.push_back(Node(274, 216, obstacle));
                    row3[2].x = 2;
                    row3[2].obstacle = obstacle;
                    row3[2].end = end;
                    row3[2].start = start;
                    row3[2].start = start;

                }

                sf::FloatRect spriteBounds24 = background14.getGlobalBounds();
                if (spriteBounds24.contains(mousePosition.x, mousePosition.y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    // std::cout << "La souris est sur le sprite !" << std::endl;
                    std::cout << texture3 << std::endl;
                    background14.setTexture(*texture3);
                    // row3.push_back(Node(332, 216, obstacle));
                    row3[3].x = 3;
                    row3[3].obstacle = obstacle;
                    row3[3].end = end;
                    row3[3].start = start;
                    row3[3].start = start;

                }

                sf::FloatRect spriteBounds25 = background15.getGlobalBounds();
                if (spriteBounds25.contains(mousePosition.x, mousePosition.y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    // std::cout << "La souris est sur le sprite !" << std::endl;
                    std::cout << texture3 << std::endl;
                    background15.setTexture(*texture3);
                    // row3.push_back(Node(390, 216, obstacle));
                    row3[4].x = 4;
                    row3[4].obstacle = obstacle;
                    row3[4].end = end;
                    row3[4].start = start;
                    row3[4].start = start;

                }



                sf::FloatRect spriteBounds26 = background16.getGlobalBounds();
                if (spriteBounds26.contains(mousePosition.x, mousePosition.y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    // std::cout << "La souris est sur le sprite !" << std::endl;
                    std::cout << texture3 << std::endl;
                    background16.setTexture(*texture3);
                    // row4.push_back(Node(158, 274, obstacle));
                    row4[0].x = 0;
                    row4[0].obstacle = obstacle;
                    row4[0].end = end;
                    row4[0].start = start;

                }

                sf::FloatRect spriteBounds27 = background17.getGlobalBounds();
                if (spriteBounds27.contains(mousePosition.x, mousePosition.y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    // std::cout << "La souris est sur le sprite !" << std::endl;
                    std::cout << texture3 << std::endl;
                    background17.setTexture(*texture3);
                    // row4.push_back(Node(216, 274, obstacle));
                    row4[1].x = 1;
                    row4[1].obstacle = obstacle;
                    row4[1].end = end;
                    row4[1].start = start;

                }

                sf::FloatRect spriteBounds28 = background18.getGlobalBounds();
                if (spriteBounds28.contains(mousePosition.x, mousePosition.y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    // std::cout << "La souris est sur le sprite !" << std::endl;
                    std::cout << texture3 << std::endl;
                    background18.setTexture(*texture3);
                    // row4.push_back(Node(274, 274, obstacle));
                    row4[2].x = 2;
                    row4[2].obstacle = obstacle;
                    row4[2].end = end;
                    row4[2].start = start;

                }

                sf::FloatRect spriteBounds29 = background19.getGlobalBounds();
                if (spriteBounds29.contains(mousePosition.x, mousePosition.y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    // std::cout << "La souris est sur le sprite !" << std::endl;
                    std::cout << texture3 << std::endl;
                    background19.setTexture(*texture3);
                    // row4.push_back(Node(332, 274, obstacle));
                    row4[3].x = 3;
                    row4[3].obstacle = obstacle;
                    row4[3].end = end;
                    row4[3].start = start;

                }

                sf::FloatRect spriteBounds30 = background20.getGlobalBounds();
                if (spriteBounds30.contains(mousePosition.x, mousePosition.y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    // std::cout << "La souris est sur le sprite !" << std::endl;
                    std::cout << texture3 << std::endl;
                    background20.setTexture(*texture3);
                    // row4.push_back(Node(390, 274, obstacle));
                    row4[4].x = 4;
                    row4[4].obstacle = obstacle;
                    row4[4].end = end;
                    row4[4].start = start;

                }



                sf::FloatRect spriteBounds31 = background21.getGlobalBounds();
                if (spriteBounds31.contains(mousePosition.x, mousePosition.y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    // std::cout << "La souris est sur le sprite !" << std::endl;
                    std::cout << texture3 << std::endl;
                    background21.setTexture(*texture3);
                    // row5.push_back(Node(158, 332, obstacle));
                    row5[0].x = 0;
                    row5[0].obstacle = obstacle;
                    row5[0].end = end;
                    row5[0].start = start;
                }

                sf::FloatRect spriteBounds32 = background22.getGlobalBounds();
                if (spriteBounds32.contains(mousePosition.x, mousePosition.y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    // std::cout << "La souris est sur le sprite !" << std::endl;
                    std::cout << texture3 << std::endl;
                    background22.setTexture(*texture3);
                    // row5.push_back(Node(216, 332, obstacle));
                    row5[1].x = 1;
                    row5[1].obstacle = obstacle;
                    row5[1].end = end;
                    row5[1].start = start;
                }

                sf::FloatRect spriteBounds33 = background23.getGlobalBounds();
                if (spriteBounds33.contains(mousePosition.x, mousePosition.y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    // std::cout << "La souris est sur le sprite !" << std::endl;
                    std::cout << texture3 << std::endl;
                    background23.setTexture(*texture3);
                    // row5.push_back(Node(274, 332, obstacle));
                    row5[2].x = 2;
                    row5[2].obstacle = obstacle;
                    row5[2].end = end;
                    row5[2].start = start;
                }

                sf::FloatRect spriteBounds34 = background24.getGlobalBounds();
                if (spriteBounds34.contains(mousePosition.x, mousePosition.y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    // std::cout << "La souris est sur le sprite !" << std::endl;
                    std::cout << texture3 << std::endl;
                    background24.setTexture(*texture3);
                    // row5.push_back(Node(332, 332, obstacle));
                    row5[3].x = 3;
                    row5[3].obstacle = obstacle;
                    row5[3].end = end;
                    row5[3].start = start;
                }

                sf::FloatRect spriteBounds35 = background25.getGlobalBounds();
                if (spriteBounds35.contains(mousePosition.x, mousePosition.y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    // std::cout << "La souris est sur le sprite !" << std::endl;
                    std::cout << texture3 << std::endl;
                    background25.setTexture(*texture3);
                    // row5.push_back(Node(390, 332, obstacle));
                    row5[4].x = 4;
                    row5[4].obstacle = obstacle;
                    row5[4].end = end;
                    row5[4].start = start;
                }


                //toolbox
                sf::FloatRect spriteBounds2 = toolbox1.getGlobalBounds();
                if (spriteBounds2.contains(mousePosition.x, mousePosition.y)) {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                        texture3 = toolbox1.getTexture();
                        std::cout << "Adresse memoire de la texture Mur: " << texture3 << std::endl;
                        obstacle = true;
                        end = false;
                        start = false;

                    }
                }
                sf::FloatRect spriteBounds3 = toolbox2.getGlobalBounds();
                if (spriteBounds3.contains(mousePosition.x, mousePosition.y)) {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                        texture3 = toolbox2.getTexture();
                        std::cout << "Adresse memoire de la texture herbe: " << texture3 << std::endl;
                        obstacle = false;
                        end = false;
                        start = false;
                    }
                }
                sf::FloatRect spriteBounds4 = toolbox3.getGlobalBounds();
                if (spriteBounds4.contains(mousePosition.x, mousePosition.y)) {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                        texture3 = toolbox3.getTexture();
                        std::cout << "Adresse memoire de la texture rouge: " << texture3 << std::endl; //end
                        obstacle = false;
                        end = true;
                        start = false;


                    }
                }
                sf::FloatRect spriteBounds5 = toolbox4.getGlobalBounds();
                if (spriteBounds5.contains(mousePosition.x, mousePosition.y)) {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                        texture3 = toolbox4.getTexture();
                        std::cout << "Adresse memoire de la texture pique: " << texture3 << std::endl;
                        obstacle = true;
                         end = false;
                        start = false;

                    }
                }
                sf::FloatRect spriteBounds6 = toolbox5.getGlobalBounds();
                if (spriteBounds6.contains(mousePosition.x, mousePosition.y)) {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                        texture3 = toolbox5.getTexture();
                        std::cout << "Adresse memoire de la texture mur cassable: " << texture3 << std::endl;
                        obstacle = true;
                         end = false;
                        start = false;

                    }
                }
                sf::FloatRect spriteBounds7 = toolbox6.getGlobalBounds();
                if (spriteBounds7.contains(mousePosition.x, mousePosition.y)) {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                        texture3 = toolbox6.getTexture();
                        std::cout << "Adresse memoire de la texture ralent: " << texture3 << std::endl;
                        obstacle = true;
                         end = false;
                        start = false;

                    }
                }
                sf::FloatRect spriteBounds8 = toolbox7.getGlobalBounds();
                if (spriteBounds8.contains(mousePosition.x, mousePosition.y)) {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                        texture3 = toolbox7.getTexture();
                        std::cout << "Adresse memoire de la texture btn: " << texture3 << std::endl;
                        obstacle = true;
                         end = false;
                        start = false;

                    }
                }
                sf::FloatRect spriteBounds9 = toolbox8.getGlobalBounds();
                if (spriteBounds9.contains(mousePosition.x, mousePosition.y)) {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                        texture3 = toolbox8.getTexture();
                        std::cout << "Adresse memoire de la texture bleu: " << texture3 << std::endl; //start
                        obstacle = false;
                        start = true;
                        end = false;
                    }
                }

                sf::FloatRect boutonBound = btnSave.getGlobalBounds();
                if (boutonBound.contains(mousePosition.x, mousePosition.y)) {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                        std::cout << "labyrinth sauvegarder" << std::endl;


                        graph.push_back(row1);
                        graph.push_back(row2);
                        graph.push_back(row3);
                        graph.push_back(row4);
                        graph.push_back(row5);






                        // std::ofstream myjsonfile("map.json");

                        // if(myjsonfile.is_open()){
                        //     myjsonfile << "{";
                        //     myjsonfile << "\t\"case_map\": [ \n";


                        //     myjsonfile << "\t\t[\n" ;
                        //    for (auto nodeIt = row1.begin(); nodeIt != row1.end(); ++nodeIt) {
                        //         const Node& node = *nodeIt;
                        //         myjsonfile << "\t\t\t{\"x\":" << node.x << ", \"y\": " << node.y << ", \"obstacle\": " << (node.obstacle ? "true" : "false") << "}";
                        //         if (nodeIt + 1 != row1.end()) {
                        //             myjsonfile << ",";
                        //         }
                        //         myjsonfile << "\n";
                        //     }
                        //     myjsonfile << "\t\t],\n" ;
                        //     myjsonfile << "\t\t[\n" ;
                        //     for (auto nodeIt = row2.begin(); nodeIt != row2.end(); ++nodeIt) {
                        //         const Node& node = *nodeIt;
                        //         myjsonfile << "\t\t\t{\"x\":" << node.x << ", \"y\": " << node.y << ", \"obstacle\": " << (node.obstacle ? "true" : "false") << "}";
                        //         if (nodeIt + 1 != row2.end()) {
                        //             myjsonfile << ",";
                        //         }
                        //         myjsonfile << "\n";
                        //     }
                        //     myjsonfile << "\t\t],\n" ;
                        //     myjsonfile << "\t\t[\n" ;
                        //     for (auto nodeIt = row3.begin(); nodeIt != row3.end(); ++nodeIt) {
                        //         const Node& node = *nodeIt;
                        //         myjsonfile << "\t\t\t{\"x\":" << node.x << ", \"y\": " << node.y << ", \"obstacle\": " << (node.obstacle ? "true" : "false") << "}";
                        //         if (nodeIt + 1 != row3.end()) {
                        //             myjsonfile << ",";
                        //         }
                        //         myjsonfile << "\n";
                        //     }
                        //     myjsonfile << "\t\t],\n" ;
                        //     myjsonfile << "\t\t[\n" ;
                        //     for (auto nodeIt = row4.begin(); nodeIt != row4.end(); ++nodeIt) {
                        //         const Node& node = *nodeIt;
                        //         myjsonfile << "\t\t\t{\"x\":" << node.x << ", \"y\": " << node.y << ", \"obstacle\": " << (node.obstacle ? "true" : "false") << "}";
                        //         if (nodeIt + 1 != row4.end()) {
                        //             myjsonfile << ",";
                        //         }
                        //         myjsonfile << "\n";
                        //     }
                        //     myjsonfile << "\t\t],\n" ;
                        //     myjsonfile << "\t\t[\n" ;


                        //     for (auto nodeIt = row5.begin(); nodeIt != row5.end(); ++nodeIt) {
                        //         const Node& node = *nodeIt;
                        //         myjsonfile << "\t\t\t{\"x\":" << node.x << ", \"y\": " << node.y << ", \"obstacle\": " << (node.obstacle ? "true" : "false") << "}";
                        //         if (nodeIt + 1 != row5.end()) {
                        //             myjsonfile << ",";
                        //         }
                        //         myjsonfile << "\n";
                        //     }



                        //     myjsonfile << "\t\t]" ;

                        //     myjsonfile << "\t], \n";
                        //     myjsonfile << "\t\"nbr_case_total\": 27, \n";
                        //     myjsonfile << "\t\"difficulty\": \"easy\", \n";
                        //     myjsonfile << "\t\"creator\": \"admin\", \n";


                        //     int sx = 0;
                        //     int sy = 0;
                        //     for (const auto& row : graph) {
                        //         for (const auto& node : row) {
                        //             if (node.start){
                        //                 sx = node.x;
                        //                 sy = node.y;
                        //             } else {
                        //                 // std::cout << std::endl;
                        //             }
                        //         }
                        //     }
                        //     myjsonfile << "\t\"start\": {\"x\":" << sx << ", \"y\": " << sy << "}, \n";


                        //     int ex = 0;
                        //     int ey = 0;
                        //     for (const auto& row : graph) {
                        //         for (const auto& node : row) {
                        //             if (node.end){
                        //                 ex = node.x;
                        //                 ey = node.y;
                        //             } else {
                        //                 // std::cout << std::endl;
                        //             }
                        //         }
                        //     }
                        //     myjsonfile << "\t\"end\": {\"x\":" << ex << ", \"y\": " << ey << "} \n";
                        //     myjsonfile << "}";
                        //     myjsonfile.close(); // N'oubliez pas de fermer le fichier une fois que vous avez terminé de l'utiliser
                        // }


                        json mapJson;

                        mapJson["case_map"] = {
                            {
                                {
                                    {"x", row1[0].x},
                                    {"y", row1[0].y},
                                    {"obstacle", row1[0].obstacle},
                                },
                                {
                                    {"x", row1[1].x},
                                    {"y", row1[1].y},
                                    {"obstacle", row1[1].obstacle},
                                },
                                {
                                    {"x", row1[2].x},
                                    {"y", row1[2].y},
                                    {"obstacle", row1[2].obstacle},
                                },
                                {
                                    {"x", row1[3].x},
                                    {"y", row1[3].y},
                                    {"obstacle", row1[3].obstacle},
                                },
                                {
                                    {"x", row1[4].x},
                                    {"y", row1[4].y},
                                    {"obstacle", row1[4].obstacle},
                                }
                            },
                            {
                                {
                                    {"x", row2[0].x},
                                    {"y", row2[0].y},
                                    {"obstacle", row2[0].obstacle},
                                },
                                {
                                    {"x", row2[1].x},
                                    {"y", row2[1].y},
                                    {"obstacle", row2[1].obstacle},
                                },
                                {
                                    {"x", row2[2].x},
                                    {"y", row2[2].y},
                                    {"obstacle", row2[2].obstacle},
                                },
                                {
                                    {"x", row2[3].x},
                                    {"y", row2[3].y},
                                    {"obstacle", row2[3].obstacle},
                                },
                                {
                                    {"x", row2[4].x},
                                    {"y", row2[4].y},
                                    {"obstacle", row2[4].obstacle},
                                }
                            },
                            {
                                {
                                    {"x", row3[0].x},
                                    {"y", row3[0].y},
                                    {"obstacle", row3[0].obstacle},
                                },
                                {
                                    {"x", row3[1].x},
                                    {"y", row3[1].y},
                                    {"obstacle", row3[1].obstacle},
                                },
                                {
                                    {"x", row3[2].x},
                                    {"y", row3[2].y},
                                    {"obstacle", row3[2].obstacle},
                                },
                                {
                                    {"x", row3[3].x},
                                    {"y", row3[3].y},
                                    {"obstacle", row3[3].obstacle},
                                },
                                {
                                    {"x", row3[4].x},
                                    {"y", row3[4].y},
                                    {"obstacle", row3[4].obstacle},
                                }
                            },
                            {
                                {
                                    {"x", row4[0].x},
                                    {"y", row4[0].y},
                                    {"obstacle", row4[0].obstacle},
                                },
                                {
                                    {"x", row4[1].x},
                                    {"y", row4[1].y},
                                    {"obstacle", row4[1].obstacle},
                                },
                                {
                                    {"x", row4[2].x},
                                    {"y", row4[2].y},
                                    {"obstacle", row4[2].obstacle},
                                },
                                {
                                    {"x", row4[3].x},
                                    {"y", row4[3].y},
                                    {"obstacle", row4[3].obstacle},
                                },
                                {
                                    {"x", row4[4].x},
                                    {"y", row4[4].y},
                                    {"obstacle", row4[4].obstacle},
                                }
                            },
                            {
                                {
                                    {"x", row5[0].x},
                                    {"y", row5[0].y},
                                    {"obstacle", row5[0].obstacle},
                                },
                                {
                                    {"x", row5[1].x},
                                    {"y", row5[1].y},
                                    {"obstacle", row5[1].obstacle},
                                },
                                {
                                    {"x", row5[2].x},
                                    {"y", row5[2].y},
                                    {"obstacle", row5[2].obstacle},
                                },
                                {
                                    {"x", row5[3].x},
                                    {"y", row5[3].y},
                                    {"obstacle", row5[3].obstacle},
                                },
                                {
                                    {"x", row5[4].x},
                                    {"y", row5[4].y},
                                    {"obstacle", row5[4].obstacle},
                                }
                            }
                        };

                        mapJson["nbr_case_total"] = 27;
                        mapJson["difficulty"] = "easy";
                        mapJson["creator"] = "admin";

                        int sx = 0;
                        int sy = 0;
                        for (const auto& row : graph) {
                            for (const auto& node : row) {
                                if (node.start) {
                                    sx = node.x;
                                    sy = node.y;
                                }
                            }
                        }
                        mapJson["start"] = {{"x", sx}, {"y", sy}};

                        // Trouver les coordonnées du point d'arrivée
                        int ex = 0;
                        int ey = 0;
                        for (const auto& row : graph) {
                            for (const auto& node : row) {
                                if (node.end) {
                                    ex = node.x;
                                    ey = node.y;
                                }
                            }
                        }
                        mapJson["end"] = {{"x", ex}, {"y", ey}};



                        // std::cout << mapJson << std::endl;



                        std::string result = d.Post("Map", mapJson);
                        std::cout << "L'id de la map: " << result << std::endl;
                        // std::cout << "dd" << std::endl;


















                        // std::ifstream f("map.json");
                        // json map;

                        // if (f.is_open()) {
                        //         f >> map;


                        //         f.close(); // N'oubliez pas de fermer le fichier une fois que vous avez terminé de l'utiliser
                        //     }

                        // // std::cout << map.dump() << std::endl;


                    }
                }











            }
            // Si l'�v�nement est une fermeture de fen�tre
            if (event.type == sf::Event::Closed){window.close();}
        }
        window.clear();

        std::array<sf::Sprite*, 34> DrawSprite = {
            &toolbox1,
            &toolbox2,
            &toolbox3,
            &toolbox4,
            &toolbox5,
            &toolbox6,
            &toolbox7,
            &toolbox8,
            &background1,
            &background2,
            &background3,
            &background4,
            &background5,
            &background6,
            &background7,
            &background8,
            &background9,
            &background10,
            &background11,
            &background12,
            &background13,
            &background14,
            &background15,
            &background16,
            &background17,
            &background18,
            &background19,
            &background20,
            &background21,
            &background22,
            &background23,
            &background24,
            &background25,

            &sprite_spe
        };

        for (int i = 0; i < DrawSprite.size(); i++) {
            window.draw(*DrawSprite[i]);
        }

        // window.draw(toolbox1);
        // window.draw(toolbox2);
        // window.draw(toolbox3);
        // window.draw(toolbox4);
        // window.draw(toolbox5);
        // window.draw(toolbox6);
        // window.draw(toolbox7);
        // window.draw(toolbox8);

        // window.draw(background1);
        // window.draw(background2);
        // window.draw(background3);
        // window.draw(background4);
        // window.draw(background5);
        // window.draw(background6);
        // window.draw(background7);
        // window.draw(background8);
        // window.draw(background9);
        // window.draw(background10);
        // window.draw(background11);
        // window.draw(background12);
        // window.draw(background13);
        // window.draw(background14);
        // window.draw(background15);
        // window.draw(background16);
        // window.draw(background17);
        // window.draw(background18);
        // window.draw(background19);
        // window.draw(background20);
        // window.draw(background21);
        // window.draw(background22);
        // window.draw(background23);
        // window.draw(background24);
        // window.draw(background25);

        // window.draw(sprite_spe);
        window.display();
    }

    return 0;
}
