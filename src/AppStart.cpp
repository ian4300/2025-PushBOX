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
        /*m_man->SetVisible(true);//腳色出現
        m_Stage->SetVisible(true);//地圖出現
        */
        m_CurrentState = State::UPDATE;
    }
    //第二關初始化
    if (m_PRM.GetPhase() == 2)
    {
        //初始化人位置
        m_man->m_Transform.translation.x = 300;
        m_man->m_Transform.translation.y = 75;
        //初始化箱子1位置，創建箱子2
        m_box1->m_Transform.translation.x = -150;
        m_box1->m_Transform.translation.y = 300;
        m_box2->SetVisible(true);
        m_box2->m_Transform.translation.x = 75;
        m_box2->m_Transform.translation.y = 75;
        //初始化目標1位置
        m_target1->m_Transform.translation.x = 0;
        m_target1->m_Transform.translation.y = -150;

        m_CurrentState = State::UPDATE;
    }
    //第三關初始化
    if (m_PRM.GetPhase() == 3)
    {
        //初始化人位置
        m_man->m_Transform.translation.x = 75;
        m_man->m_Transform.translation.y = 0;
        //初始化箱子1,2位置，創建箱子3
        m_box1->m_Transform.translation.x = -150;
        m_box1->m_Transform.translation.y = -225;
        m_box2->m_Transform.translation.x = 75;
        m_box2->m_Transform.translation.y = 150;
        m_box3->SetVisible(true);
        m_box3->m_Transform.translation.x = 300;
        m_box3->m_Transform.translation.y = -150;

        //初始化目標1位置
        m_target1->m_Transform.translation.x = -225;
        m_target1->m_Transform.translation.y = 75;

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