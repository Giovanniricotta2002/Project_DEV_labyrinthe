#ifndef _HTTPLAB
#define _HTTPLAB

#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>
#include <sstream>
#include "lib/json/single_include/nlohmann/json.hpp"

using json = nlohmann::json;


class HTTPlab {
    private:
        std::string _hostname;
        int _port;
    public:

        HTTPlab(std::string hostname, int port);

        std::string GetAllMap();
        std::string Get(int id);
        std::string Post(std::string name, json value);
        std::string Update(int id, json value);
        std::string Texturees(const sf::Sprite& sprite);

};


#endif // _HTTPLAB

