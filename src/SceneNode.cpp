//
// Created by spencer on 4/2/18.
//

#include "SceneNode.h"
#include <memory>
#include <cassert>

void SceneNode::draw(sf::RenderTarget &target, sf::RenderStates renderStates) const {
    renderStates.transform *= getTransform();

    onDraw(target, renderStates);

    for (const Ptr& node : m_children) {
        node->draw(target, renderStates);
    }
}

void SceneNode::attachChild(Ptr child)
{
    child->m_parent = this;
    m_children.push_back(std::move(child));
}

SceneNode::Ptr SceneNode::detachChild(const SceneNode &node)
{
    auto found = std::find_if(m_children.begin(), m_children.end(), [&] (Ptr& p) -> bool { return p.get() == &node; });
    assert(found != m_children.end());
    Ptr result = std::move(*found);
    result->m_parent = nullptr;
    m_children.erase(found);
    return result;
}

void SceneNode::update()
{
    onUpdate();

    for (const Ptr& node : m_children) {
        node->update();
    }
}

void SceneNode::onDraw(sf::RenderTarget &target, sf::RenderStates states) const
{

}

void SceneNode::onUpdate()
{

}


