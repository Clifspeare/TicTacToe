//
// Created by spencer on 4/2/18.
//

#ifndef TICTACTOE_MARKNODE_H
#define TICTACTOE_MARKNODE_H


#include "SpriteNode.h"

class MarkNode : public SpriteNode
{
public:
    enum MarkType {
        X,
        O,
        NONE
    };
public:
    explicit MarkNode(MarkType type);

    static std::string getNameOfMark(MarkType type);

    MarkType m_type;

    sf::Texture &getTextureFromMarkType(MarkType type);
};


#endif //TICTACTOE_MARKNODE_H
