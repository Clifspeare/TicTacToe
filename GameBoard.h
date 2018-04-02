//
// Created by spencer on 4/2/18.
//

#ifndef TICTACTOE_BOARD_H
#define TICTACTOE_BOARD_H


#include "SpriteNode.h"

class GameBoard : public SpriteNode
{
public:
    GameBoard(sf::Texture& texture);

    void handleClickEvent(double x, double y);
private:
    int getClickedSquare(sf::Vector2f coordinate);
    void placeX(int index);

    /*
     * Represents the 9 possible locations on a 3x3 grid by index 1-9.
     */
    int *m_boardSquares;
};


#endif //TICTACTOE_BOARD_H
