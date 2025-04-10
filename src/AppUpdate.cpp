#include "App.hpp"

#include "Util/Keycode.hpp"
#include "Util/Input.hpp"

void App::Update() {
    // 處理玩家移動
    auto manPosition = m_man.GetPosition();
    const float moveSpeed = 1.0f;

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            m_CurrentState = State::END; // 更新狀態為 END
        }
    }

    if (Util::Input::IsKeyPressed(Util::Keycode::UP)) {
        manPosition.y -= moveSpeed;
        m_CurrentTexture = m_Textures[0]; // 顯示向上的圖片
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::DOWN)) {
        manPosition.y += moveSpeed;
        m_CurrentTexture = m_Textures[1]; // 顯示向下的圖片
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::LEFT)) {
        manPosition.x -= moveSpeed;
        m_CurrentTexture = m_Textures[2]; // 顯示向左的圖片
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::RIGHT)) {
        manPosition.x += moveSpeed;
        m_CurrentTexture = m_Textures[3]; // 顯示向右的圖片
    }
    m_man.SetPosition(manPosition);

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

    // 跳轉至結束階段
    if (Util::Input::IsKeyUp(Util::Keycode::ESCAPE) || Util::Input::IfExit()) {
        m_CurrentState = State::END;
    }
    */
}