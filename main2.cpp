#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <fstream>
#include "lib/json/single_include/nlohmann/json.hpp"

#include "HTTPlab.hpp"
// #include "HTTPlab.cpp"
using json = nlohmann::json;

int main()
{

    HTTPlab d("localhost", 3000);

    sf::RenderWindow window(sf::VideoMode(1000, 500), "SFML Window");
    sf::Texture texture;
    sf::Texture texture2;
    sf::Texture texture4;
    sf::Texture texture5;
    sf::Texture texture6;
    sf::Texture texture7;
    sf::Texture texture8;
    sf::Texture texture9;
    sf::Texture texture10;

    sf::Texture texture1;

    const sf::Texture *texture3;

    texture.setSmooth(true);
    texture2.setSmooth(true);
    texture4.setSmooth(true);
    texture5.setSmooth(true);
    texture6.setSmooth(true);
    texture7.setSmooth(true);
    texture8.setSmooth(true);
    texture9.setSmooth(true);
    texture10.setSmooth(true);

    texture1.setSmooth(true);

    if (!texture.loadFromFile("tiles/mur.png"))
    {
        return -1;
    }
    if (!texture1.loadFromFile("tiles/herbe.png"))
    {
        return -1;
    }
    if (!texture2.loadFromFile("tiles/fin.png"))
    {
        return -1;
    }
    if (!texture4.loadFromFile("tiles/piege.png"))
    {
        return -1;
    }
    if (!texture5.loadFromFile("tiles/mur_cassable.png"))
    {
        return -1;
    }
    if (!texture6.loadFromFile("tiles/piege_vitesse.png"))
    {
        return -1;
    }
    if (!texture7.loadFromFile("tiles/interrupteur_tiles/interrupteur16.png"))
    {
        return -1;
    }
    if (!texture8.loadFromFile("tiles/start.png"))
    {
        return -1;
    }
    if (!texture9.loadFromFile("tiles/BORDURE.png"))
    {
        return -1;
    }
    if (!texture10.loadFromFile("tiles/bouton/bouton_save.png"))
    {
        return -1;
    }
    // sprite outils
    sf::Sprite toolbox1(texture);
    sf::Sprite toolbox2(texture1);
    sf::Sprite toolbox3(texture2);
    sf::Sprite toolbox4(texture4);
    sf::Sprite toolbox5(texture5);
    sf::Sprite toolbox6(texture6);
    sf::Sprite toolbox7(texture7);
    sf::Sprite toolbox8(texture8);
    // sprite map
    sf::Sprite background1(texture1);
    sf::Sprite background2(texture1);
    sf::Sprite background3(texture1);
    sf::Sprite background4(texture1);
    sf::Sprite background5(texture1);
    sf::Sprite background6(texture1);
    sf::Sprite background7(texture1);
    sf::Sprite background8(texture1);
    sf::Sprite background9(texture1);
    sf::Sprite background10(texture1);
    sf::Sprite background11(texture1);
    sf::Sprite background12(texture1);
    sf::Sprite background13(texture1);
    sf::Sprite background14(texture1);
    sf::Sprite background15(texture1);
    sf::Sprite background16(texture1);
    sf::Sprite background17(texture1);
    sf::Sprite background18(texture1);
    sf::Sprite background19(texture1);
    sf::Sprite background20(texture1);
    sf::Sprite background21(texture1);
    sf::Sprite background22(texture1);
    sf::Sprite background23(texture1);
    sf::Sprite background24(texture1);
    sf::Sprite background25(texture1);
    // sprite ligne jaune en pointill�
    sf::Sprite yellow_line(texture9);
    // sprite bouton sauvegard�
    sf::Sprite bouton_save(texture10);

    background1.setPosition(158, 100);
    background2.setPosition(216, 100);
    background3.setPosition(274, 100);
    background4.setPosition(332, 100);
    background5.setPosition(390, 100);
    background6.setPosition(158, 158);
    background7.setPosition(216, 158);
    background8.setPosition(274, 158);
    background9.setPosition(332, 158);
    background10.setPosition(390, 158);
    background11.setPosition(158, 216);
    background12.setPosition(216, 216);
    background13.setPosition(274, 216);
    background14.setPosition(332, 216);
    background15.setPosition(390, 216);
    background16.setPosition(158, 274);
    background17.setPosition(216, 274);
    background18.setPosition(274, 274);
    background19.setPosition(332, 274);
    background20.setPosition(390, 274);
    background21.setPosition(158, 332);
    background22.setPosition(216, 332);
    background23.setPosition(274, 332);
    background24.setPosition(332, 332);
    background25.setPosition(390, 332);

    toolbox1.setPosition(700, 58);
    toolbox2.setPosition(758, 58);
    toolbox3.setPosition(816, 58);
    toolbox4.setPosition(874, 58);
    toolbox5.setPosition(932, 58);
    toolbox6.setPosition(700, 116);
    toolbox7.setPosition(758, 116);
    toolbox8.setPosition(816, 116);

    yellow_line.setPosition(550, 0);

    bouton_save.setPosition(158, 400);

    while (window.isOpen())
    {
        // G�rez les �v�nements de la fen�tre
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::MouseButtonPressed)
            {
                // background
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                sf::FloatRect spriteBounds11 = background1.getGlobalBounds();
                if (spriteBounds11.contains(mousePosition.x, mousePosition.y))
                {
                    // std::cout << "La souris est sur le sprite !" << std::endl;
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        std::cout << texture3 << std::endl;
                        background1.setTexture(*texture3);
                    }
                }

                sf::FloatRect spriteBounds12 = background2.getGlobalBounds();
                if (spriteBounds12.contains(mousePosition.x, mousePosition.y))
                {
                    // std::cout << "La souris est sur le sprite !" << std::endl;
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        std::cout << texture3 << std::endl;
                        background2.setTexture(*texture3);
                    }
                }

                sf::FloatRect spriteBounds13 = background3.getGlobalBounds();
                if (spriteBounds13.contains(mousePosition.x, mousePosition.y))
                {
                    // std::cout << "La souris est sur le sprite !" << std::endl;
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        std::cout << texture3 << std::endl;
                        background3.setTexture(*texture3);
                    }
                }

                sf::FloatRect spriteBounds14 = background4.getGlobalBounds();
                if (spriteBounds14.contains(mousePosition.x, mousePosition.y))
                {
                    // std::cout << "La souris est sur le sprite !" << std::endl;
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        std::cout << texture3 << std::endl;
                        background4.setTexture(*texture3);
                    }
                }

                sf::FloatRect spriteBounds15 = background5.getGlobalBounds();
                if (spriteBounds15.contains(mousePosition.x, mousePosition.y))
                {
                    // std::cout << "La souris est sur le sprite !" << std::endl;
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        std::cout << texture3 << std::endl;
                        background5.setTexture(*texture3);
                    }
                }

                sf::FloatRect spriteBounds16 = background6.getGlobalBounds();
                if (spriteBounds16.contains(mousePosition.x, mousePosition.y))
                {
                    // std::cout << "La souris est sur le sprite !" << std::endl;
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        std::cout << texture3 << std::endl;
                        background6.setTexture(*texture3);
                    }
                }

                sf::FloatRect spriteBounds17 = background7.getGlobalBounds();
                if (spriteBounds17.contains(mousePosition.x, mousePosition.y))
                {
                    // std::cout << "La souris est sur le sprite !" << std::endl;
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        std::cout << texture3 << std::endl;
                        background7.setTexture(*texture3);
                    }
                }

                sf::FloatRect spriteBounds18 = background8.getGlobalBounds();
                if (spriteBounds18.contains(mousePosition.x, mousePosition.y))
                {
                    // std::cout << "La souris est sur le sprite !" << std::endl;
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        std::cout << texture3 << std::endl;
                        background8.setTexture(*texture3);
                    }
                }

                sf::FloatRect spriteBounds19 = background9.getGlobalBounds();
                if (spriteBounds19.contains(mousePosition.x, mousePosition.y))
                {
                    // std::cout << "La souris est sur le sprite !" << std::endl;
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        std::cout << texture3 << std::endl;
                        background9.setTexture(*texture3);
                    }
                }

                sf::FloatRect spriteBounds20 = background10.getGlobalBounds();
                if (spriteBounds20.contains(mousePosition.x, mousePosition.y))
                {
                    // std::cout << "La souris est sur le sprite !" << std::endl;
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        std::cout << texture3 << std::endl;
                        background10.setTexture(*texture3);
                    }
                }

                sf::FloatRect spriteBounds21 = background11.getGlobalBounds();
                if (spriteBounds21.contains(mousePosition.x, mousePosition.y))
                {
                    // std::cout << "La souris est sur le sprite !" << std::endl;
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        std::cout << texture3 << std::endl;
                        background11.setTexture(*texture3);
                    }
                }

                sf::FloatRect spriteBounds22 = background12.getGlobalBounds();
                if (spriteBounds22.contains(mousePosition.x, mousePosition.y))
                {
                    // std::cout << "La souris est sur le sprite !" << std::endl;
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        std::cout << texture3 << std::endl;
                        background12.setTexture(*texture3);
                    }
                }

                sf::FloatRect spriteBounds23 = background13.getGlobalBounds();
                if (spriteBounds23.contains(mousePosition.x, mousePosition.y))
                {
                    // std::cout << "La souris est sur le sprite !" << std::endl;
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        std::cout << texture3 << std::endl;
                        background13.setTexture(*texture3);
                    }
                }

                sf::FloatRect spriteBounds24 = background14.getGlobalBounds();
                if (spriteBounds24.contains(mousePosition.x, mousePosition.y))
                {
                    // std::cout << "La souris est sur le sprite !" << std::endl;
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        std::cout << texture3 << std::endl;
                        background14.setTexture(*texture3);
                    }
                }

                sf::FloatRect spriteBounds25 = background15.getGlobalBounds();
                if (spriteBounds25.contains(mousePosition.x, mousePosition.y))
                {
                    // std::cout << "La souris est sur le sprite !" << std::endl;
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        std::cout << texture3 << std::endl;
                        background15.setTexture(*texture3);
                    }
                }

                sf::FloatRect spriteBounds26 = background16.getGlobalBounds();
                if (spriteBounds26.contains(mousePosition.x, mousePosition.y))
                {
                    // std::cout << "La souris est sur le sprite !" << std::endl;
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        std::cout << texture3 << std::endl;
                        background16.setTexture(*texture3);
                    }
                }

                sf::FloatRect spriteBounds27 = background17.getGlobalBounds();
                if (spriteBounds27.contains(mousePosition.x, mousePosition.y))
                {
                    // std::cout << "La souris est sur le sprite !" << std::endl;
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        std::cout << texture3 << std::endl;
                        background17.setTexture(*texture3);
                    }
                }

                sf::FloatRect spriteBounds28 = background18.getGlobalBounds();
                if (spriteBounds28.contains(mousePosition.x, mousePosition.y))
                {
                    // std::cout << "La souris est sur le sprite !" << std::endl;
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        std::cout << texture3 << std::endl;
                        background18.setTexture(*texture3);
                    }
                }

                sf::FloatRect spriteBounds29 = background19.getGlobalBounds();
                if (spriteBounds29.contains(mousePosition.x, mousePosition.y))
                {
                    // std::cout << "La souris est sur le sprite !" << std::endl;
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        std::cout << texture3 << std::endl;
                        background19.setTexture(*texture3);
                    }
                }

                sf::FloatRect spriteBounds30 = background20.getGlobalBounds();
                if (spriteBounds30.contains(mousePosition.x, mousePosition.y))
                {
                    // std::cout << "La souris est sur le sprite !" << std::endl;
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        std::cout << texture3 << std::endl;
                        background20.setTexture(*texture3);
                    }
                }

                sf::FloatRect spriteBounds31 = background21.getGlobalBounds();
                if (spriteBounds31.contains(mousePosition.x, mousePosition.y))
                {
                    // std::cout << "La souris est sur le sprite !" << std::endl;
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        std::cout << texture3 << std::endl;
                        background21.setTexture(*texture3);
                    }
                }

                sf::FloatRect spriteBounds32 = background22.getGlobalBounds();
                if (spriteBounds32.contains(mousePosition.x, mousePosition.y))
                {
                    // std::cout << "La souris est sur le sprite !" << std::endl;
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        std::cout << texture3 << std::endl;
                        background22.setTexture(*texture3);
                    }
                }

                sf::FloatRect spriteBounds33 = background23.getGlobalBounds();
                if (spriteBounds33.contains(mousePosition.x, mousePosition.y))
                {
                    // std::cout << "La souris est sur le sprite !" << std::endl;
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        std::cout << texture3 << std::endl;
                        background23.setTexture(*texture3);
                    }
                }

                sf::FloatRect spriteBounds34 = background24.getGlobalBounds();
                if (spriteBounds34.contains(mousePosition.x, mousePosition.y))
                {
                    // std::cout << "La souris est sur le sprite !" << std::endl;
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        std::cout << texture3 << std::endl;
                        background24.setTexture(*texture3);
                    }
                }

                sf::FloatRect spriteBounds35 = background25.getGlobalBounds();
                if (spriteBounds35.contains(mousePosition.x, mousePosition.y))
                {
                    // std::cout << "La souris est sur le sprite !" << std::endl;
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        std::cout << texture3 << std::endl;
                        background25.setTexture(*texture3);
                    }
                }
                // toolbox
                sf::FloatRect spriteBounds2 = toolbox1.getGlobalBounds();
                if (spriteBounds2.contains(mousePosition.x, mousePosition.y))
                {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        texture3 = toolbox1.getTexture();
                        std::cout << "Adresse memoire de la texture spirte2: " << texture3 << std::endl;
                    }
                }
                sf::FloatRect spriteBounds3 = toolbox2.getGlobalBounds();
                if (spriteBounds3.contains(mousePosition.x, mousePosition.y))
                {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        texture3 = toolbox2.getTexture();
                        std::cout << "Adresse memoire de la texture spirte2: " << texture3 << std::endl;
                    }
                }
                sf::FloatRect spriteBounds4 = toolbox3.getGlobalBounds();
                if (spriteBounds4.contains(mousePosition.x, mousePosition.y))
                {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        texture3 = toolbox3.getTexture();
                        std::cout << "Adresse memoire de la texture spirte2: " << texture3 << std::endl;
                    }
                }
                sf::FloatRect spriteBounds5 = toolbox4.getGlobalBounds();
                if (spriteBounds5.contains(mousePosition.x, mousePosition.y))
                {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        texture3 = toolbox4.getTexture();
                        std::cout << "Adresse memoire de la texture spirte2: " << texture3 << std::endl;
                    }
                }
                sf::FloatRect spriteBounds6 = toolbox5.getGlobalBounds();
                if (spriteBounds6.contains(mousePosition.x, mousePosition.y))
                {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        texture3 = toolbox5.getTexture();
                        std::cout << "Adresse memoire de la texture spirte2: " << texture3 << std::endl;
                    }
                }
                sf::FloatRect spriteBounds7 = toolbox6.getGlobalBounds();
                if (spriteBounds7.contains(mousePosition.x, mousePosition.y))
                {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        texture3 = toolbox6.getTexture();
                        std::cout << "Adresse memoire de la texture spirte2: " << texture3 << std::endl;
                    }
                }
                sf::FloatRect spriteBounds8 = toolbox7.getGlobalBounds();
                if (spriteBounds8.contains(mousePosition.x, mousePosition.y))
                {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        texture3 = toolbox7.getTexture();
                        std::cout << "Adresse memoire de la texture spirte2: " << texture3 << std::endl;
                    }
                }
                sf::FloatRect spriteBounds9 = toolbox8.getGlobalBounds();
                if (spriteBounds9.contains(mousePosition.x, mousePosition.y))
                {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        texture3 = toolbox8.getTexture();
                        std::cout << "Adresse memoire de la texture spirte2: " << texture3 << std::endl;
                    }
                }
                // special
                sf::FloatRect boutonBound = bouton_save.getGlobalBounds();
                if (boutonBound.contains(mousePosition.x, mousePosition.y))
                {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        std::cout << "labyrinth sauvegarder" << std::endl;

                        /*json jsonMapPost = json::parse(R"(
                            {
                                'case_map': [
                                    [background1.getTexture(), background2.getTexture(), background3.getTexture(), background4.getTexture(), background5.getTexture()],
                                    [background6.getTexture(), background7.getTexture(), background8.getTexture(), background9.getTexture(), background10.getTexture()],
                                    [background11.getTexture(), background12.getTexture(), background13.getTexture(), background14.getTexture(), background15.getTexture()],
                                    [background16.getTexture(), background17.getTexture(), background18.getTexture(), background19.getTexture(), background20.getTexture()],
                                    [background21.getTexture(), background22.getTexture(), background23.getTexture(), background24.getTexture(), background25.getTexture()]
                                ],
                                'nbr_case_total': 25,
                                'difficulty': 'normal',
                                'creator': 'exemple'
                            }
                        )");*/

                        json map05 = json::array();

                        map05.push_back(background1.getTexture());
                        map05.push_back(background2.getTexture());
                        map05.push_back(background3.getTexture());
                        map05.push_back(background4.getTexture());
                        map05.push_back(background5.getTexture());

                        json map15 = json::array();

                        map15.push_back(background6.getTexture());
                        map15.push_back(background7.getTexture());
                        map15.push_back(background8.getTexture());
                        map15.push_back(background9.getTexture());
                        map15.push_back(background10.getTexture());

                        json map25 = json::array();

                        map25.push_back(background11.getTexture());
                        map25.push_back(background12.getTexture());
                        map25.push_back(background13.getTexture());
                        map25.push_back(background14.getTexture());
                        map25.push_back(background15.getTexture());

                        json map35 = json::array();

                        map35.push_back(background16.getTexture());
                        map35.push_back(background17.getTexture());
                        map35.push_back(background18.getTexture());
                        map35.push_back(background19.getTexture());
                        map35.push_back(background20.getTexture());

                        json map45 = json::array();

                        map45.push_back(background21.getTexture());
                        map45.push_back(background22.getTexture());
                        map45.push_back(background23.getTexture());
                        map45.push_back(background24.getTexture());
                        map45.push_back(background25.getTexture());

                        json jsonMapPost;
                        jsonMapPost["case_map"][0] = map05;
                        jsonMapPost["case_map"][0] = map15;
                        jsonMapPost["case_map"][0] = map25;
                        jsonMapPost["case_map"][0] = map35;
                        jsonMapPost["case_map"][0] = map45;
                        jsonMapPost["nbr_case_total"] = 25;
                        jsonMapPost["difficulty"] = "normal";
                        jsonMapPost["creator"] = "exemple";

                        // std::string result = d.Post("Map", jsonMapPost);
                        // std::cout << result << std::endl;

                        std::ofstream myfile("map.txt");
                        if (myfile.is_open())
                        {
                            myfile << background1.getTexture();
                            myfile << "   ";
                            myfile << background2.getTexture();
                            myfile << "   ";
                            myfile << background3.getTexture();
                            myfile << "   ";
                            myfile << background4.getTexture();
                            myfile << "   ";
                            myfile << background5.getTexture();
                            myfile << " \n";
                            myfile << background6.getTexture();
                            myfile << "   ";
                            myfile << background7.getTexture();
                            myfile << "   ";
                            myfile << background8.getTexture();
                            myfile << "   ";
                            myfile << background9.getTexture();
                            myfile << "   ";
                            myfile << background10.getTexture();
                            myfile << " \n";
                            myfile << background11.getTexture();
                            myfile << "   ";
                            myfile << background12.getTexture();
                            myfile << "   ";
                            myfile << background13.getTexture();
                            myfile << "   ";
                            myfile << background14.getTexture();
                            myfile << "   ";
                            myfile << background15.getTexture();
                            myfile << " \n";
                            myfile << background16.getTexture();
                            myfile << "   ";
                            myfile << background17.getTexture();
                            myfile << "   ";
                            myfile << background18.getTexture();
                            myfile << "   ";
                            myfile << background19.getTexture();
                            myfile << "   ";
                            myfile << background20.getTexture();
                            myfile << " \n";
                            myfile << background21.getTexture();
                            myfile << "   ";
                            myfile << background22.getTexture();
                            myfile << "   ";
                            myfile << background23.getTexture();
                            myfile << "   ";
                            myfile << background24.getTexture();
                            myfile << "   ";
                            myfile << background25.getTexture();
                        }
                    }
                }
            }
            // Si l'�v�nement est une fermeture de fen�tre
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        window.clear();
        window.draw(toolbox1);
        window.draw(toolbox2);
        window.draw(toolbox3);
        window.draw(toolbox4);
        window.draw(toolbox5);
        window.draw(toolbox6);
        window.draw(toolbox7);
        window.draw(toolbox8);

        window.draw(background1);
        window.draw(background2);
        window.draw(background3);
        window.draw(background4);
        window.draw(background5);
        window.draw(background6);
        window.draw(background7);
        window.draw(background8);
        window.draw(background9);
        window.draw(background10);
        window.draw(background11);
        window.draw(background12);
        window.draw(background13);
        window.draw(background14);
        window.draw(background15);
        window.draw(background16);
        window.draw(background17);
        window.draw(background18);
        window.draw(background19);
        window.draw(background20);
        window.draw(background21);
        window.draw(background22);
        window.draw(background23);
        window.draw(background24);
        window.draw(background25);

        window.draw(yellow_line);

        window.draw(bouton_save);

        window.display();
    }

    json jsonGetAll = json::parse(d.GetAllMap());
    std::cout << jsonGetAll << std::endl;

    json jsonGetId = json::parse(d.Get(1));
    std::cout << jsonGetId << std::endl;

    json jsonPost = json::parse(R"(
            {
                "case_map": [
                    [1, 0, 0, 0, 1],
                    [1, 1, 1, 1, 1],
                    [1, 0, 1, 0, 1],
                    [1, 0, 0, 0, 1],
                    [1, 0, 1, 0, 1]
                ],
                "nbr_case_total": 25,
                "difficulty": "easy",
                "creator": "admin"
            }
        )");
    return 0;
}
