//
// Created by spencer on 4/4/18.
//

#include <SFML/System.hpp>
#include <random>

#include "Player.h"

Player::Player(Player::Type playerType, MarkNode::MarkType markType)
{
    m_type = playerType;
    m_mark = markType;
}

void Player::handleDirectInput(sf::Window &window, GameBoard::MarksQueue &marksQueue)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        marksQueue.push(std::pair<MarkNode::MarkType, sf::Vector2i>(m_mark, mousePos));
    }
}

void Player::handleNetworkInput()
{
    //TODO
}

void Player::handleGeneratedInput(GameBoard::MarksQueue& marksQueue)
{
    float marginOffset = 25.0f / 2;
    float stepOffset = 75.0f;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 8);
    int index = dis(gen);
    float x = marginOffset + (stepOffset * ((index % 3) + 1));
    float y = (stepOffset * ((index / 3) + 1)) + marginOffset;
    sf::Vector2i mousePos(x, y);
    marksQueue.push(std::pair<MarkNode::MarkType, sf::Vector2i>(m_mark, mousePos));
}
