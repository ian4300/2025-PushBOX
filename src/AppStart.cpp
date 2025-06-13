#include "App.hpp"
#include "Util/Logger.hpp"
#include "Util/Image.hpp"
#include "PhaseResourceManger.hpp"
#include <SDL_image.h>

void App::Start() {
    LOG_TRACE("Start");
    if (m_PRM.GetPhase() <= 29)
    m_PRM.NextPhase();
    else
        m_CurrentState = State::END;

    // 將 finishtarget 陣列重置為 0
    std::fill(std::begin(finishtarget), std::end(finishtarget), 0);

    // 根據 Phase 切換地圖
    int phase = m_PRM.GetPhase();
    if (phase > 6 && phase <= 12) {
        m_Stage->SetBackgroundImage("Resources/map2.png" , 7);
    } else if (phase > 12 && phase <= 18) {
        m_Stage->SetBackgroundImage("Resources/map3.png" , 13);
    } else if (phase > 18 && phase <= 24) {
        m_Stage->SetBackgroundImage("Resources/map4.png" , 19);
    } else if (phase > 24 && phase <= 30) {
        m_Stage->SetBackgroundImage("Resources/map5.png" , 25);
    }
    //第一關初始化
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
        m_man->m_Transform.translation.y = 0;

        m_box1->m_Transform.translation.x = -50;
        m_box1->m_Transform.translation.y = -100;

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
    //第四關初始化
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
    //第五關初始化
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
    //第六關初始化
    if (m_PRM.GetPhase() == 6)
    {
        //初始化人位置
        m_man->m_Transform.translation.x = -250;
        m_man->m_Transform.translation.y = -200;
        //初始化箱子1,2,3,4,5位置
        m_box1->m_Transform.translation.x = -250;
        m_box1->m_Transform.translation.y = 100;
        m_box2->m_Transform.translation.x = 150;
        m_box2->m_Transform.translation.y = 100;
        m_box3->m_Transform.translation.x = 250;
        m_box3->m_Transform.translation.y = -100;
        m_box4->m_Transform.translation.x = -50;
        m_box4->m_Transform.translation.y = -200;
        m_box5->m_Transform.translation.x = 50;
        m_box5->m_Transform.translation.y = 0;

        //初始化目標1,2,3,4,5位置
        m_target1->m_Transform.translation.x = -350;
        m_target1->m_Transform.translation.y = 200;
        m_target2->m_Transform.translation.x = 250;
        m_target2->m_Transform.translation.y = 100;
        m_target3->m_Transform.translation.x = 350;
        m_target3->m_Transform.translation.y = 0;
        m_target4->m_Transform.translation.x = 50;
        m_target4->m_Transform.translation.y = 200;
        m_target5->m_Transform.translation.x = 150;
        m_target5->m_Transform.translation.y = -200;

        m_CurrentState = State::UPDATE;
    }

    //第七關初始化
    if (m_PRM.GetPhase() == 7)
    {
        HideBoxesAndTargets();
        m_man->m_Transform.translation.x = 50;
        m_man->m_Transform.translation.y = 0;

        m_box1->m_Transform.translation.x = -50;
        m_box1->m_Transform.translation.y = 0;

        m_target1->m_Transform.translation.x = 150;
        m_target1->m_Transform.translation.y = -200;
        m_CurrentState = State::UPDATE;
    }
    //第八關初始化
    if (m_PRM.GetPhase() == 8)
    {
        m_man->m_Transform.translation.x = 250;
        m_man->m_Transform.translation.y = -300;
        //初始化箱子1,2位置，顯示箱子2
        m_box1->m_Transform.translation.x = -150;
        m_box1->m_Transform.translation.y = 100;
        m_box2->SetVisible(true);
        m_box2->m_Transform.translation.x = 50;
        m_box2->m_Transform.translation.y = -200;
        //初始化目標1,2位置，顯示目標2
        m_target1->m_Transform.translation.x = 50;
        m_target1->m_Transform.translation.y = 200;
        m_target2->SetVisible(true);
        m_target2->m_Transform.translation.x = 250;
        m_target2->m_Transform.translation.y = -300;
        m_CurrentState = State::UPDATE;
    }
    //第九關初始化
    if (m_PRM.GetPhase() == 9)
    {
        //初始化人位置
        m_man->m_Transform.translation.x = -250;
        m_man->m_Transform.translation.y = -100;
        //初始化箱子1,2位置，顯示箱子3
        m_box1->m_Transform.translation.x = -150;
        m_box1->m_Transform.translation.y = -200;
        m_box2->m_Transform.translation.x = -150;
        m_box2->m_Transform.translation.y = 100;
        m_box3->SetVisible(true);
        m_box3->m_Transform.translation.x = 50;
        m_box3->m_Transform.translation.y = 100;

        //初始化目標1,2,3位置，顯示目標3
        m_target1->m_Transform.translation.x = 50;
        m_target1->m_Transform.translation.y = 200;
        m_target2->m_Transform.translation.x = 150;
        m_target2->m_Transform.translation.y = 100;
        m_target3->SetVisible(true);
        m_target3->m_Transform.translation.x = 250;
        m_target3->m_Transform.translation.y = -300;

        m_CurrentState = State::UPDATE;
    }
    //第十關初始化
    if (m_PRM.GetPhase() == 10)
    {
        //初始化人位置
        m_man->m_Transform.translation.x = -250;
        m_man->m_Transform.translation.y = 100;
        //初始化箱子1,2,3位置，顯示箱子4
        m_box1->m_Transform.translation.x = -50;
        m_box1->m_Transform.translation.y = -300;
        m_box2->m_Transform.translation.x = -150;
        m_box2->m_Transform.translation.y = 100;
        m_box3->m_Transform.translation.x = -250;
        m_box3->m_Transform.translation.y = -100;
        m_box4->SetVisible(true);
        m_box4->m_Transform.translation.x = -50;
        m_box4->m_Transform.translation.y = -200;

        //初始化目標1,2,3位置，顯示目標4
        m_target1->m_Transform.translation.x = -350;
        m_target1->m_Transform.translation.y = -100;
        m_target2->m_Transform.translation.x = 50;
        m_target2->m_Transform.translation.y = 200;
        m_target3->m_Transform.translation.x = -250;
        m_target3->m_Transform.translation.y = 100;
        m_target4->SetVisible(true);
        m_target4->m_Transform.translation.x = 250;
        m_target4->m_Transform.translation.y = -300;

        m_CurrentState = State::UPDATE;
    }
    //第十一關初始化
    if (m_PRM.GetPhase() == 11)
    {
        //初始化人位置
        m_man->m_Transform.translation.x = 150;
        m_man->m_Transform.translation.y = 200;
        //初始化箱子1,2,3,4位置，顯示箱子5
        m_box1->m_Transform.translation.x = -250;
        m_box1->m_Transform.translation.y = 0;
        m_box2->m_Transform.translation.x = 50;
        m_box2->m_Transform.translation.y = 100;
        m_box3->m_Transform.translation.x = -250;
        m_box3->m_Transform.translation.y = -300;
        m_box4->m_Transform.translation.x = -150;
        m_box4->m_Transform.translation.y = -200;
        m_box5->SetVisible(true);
        m_box5->m_Transform.translation.x = 50;
        m_box5->m_Transform.translation.y = -200;

        //初始化目標1,2,3,4位置，顯示目標5
        m_target1->m_Transform.translation.x = -250;
        m_target1->m_Transform.translation.y = 100;
        m_target2->m_Transform.translation.x = 250;
        m_target2->m_Transform.translation.y = -300;
        m_target3->m_Transform.translation.x = -350;
        m_target3->m_Transform.translation.y = -300;
        m_target4->m_Transform.translation.x = 50;
        m_target4->m_Transform.translation.y = 200;
        m_target5->SetVisible(true);
        m_target5->m_Transform.translation.x = 150;
        m_target5->m_Transform.translation.y = -200;

        m_CurrentState = State::UPDATE;
    }
    //第十二關初始化
    if (m_PRM.GetPhase() == 12)
    {
        //初始化人位置
        m_man->m_Transform.translation.x = -250;
        m_man->m_Transform.translation.y = -200;
        //初始化箱子1,2,3,4,5位置
        m_box1->m_Transform.translation.x = -250;
        m_box1->m_Transform.translation.y = 100;
        m_box2->m_Transform.translation.x = 150;
        m_box2->m_Transform.translation.y = 100;
        m_box3->m_Transform.translation.x = 250;
        m_box3->m_Transform.translation.y = -100;
        m_box4->m_Transform.translation.x = -50;
        m_box4->m_Transform.translation.y = -200;
        m_box5->m_Transform.translation.x = 50;
        m_box5->m_Transform.translation.y = 0;

        //初始化目標1,2,3,4,5位置
        m_target1->m_Transform.translation.x = -350;
        m_target1->m_Transform.translation.y = 200;
        m_target2->m_Transform.translation.x = 250;
        m_target2->m_Transform.translation.y = 100;
        m_target3->m_Transform.translation.x = 350;
        m_target3->m_Transform.translation.y = 0;
        m_target4->m_Transform.translation.x = 50;
        m_target4->m_Transform.translation.y = 200;
        m_target5->m_Transform.translation.x = 150;
        m_target5->m_Transform.translation.y = -200;

        m_CurrentState = State::UPDATE;
    }

    //第十三關初始化
    if (m_PRM.GetPhase() == 13)
    {
        HideBoxesAndTargets();
        m_man->m_Transform.translation.x = 50;
        m_man->m_Transform.translation.y = 0;

        m_box1->m_Transform.translation.x = -50;
        m_box1->m_Transform.translation.y = 0;

        m_target1->m_Transform.translation.x = 150;
        m_target1->m_Transform.translation.y = -200;
        m_CurrentState = State::UPDATE;
    }
    //第十四關初始化
    if (m_PRM.GetPhase() == 14)
    {
        m_man->m_Transform.translation.x = 250;
        m_man->m_Transform.translation.y = -300;
        //初始化箱子1,2位置，顯示箱子2
        m_box1->m_Transform.translation.x = -150;
        m_box1->m_Transform.translation.y = 100;
        m_box2->SetVisible(true);
        m_box2->m_Transform.translation.x = 50;
        m_box2->m_Transform.translation.y = -200;
        //初始化目標1,2位置，顯示目標2
        m_target1->m_Transform.translation.x = -350;
        m_target1->m_Transform.translation.y = 100;
        m_target2->SetVisible(true);
        m_target2->m_Transform.translation.x = 250;
        m_target2->m_Transform.translation.y = -300;
        m_CurrentState = State::UPDATE;
    }
    //第十五關初始化
    if (m_PRM.GetPhase() == 15)
    {
        //初始化人位置
        m_man->m_Transform.translation.x = -350;
        m_man->m_Transform.translation.y = 100;
        //初始化箱子1,2位置，顯示箱子3
        m_box1->m_Transform.translation.x = -150;
        m_box1->m_Transform.translation.y = -200;
        m_box2->m_Transform.translation.x = -150;
        m_box2->m_Transform.translation.y = 100;
        m_box3->SetVisible(true);
        m_box3->m_Transform.translation.x = 50;
        m_box3->m_Transform.translation.y = -100;

        //初始化目標1,2,3位置，顯示目標3
        m_target1->m_Transform.translation.x = -50;
        m_target1->m_Transform.translation.y = 300;
        m_target2->m_Transform.translation.x = 150;
        m_target2->m_Transform.translation.y = -400;
        m_target3->SetVisible(true);
        m_target3->m_Transform.translation.x = -250;
        m_target3->m_Transform.translation.y = -200;

        m_CurrentState = State::UPDATE;
    }
    //第十六關初始化
    if (m_PRM.GetPhase() == 16)
    {
        //初始化人位置
        m_man->m_Transform.translation.x = -350;
        m_man->m_Transform.translation.y = 100;
        //初始化箱子1,2,3位置，顯示箱子4
        m_box1->m_Transform.translation.x = -150;
        m_box1->m_Transform.translation.y = 0;
        m_box2->m_Transform.translation.x = -150;
        m_box2->m_Transform.translation.y = 100;
        m_box3->m_Transform.translation.x = -50;
        m_box3->m_Transform.translation.y = -200;
        m_box4->SetVisible(true);
        m_box4->m_Transform.translation.x = 50;
        m_box4->m_Transform.translation.y = -200;

        //初始化目標1,2,3位置，顯示目標4
        m_target1->m_Transform.translation.x = 250;
        m_target1->m_Transform.translation.y = -100;
        m_target2->m_Transform.translation.x = 250;
        m_target2->m_Transform.translation.y = -300;
        m_target3->m_Transform.translation.x = -350;
        m_target3->m_Transform.translation.y = 100;
        m_target4->SetVisible(true);
        m_target4->m_Transform.translation.x = -250;
        m_target4->m_Transform.translation.y = -200;

        m_CurrentState = State::UPDATE;
    }
    //第十七關初始化
    if (m_PRM.GetPhase() == 17)
    {
        //初始化人位置
        m_man->m_Transform.translation.x = -250;
        m_man->m_Transform.translation.y = -200;
        //初始化箱子1,2,3,4位置，顯示箱子5
        m_box1->m_Transform.translation.x = -150;
        m_box1->m_Transform.translation.y = 100;
        m_box2->m_Transform.translation.x = 50;
        m_box2->m_Transform.translation.y = -300;
        m_box3->m_Transform.translation.x = -150;
        m_box3->m_Transform.translation.y = 200;
        m_box4->m_Transform.translation.x = -50;
        m_box4->m_Transform.translation.y = -200;
        m_box5->SetVisible(true);
        m_box5->m_Transform.translation.x = -150;
        m_box5->m_Transform.translation.y = 0;

        //初始化目標1,2,3,4位置，顯示目標5
        m_target1->m_Transform.translation.x = -350;
        m_target1->m_Transform.translation.y = 100;
        m_target2->m_Transform.translation.x = -250;
        m_target2->m_Transform.translation.y = -200;
        m_target3->m_Transform.translation.x = -250;
        m_target3->m_Transform.translation.y = -100;
        m_target4->m_Transform.translation.x = 250;
        m_target4->m_Transform.translation.y = -100;
        m_target5->SetVisible(true);
        m_target5->m_Transform.translation.x = 250;
        m_target5->m_Transform.translation.y = -300;

        m_CurrentState = State::UPDATE;
    }
    //第十八關初始化
    if (m_PRM.GetPhase() == 18)
    {
        //初始化人位置
        m_man->m_Transform.translation.x = -250;
        m_man->m_Transform.translation.y = -200;
        //初始化箱子1,2,3,4,5位置
        m_box1->m_Transform.translation.x = -250;
        m_box1->m_Transform.translation.y = 100;
        m_box2->m_Transform.translation.x = 150;
        m_box2->m_Transform.translation.y = 100;
        m_box3->m_Transform.translation.x = 250;
        m_box3->m_Transform.translation.y = -100;
        m_box4->m_Transform.translation.x = -50;
        m_box4->m_Transform.translation.y = -200;
        m_box5->m_Transform.translation.x = 50;
        m_box5->m_Transform.translation.y = 0;

        //初始化目標1,2,3,4,5位置
        m_target1->m_Transform.translation.x = -350;
        m_target1->m_Transform.translation.y = 200;
        m_target2->m_Transform.translation.x = 250;
        m_target2->m_Transform.translation.y = 100;
        m_target3->m_Transform.translation.x = 350;
        m_target3->m_Transform.translation.y = 0;
        m_target4->m_Transform.translation.x = 50;
        m_target4->m_Transform.translation.y = 200;
        m_target5->m_Transform.translation.x = 150;
        m_target5->m_Transform.translation.y = -200;

        m_CurrentState = State::UPDATE;
    }

    //第十九關初始化
    if (m_PRM.GetPhase() == 19)
    {
        HideBoxesAndTargets();
        m_man->m_Transform.translation.x = 50;
        m_man->m_Transform.translation.y = 0;

        m_box1->m_Transform.translation.x = -50;
        m_box1->m_Transform.translation.y = 0;

        m_target1->m_Transform.translation.x = -250;
        m_target1->m_Transform.translation.y = -300;
        m_CurrentState = State::UPDATE;
    }
    //第二十關初始化
    if (m_PRM.GetPhase() == 20)
    {
        m_man->m_Transform.translation.x = -250;
        m_man->m_Transform.translation.y = -300;
        //初始化箱子1,2位置，顯示箱子2
        m_box1->m_Transform.translation.x = -150;
        m_box1->m_Transform.translation.y = 0;
        m_box2->SetVisible(true);
        m_box2->m_Transform.translation.x = 50;
        m_box2->m_Transform.translation.y = -200;
        //初始化目標1,2位置，顯示目標2
        m_target1->m_Transform.translation.x = 50;
        m_target1->m_Transform.translation.y = 200;
        m_target2->SetVisible(true);
        m_target2->m_Transform.translation.x = 250;
        m_target2->m_Transform.translation.y = -100;
        m_CurrentState = State::UPDATE;
    }
    //第二十一關初始化
    if (m_PRM.GetPhase() == 21)
    {
        //初始化人位置
        m_man->m_Transform.translation.x = 50;
        m_man->m_Transform.translation.y = 200;
        //初始化箱子1,2位置，顯示箱子3
        m_box1->m_Transform.translation.x = -50;
        m_box1->m_Transform.translation.y = -300;
        m_box2->m_Transform.translation.x = 150;
        m_box2->m_Transform.translation.y = 0;
        m_box3->SetVisible(true);
        m_box3->m_Transform.translation.x = 150;
        m_box3->m_Transform.translation.y = 100;

        //初始化目標1,2,3位置，顯示目標3
        m_target1->m_Transform.translation.x = -250;
        m_target1->m_Transform.translation.y = -100;
        m_target2->m_Transform.translation.x = -250;
        m_target2->m_Transform.translation.y = -300;
        m_target3->SetVisible(true);
        m_target3->m_Transform.translation.x = -250;
        m_target3->m_Transform.translation.y = -200;

        m_CurrentState = State::UPDATE;
    }
    //第二十二關初始化
    if (m_PRM.GetPhase() == 22)
    {
        //初始化人位置
        m_man->m_Transform.translation.x = 50;
        m_man->m_Transform.translation.y = 300;
        //初始化箱子1,2,3位置，顯示箱子4
        m_box1->m_Transform.translation.x = 150;
        m_box1->m_Transform.translation.y = 100;
        m_box2->m_Transform.translation.x = 50;
        m_box2->m_Transform.translation.y = 200;
        m_box3->m_Transform.translation.x = 150;
        m_box3->m_Transform.translation.y = 0;
        m_box4->SetVisible(true);
        m_box4->m_Transform.translation.x = 50;
        m_box4->m_Transform.translation.y = -200;

        //初始化目標1,2,3位置，顯示目標4
        m_target1->m_Transform.translation.x = -250;
        m_target1->m_Transform.translation.y = 0;
        m_target2->m_Transform.translation.x = 250;
        m_target2->m_Transform.translation.y = -100;
        m_target3->m_Transform.translation.x = -250;
        m_target3->m_Transform.translation.y = -100;
        m_target4->SetVisible(true);
        m_target4->m_Transform.translation.x = -250;
        m_target4->m_Transform.translation.y = -200;

        m_CurrentState = State::UPDATE;
    }
    //第二十三關初始化
    if (m_PRM.GetPhase() == 23)
    {
        //初始化人位置
        m_man->m_Transform.translation.x = -250;
        m_man->m_Transform.translation.y = -300;
        //初始化箱子1,2,3,4位置，顯示箱子5
        m_box1->m_Transform.translation.x = -150;
        m_box1->m_Transform.translation.y = 0;
        m_box2->m_Transform.translation.x = 150;
        m_box2->m_Transform.translation.y = 100;
        m_box3->m_Transform.translation.x = 150;
        m_box3->m_Transform.translation.y = -100;
        m_box4->m_Transform.translation.x = 50;
        m_box4->m_Transform.translation.y = 0;
        m_box5->SetVisible(true);
        m_box5->m_Transform.translation.x = 50;
        m_box5->m_Transform.translation.y = 200;

        //初始化目標1,2,3,4位置，顯示目標5
        m_target1->m_Transform.translation.x = -250;
        m_target1->m_Transform.translation.y = 100;
        m_target2->m_Transform.translation.x = 250;
        m_target2->m_Transform.translation.y = 200;
        m_target3->m_Transform.translation.x = -250;
        m_target3->m_Transform.translation.y = 0;
        m_target4->m_Transform.translation.x = 50;
        m_target4->m_Transform.translation.y = -300;
        m_target5->SetVisible(true);
        m_target5->m_Transform.translation.x = 250;
        m_target5->m_Transform.translation.y = -100;

        m_CurrentState = State::UPDATE;
    }
    //第二十四關初始化
    if (m_PRM.GetPhase() == 24)
    {
        //初始化人位置
        m_man->m_Transform.translation.x = -250;
        m_man->m_Transform.translation.y = -200;
        //初始化箱子1,2,3,4,5位置
        m_box1->m_Transform.translation.x = -250;
        m_box1->m_Transform.translation.y = 100;
        m_box2->m_Transform.translation.x = 150;
        m_box2->m_Transform.translation.y = 100;
        m_box3->m_Transform.translation.x = 250;
        m_box3->m_Transform.translation.y = -100;
        m_box4->m_Transform.translation.x = -50;
        m_box4->m_Transform.translation.y = -200;
        m_box5->m_Transform.translation.x = 50;
        m_box5->m_Transform.translation.y = 0;

        //初始化目標1,2,3,4,5位置
        m_target1->m_Transform.translation.x = -350;
        m_target1->m_Transform.translation.y = 200;
        m_target2->m_Transform.translation.x = 250;
        m_target2->m_Transform.translation.y = 100;
        m_target3->m_Transform.translation.x = 350;
        m_target3->m_Transform.translation.y = 0;
        m_target4->m_Transform.translation.x = 50;
        m_target4->m_Transform.translation.y = 200;
        m_target5->m_Transform.translation.x = 150;
        m_target5->m_Transform.translation.y = -200;

        m_CurrentState = State::UPDATE;
    }

    //第二十五關初始化
    if (m_PRM.GetPhase() == 25)
    {
        HideBoxesAndTargets();
        m_man->m_Transform.translation.x = 50;
        m_man->m_Transform.translation.y = 0;

        m_box1->m_Transform.translation.x = -50;
        m_box1->m_Transform.translation.y = 0;

        m_target1->m_Transform.translation.x = 150;
        m_target1->m_Transform.translation.y = -200;
        m_CurrentState = State::UPDATE;
    }
    //第二十六關初始化
    if (m_PRM.GetPhase() == 26)
    {
        m_man->m_Transform.translation.x = 250;
        m_man->m_Transform.translation.y = -300;
        //初始化箱子1,2位置，顯示箱子2
        m_box1->m_Transform.translation.x = -150;
        m_box1->m_Transform.translation.y = 100;
        m_box2->SetVisible(true);
        m_box2->m_Transform.translation.x = 50;
        m_box2->m_Transform.translation.y = -200;
        //初始化目標1,2位置，顯示目標2
        m_target1->m_Transform.translation.x = 50;
        m_target1->m_Transform.translation.y = 200;
        m_target2->SetVisible(true);
        m_target2->m_Transform.translation.x = 250;
        m_target2->m_Transform.translation.y = -300;
        m_CurrentState = State::UPDATE;
    }
    //第二十七關初始化
    if (m_PRM.GetPhase() == 27)
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
    //第二十八關初始化
    if (m_PRM.GetPhase() == 28)
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
    //第二十九關初始化
    if (m_PRM.GetPhase() == 29)
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
    //第三十關初始化
    if (m_PRM.GetPhase() == 30)
    {
        //初始化人位置
        m_man->m_Transform.translation.x = -250;
        m_man->m_Transform.translation.y = -200;
        //初始化箱子1,2,3,4,5位置
        m_box1->m_Transform.translation.x = -250;
        m_box1->m_Transform.translation.y = 100;
        m_box2->m_Transform.translation.x = 150;
        m_box2->m_Transform.translation.y = 100;
        m_box3->m_Transform.translation.x = 250;
        m_box3->m_Transform.translation.y = -100;
        m_box4->m_Transform.translation.x = -50;
        m_box4->m_Transform.translation.y = -200;
        m_box5->m_Transform.translation.x = 50;
        m_box5->m_Transform.translation.y = 0;

        //初始化目標1,2,3,4,5位置
        m_target1->m_Transform.translation.x = -350;
        m_target1->m_Transform.translation.y = 200;
        m_target2->m_Transform.translation.x = 250;
        m_target2->m_Transform.translation.y = 100;
        m_target3->m_Transform.translation.x = 350;
        m_target3->m_Transform.translation.y = 0;
        m_target4->m_Transform.translation.x = 50;
        m_target4->m_Transform.translation.y = 200;
        m_target5->m_Transform.translation.x = 150;
        m_target5->m_Transform.translation.y = -200;

        m_CurrentState = State::UPDATE;
    }
}
void App::HideBoxesAndTargets() {
    m_box2->SetVisible(false);
    m_box3->SetVisible(false);
    m_box4->SetVisible(false);
    m_box5->SetVisible(false);
    m_target2->SetVisible(false);
    m_target3->SetVisible(false);
    m_target4->SetVisible(false);
    m_target5->SetVisible(false);

    m_box2->m_Transform.translation.x = 1000;
    m_box2->m_Transform.translation.y = 1000;
    m_box3->m_Transform.translation.x = 1000;
    m_box3->m_Transform.translation.y = 1000;
    m_box4->m_Transform.translation.x = 1000;
    m_box4->m_Transform.translation.y = 1000;
    m_box5->m_Transform.translation.x = 1000;
    m_box5->m_Transform.translation.y = 1000;

    m_target2->m_Transform.translation.x = 1000;
    m_target2->m_Transform.translation.y = 1000;
    m_target3->m_Transform.translation.x = 1000;
    m_target3->m_Transform.translation.y = 1000;
    m_target4->m_Transform.translation.x = 1000;
    m_target4->m_Transform.translation.y = 1000;
    m_target5->m_Transform.translation.x = 1000;
    m_target5->m_Transform.translation.y = 1000;
}