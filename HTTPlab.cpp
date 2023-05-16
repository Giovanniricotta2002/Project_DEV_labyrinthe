#include <SFML/Graphics.hpp>
#include "HTTPlab.hpp"
#include "lib/json/single_include/nlohmann/json.hpp"

using json = nlohmann::json;


HTTPlab::HTTPlab(std::string hostname, int port){
    _hostname = hostname;
    _port = port;
}

std::string HTTPlab::GetAllMap() {
    sf::Http http;
    // We'll work on http://www.sfml-dev.org
    http.setHost(_hostname, _port);
    // Prepare a request to get the 'features.php' page
    sf::Http::Request request;

    request.setMethod(sf::Http::Request::Get);
    request.setUri("/mapall/");
    request.setHttpVersion(1, 1); // HTTP 1.1
    request.setField("Content-Type", "application/json");

    // Send the request
    sf::Http::Response response = http.sendRequest(request);

    // Check the status code and display the result
    sf::Http::Response::Status status = response.getStatus();
    if (status == sf::Http::Response::Ok) {
        return response.getBody();
    }
}

std::string HTTPlab::Get(int i) {

    std::string url;
    std::string uri = "/map/";
    int param = i;
    url = uri + std::to_string(param);


    sf::Http http;
    // We'll work on http://www.sfml-dev.org
    http.setHost(_hostname, _port);
    // Prepare a request to get the 'features.php' page
    sf::Http::Request request;

    request.setMethod(sf::Http::Request::Get);
    request.setUri(url);
    request.setHttpVersion(1, 1); // HTTP 1.1
    request.setField("Content-Type", "application/json");

    // Send the request
    sf::Http::Response response = http.sendRequest(request);

    // Check the status code and display the result
    sf::Http::Response::Status status = response.getStatus();
    if (status == sf::Http::Response::Ok) {
        return response.getBody();
    }
}

std::string HTTPlab::Post(std::string name, json value) {

    std::string url;
    std::string uri = "/creation/";
    std::string param = name;
    url = uri + param;


    sf::Http http;
    // We'll work on http://www.sfml-dev.org
    http.setHost(_hostname, _port);
    // Prepare a request to get the 'features.php' page
    sf::Http::Request request;

    request.setMethod(sf::Http::Request::Post);
    request.setUri(url);
    request.setHttpVersion(1, 1); // HTTP 1.1
    request.setField("Content-Type", "application/json");
    //request.setField("map", j_map.dump());
    request.setField("map", value.dump());

    // Send the request
    sf::Http::Response response = http.sendRequest(request);

    // Check the status code and display the result
    sf::Http::Response::Status status = response.getStatus();
    if (status == sf::Http::Response::Ok) { return "ok"; }
    else { return "error"; }
}

std::string HTTPlab::Update(int id, json value){

    sf::Http http;
    // We'll work on http://www.sfml-dev.org
    http.setHost(_hostname, _port);
    // Prepare a request to get the 'features.php' page
    sf::Http::Request request;

    request.setMethod(sf::Http::Request::Put);
    request.setUri("/update/map/");
    request.setHttpVersion(1, 1); // HTTP 1.1
    request.setField("Content-Type", "application/json");

    request.setField("update", value.dump());
    request.setField("id", std::to_string(id));

    // Send the request
    sf::Http::Response response = http.sendRequest(request);

    // Check the status code and display the result
    sf::Http::Response::Status status = response.getStatus();
    if (status == sf::Http::Response::Ok) { return "ok"; }
    else { return "error"; }



    return "d";
}







/*
    case_map                | c++
    nbr_de_case_total       | c++/nodejs
    name_difficulte         | c++
    nom                     | header http post cpp
    creator                 | c++
    date_creation           | nodejs
    date_modification       | nodejs
    date_test               | WIP (nodejs/cpp)
*/


