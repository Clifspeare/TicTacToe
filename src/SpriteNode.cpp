//
// Created by spencer on 4/2/18.
//

#include "SpriteNode.h"

SpriteNode::SpriteNode(sf::Texture &texture) : m_sprite(texture)
{
}

void SpriteNode::onDraw(sf::RenderTarget &target, sf::RenderStates renderStates) const
{
    target.draw(m_sprite, renderStates);
}