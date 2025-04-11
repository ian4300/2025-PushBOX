#include "App.hpp"
#include "Util/Logger.hpp"
#include "SDL.h"

void App::End() {
    LOG_TRACE("End");

    // 釋放所有加載的紋理
    for (auto& texture : m_Textures) {
        if (texture) {
            SDL_DestroyTexture(texture);
            texture = nullptr;
        }
    }

    // 銷毀渲染器
    if (m_Renderer) {
        SDL_DestroyRenderer(m_Renderer);
        m_Renderer = nullptr;
    }

    // 銷毀窗口
    if (m_Window) {
        SDL_DestroyWindow(m_Window);
        m_Window = nullptr;
    }

    // 關閉 SDL 子系統
    SDL_Quit();
}