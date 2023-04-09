#include <SFML/Network.hpp>
#include <iostream>
#include <string>
#include "lib/json/single_include/nlohmann/json.hpp"

#include "HTTPlab.hpp"

using json = nlohmann::json;


int main() {

    HTTPlab d("localhost", 3000);

    
    json jsonGetAll = json::parse(d.GetAllMaps());
    std::cout << jsonGetAll << std::endl;

    json jsonGetid = json::parse(d.Get(1));
    std::cout << jsonGetId << std::endl;


    json jsonPost = json::parse(R"(
            {
                "case_map": [
                    [1, 1, 0],
                    [1, 1, 1],
                    [1, 0, 1]
                ],
                "nbr_case_total": 27,
                "difficulty": "easy",
                "creator": "admin"
            }
        )");

    std::string post = d.Post("exempleMap", jsonPost);
    std::cout << post << std::endl;

    json jsonUpdate = json::parse(R"(
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


    std::string update = d.Update(6, jsonUpdate);
    std::cout << update << std::endl;




    return 0;
}
