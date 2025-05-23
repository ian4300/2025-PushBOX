#include "App.hpp"
#include "Util/Logger.hpp"
#include "Util/Image.hpp"
#include "PhaseResourceManger.hpp"
#include <SDL_image.h>

void App::Start() {
    LOG_TRACE("Start");
    if (m_PRM.GetPhase() <= 5)
    m_PRM.NextPhase();
    else
        m_CurrentState = State::END;

    // 將 finishtarget 陣列重置為 0
    std::fill(std::begin(finishtarget), std::end(finishtarget), 0);

    // 根據 Phase 切換地圖
    int phase = m_PRM.GetPhase();
    if (phase >= 7 && phase <= 12) {
        m_Stage->SetBackgroundImage("Resources/map2.png");
    } else if (phase >= 13 && phase <= 18) {
        m_Stage->SetBackgroundImage("Resources/map3.png");
    } else if (phase >= 19 && phase <= 24) {
        m_Stage->SetBackgroundImage("Resources/map4.png");
    } else if (phase >= 25 && phase <= 30) {
        m_Stage->SetBackgroundImage("Resources/map5.png");
    }

    if (m_PRM.GetPhase() == 1)
    {
        m_Root.AddChild(m_man);
        m_Root.AddChild(m_Stage);

        m_Root.AddChild(m_box1);
        m_Root.AddChild(m_box2);
        m_box2->SetVisible(false);
        m_Root.AddChild(m_box3);
        m_box3->SetVisible(false);
        m_Root.AddChild(m_box4);
        m_box4->SetVisible(false);
        m_Root.AddChild(m_box5);
        m_box5->SetVisible(false);

        m_Root.AddChild(m_target1);
        m_Root.AddChild(m_target2);
        m_target2->SetVisible(false);
        m_Root.AddChild(m_target3);
        m_target3->SetVisible(false);
        m_Root.AddChild(m_target4);
        m_target4->SetVisible(false);
        m_Root.AddChild(m_target5);
        m_target5->SetVisible(false);

        m_man->m_Transform.translation.x = 50;
        m_man->m_Transform.translation.y = 0;//map2換為x=0,y=50

        m_box1->m_Transform.translation.x = -50;
        m_box1->m_Transform.translation.y = 100;

        m_target1->m_Transform.translation.x = 50;
        m_target1->m_Transform.translation.y = -200;

        m_CurrentState = State::UPDATE;
    }
    //第二關初始化
    if (m_PRM.GetPhase() == 2)
    {
        //初始化人位置
        m_man->m_Transform.translation.x = 250;
        m_man->m_Transform.translation.y = 0;
        //初始化箱子1,2位置，顯示箱子2
        m_box1->m_Transform.translation.x = -150;
        m_box1->m_Transform.translation.y = 100;
        m_box2->SetVisible(true);
        m_box2->m_Transform.translation.x = 50;
        m_box2->m_Transform.translation.y = 100;
        //初始化目標1,2位置，顯示目標2
        m_target1->m_Transform.translation.x = 50;
        m_target1->m_Transform.translation.y = -100;
        m_target2->SetVisible(true);
        m_target2->m_Transform.translation.x = 250;
        m_target2->m_Transform.translation.y = 100;

        m_CurrentState = State::UPDATE;
    }
    //第三關初始化
    if (m_PRM.GetPhase() == 3)
    {
        //初始化人位置
        m_man->m_Transform.translation.x = 50;
        m_man->m_Transform.translation.y = 100;
        //初始化箱子1,2位置，顯示箱子3
        m_box1->m_Transform.translation.x = -150;
        m_box1->m_Transform.translation.y = -200;
        m_box2->m_Transform.translation.x = -150;
        m_box2->m_Transform.translation.y = 100;
        m_box3->SetVisible(true);
        m_box3->m_Transform.translation.x = 250;
        m_box3->m_Transform.translation.y = -100;

        //初始化目標1,2,3位置，顯示目標3
        m_target1->m_Transform.translation.x = 250;
        m_target1->m_Transform.translation.y = 100;
        m_target2->m_Transform.translation.x = 150;
        m_target2->m_Transform.translation.y = 100;
        m_target3->SetVisible(true);
        m_target3->m_Transform.translation.x = -250;
        m_target3->m_Transform.translation.y = -200;

        m_CurrentState = State::UPDATE;
    }
    if (m_PRM.GetPhase() == 4)
    {
        //初始化人位置
        m_man->m_Transform.translation.x = -350;
        m_man->m_Transform.translation.y = 200;
        //初始化箱子1,2,3位置，顯示箱子4
        m_box1->m_Transform.translation.x = 150;
        m_box1->m_Transform.translation.y = 100;
        m_box2->m_Transform.translation.x = -150;
        m_box2->m_Transform.translation.y = 100;
        m_box3->m_Transform.translation.x = 250;
        m_box3->m_Transform.translation.y = -100;
        m_box4->SetVisible(true);
        m_box4->m_Transform.translation.x = 50;
        m_box4->m_Transform.translation.y = -200;

        //初始化目標1,2,3位置，顯示目標4
        m_target1->m_Transform.translation.x = -350;
        m_target1->m_Transform.translation.y = 200;
        m_target2->m_Transform.translation.x = -150;
        m_target2->m_Transform.translation.y = 200;
        m_target3->m_Transform.translation.x = -250;
        m_target3->m_Transform.translation.y = 0;
        m_target4->SetVisible(true);
        m_target4->m_Transform.translation.x = -250;
        m_target4->m_Transform.translation.y = -200;

        m_CurrentState = State::UPDATE;
    }
    if (m_PRM.GetPhase() == 5)
    {
        //初始化人位置
        m_man->m_Transform.translation.x = -250;
        m_man->m_Transform.translation.y = -200;
        //初始化箱子1,2,3,4位置，顯示箱子5
        m_box1->m_Transform.translation.x = -250;
        m_box1->m_Transform.translation.y = 100;
        m_box2->m_Transform.translation.x = 150;
        m_box2->m_Transform.translation.y = 100;
        m_box3->m_Transform.translation.x = 250;
        m_box3->m_Transform.translation.y = -100;
        m_box4->m_Transform.translation.x = -50;
        m_box4->m_Transform.translation.y = -200;
        m_box5->SetVisible(true);
        m_box5->m_Transform.translation.x = 50;
        m_box5->m_Transform.translation.y = 0;

        //初始化目標1,2,3,4位置，顯示目標5
        m_target1->m_Transform.translation.x = -350;
        m_target1->m_Transform.translation.y = 200;
        m_target2->m_Transform.translation.x = 250;
        m_target2->m_Transform.translation.y = 100;
        m_target3->m_Transform.translation.x = 350;
        m_target3->m_Transform.translation.y = 0;
        m_target4->m_Transform.translation.x = 50;
        m_target4->m_Transform.translation.y = 200;
        m_target5->SetVisible(true);
        m_target5->m_Transform.translation.x = 150;
        m_target5->m_Transform.translation.y = -200;

        m_CurrentState = State::UPDATE;
    }
}