#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "SpriteNode.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(375, 375), "TicTacToe");

    sf::Texture texture;
    texture.loadFromFile("board.png");
    SpriteNode root(texture);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    // do
                    break;
            }
        }
        window.clear(sf::Color::Black);
        window.draw(root);
        window.display();
    }
}