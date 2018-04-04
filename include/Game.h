//
// Created by spencer on 4/3/18.
//

#ifndef TICTACTOE_GAME_H
#define TICTACTOE_GAME_H


#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "SpriteNode.h"
#include "GameBoard.h"
#include "Player.h"

class Game
{
public:
    Game();

    void run();
private:
    void update();
    void render();
    void handleEvents();
    void setup();

    sf::Texture& getTextureForBoard();

    sf::RenderWindow m_window;
    sf::Event m_event;
    GameBoard m_root;
    sf::Texture* m_tempTexture;
    Player m_player;
};


#endif //TICTACTOE_GAME_H
