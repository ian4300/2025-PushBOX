#include "App.hpp"
#include "PhaseResourceManager.hpp"
#include <SDL_image.h>

void App::InitSDL() {
    SDL_Init(SDL_INIT_VIDEO);
    m_Window = SDL_CreateWindow("App", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);
}

void App::LoadTextures() {
    SDL_Surface* surface = IMG_Load("Resource/character1.png");
    m_Textures[0] = SDL_CreateTextureFromSurface(m_Renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("Resource/character2.png");
    m_Textures[1] = SDL_CreateTextureFromSurface(m_Renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("Resource/character3.png");
    m_Textures[2] = SDL_CreateTextureFromSurface(m_Renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("Resource/character4.png");
    m_Textures[3] = SDL_CreateTextureFromSurface(m_Renderer, surface);
    SDL_FreeSurface(surface);
}

void App::Start() {
    PhaseResourceManager::LoadPhase(m_Phase, m_man, m_boxes, m_targets);

    m_CurrentTexture = m_Textures[0]; // 初始顯示第一張圖片

    // 根據當前關卡初始化遊戲元素
    if (m_Phase == 1) {
        m_man.SetPosition({1, 1});
        m_boxes = {{2, 2}, {3, 3}};
        m_targets = {{4, 4}, {5, 5}};
    } else if (m_Phase == 2) {
        m_man.SetPosition({2, 2});
        m_boxes = {{3, 3}, {4, 4}};
        m_targets = {{5, 5}, {6, 6}};
    } else if (m_Phase == 3) {
        m_man.SetPosition({3, 3});
        m_boxes = {{4, 4}, {5, 5}};
        m_targets = {{6, 6}, {7, 7}};
    }
    m_CurrentState = State::UPDATE;
}