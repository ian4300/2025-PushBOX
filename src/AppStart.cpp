#include "App.hpp"
#include "Util/Logger.hpp"
#include "Util/Image.hpp"
#include <SDL_image.h>

void App::Start() {
    LOG_TRACE("Start");

    m_Root.AddChild(m_man);
    m_Root.AddChild(m_Stage);
    m_Root.AddChild(m_box1);
    m_man->SetVisible(true);//腳色出現
    m_Stage->SetVisible(true);//地圖出現
    m_CurrentState = State::UPDATE;
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