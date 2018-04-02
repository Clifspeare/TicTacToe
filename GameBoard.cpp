//
// Created by spencer on 4/2/18.
//

#include "GameBoard.h"

int GameBoard::getClickedSquare(sf::Vector2f coordinate)
{
    /*
     * The gameboard has 9 locations centered in the sprite with large border margins.
     *
     */
    int indexOfClickedSquare = -1;

    if (coordinate.x > 75 && coordinate.x <= 150) {
        indexOfClickedSquare = 1;
    } else if (coordinate.x > 150 && coordinate.x <= 225) {
        indexOfClickedSquare = 2;
    } else if (coordinate.x > 225 && coordinate.x <= 300) {
        indexOfClickedSquare = 3;
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
