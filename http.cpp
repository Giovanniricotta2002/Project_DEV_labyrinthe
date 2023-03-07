#include <SFML/Network.hpp>
#include <iostream>

int main() {
    sf::Http http;
    // We'll work on http://www.sfml-dev.org
    http.setHost("localhost", 8080);
    // Prepare a request to get the 'features.php' page
    sf::Http::Request request;

    request.setMethod(sf::Http::Request::Post);
    //request.setUri("/toto");
    request.setHttpVersion(1, 1); // HTTP 1.1
    request.setField("Content-Type", "application/json");
    request.setBody("prenom=Sherlock");






    // Send the request
    sf::Http::Response response = http.sendRequest(request);




    // Check the status code and display the result
    sf::Http::Response::Status status = response.getStatus();
    if (status == sf::Http::Response::Ok) {
        std::cout << response.getBody() << std::endl;
    }
    else {
        std::cout << "Error " << status << std::endl;
    }

    return 0;
}
