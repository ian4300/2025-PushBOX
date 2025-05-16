#include "App.hpp"
#include "Util/Logger.hpp"
#include "Util/Image.hpp"
#include "PhaseResourceManger.hpp"
#include <SDL_image.h>

void App::Start() {
    LOG_TRACE("Start");
    if (m_PRM.GetPhase() < 4)
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
        m_target2->SetVisible(false);
        m_Root.AddChild(m_target4);
        m_target2->SetVisible(false);
        m_Root.AddChild(m_target5);
        m_target2->SetVisible(false);

        m_man->m_Transform.translation.x = 50;
        m_man->m_Transform.translation.y = 0;

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
}
//廢案
/*  void App::InitSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
        exit(1);
    }

    m_Window = SDL_CreateWindow("Game Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    if (!m_Window) {
        SDL_Log("Failed to create window: %s", SDL_GetError());
        SDL_Quit();
        exit(1);
    }

    m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!m_Renderer) {
        SDL_Log("Failed to create renderer: %s", SDL_GetError());
        SDL_DestroyWindow(m_Window);
        SDL_Quit();
        exit(1);
    }
}
void App::LoadTextures() {
    SDL_Surface* surface = nullptr;

    surface = IMG_Load("Resources/character1.png");
    if (!surface) {
        SDL_Log("Failed to load texture: %s", IMG_GetError());
        return;
    }
    m_Textures[0] = SDL_CreateTextureFromSurface(m_Renderer, surface);
    SDL_FreeSurface(surface);

    if (!m_Textures[0]) {
        SDL_Log("Failed to create texture: %s", SDL_GetError());
    }
}

Character::Character(const std::string& ImagePath) {
    SetImage(ImagePath);

    ResetPosition();
}

void Character::SetImage(const std::string& ImagePath) {
    m_ImagePath = ImagePath;

    m_Drawable = std::make_shared<Util::Image>(m_ImagePath);
}*/