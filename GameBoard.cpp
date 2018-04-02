//
// Created by spencer on 4/2/18.
//

#include "GameBoard.h"
#include <memory>
#include <iostream>

int GameBoard::getClickedSquare(sf::Vector2f coordinate)
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
    m_boardSquares = new int[9];
}

void GameBoard::handleClickEvent(double x, double y)
{
    sf::Vector2f clickCoordinate(x, y);
    int indexOfClickedSquare = getClickedSquare(clickCoordinate);
    auto texture = new sf::Texture();
    if (lastPlaced == 0 || lastPlaced == 2) {
        texture->loadFromFile("X.png");
        lastPlaced = 1;
    }
    else {
        texture->loadFromFile("O.png");
        lastPlaced = 2;
    }
    placeMark(indexOfClickedSquare, *texture);
}

void GameBoard::placeMark(int index, sf::Texture& texture)
{
    float marginOffset = 25.0f / 2;
    float stepOffset = 75.0f;

    if (index != -1) {
        std::unique_ptr<SpriteNode> xNode(new SpriteNode(texture));
        xNode->move( marginOffset + (stepOffset * ((index % 3) + 1)), (stepOffset * ((index / 3) + 1)) + marginOffset);
        attachChild(std::move(xNode));
    }
}
