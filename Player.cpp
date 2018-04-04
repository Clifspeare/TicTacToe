//
// Created by spencer on 4/4/18.
//

#include "Player.h"

Player::Player(Player::Type playerType)
{
    m_type = playerType;
}

void Player::handleDirectInput(sf::Window &window, GameBoard::MarksQueue &marksQueue)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        marksQueue.push(std::pair<MarkNode::MarkType, sf::Vector2i>(MarkNode::MarkType::X, mousePos));
    } else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
        marksQueue.push(std::pair<MarkNode::MarkType, sf::Vector2i>(MarkNode::MarkType::O, mousePos));
    }
}

void Player::handleNetworkInput()
{
    //TODO
}
