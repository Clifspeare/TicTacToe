//
// Created by spencer on 4/2/18.
//

#ifndef TICTACTOE_BOARD_H
#define TICTACTOE_BOARD_H

#include <queue>

#include "SpriteNode.h"
#include "MarkNode.h"

class GameBoard : public SpriteNode
{
public:
    typedef std::queue<std::pair<MarkNode::MarkType, sf::Vector2i>> MarksQueue;
public:
    GameBoard(sf::Texture& texture);

    MarksQueue& getMarksToPlace();

    void handleClickEvent(sf::Mouse::Button button, double x, double y);
private:
    int getClickedSquare(sf::Vector2i coordinate);
    void placeMark(int index, MarkNode::MarkType type);

    void onUpdate() override;

    /*
     * Represents the 9 possible locations on a 3x3 grid by index 1-9.
     */
    MarkNode::MarkType *m_boardSquares;
    MarksQueue m_marksToPlace;
};


#endif //TICTACTOE_BOARD_H
