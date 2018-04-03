//
// Created by spencer on 4/2/18.
//

#include <iostream>
#include "MarkNode.h"

MarkNode::MarkNode(MarkNode::MarkType type) : m_type(type), SpriteNode(getTextureFromMarkType(type))
{
}

sf::Texture &MarkNode::getTextureFromMarkType(MarkNode::MarkType type)
{
    std::string texturePath;
    sf::Texture* texture = new sf::Texture();
    if (type == MarkType::O) {
        texturePath = "O.png";
    }
    else if (type == MarkType::X)
        texturePath = "X.png";
    else
        std::cerr << "UH OH" << std::endl;
    texture->loadFromFile(texturePath);
    return *texture;
}
