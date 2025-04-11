#include "App.hpp"
#include "PhaseResourceManager.hpp"
#include <SDL_image.h>

void App::InitSDL() {
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

    m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);
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

    surface = IMG_Load("Resources/character2.png");
    if (!surface) {
        SDL_Log("Failed to load texture: %s", IMG_GetError());
        return;
    }
    m_Textures[1] = SDL_CreateTextureFromSurface(m_Renderer, surface);
    SDL_FreeSurface(surface);

    if (!m_Textures[1]) {
        SDL_Log("Failed to create texture: %s", SDL_GetError());
    }

    surface = IMG_Load("Resources/character3.png");
    if (!surface) {
        SDL_Log("Failed to load texture: %s", IMG_GetError());
        return;
    }
    m_Textures[2] = SDL_CreateTextureFromSurface(m_Renderer, surface);
    SDL_FreeSurface(surface);

    if (!m_Textures[2]) {
        SDL_Log("Failed to create texture: %s", SDL_GetError());
    }

    surface = IMG_Load("Resources/character4.png");
    if (!surface) {
        SDL_Log("Failed to load texture: %s", IMG_GetError());
        return;
    }
    m_Textures[3] = SDL_CreateTextureFromSurface(m_Renderer, surface);
    SDL_FreeSurface(surface);

    if (!m_Textures[3]) {
        SDL_Log("Failed to create texture: %s", SDL_GetError());
    }
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