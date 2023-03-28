#include <SFML/Network.hpp>
#include <iostream>
#include "lib/json/single_include/nlohmann/json.hpp"

using json = nlohmann::json;


int main() {

    /*json j2 = {
        "name"= "toto",
        "dif": "easy"
        "map": {
                [0, 1, 0],
                [1, 1, 1],
                [1, 0, 1]
            }
    };*/


    json j2 = json::parse(R"(
        {
            "name": "toto",
            "dif": "easy",
            "map": {
                [0, 1, 0],
                [1, 1, 1],
                [1, 0, 1]
            }
        }
    )");





    sf::Http http;
    // We'll work on http://www.sfml-dev.org
    http.setHost("localhost", 3000);
    // Prepare a request to get the 'features.php' page
    sf::Http::Request request;

    request.setMethod(sf::Http::Request::Post);
    request.setUri("/creation/toto");
    request.setHttpVersion(1, 1); // HTTP 1.1
    request.setField("Content-Type", "application/json");
    //request.setField("map", j_map.dump());
    request.setField("map", j2.dump());

    // Send the request
    sf::Http::Response response = http.sendRequest(request);

    // Check the status code and display the result
    sf::Http::Response::Status status = response.getStatus();
    if (status == sf::Http::Response::Ok) {
        json data = json::parse(response.getBody());
        std::cout << response.getBody() << std::endl;
        std::cout << data["map"][0][0] << std::endl;
        std::cout << data["map"][0][1] << std::endl;
        std::cout << data["map"][0][2] << std::endl;
    }
    else {
        std::cout << "Error " << status << std::endl;
    }

    return 0;
}
