#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>

#include "GameBoard.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(375, 375), "TicTacToe");

    sf::Texture texture;
    texture.loadFromFile("board.png");
    GameBoard root(texture);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    root.handleClickEvent(event.mouseButton.button, event.mouseButton.x, event.mouseButton.y);
                    break;
            }
        }
        window.clear(sf::Color::Black);
        window.draw(root);
        window.display();
    }
}