//
// Created by spencer on 4/2/18.
//

#include "GameBoard.h"
#include <memory>
#include <iostream>

int GameBoard::getClickedSquare(sf::Vector2i coordinate)
{
    /*
     * The gameboard has 9 locations centered in the sprite with large border margins. (0 - 8)
     *
     */
    int indexOfClickedSquare = -1;

    if (coordinate.x > 75 && coordinate.x <= 150) {
        indexOfClickedSquare = 0;
    } else if (coordinate.x > 150 && coordinate.x <= 225) {
        indexOfClickedSquare = 1;
    } else if (coordinate.x > 225 && coordinate.x <= 300) {
        indexOfClickedSquare = 2;
    }

    if (coordinate.y > 75 && coordinate.y <= 150) {
        indexOfClickedSquare += 0;
    } else if (coordinate.y > 150 && coordinate.y <= 225) {
        indexOfClickedSquare += 3;
    } else if (coordinate.y > 225 && coordinate.y <= 300) {
        indexOfClickedSquare += 6;
    }

    return indexOfClickedSquare;

}

GameBoard::GameBoard(sf::Texture &texture) : SpriteNode(texture)
{
    m_boardSquares = new MarkNode::MarkNode::MarkType[9];
    for (int i = 0; i < 9; ++i) {
        m_boardSquares[i] = MarkNode::MarkType::NONE;
    }
}

void GameBoard::handleClickEvent(sf::Mouse::Button button, double x, double y)
{
    int indexOfClickedSquare = getClickedSquare(sf::Vector2i(x, y));
    MarkNode::MarkType type = ( (button == sf::Mouse::Button::Left) ? MarkNode::MarkType::X : MarkNode::MarkType::O );
    placeMark(indexOfClickedSquare, type);
}

void GameBoard::placeMark(int index, MarkNode::MarkType type)
{
    float marginOffset = 25.0f / 2;
    float stepOffset = 75.0f;

    if (index != -1 && (m_boardSquares[index] == MarkNode::MarkType::NONE)) {
        std::unique_ptr<MarkNode> mark(new MarkNode(type));
        mark->move( marginOffset + (stepOffset * ((index % 3) + 1)), (stepOffset * ((index / 3) + 1)) + marginOffset);
        attachChild(std::move(mark));
        m_boardSquares[index] = type;
    }
}

void GameBoard::onUpdate()
{

}

std::queue<std::pair<MarkNode::MarkType, sf::Vector2i>> &GameBoard::getMarksToPlace()
{
    return m_marksToPlace;
}
