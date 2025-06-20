#include "App.hpp"
#include "Util/Logger.hpp"
#include "Util/Image.hpp"
#include "thread"
#include "chrono"
#include "PhaseResourceManger.hpp"
#include <SDL_image.h>

void App::Start() {

    m_PRM.NextPhase();
    int phase = m_PRM.GetPhase();

    // 將 finishtarget 陣列重置為 0
    std::fill(std::begin(finishtarget), std::end(finishtarget), 0);
    if (phase > 30)
        m_CurrentState = State::END;
    // 根據 Phase 切換地圖
    if (phase <= 6) {
        m_Stage->SetBackgroundImage("../Resources/map1.png" , 1);
    } else if (phase > 6 && phase <= 12) {
        m_Stage->SetBackgroundImage("../Resources/map2.png" , 7);
    } else if (phase > 12 && phase <= 18) {
        m_Stage->SetBackgroundImage("../Resources/map3.png" , 13);
    } else if (phase > 18 && phase <= 24) {
        m_Stage->SetBackgroundImage("../Resources/map4.png" , 19);
    } else if (phase > 24 && phase <= 30){
        m_Stage->SetBackgroundImage("../Resources/map5.png" , 25);
    }
    //第一關初始化
    if (m_PRM.GetPhase() == 1)
    {
        m_Root.AddChild(m_man);
        m_Root.AddChild(m_Stage);
        m_Root.AddChild(m_StepCounter);
        m_StepText = std::make_shared<GiraffeText>("../PTSD/assets/fonts/Inter.ttf", 100);
        m_StepText->Start();
        m_StepText->SetZIndex(8);
        m_Root.AddChild(m_StepText);
        m_StepText->m_Transform.translation = { -530, -230 };
        m_StepText->SetVisible(true);

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

        step = 7;

        m_CurrentState = State::UPDATE;
    }
    //第二關初始化
    if (m_PRM.GetPhase() == 2)
    {
        HideBoxesAndTargets();
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

        step = 19;

        m_CurrentState = State::UPDATE;
    }
    //第三關初始化
    if (m_PRM.GetPhase() == 3)
    {
        HideBoxesAndTargets();
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

        step = 30;

        m_CurrentState = State::UPDATE;
    }
    //第四關初始化
    if (m_PRM.GetPhase() == 4)
    {
        HideBoxesAndTargets();
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

        step = 55;

        m_CurrentState = State::UPDATE;
    }
    //第五關初始化
    if (m_PRM.GetPhase() == 5)
    {
        HideBoxesAndTargets();
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

        step = 40;

        m_CurrentState = State::UPDATE;
    }
    //第六關初始化
    if (m_PRM.GetPhase() == 6)
    {
        //初始化人位置
        m_man->m_Transform.translation.x = -250;
        m_man->m_Transform.translation.y = -200;
        //初始化箱子1,2,3,4,5位置
        m_box2->SetVisible(true);
        m_box3->SetVisible(true);
        m_box4->SetVisible(true);
        m_box5->SetVisible(true);
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

        m_target2->SetVisible(true);
        m_target3->SetVisible(true);
        m_target4->SetVisible(true);
        m_target5->SetVisible(true);
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

        step = 40;

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

        step = 15;

        m_CurrentState = State::UPDATE;
    }
    //第八關初始化
    if (m_PRM.GetPhase() == 8)
    {
        HideBoxesAndTargets();
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

        step = 35;

        m_CurrentState = State::UPDATE;
    }
    //第九關初始化
    if (m_PRM.GetPhase() == 9)
    {
        HideBoxesAndTargets();
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

        step = 45;

        m_CurrentState = State::UPDATE;
    }
    //第十關初始化
    if (m_PRM.GetPhase() == 10)
    {
        HideBoxesAndTargets();
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

        step = 35;

        m_CurrentState = State::UPDATE;
    }
    //第十一關初始化
    if (m_PRM.GetPhase() == 11)
    {
        HideBoxesAndTargets();
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

        step = 55;

        m_CurrentState = State::UPDATE;
    }
    //第十二關初始化
    if (m_PRM.GetPhase() == 12)
    {
        //初始化人位置
        m_man->m_Transform.translation.x = 150;
        m_man->m_Transform.translation.y = 200;
        m_box2->SetVisible(true);
        m_box3->SetVisible(true);
        m_box4->SetVisible(true);
        m_box5->SetVisible(true);
        //初始化箱子1,2,3,4,5位置
        m_box1->m_Transform.translation.x = -250;
        m_box1->m_Transform.translation.y = 0;
        m_box2->m_Transform.translation.x = 50;
        m_box2->m_Transform.translation.y = 100;
        m_box3->m_Transform.translation.x = -250;
        m_box3->m_Transform.translation.y = -300;
        m_box4->m_Transform.translation.x = -150;
        m_box4->m_Transform.translation.y = -200;
        m_box5->m_Transform.translation.x = 50;
        m_box5->m_Transform.translation.y = -200;

        m_target2->SetVisible(true);
        m_target3->SetVisible(true);
        m_target4->SetVisible(true);
        m_target5->SetVisible(true);
        //初始化目標1,2,3,4,5位置
        m_target1->m_Transform.translation.x = -250;
        m_target1->m_Transform.translation.y = 100;
        m_target2->m_Transform.translation.x = 250;
        m_target2->m_Transform.translation.y = -300;
        m_target3->m_Transform.translation.x = -350;
        m_target3->m_Transform.translation.y = -300;
        m_target4->m_Transform.translation.x = 50;
        m_target4->m_Transform.translation.y = 200;
        m_target5->m_Transform.translation.x = 150;
        m_target5->m_Transform.translation.y = -200;

        step = 55;

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

        step = 20;

        m_CurrentState = State::UPDATE;
    }
    //第十四關初始化
    if (m_PRM.GetPhase() == 14)
    {
        HideBoxesAndTargets();
        //初始化人位置
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

        step = 23;

        m_CurrentState = State::UPDATE;
    }
    //第十五關初始化
    if (m_PRM.GetPhase() == 15)
    {
        HideBoxesAndTargets();
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

        step = 20;

        m_CurrentState = State::UPDATE;
    }
    //第十六關初始化
    if (m_PRM.GetPhase() == 16)
    {
        HideBoxesAndTargets();
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

        step = 50;

        m_CurrentState = State::UPDATE;
    }
    //第十七關初始化
    if (m_PRM.GetPhase() == 17)
    {
        HideBoxesAndTargets();
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

        step = 68;

        m_CurrentState = State::UPDATE;
    }
    //第十八關初始化
    if (m_PRM.GetPhase() == 18)
    {
        //初始化人位置
        m_man->m_Transform.translation.x = -250;
        m_man->m_Transform.translation.y = -200;
        m_box2->SetVisible(true);
        m_box3->SetVisible(true);
        m_box4->SetVisible(true);
        m_box5->SetVisible(true);
        //初始化箱子1,2,3,4,5位置
        m_box1->m_Transform.translation.x = -150;
        m_box1->m_Transform.translation.y = 100;
        m_box2->m_Transform.translation.x = 50;
        m_box2->m_Transform.translation.y = -300;
        m_box3->m_Transform.translation.x = -150;
        m_box3->m_Transform.translation.y = 200;
        m_box4->m_Transform.translation.x = -50;
        m_box4->m_Transform.translation.y = -200;
        m_box5->m_Transform.translation.x = -150;
        m_box5->m_Transform.translation.y = 0;

        m_target2->SetVisible(true);
        m_target3->SetVisible(true);
        m_target4->SetVisible(true);
        m_target5->SetVisible(true);
        //初始化目標1,2,3,4,5位置
        m_target1->m_Transform.translation.x = -350;
        m_target1->m_Transform.translation.y = 100;
        m_target2->m_Transform.translation.x = -250;
        m_target2->m_Transform.translation.y = -200;
        m_target3->m_Transform.translation.x = -250;
        m_target3->m_Transform.translation.y = -100;
        m_target4->m_Transform.translation.x = 250;
        m_target4->m_Transform.translation.y = -100;
        m_target5->m_Transform.translation.x = 250;
        m_target5->m_Transform.translation.y = -300;

        step = 68;

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

        step = 7;

        m_CurrentState = State::UPDATE;
    }
    //第二十關初始化
    if (m_PRM.GetPhase() == 20)
    {
        HideBoxesAndTargets();
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

        step = 20;

        m_CurrentState = State::UPDATE;
    }
    //第二十一關初始化
    if (m_PRM.GetPhase() == 21)
    {
        HideBoxesAndTargets();
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

        step = 43;

        m_CurrentState = State::UPDATE;
    }
    //第二十二關初始化
    if (m_PRM.GetPhase() == 22)
    {
        HideBoxesAndTargets();
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

        step = 75;

        m_CurrentState = State::UPDATE;
    }
    //第二十三關初始化
    if (m_PRM.GetPhase() == 23)
    {
        HideBoxesAndTargets();
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

        step = 55;

        m_CurrentState = State::UPDATE;
    }
    //第二十四關初始化
    if (m_PRM.GetPhase() == 24)
    {
        m_box2->SetVisible(true);
        m_box3->SetVisible(true);
        m_box4->SetVisible(true);
        m_box5->SetVisible(true);
        //初始化人位置
        m_man->m_Transform.translation.x = -250;
        m_man->m_Transform.translation.y = -300;
        //初始化箱子1,2,3,4,5位置
        m_box1->m_Transform.translation.x = -150;
        m_box1->m_Transform.translation.y = 0;
        m_box2->m_Transform.translation.x = 150;
        m_box2->m_Transform.translation.y = 100;
        m_box3->m_Transform.translation.x = 150;
        m_box3->m_Transform.translation.y = -100;
        m_box4->m_Transform.translation.x = 50;
        m_box4->m_Transform.translation.y = 0;
        m_box5->m_Transform.translation.x = 50;
        m_box5->m_Transform.translation.y = 200;

        m_target2->SetVisible(true);
        m_target3->SetVisible(true);
        m_target4->SetVisible(true);
        m_target5->SetVisible(true);
        //初始化目標1,2,3,4,5位置
        m_target1->m_Transform.translation.x = -250;
        m_target1->m_Transform.translation.y = 100;
        m_target2->m_Transform.translation.x = 250;
        m_target2->m_Transform.translation.y = 200;
        m_target3->m_Transform.translation.x = -250;
        m_target3->m_Transform.translation.y = 0;
        m_target4->m_Transform.translation.x = 50;
        m_target4->m_Transform.translation.y = -300;
        m_target5->m_Transform.translation.x = 250;
        m_target5->m_Transform.translation.y = -100;

        step = 55;

        m_CurrentState = State::UPDATE;
    }

    //第二十五關初始化
    if (m_PRM.GetPhase() == 25)
    {
        HideBoxesAndTargets();
        m_man->m_Transform.translation.x = 50;
        m_man->m_Transform.translation.y = 0;

        m_box1->m_Transform.translation.x = -50;
        m_box1->m_Transform.translation.y = -100;

        m_target1->m_Transform.translation.x = 150;
        m_target1->m_Transform.translation.y = -300;

        step = 21;

        m_CurrentState = State::UPDATE;
    }
    //第二十六關初始化
    if (m_PRM.GetPhase() == 26)
    {
        HideBoxesAndTargets();
        //初始化人位置
        m_man->m_Transform.translation.x = 250;
        m_man->m_Transform.translation.y = -300;
        //初始化箱子1,2位置，顯示箱子2
        m_box1->m_Transform.translation.x = -50;
        m_box1->m_Transform.translation.y = 100;
        m_box2->SetVisible(true);
        m_box2->m_Transform.translation.x = 50;
        m_box2->m_Transform.translation.y = -200;
        //初始化目標1,2位置，顯示目標2
        m_target1->m_Transform.translation.x = 250;
        m_target1->m_Transform.translation.y = 300;
        m_target2->SetVisible(true);
        m_target2->m_Transform.translation.x = -350;
        m_target2->m_Transform.translation.y = -300;

        step = 35;

        m_CurrentState = State::UPDATE;
    }
    //第二十七關初始化
    if (m_PRM.GetPhase() == 27)
    {
        HideBoxesAndTargets();
        //初始化人位置
        m_man->m_Transform.translation.x = -350;
        m_man->m_Transform.translation.y = -200;
        //初始化箱子1,2位置，顯示箱子3
        m_box1->m_Transform.translation.x = -150;
        m_box1->m_Transform.translation.y = -200;
        m_box2->m_Transform.translation.x = -50;
        m_box2->m_Transform.translation.y = -100;
        m_box3->SetVisible(true);
        m_box3->m_Transform.translation.x = 250;
        m_box3->m_Transform.translation.y = -100;

        //初始化目標1,2,3位置，顯示目標3
        m_target1->m_Transform.translation.x = 250;
        m_target1->m_Transform.translation.y = 300;
        m_target2->m_Transform.translation.x = 150;
        m_target2->m_Transform.translation.y = -300;
        m_target3->SetVisible(true);
        m_target3->m_Transform.translation.x = -350;
        m_target3->m_Transform.translation.y = -300;

        step = 53;

        m_CurrentState = State::UPDATE;
    }
    //第二十八關初始化
    if (m_PRM.GetPhase() == 28)
    {
        HideBoxesAndTargets();
        //初始化人位置
        m_man->m_Transform.translation.x = -50;
        m_man->m_Transform.translation.y = 300;
        //初始化箱子1,2,3位置，顯示箱子4
        m_box1->m_Transform.translation.x = 150;
        m_box1->m_Transform.translation.y = 100;
        m_box2->m_Transform.translation.x = -50;
        m_box2->m_Transform.translation.y = -100;
        m_box3->m_Transform.translation.x = 250;
        m_box3->m_Transform.translation.y = 0;
        m_box4->SetVisible(true);
        m_box4->m_Transform.translation.x = 50;
        m_box4->m_Transform.translation.y = -200;

        //初始化目標1,2,3位置，顯示目標4
        m_target1->m_Transform.translation.x = 250;
        m_target1->m_Transform.translation.y = 300;
        m_target2->m_Transform.translation.x = 350;
        m_target2->m_Transform.translation.y = 100;
        m_target3->m_Transform.translation.x = -150;
        m_target3->m_Transform.translation.y = 100;
        m_target4->SetVisible(true);
        m_target4->m_Transform.translation.x = 250;
        m_target4->m_Transform.translation.y = -300;

        step = 65;

        m_CurrentState = State::UPDATE;
    }
    //第二十九關初始化
    if (m_PRM.GetPhase() == 29)
    {
        HideBoxesAndTargets();
        //初始化人位置
        m_man->m_Transform.translation.x = 50;
        m_man->m_Transform.translation.y = -100;
        //初始化箱子1,2,3,4位置，顯示箱子5
        m_box1->m_Transform.translation.x = -50;
        m_box1->m_Transform.translation.y = -100;
        m_box2->m_Transform.translation.x = 150;
        m_box2->m_Transform.translation.y = -100;
        m_box3->m_Transform.translation.x = 250;
        m_box3->m_Transform.translation.y = -100;
        m_box4->m_Transform.translation.x = -50;
        m_box4->m_Transform.translation.y = -300;
        m_box5->SetVisible(true);
        m_box5->m_Transform.translation.x = 50;
        m_box5->m_Transform.translation.y = 0;

        //初始化目標1,2,3,4位置，顯示目標5
        m_target1->m_Transform.translation.x = -350;
        m_target1->m_Transform.translation.y = -300;
        m_target2->m_Transform.translation.x = 350;
        m_target2->m_Transform.translation.y = 100;
        m_target3->m_Transform.translation.x = -50;
        m_target3->m_Transform.translation.y = 100;
        m_target4->m_Transform.translation.x = 250;
        m_target4->m_Transform.translation.y = 300;
        m_target5->SetVisible(true);
        m_target5->m_Transform.translation.x = 250;
        m_target5->m_Transform.translation.y = -300;

        step = 60;

        m_CurrentState = State::UPDATE;
    }
    //第三十關初始化
    if (m_PRM.GetPhase() == 30)
    {
        //初始化人位置
        m_man->m_Transform.translation.x = 50;
        m_man->m_Transform.translation.y = -100;
        m_box2->SetVisible(true);
        m_box3->SetVisible(true);
        m_box4->SetVisible(true);
        m_box5->SetVisible(true);
        //初始化箱子1,2,3,4,5位置
        m_box1->m_Transform.translation.x = -50;
        m_box1->m_Transform.translation.y = -100;
        m_box2->m_Transform.translation.x = 150;
        m_box2->m_Transform.translation.y = -100;
        m_box3->m_Transform.translation.x = 250;
        m_box3->m_Transform.translation.y = -100;
        m_box4->m_Transform.translation.x = -50;
        m_box4->m_Transform.translation.y = -300;
        m_box5->m_Transform.translation.x = 50;
        m_box5->m_Transform.translation.y = 0;

        m_target2->SetVisible(true);
        m_target3->SetVisible(true);
        m_target4->SetVisible(true);
        m_target5->SetVisible(true);
        //初始化目標1,2,3,4,5位置
        m_target1->m_Transform.translation.x = -350;
        m_target1->m_Transform.translation.y = -300;
        m_target2->m_Transform.translation.x = 350;
        m_target2->m_Transform.translation.y = 100;
        m_target3->m_Transform.translation.x = -50;
        m_target3->m_Transform.translation.y = 100;
        m_target4->m_Transform.translation.x = 250;
        m_target4->m_Transform.translation.y = 300;
        m_target5->m_Transform.translation.x = 250;
        m_target5->m_Transform.translation.y = -300;

        step = 60;

        m_CurrentState = State::UPDATE;
    }
}
void App::HideBoxesAndTargets() {
    if (m_PRM.GetPhase() % 6 <= 2)
    {
        m_box2->SetVisible(false);
        m_box2->m_Transform.translation.x = 1000;
        m_box2->m_Transform.translation.y = 1000;
        m_target2->SetVisible(false);
        m_target2->m_Transform.translation.x = 1000;
        m_target2->m_Transform.translation.y = 1000;
    }
    if (m_PRM.GetPhase() % 6 <= 3)
    {
        m_box3->SetVisible(false);
        m_box3->m_Transform.translation.x = 1000;
        m_box3->m_Transform.translation.y = 1000;
        m_target3->SetVisible(false);
        m_target3->m_Transform.translation.x = 1000;
        m_target3->m_Transform.translation.y = 1000;
    }
    if (m_PRM.GetPhase() % 6 <= 4)
    {
        m_box4->SetVisible(false);
        m_box4->m_Transform.translation.x = 1000;
        m_box4->m_Transform.translation.y = 1000;
        m_target4->SetVisible(false);
        m_target4->m_Transform.translation.x = 1000;
        m_target4->m_Transform.translation.y = 1000;
    }
    if (m_PRM.GetPhase() % 6 <= 5)
    {
        m_box5->SetVisible(false);
        m_box5->m_Transform.translation.x = 1000;
        m_box5->m_Transform.translation.y = 1000;
        m_target5->SetVisible(false);
        m_target5->m_Transform.translation.x = 1000;
        m_target5->m_Transform.translation.y = 1000;
    }
}