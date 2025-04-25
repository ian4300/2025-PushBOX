#include "App.hpp"
#include "Util/Input.hpp"
#include "Util/GameObject.hpp"
#include "Util/Image.hpp"

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
        if (m_Transform.translation.y - 75 >= -265) { // 檢查是否超出下邊界
            m_Transform.translation.y -= 75;
        }
        m_Image = std::make_shared<Util::Image>("Resources/character1.png");
        SetDrawable(m_Image);
    } else if (Util::Input::IsKeyDown(Util::Keycode::UP)) {
        if (m_Transform.translation.y + 75 <= 335) { // 檢查是否超出上邊界
            m_Transform.translation.y += 75;
        }
        m_Image = std::make_shared<Util::Image>("Resources/character2.png");
        SetDrawable(m_Image);
    } else if (Util::Input::IsKeyDown(Util::Keycode::LEFT)) {
        if (m_Transform.translation.x - 75 >= -600) { // 檢查是否超出左邊界
            m_Transform.translation.x -= 75;
        }
        m_Image = std::make_shared<Util::Image>("Resources/character4.png");
        SetDrawable(m_Image);
    } else if (Util::Input::IsKeyDown(Util::Keycode::RIGHT)) {
        if (m_Transform.translation.x + 75 <= 600) { // 檢查是否超出右邊界
            m_Transform.translation.x += 75;
        }
        m_Image = std::make_shared<Util::Image>("Resources/character3.png");
        SetDrawable(m_Image);
    }
      /*取地圖座標  std::cout << "Character Position: ("
             << m_Transform.translation.x << ", "
             << m_Transform.translation.y << ")" << std::endl;//地圖劃分左右x=+-600有16格=75/格,上下y=335~-265有8格*/
}
void App::Update()
{
    m_man->Update();
    m_Stage->Update();
    m_Root.Update();
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