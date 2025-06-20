#include "iostream"
#include "App.hpp"
#include <thread>
#include <chrono>
#include "Util/Input.hpp"
#include "Util/GameObject.hpp"
#include "Util/Image.hpp"


void App::Update()
{
    int sum = 0;
    std::vector<std::shared_ptr<Box>> boxes = {m_box1, m_box2, m_box3, m_box4, m_box5};
    // 收集所有箱子的座標
    m_man->Update(boxes,m_PRM.GetPhase());
    m_Stage->Update();
    m_StepCounter->Update();
    m_StepText->m_Text->SetText(fmt::format("{}", step));
    m_Root.Update();

    //判負條件
    if (step == 0)
    {
        m_PRM.Fail();
        m_PRM.Reset();
        m_CurrentState = State::START;
    }
    //第一關
    if (m_PRM.GetPhase() == 1 || m_PRM.GetPhase() == 7 || m_PRM.GetPhase() == 13 || m_PRM.GetPhase() == 19 || m_PRM.GetPhase() == 25)
    {
        if (m_target1->m_Transform.translation == m_box1->m_Transform.translation) {
            m_CurrentState = State::START;
        }

    }
    //第二關
    if (m_PRM.GetPhase() == 2 || m_PRM.GetPhase() == 8 || m_PRM.GetPhase() ==  14 || m_PRM.GetPhase() == 20 || m_PRM.GetPhase() == 26)
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
    if (m_PRM.GetPhase() == 3 || m_PRM.GetPhase() == 9 || m_PRM.GetPhase() == 15 || m_PRM.GetPhase() == 21 || m_PRM.GetPhase() == 27)
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
    //第四關
    if (m_PRM.GetPhase() == 4 || m_PRM.GetPhase() == 10 || m_PRM.GetPhase() == 16 || m_PRM.GetPhase() == 22 || m_PRM.GetPhase() == 28)
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
        //目標4判別
        for (const auto& box : boxes) {
            if (m_target4->m_Transform.translation == box->GetPosition()) {
                finishtarget[3] = 1;
                break; // 找到匹配後即可跳出迴圈
            }
            else
                finishtarget[3] = 0;
        }
        //總和判別
        for (int value : finishtarget)
        {
            sum += value;
        }
        if (sum == 4)
        {
            m_CurrentState = State::START;
        }
    }
    //第五關
    if (m_PRM.GetPhase() == 5 || m_PRM.GetPhase() == 11 || m_PRM.GetPhase() == 17 || m_PRM.GetPhase() == 23 || m_PRM.GetPhase() == 29)
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
        //目標4判別
        for (const auto& box : boxes) {
            if (m_target4->m_Transform.translation == box->GetPosition()) {
                finishtarget[3] = 1;
                break; // 找到匹配後即可跳出迴圈
            }
            else
                finishtarget[3] = 0;
        }
        //目標5判別
        for (const auto& box : boxes) {
            if (m_target5->m_Transform.translation == box->GetPosition()) {
                finishtarget[4] = 1;
                break; // 找到匹配後即可跳出迴圈
            }
            else
                finishtarget[4] = 0;
        }
        //總和判別
        for (int value : finishtarget)
        {
            sum += value;
        }
        if (sum == 5)
        {
            m_CurrentState = State::START;
        }
    }
    //第六關
    if (m_PRM.GetPhase() == 6 || m_PRM.GetPhase() == 12 || m_PRM.GetPhase() == 18 || m_PRM.GetPhase() == 24 || m_PRM.GetPhase() == 30)
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
        //目標4判別
        for (const auto& box : boxes) {
            if (m_target4->m_Transform.translation == box->GetPosition()) {
                finishtarget[3] = 1;
                break; // 找到匹配後即可跳出迴圈
            }
            else
                finishtarget[3] = 0;
        }
        //目標5判別
        for (const auto& box : boxes) {
            if (m_target5->m_Transform.translation == box->GetPosition()) {
                finishtarget[4] = 1;
                break; // 找到匹配後即可跳出迴圈
            }
            else
                finishtarget[4] = 0;
        }
        //總和判別
        for (int value : finishtarget)
        {
            sum += value;
        }
        if (sum == 5)
        {
            m_CurrentState = State::START;
        }
    }



    //重設
    if (Util::Input::IsKeyUp(Util::Keycode::R) || Util::Input::IfExit())
    {
        m_PRM.Reset();
        m_CurrentState = State::START;
    }
    //上一關
    if (Util::Input::IsKeyUp(Util::Keycode::B) || Util::Input::IfExit())
    {
        m_PRM.Reset();
        m_PRM.Reset();
        m_CurrentState = State::START;
    }
    //跳轉(未完成)
    if (Util::Input::IsKeyUp(Util::Keycode::J) || Util::Input::IfExit())
    {
        m_PRM.Jump();
        m_CurrentState = State::START;
    }
    //跳過
    if (Util::Input::IsKeyUp(Util::Keycode::K) || Util::Input::IfExit())
    {
        m_CurrentState = State::START;
    }
    // 跳轉至結束階段
    if (Util::Input::IsKeyUp(Util::Keycode::ESCAPE) || Util::Input::IfExit())
    {
        m_CurrentState = State::END;
    }
}