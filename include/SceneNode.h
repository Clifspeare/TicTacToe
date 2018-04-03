//
// Created by spencer on 4/2/18.
//

#ifndef TICTACTOE_GAMENODE_H
#define TICTACTOE_GAMENODE_H

#include <vector>

#include <SFML/Graphics.hpp>

class SceneNode : public sf::Transformable, public sf::Drawable, public sf::NonCopyable
{
public:
    typedef std::unique_ptr<SceneNode> Ptr;
    void attachChild(Ptr node);
    Ptr detachChild(const SceneNode &node);

    // rendering
    void draw(sf::RenderTarget& target, sf::RenderStates renderStates) const final;
private:
    virtual void onDraw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

    SceneNode* m_parent;
    std::vector<Ptr> m_children;
};


#endif //TICTACTOE_GAMENODE_H
