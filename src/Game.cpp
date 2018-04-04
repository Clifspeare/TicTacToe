//
// Created by spencer on 4/3/18.
//

#include <iostream>
#include <wait.h>

#include "GameBoard.h"
#include "Game.h"

Game::Game() : m_window(sf::VideoMode(375, 375), "TicTacToe"), m_event()
        , m_root(getTextureForBoard())
        , m_playerQueue()
{
    m_playerQueue.push(Player(Player::Type::HUMAN, MarkNode::MarkType::X));
    m_playerQueue.push(Player(Player::Type::AI, MarkNode::MarkType::O));
}

void Game::run()
{
    setup();

    while (m_window.isOpen() && !m_gameIsWon) {
        handleEvents();
        update();
        render();
    }
    sf::RectangleShape rect(sf::Vector2f(m_window.getSize().x, m_window.getSize().y));
    rect.setFillColor(sf::Color::Blue);
    sf::Font font;
    font.loadFromFile("/usr/share/fonts/truetype/hack/Hack-Regular.ttf");
    sf::Text text("GAME OVER.", font);
    sf::Text text1("Winner:  " + MarkNode::getNameOfMark(m_root.markWith3InARow()), font);
    text.move(((m_window.getSize().x / 2) - (text.getLocalBounds().width / 2)), 0);
    text1.move(((m_window.getSize().x / 2) - (text.getLocalBounds().width / 2)), text.getLocalBounds().height + text.getLocalBounds().height / 2);

    while (m_gameIsWon && m_window.isOpen()) {
        handleEvents();
        m_window.clear(sf::Color::Black);
        m_window.draw(rect);
        m_window.draw(text);
        m_window.draw(text1);
        m_window.display();
    }
    m_window.close();
}

void Game::handleEvents()
{
    Player p = m_playerQueue.front();
    bool didTurn = false;

    while (m_window.pollEvent(m_event)) {
        switch (m_event.type) {
            case sf::Event::Closed:
                m_window.close();
                break;
            case sf::Event::MouseButtonPressed:
                p = m_playerQueue.front();
                if (p.getType() == Player::Type::HUMAN) {
                    didTurn = p.handleDirectInput(m_event, m_root.getMarksToPlace())
                              && !m_root.hasMarkOnIndex(m_root.getClickedSquare(m_root.getMarksToPlace().back().second));
                }
        }
    }

    if (p.getType() == Player::Type::AI) {
        didTurn = p.handleGeneratedInput(m_root.getMarksToPlace())
                  && !m_root.hasMarkOnIndex(m_root.getClickedSquare(m_root.getMarksToPlace().back().second));
    }
    if (didTurn) {
        m_playerQueue.push(p);
        m_playerQueue.pop();
    }
}

void Game::render()
{
    m_window.clear(sf::Color::Black);
    m_window.draw(m_root);
    m_window.display();
}

void Game::update()
{
    if ((m_root.markWith3InARow() != MarkNode::MarkType::NONE) || (m_root.isFull())) {
        m_gameIsWon = true;
        std::cout << "WINNER IS: " << MarkNode::getNameOfMark(m_root.markWith3InARow());
    }
    m_root.update();
}

void Game::setup()
{

}

sf::Texture& Game::getTextureForBoard()
{
    m_tempTexture = new sf::Texture();
    m_tempTexture->loadFromFile("board.png");
    return *m_tempTexture;
}
