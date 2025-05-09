#include "iostream"
#include "App.hpp"
#include "Util/Input.hpp"
#include "Util/GameObject.hpp"
#include "Util/Image.hpp"

man::man()
    : m_Image(std::make_shared<Util::Image>("Resources/character1.png"))
    {
        m_Transform.scale = {0.7f, 0.7f};
        m_Transform.translation = {0, 0};
        SetDrawable(m_Image); // 設置單一圖片
        SetZIndex(5);
}

void man::Update(const std::vector<glm::vec2>& boxes)
{
    Impact impact;
    int direction = 0;
    //移動邏輯
    if (Util::Input::IsKeyDown(Util::Keycode::DOWN)) {
        if (m_Transform.translation.y - 75 >= -300) { // 檢查是否超出下邊界
            m_Transform.translation.y -= 75;
        }
        direction = 2;
        SetDrawable(m_Image);

    } else if (Util::Input::IsKeyDown(Util::Keycode::UP)) {
        if (m_Transform.translation.y + 75 <= 300) { // 檢查是否超出上邊界
            m_Transform.translation.y += 75;
        }
        direction = 8;
        SetDrawable(m_Image);
    } else if (Util::Input::IsKeyDown(Util::Keycode::LEFT)) {
        if (m_Transform.translation.x - 75 >= -600) { // 檢查是否超出左邊界
            m_Transform.translation.x -= 75;
        }
        direction = 4;
        m_Transform.scale.x = -0.7f;
        SetDrawable(m_Image);
    } else if (Util::Input::IsKeyDown(Util::Keycode::RIGHT)) {
        if (m_Transform.translation.x + 75 <= 600) { // 檢查是否超出右邊界
            m_Transform.translation.x += 75;
        }
        direction = 6;
        m_Transform.scale.x = 0.7f;
        SetDrawable(m_Image);
    }
    glm::vec2 newPosition = m_Transform.translation;
    // 呼叫碰撞檢測
    for (const auto& box : boxes)
    {
        if (newPosition == box) {
            // 呼叫碰撞檢測函式
            if (impact.CheckBoxCollision(box, boxes, direction)) {
                // 更新箱子位置
                switch (direction) {
                case 8: m_Transform.translation.y -= 75; break; // 上
                case 2: m_Transform.translation.y += 75; break; // 下
                case 4: m_Transform.translation.x += 75; break; // 左
                case 6: m_Transform.translation.x -= 75; break; // 右
                }
                SDL_Log("Invalid position detected!");
            } else {
                switch (direction) {
                case 8: // 上
                    const_cast<glm::vec2&>(box).y += 75;
                    break;
                case 2: // 下
                    const_cast<glm::vec2&>(box).y -= 75;
                    break;
                case 4: // 左
                    const_cast<glm::vec2&>(box).x -= 75;
                    break;
                case 6: // 右
                    const_cast<glm::vec2&>(box).x += 75;
                    break;
                }
                SDL_Log("Invalid position detected!");
            }
            /*取地圖座標
            std::cout << "Character Position: ("
                   << m_Transform.translation.x << ", "
                   << m_Transform.translation.y << ")" << std::endl;//地圖劃分左右x=+-600有16格=75/格,上下y=335~-265有8格*/
        }
    }
}
void App::Update()
{
    std::vector<glm::vec2> boxes;
    // 收集所有箱子的座標
    boxes.push_back(m_box1->GetPosition());
    boxes.push_back(m_box2->GetPosition());
    boxes.push_back(m_box3->GetPosition());
    boxes.push_back(m_box4->GetPosition());
    boxes.push_back(m_box5->GetPosition());

    m_man->Update(boxes);
    m_Stage->Update();
    m_Root.Update();
    // 切換關卡
    if (m_PRM.GetPhase() == 1)
    {
        glm::vec2 manPosition = m_man->GetPosition();
        if (manPosition.x == 300 && manPosition.y == 150) {
            m_CurrentState = State::START;
        }
    }
    if (m_PRM.GetPhase() == 2)
    {
        glm::vec2 manPosition = m_man->GetPosition();
        if (manPosition.x == 0 && manPosition.y == -150) {
            m_CurrentState = State::START;
        }
    }
    if (m_PRM.GetPhase() == 3)
    {
        glm::vec2 manPosition = m_man->GetPosition();
        if (manPosition.x == -225 && manPosition.y == 0) {
            m_CurrentState = State::START;
        }
    }
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