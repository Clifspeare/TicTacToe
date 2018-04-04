//
// Created by spencer on 4/4/18.
//

#ifndef TICTACTOE_PLAYER_H
#define TICTACTOE_PLAYER_H


#include <SFML/Window.hpp>
#include "GameBoard.h"

class Player
{
public:
    enum Type {
        HUMAN,
        AI,
        NETWORK
    };
public:
    explicit Player(Type playerType, MarkNode::MarkType markType);

    void handleDirectInput(sf::Window& render, GameBoard::MarksQueue& marksQueue);
    void handleNetworkInput();
    void handleGeneratedInput(GameBoard::MarksQueue& marksQueue);
private:
    Type m_type;
    MarkNode::MarkType m_mark;
};


#endif //TICTACTOE_PLAYER_H
