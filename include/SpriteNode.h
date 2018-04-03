//
// Created by spencer on 4/2/18.
//

#ifndef TICTACTOE_SPRITENODE_H
#define TICTACTOE_SPRITENODE_H

#include "SceneNode.h"

class SpriteNode : public SceneNode
{
public:
    SpriteNode() = default;
    explicit SpriteNode(sf::Texture& texture);
private:
    void onDraw(sf::RenderTarget &target, sf::RenderStates renderStates) const override;

    sf::Sprite m_sprite;
};


#endif //TICTACTOE_SPRITENODE_H
