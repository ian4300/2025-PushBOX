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

void man::Update(const std::vector<std::shared_ptr<Box>>& boxes, int phase)
{
    Impact impact;
    int direction = 0;

    // 移動邏輯
    if (Util::Input::IsKeyDown(Util::Keycode::DOWN)) {
        if (m_Transform.translation.y - 75 >= -300) {
            m_Transform.translation.y -= 75;
        }
        direction = 2;
        SetDrawable(m_Image);
    } else if (Util::Input::IsKeyDown(Util::Keycode::UP)) {
        if (m_Transform.translation.y + 75 <= 300) {
            m_Transform.translation.y += 75;
        }
        direction = 8;
        SetDrawable(m_Image);
    } else if (Util::Input::IsKeyDown(Util::Keycode::LEFT)) {
        if (m_Transform.translation.x - 75 >= -600) {
            m_Transform.translation.x -= 75;
        }
        direction = 4;
        m_Transform.scale.x = -0.7f;
        SetDrawable(m_Image);
    } else if (Util::Input::IsKeyDown(Util::Keycode::RIGHT)) {
        if (m_Transform.translation.x + 75 <= 600) {
            m_Transform.translation.x += 75;
        }
        direction = 6;
        m_Transform.scale.x = 0.7f;
        SetDrawable(m_Image);
    }

    glm::vec2 newPosition = m_Transform.translation;

    // 提取箱子座標
    std::vector<glm::vec2> boxPositions;
    for (const auto& box : boxes) {
        boxPositions.push_back(box->GetPosition());
    }

    // 碰撞檢測
    for (const auto& box : boxes) {
        if (newPosition == box->GetPosition()) {
            if (impact.CheckBoxCollision(box->GetPosition(), boxPositions, direction , phase)) {
                // 還原角色位置
                switch (direction) {
                case 8: m_Transform.translation.y -= 75; break;
                case 2: m_Transform.translation.y += 75; break;
                case 4: m_Transform.translation.x += 75; break;
                case 6: m_Transform.translation.x -= 75; break;
                }
            } else {
                // 更新箱子位置
                switch (direction) {
                case 8: box->m_Transform.translation.y += 75; break;
                case 2: box->m_Transform.translation.y -= 75; break;
                case 4: box->m_Transform.translation.x -= 75; break;
                case 6: box->m_Transform.translation.x += 75; break;
                }
            }
        }
    }
}
void App::Update()
{
    int sum = 0;
    std::vector<std::shared_ptr<Box>> boxes = {m_box1, m_box2, m_box3, m_box4, m_box5};
    // 收集所有箱子的座標
    m_man->Update(boxes,m_PRM.GetPhase());
    m_Stage->Update();
    m_Root.Update();

    //第一關
    if (m_PRM.GetPhase() == 1)
    {
        if (m_target1->m_Transform.translation == m_box1->m_Transform.translation) {
            m_CurrentState = State::START;
        }

    }
    //第二關
    if (m_PRM.GetPhase() == 2)
    {
        //目標1判別
        for (const auto& box : boxes) {
            if (m_target1->m_Transform.translation == box->GetPosition()) {
                finishtarget[0] = 1;
                break; // 找到匹配後即可跳出迴圈
            }
            else
                finishtarget[0] = 0;
        }
        //目標2判別
        for (const auto& box : boxes) {
            if (m_target2->m_Transform.translation == box->GetPosition()) {
                finishtarget[1] = 1;
                break; // 找到匹配後即可跳出迴圈
            }
            else
                finishtarget[1] = 0;
        }
        //總和判別
        for (int value : finishtarget)
        {
            sum += value;
        }
        if (sum == 2)
        {
            m_CurrentState = State::START;
        }
    }
    //第三關
    if (m_PRM.GetPhase() == 3)
    {
        //目標1判別
        for (const auto& box : boxes) {
            if (m_target1->m_Transform.translation == box->GetPosition()) {
                finishtarget[0] = 1;
                break; // 找到匹配後即可跳出迴圈
            }
            else
                finishtarget[0] = 0;
        }
        //目標2判別
        for (const auto& box : boxes) {
            if (m_target2->m_Transform.translation == box->GetPosition()) {
                finishtarget[1] = 1;
                break; // 找到匹配後即可跳出迴圈
            }
            else
                finishtarget[1] = 0;
        }
        //目標3判別
        for (const auto& box : boxes) {
            if (m_target3->m_Transform.translation == box->GetPosition()) {
                finishtarget[2] = 1;
                break; // 找到匹配後即可跳出迴圈
            }
            else
                finishtarget[2] = 0;
        }
        //總和判別
        for (int value : finishtarget)
        {
            sum += value;
        }
        if (sum == 3)
        {
            m_CurrentState = State::START;
        }
    }

    // 跳轉至結束階段
    if (Util::Input::IsKeyUp(Util::Keycode::R) || Util::Input::IfExit())
    {
        m_PRM.Reset();
        m_CurrentState = State::START;
    }
    if (Util::Input::IsKeyUp(Util::Keycode::ESCAPE) || Util::Input::IfExit())
    {
        m_CurrentState = State::END;
    }
}