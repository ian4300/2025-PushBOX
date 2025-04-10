#ifndef TARGET_HPP
#define TARGET_HPP

#include "pch.hpp"
#include <glm/glm.hpp>

class Target {
public:
    // 構造函數，接受 glm::vec2
    Target(const glm::vec2& position) : m_position(position) {}

    // 構造函數，接受兩個 float
    Target(float x, float y) : m_position(x, y) {}

    glm::vec2 GetPosition() const { return m_position; }

private:
    glm::vec2 m_position; // 目標區域的位置
};

#endif // TARGET_HPP