#include <SFML/Graphics.hpp>
#include <iostream>


#define max_number_of_items 3

class Menu {
    public:
        Menu(float width, float height);
        ~Menu();

        void draw(sf::RenderWindow &window);
        void MoveUp();
        void MoveDown();

    private:
        int selectedItemIndex;
        sf::Sprite sprite[max_number_of_items];
};
