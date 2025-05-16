#include <vector>
#include "App.hpp"


Impact::Impact() {
    // Constructor implementation
}

// 檢測箱子是否碰撞到其他箱子或邊界
bool Impact::CheckBoxCollision(const glm::vec2& currentBoxPosition, const std::vector<glm::vec2>& otherBoxes, int direction ,int phase) {
    glm::vec2 newBoxPosition = currentBoxPosition;
    // 根據方向計算新位置
    if (phase <= 6)
    switch (direction) {
    case 8: newBoxPosition.y += 100; break; // 上
    case 2: newBoxPosition.y -= 100; break; // 下
    case 4: newBoxPosition.x -= 100; break; // 左
    case 6: newBoxPosition.x += 100; break; // 右
    }

    // 檢測是否超出邊界
    if (phase <= 6)
    {
        if (newBoxPosition.x < -350 || newBoxPosition.x > 350 ||
            newBoxPosition.y < -200 || newBoxPosition.y > 200) {
            return true; // 無效位置
            }

        // 檢測是否與其他箱子碰撞
        for (const auto& otherBox : otherBoxes) {
            if (newBoxPosition == otherBox) {
                return true; // 無效位置
            }
        }
    }
    return false; // 位置有效
}