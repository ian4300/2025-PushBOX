#include "App.hpp"
#include "Util/Keycode.hpp"
#include "Util/Input.hpp"

void App::MoveMan(const glm::vec2& direction, int textureIndex) {
    // 更新角色位置
    auto manPosition = m_man.GetPosition();
    manPosition += direction;
    m_man.SetPosition(manPosition);

    // 更新當前顯示的圖片
    m_CurrentTexture = m_Textures[textureIndex];
}

void App::Update() {
    const float moveSpeed = 5.0f; // 移動速度
    // 根據按鍵輸入移動角色
    if (Util::Input::IsKeyPressed(Util::Keycode::DOWN)) {
        MoveMan({0, moveSpeed}, 0); // 向下移動
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::UP)) {
        MoveMan({0, -moveSpeed}, 1); // 向上移動
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::RIGHT)) {
        MoveMan({moveSpeed, 0}, 2); // 向右移動
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::LEFT)) {
        MoveMan({-moveSpeed, 0}, 3); // 向左移動
    }

    // 清除畫面
    SDL_RenderClear(m_Renderer);

    // 渲染角色
    auto manPosition = m_man.GetPosition();
    SDL_Rect dstRect = {static_cast<int>(manPosition.x), static_cast<int>(manPosition.y), 50, 50}; // 假設角色大小為 50x50
    SDL_RenderCopy(m_Renderer, m_CurrentTexture, nullptr, &dstRect);

    // 更新畫面
    SDL_RenderPresent(m_Renderer);

    /*// 處理箱子推動邏輯
    for (auto& box : m_boxes) {
        if (box.IsCollidingWith(m_man)) {
            box.Move(manPosition); // 假設 Box 類有 Move 方法
        }
    }
*/
    /*
    // 檢查是否完成關卡
    bool allBoxesOnTargets = true;
    for (const auto& box : m_boxes) {
        bool boxOnTarget = false;
        for (const auto& target : m_targets) {
            if (box.GetPosition() == target.GetPosition()) {
                boxOnTarget = true;
                break;
            }
        }
        if (!boxOnTarget) {
            allBoxesOnTargets = false;
            break;
        }
    }

    if (allBoxesOnTargets) {
        m_Phase++;
        if (m_Phase > 3) {
            m_CurrentState = State::END;
        } else {
            m_CurrentState = State::START; // 切換到 START 狀態以初始化下一關
        }
    }
*/
    // 跳轉至結束階段
    if (Util::Input::IsKeyUp(Util::Keycode::ESCAPE) || Util::Input::IfExit())
    {
        m_CurrentState = State::END;
    }
}