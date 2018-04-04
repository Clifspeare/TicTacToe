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

    bool handleDirectInput(sf::Event event, GameBoard::MarksQueue& marksQueue);
    bool handleNetworkInput();
    bool handleGeneratedInput(GameBoard::MarksQueue& marksQueue);

    Type getType() {return m_type;}
private:
    Type m_type;
    MarkNode::MarkType m_mark;
};


#endif //TICTACTOE_PLAYER_H
