//
// Created by spencer on 4/2/18.
//

#include "GameBoard.h"

int GameBoard::getClickedSquare(sf::Vector2f coordinate)
{
    /*
     * The gameboard has 9 locations centered in the sprite with large border margins.
     * TODO: clean this crap up
     */
    int indexOfClickedSquare = -1;
    if (coordinate.x > 75 && coordinate.x <= 300 && coordinate.y > 75 && coordinate.y <= 300) {
        if (coordinate.x > 75 && coordinate.x <= 150) { //first column
            if (coordinate.y > 75 && coordinate.y <= 150) { //first row
                indexOfClickedSquare = 1;
            } else if (coordinate.y > 150 && coordinate.y <= 225) { //second row
                indexOfClickedSquare = 4;
            } else if (coordinate.y > 225 && coordinate.y <= 300) { //third row
                indexOfClickedSquare = 7;
            }
        } else if (coordinate.x > 150 && coordinate.x <= 225) { //second column
            if (coordinate.y > 75 && coordinate.y <= 150) { //first row
                indexOfClickedSquare = 2;
            } else if (coordinate.y > 150 && coordinate.y <= 225) { //second row
                indexOfClickedSquare = 5;
            } else if (coordinate.y > 225 && coordinate.y <= 300) { //third row
                indexOfClickedSquare = 8;
            }
        } else if (coordinate.x > 225 && coordinate.x <= 300) { //third column
            if (coordinate.y > 75 && coordinate.y <= 150) { //first row
                indexOfClickedSquare = 3;
            } else if (coordinate.y > 150 && coordinate.y <= 225) { //second row
                indexOfClickedSquare = 6;
            } else if (coordinate.y > 225 && coordinate.y <= 300) { //third row
                indexOfClickedSquare = 9;
            }
        }
    }
    return indexOfClickedSquare;

}

GameBoard::GameBoard(sf::Texture &texture) : SpriteNode(texture)
{
    m_boardSquares = new int[9];
}
