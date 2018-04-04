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
    while (!m_marksToPlace.empty()) {
        auto pair = m_marksToPlace.front();
        int indexOfClickedSquare = getClickedSquare(pair.second);
        auto type = pair.first;
        placeMark(indexOfClickedSquare, type);
        m_marksToPlace.pop();
    }
}

std::queue<std::pair<MarkNode::MarkType, sf::Vector2i>> &GameBoard::getMarksToPlace()
{
    return m_marksToPlace;
}

bool GameBoard::hasMarkOnIndex(int boardIndex)
{
    return m_boardSquares[boardIndex] != MarkNode::MarkType::NONE;
}

MarkNode::MarkType GameBoard::checkHorizontal(int index, MarkNode::MarkType *array)
{
    if (array[index] == MarkNode::MarkType::NONE)
        return MarkNode::MarkType::NONE;
    MarkNode::MarkType type = array[index];
    if (array[index+1] == type && array[index+2] == type) {
        return type;
    }
    return MarkNode::MarkType::NONE;
}

MarkNode::MarkType GameBoard::checkVertical(int index, MarkNode::MarkType *array)
{
    if (array[index] == MarkNode::MarkType::NONE)
        return MarkNode::MarkType::NONE;
    MarkNode::MarkType type = array[index];
    if (array[index + 3] == type && array[index + 3*2] == type) {
        return type;
    }
    return MarkNode::MarkType::NONE;
}

MarkNode::MarkType GameBoard::checkDiagonal(int index, MarkNode::MarkType *array)
{
    if (array[index] == MarkNode::MarkType::NONE)
        return MarkNode::MarkType::NONE;
    MarkNode::MarkType type = array[index];
    if (index % 3 == 0) {
        if (array[index + 4] == type && array[index + 4*2] == type) {
            return type;
        }
        return MarkNode::MarkType::NONE;
    } else {
        if (array[index + 2] == type && array[index + 2*2] == type) {
            return type;
        }
        return MarkNode::MarkType::NONE;
    }
}


MarkNode::MarkType GameBoard::markWith3InARow()
{
    // diagonal: add 4, add 4; add 2, add 2; horizontal: add 1, add 2; vertical: add 3, add 3;
    /*
     * for top-left (index 0), check horizontal, vertical, and diagonal.
     * for top-right (index 2), vertical, and diagonal (horizontal is included)
     * for top-middle, check vertical.  (diagonal impossible, horizontal included).
     *
     * for middle-left (index 3), check horizontal.
     * for bottom-left (index 6), check horizontal
     */

    MarkNode::MarkType winningMark = MarkNode::MarkType::NONE;
    MarkNode::MarkType markValue[8];

    markValue[0] = checkHorizontal(0, m_boardSquares);
    markValue[1] = checkHorizontal(3, m_boardSquares);
    markValue[2] = checkHorizontal(6, m_boardSquares);
    markValue[3] = checkVertical(0, m_boardSquares);
    markValue[4] = checkVertical(1, m_boardSquares);
    markValue[5] = checkVertical(2, m_boardSquares);
    markValue[6] = checkDiagonal(0, m_boardSquares);
    markValue[7] = checkDiagonal(2, m_boardSquares);
    for (int i = 0; i < 8; ++i) {
        if (markValue[i] != MarkNode::MarkType::NONE) {
            winningMark = markValue[i];
            break;
        }
    }
    return winningMark;
}

bool GameBoard::isFull()
{
    for (int i = 0; i < 9; ++i) {
        if (m_boardSquares[i] == MarkNode::MarkType::NONE) {
            return false;
        }
    }
    return true;
}
