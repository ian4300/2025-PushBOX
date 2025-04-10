#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "pch.hpp"
#include <glm/glm.hpp>

class Character {
public:
    void SetPosition(const glm::vec2& position) { m_position = position; }
    glm::vec2 GetPosition() const { return m_position; }

private:
    glm::vec2 m_position; // 玩家角色的位置
};

#endif // CHARACTER_HPP