#ifndef BOX_HPP
#define BOX_HPP

#include "pch.hpp"
#include <glm/glm.hpp>

class Box {
public:
    // 構造函數，接受 glm::vec2
    Box(const glm::vec2& position) : m_position(position) {}

    // 構造函數，接受兩個 float
    Box(float x, float y) : m_position(x, y) {}

    void Move(const glm::vec2& direction) { m_position += direction; }
    glm::vec2 GetPosition() const { return m_position; }
    bool IsCollidingWith(const glm::vec2& otherPosition) const {
        return m_position == otherPosition;
    }

private:
    glm::vec2 m_position; // 箱子的位置
};

#endif // BOX_HPP