#include "App.hpp"
#include "Util/Input.hpp"
#include "Util/GameObject.hpp"
#include "Util/Image.hpp"
#include "Character.hpp"

man::man()
    : m_Image(std::make_shared<Util::Image>("Resources/character1.png"))
    {
        m_Transform.scale = {1.00f, 1.00f};
        m_Transform.translation = {0, 110};
        SetDrawable(m_Image); // 設置單一圖片
        SetZIndex(5);
}
void man::Update() {
    //移動邏輯
    if (Util::Input::IsKeyDown(Util::Keycode::DOWN)) {
        m_Image = std::make_shared<Util::Image>("Resources/character1.png");
        SetDrawable(m_Image);
        m_Transform.translation.y -= 75;
    } else if (Util::Input::IsKeyDown(Util::Keycode::UP)) {
        m_Image = std::make_shared<Util::Image>("Resources/character2.png");
        SetDrawable(m_Image);
        m_Transform.translation.y += 75;
    } else if (Util::Input::IsKeyDown(Util::Keycode::LEFT)) {
        m_Image = std::make_shared<Util::Image>("Resources/character4.png");
        SetDrawable(m_Image);
        m_Transform.translation.x -= 75;
    } else if (Util::Input::IsKeyDown(Util::Keycode::RIGHT)) {
        m_Image = std::make_shared<Util::Image>("Resources/character3.png");
        SetDrawable(m_Image);
        m_Transform.translation.x += 75;
    }
}
void App::Update()
{
    m_man->Update();
    m_Root.Update();
   /* if (Util::Input::IsKeyPressed(Util::Keycode::UP)) {
        m_Transform.translation.y -= moveSpeed;
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::DOWN)) {
        m_Transform.translation.y += moveSpeed;
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::LEFT)) {
        m_Transform.translation.x -= moveSpeed;
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::RIGHT)) {
        m_Transform.translation.x += moveSpeed;
    }
    m_man.SetPosition(manPosition);


    // 渲染角色

*/
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