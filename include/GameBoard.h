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
    int getClickedSquare(sf::Vector2i coordinate);
    bool hasMarkOnIndex(int boardIndex);
    bool has3InARow();
    bool isFull();
private:
    void placeMark(int index, MarkNode::MarkType type);
    MarkNode::MarkType checkDiagonal(int index, MarkNode::MarkType *array);
    MarkNode::MarkType checkVertical(int index, MarkNode::MarkType *array);
    MarkNode::MarkType checkHorizontal(int index, MarkNode::MarkType *array);

    void onUpdate() override;

    /*
     * Represents the 9 possible locations on a 3x3 grid by index 1-9.
     */
    MarkNode::MarkType *m_boardSquares;
    MarksQueue m_marksToPlace;
};


#endif //TICTACTOE_BOARD_H
