//
// Created by spencer on 4/3/18.
//

#include "GameBoard.h"
#include "Game.h"

Game::Game() : m_window(sf::VideoMode(375, 375), "TicTacToe"), m_event()
        , m_root(getTextureForBoard()), m_player(Player::Type::HUMAN, MarkNode::MarkType::X)
        , m_aiPlayer(Player::Type::AI, MarkNode::MarkType::O)
{
}

void Game::run()
{
    setup();

    while (m_window.isOpen()) {
        handleEvents();
        update();
        render();
    }
}

void Game::handleEvents()
{
    while (m_window.pollEvent(m_event)) {
        switch (m_event.type) {
            case sf::Event::Closed:
                m_window.close();
                break;
        }
    }
    m_player.handleDirectInput(m_window, m_root.getMarksToPlace());
    m_aiPlayer.handleGeneratedInput(m_root.getMarksToPlace());
}

void Game::render()
{
    m_window.clear(sf::Color::Black);
    m_window.draw(m_root);
    m_window.display();
}

void Game::update()
{
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
