#include <SFML/Network.hpp>
#include <iostream>
#include <string>
#include "lib/json/single_include/nlohmann/json.hpp"

#include "HTTPlab.hpp"

using json = nlohmann::json;


int main() {

    //ADDA t("localhost", 3000);
    HTTPlab d("localhost", 3000);




    /*json j = json::parse(d.GetAllMap());

    std::cout << j << std::endl;
    //std::cout << j["creator"] << std::endl;*/

    /*json j2 = json::parse(d.Get(1));
    std::cout << j2[0]["case_map"] << std::endl;*/
    //std::cout << j2["creator"] << std::endl;

   /* json j3 = json::parse(R"(
        {
            "case_map": [
                [1, 1, 0],
                [1, 1, 1],
                [1, 0, 1]
            ],
            "nbr_case_total": 25,
            "difficulty": "easy",
            "creator": "admin"
        }
    )");


    //d.Put(0, j3, HTTPlab::update_type::all);
    std::string test = d.Update(6, j3);
    std::cout << test << std::endl;*/





/*

    sf::Http http;
    // We'll work on http://www.sfml-dev.org
    http.setHost("localhost", 3000);
    // Prepare a request to get the 'features.php' page
    sf::Http::Request request;

    request.setMethod(sf::Http::Request::Post);
    //request.setUri("/creation/toto");
    request.setUri("/creation/toto");
    request.setHttpVersion(1, 1); // HTTP 1.1
    request.setField("Content-Type", "application/json");
    //request.setField("map", j_map.dump());
    request.setField("map", j2.dump());

    // Send the request
    sf::Http::Response response = http.sendRequest(request);
    json data;
    // Check the status code and display the result
    sf::Http::Response::Status status = response.getStatus();
    if (status == sf::Http::Response::Ok) {
        data = json::parse(response.getBody());
        std::cout << response.getBody() << std::endl;
        std::cout << data["id_map"] << std::endl;
    }
    else {
        std::cout << "Error " << status << std::endl;
    }


    std::string url;
    std::string uri = "/map/";
    int param = data["id_map"];
    url = uri + std::to_string(param);


    // Prepare a request to get the 'features.php' page
    sf::Http::Request request2;

    //request2.setMethod(sf::Http::Request::Get);
    //request.setUri("/creation/toto");
    request2.setUri(url);
    request2.setHttpVersion(1, 1); // HTTP 1.1
    request2.setField("Content-Type", "application/json");
    //request.setField("map", j_map.dump());
    request2.setField("map", j2.dump());

    // Send the request
    sf::Http::Response response2 = http.sendRequest(request2);

    // Check the status code and display the result
    sf::Http::Response::Status status2 = response2.getStatus();
    if (status2 == sf::Http::Response::Ok) {
        std::cout << response2.getBody() << std::endl;
    }
    else {
        std::cout << "Error " << status << std::endl;
    }*/

    return 0;
}
/*
{"creator":"tata","date_creation":"2023-03-28T10:17:44.401Z","id_map":1,"nom":"toto"}
"tata"

*/
